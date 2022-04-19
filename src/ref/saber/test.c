
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#include <arm_neon.h>

#include "SABER_params.h"
#include "poly.h"
#include "MatrixVector.h"
#include "hal.h"

#define ITERATIONS 10000

void schoolbook_core(uint16_t des[SABER_N], const uint16_t src1[SABER_N], const uint16_t src2[SABER_N]);
void schoolbook(poly *des, const poly *src1, const poly *src2);
void poly_add(poly *des, const poly *src1, const poly *src2);

void MatrixVectorMul_ref(poly c[SABER_L], const poly A[SABER_L][SABER_L], const poly s[SABER_L]);
void InnerProd_ref(poly *c, const poly b[SABER_L], const poly s[SABER_L]);

void Enc_MatrixVectorMul_InnerProd_ref(poly bp[SABER_L], poly *c, const poly A[SABER_L][SABER_L], const poly b[SABER_L], const poly s[SABER_L]);

int main(void){

    poly ref;
    poly res;

    poly mat[SABER_L][SABER_L];
    poly secret[SABER_L];
    poly cipher[SABER_L];
    poly ref_vec[SABER_L];
    poly res_vec[SABER_L];

    for(size_t i = 0; i < ITERATIONS; i++){

        for(size_t j = 0; j < SABER_L; j++){
            for(size_t k = 0; k < SABER_N; k++){
                secret[j].coeffs[k] = rand() % (SABER_MU + 1);
            }
        }

        for(size_t j = 0; j < SABER_L; j++){
            for(size_t k = 0; k < SABER_N; k++){
                cipher[j].coeffs[k] = rand() & (SABER_Q - 1);
            }
        }

        InnerProd_ref(&ref, cipher, secret);
        InnerProd(&res, cipher, secret);

        for(size_t j = 0; j < SABER_N; j++){
            assert( MODQ(ref.coeffs[j]) == MODQ(res.coeffs[j]) );
        }

    }
    printf("InnerProd passed!\n");

    for(size_t i = 0; i < ITERATIONS; i++){

        for(size_t j = 0; j < SABER_L; j++){
            for(size_t k = 0; k < SABER_N; k++){
                secret[j].coeffs[k] = rand() % (SABER_MU + 1);
            }
        }

        for(size_t j = 0; j < SABER_L; j++){
            for(size_t k = 0; k < SABER_L; k++){
                for(size_t h = 0; h < SABER_N; h++){
                    mat[j][k].coeffs[h] = rand() & (SABER_Q - 1);
                }
            }
        }

        MatrixVectorMul_ref(ref_vec, (const poly (*)[SABER_L])mat, secret);
        MatrixVectorMul(res_vec, (const poly (*)[SABER_L])mat, secret);

        for(size_t j = 0; j < SABER_L; j++){
            for(size_t k = 0; k < SABER_N; k++){
                assert( MODQ(ref_vec[j].coeffs[k]) == MODQ(res_vec[j].coeffs[k]) );
            }
        }

    }
    printf("MatrixVectorMul passed!\n");

    for(size_t i = 0; i < ITERATIONS; i++){

        for(size_t j = 0; j < SABER_L; j++){
            for(size_t k = 0; k < SABER_N; k++){
                secret[j].coeffs[k] = rand() % (SABER_MU + 1);
            }
        }

        for(size_t j = 0; j < SABER_L; j++){
            for(size_t k = 0; k < SABER_L; k++){
                for(size_t h = 0; h < SABER_N; h++){
                    mat[j][k].coeffs[h] = rand() & (SABER_Q - 1);
                }
            }
        }

        for(size_t j = 0; j < SABER_L; j++){
            for(size_t k = 0; k < SABER_N; k++){
                cipher[j].coeffs[k] = rand() & (SABER_Q - 1);
            }
        }

        Enc_MatrixVectorMul_InnerProd_ref(ref_vec, &ref, (const poly (*)[SABER_L])mat, cipher, secret);
        Enc_MatrixVectorMul_InnerProd(res_vec, &res, (const poly (*)[SABER_L])mat, cipher, secret);

        for(size_t j = 0; j < SABER_N; j++){
            assert( MODQ(ref.coeffs[j]) == MODQ(res.coeffs[j]) );
        }

        for(size_t j = 0; j < SABER_L; j++){
            for(size_t k = 0; k < SABER_N; k++){
                assert( MODQ(ref_vec[j].coeffs[k]) == MODQ(res_vec[j].coeffs[k]) );
            }
        }

    }
    printf("InnerProd (Encrypt) + MatrixVectorMul passed!\n");


}


void schoolbook_core(uint16_t des[SABER_N], const uint16_t src1[SABER_N], const uint16_t src2[SABER_N]){

    uint16_t tmp[SABER_N * 2];

    for(size_t i = 0; i < SABER_N * 2; i++){
        tmp[i] = 0;
    }

    for(size_t i = 0; i < SABER_N; i++){
        for(size_t j = 0; j < SABER_N; j++){
            tmp[i + j] += src1[i] * src2[j];
        }
    }

    for(size_t i = 0; i < SABER_N; i++){
        des[i] = tmp[i];
    }

    for(size_t i = SABER_N; i < SABER_N * 2; i++){
        des[i - SABER_N] -= tmp[i];
    }

}

void schoolbook(poly *des, const poly *src1, const poly *src2){
    schoolbook_core(des->coeffs, (const uint16_t*)src1->coeffs, (const uint16_t*)src2->coeffs);
}

void poly_add(poly *des, const poly *src1, const poly *src2){

    for(size_t i = 0; i < SABER_N; i++){
        des->coeffs[i] = src1->coeffs[i] + src2->coeffs[i];
    }

}

void MatrixVectorMul_ref(poly c[SABER_L], const poly A[SABER_L][SABER_L], const poly s[SABER_L]){

    poly tmp;

    for (size_t i = 0; i < SABER_L; i++) {
        schoolbook(&c[i], &A[i][0], &s[0]);
        for (size_t j = 1; j < SABER_L; j++) {
            schoolbook(&tmp, &A[i][j], &s[j]);
            poly_add(&c[i], &c[i], &tmp);
        }
    }
}

void InnerProd_ref(poly *c, const poly b[SABER_L], const poly s[SABER_L]) {

    poly tmp;

    schoolbook(c, &b[0], &s[0]);
    for (size_t i = 1; i < SABER_L; i++) {
        schoolbook(&tmp, &b[i], &s[i]);
        poly_add(c, c, &tmp);
    }
}


void Enc_MatrixVectorMul_InnerProd_ref(poly bp[SABER_L], poly *c, const poly A[SABER_L][SABER_L], const poly b[SABER_L], const poly s[SABER_L]){


    MatrixVectorMul_ref(bp, (const poly (*)[SABER_L])A, s);
    InnerProd_ref(c, b, s);

}






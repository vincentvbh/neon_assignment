
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#include "params.h"
#include "poly.h"
#include "hal.h"

#define ITERATIONS 1000

void schoolbook_core(int32_t des[N], const int32_t src1[N], const int32_t src2[N]);
void schoolbook(poly *des, const poly *src1, const poly *src2);

int main(void){

    polyvecl mat[K];
    polyvecl vector;
    polyveck ref_vec;
    polyveck res_vec;
    poly src1, src2;
    poly ref;
    poly res;
    poly tmp;

    for(size_t i = 0; i < ITERATIONS; i++){

        for(size_t j = 0; j < N; j++){
            src1.coeffs[j] = rand() % Q;
            src2.coeffs[j] = rand() % Q;
            src1.coeffs[j] -= (Q >> 1);
            src2.coeffs[j] -= (Q >> 1);
        }

        schoolbook(&ref, &src1, &src2);

        poly_ntt(&src1);
        poly_ntt(&src2);
        poly_pointwise_montgomery(&res, &src1, &src2);
        poly_invntt_tomont(&res);

        for(size_t j = 0; j < N; j++){
            assert( ((ref.coeffs[j] - res.coeffs[j]) % Q) == 0);
        }

    }
    printf("poly_mul passed!\n");

    for(size_t i = 0; i < ITERATIONS; i++){

        for(size_t j = 0; j < K; j++){
            for(size_t k = 0; k < L; k++){
                for(size_t h = 0; h < N; h++){
                    mat[j].vec[k].coeffs[h] = rand() % Q;
                    mat[j].vec[k].coeffs[h] -= (Q >> 1);
                }
            }
        }

        for(size_t j = 0; j < L; j++){
            for(size_t k = 0; k < N; k++){
            vector.vec[j].coeffs[k] = rand() % Q;
            vector.vec[j].coeffs[k] -= (Q >> 1);
            }
        }

        for(size_t j = 0; j < K; j++){
            schoolbook(&ref_vec.vec[j], &mat[j].vec[0], &vector.vec[0]);
            for(size_t k = 1; k < L; k++){
                schoolbook(&tmp, &mat[j].vec[k], &vector.vec[k]);
                poly_add(&ref_vec.vec[j], &ref_vec.vec[j], &tmp);
            }
        }

        for(size_t j = 0; j < K; j++){
            for(size_t k = 0; k < L; k++){
                poly_ntt(&mat[j].vec[k]);
            }
        }
        for(size_t j = 0; j < L; j++){
            poly_ntt(&vector.vec[j]);
        }
        for(size_t j = 0; j < K; j++){
                polyvecl_pointwise_acc_montgomery(&res_vec.vec[j], (const polyvecl *)&mat[j], &vector);
        }
        for(size_t j = 0; j < K; j++){
            poly_invntt_tomont(&res_vec.vec[j]);
        }

        for(size_t j = 0; j < K; j++){
            for(size_t k = 0; k < N; k++){
                assert( ((ref_vec.vec[j].coeffs[k] - res_vec.vec[j].coeffs[k]) % Q) == 0 );
            }
        }

    }
    printf("matrix-to-vector mul passed!\n");

}

void schoolbook_core(int32_t des[N], const int32_t src1[N], const int32_t src2[N]){

    int32_t tmp[N * 2];

    for(size_t i = 0; i < N * 2; i++){
        tmp[i] = 0;
    }

    for(size_t i = 0; i < N; i++){
        for(size_t j = 0; j < N; j++){
            tmp[i + j] += (int64_t)src1[i] * src2[j] % Q;
        }
    }

    for(size_t i = 0; i < N; i++){
        des[i] = tmp[i];
    }

    for(size_t i = N; i < N * 2; i++){
        des[i - N] -= tmp[i];
    }

}

void schoolbook(poly *des, const poly *src1, const poly *src2){
    schoolbook_core(des->coeffs, (const int32_t*)src1->coeffs, (const int32_t*)src2->coeffs);
}









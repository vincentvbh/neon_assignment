
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#include "params.h"
#include "poly.h"
#include "hal.h"

#define ITERATIONS 10000

void schoolbook_core(int32_t des[N], const int32_t src1[N], const int32_t src2[N]);
void schoolbook(poly *des, const poly *src1, const poly *src2);
void poly_add(poly *des, const poly *src1, const poly *src2);

int main(void){

    poly src1, src2;
    poly ref;
    poly res;

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

void poly_add(poly *des, const poly *src1, const poly *src2){

    for(size_t i = 0; i < N; i++){
        des->coeffs[i] = src1->coeffs[i] + src2->coeffs[i];
    }

}








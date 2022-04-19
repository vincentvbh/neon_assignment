
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#include <arm_neon.h>

#include "SABER_params.h"
#include "poly.h"
#include "MatrixVector.h"
#include "hal.h"

#define ITERATIONS 100000

uint64_t t0, t1;
uint64_t times[ITERATIONS];

static int cmp_uint64(const void *a, const void *b){
    return ((*((const uint64_t*)a)) - ((*((const uint64_t*)b))));
}


int main(void){


    poly mat[SABER_L][SABER_L];
    poly secret[SABER_L];
    poly cipher[SABER_L];
    poly res_vec[SABER_L];
    poly res;

    for(size_t i = 0; i < ITERATIONS; i++){
        t0 = hal_get_time();
        InnerProd(&res, cipher, secret);
        t1 = hal_get_time();
        times[i] = t1 - t0;
    }
    qsort(times, ITERATIONS, sizeof(uint64_t), cmp_uint64);
    printf("InnerProd: %ld\n", times[ITERATIONS >> 1]);

    for(size_t i = 0; i < ITERATIONS; i++){
        t0 = hal_get_time();
        MatrixVectorMul(res_vec, (const poly (*)[SABER_L])mat, secret);
        t1 = hal_get_time();
        times[i] = t1 - t0;
    }
    qsort(times, ITERATIONS, sizeof(uint64_t), cmp_uint64);
    printf("MatrixVectorMul: %ld\n", times[ITERATIONS >> 1]);

    for(size_t i = 0; i < ITERATIONS; i++){
        t0 = hal_get_time();
        Enc_MatrixVectorMul_InnerProd(res_vec, &res, (const poly (*)[SABER_L])mat, cipher, secret);
        t1 = hal_get_time();
        times[i] = t1 - t0;
    }
    qsort(times, ITERATIONS, sizeof(uint64_t), cmp_uint64);
    printf("InnerProd (Enc) + MatrixVectorMul: %ld\n", times[ITERATIONS >> 1]);


}

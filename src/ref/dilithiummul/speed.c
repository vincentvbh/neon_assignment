
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#include "params.h"
#include "poly.h"
#include "hal.h"

#define ITERATIONS 100000

uint64_t t0, t1;
uint64_t times[ITERATIONS];

static int cmp_uint64(const void *a, const void *b){
    return ((*((const uint64_t*)a)) - ((*((const uint64_t*)b))));
}

int main(void){

    polyvecl src1_vec, src2_vec;
    poly src1, src2;
    poly des;

    for(size_t i = 0; i < ITERATIONS; i++){
        t0 = hal_get_time();
        poly_ntt(&src1);
        t1 = hal_get_time();
        times[i] = t1 - t0;
    }
    qsort(times, ITERATIONS, sizeof(uint64_t), cmp_uint64);
    printf("poly_ntt: %ld\n", times[ITERATIONS >> 1]);

    for(size_t i = 0; i < ITERATIONS; i++){
        t0 = hal_get_time();
        poly_invntt_tomont(&src1);
        t1 = hal_get_time();
        times[i] = t1 - t0;
    }
    qsort(times, ITERATIONS, sizeof(uint64_t), cmp_uint64);
    printf("poly_invntt_tomont: %ld\n", times[ITERATIONS >> 1]);

    for(size_t i = 0; i < ITERATIONS; i++){
        t0 = hal_get_time();
        poly_pointwise_montgomery(&des, &src1, &src2);
        t1 = hal_get_time();
        times[i] = t1 - t0;
    }
    qsort(times, ITERATIONS, sizeof(uint64_t), cmp_uint64);
    printf("poly_pointwise_montgomery: %ld\n", times[ITERATIONS >> 1]);

    for(size_t i = 0; i < ITERATIONS; i++){
        t0 = hal_get_time();
        polyvecl_pointwise_acc_montgomery(&des, &src1_vec, &src2_vec);
        t1 = hal_get_time();
        times[i] = t1 - t0;
    }
    qsort(times, ITERATIONS, sizeof(uint64_t), cmp_uint64);
    printf("polyvecl_pointwise_acc_montgomery: %ld\n", times[ITERATIONS >> 1]);


}






#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#include "params.h"
#include "poly.h"
#include "hal.h"

#define ITERATIONS 1000

uint64_t t0, t1;
uint64_t times[ITERATIONS];

static int cmp_uint64(const void *a, const void *b){
    return ((*((const uint64_t*)a)) - ((*((const uint64_t*)b))));
}


int main(void){

    int16_t src1[NTRUP_P];
    int8_t src2[NTRUP_P];
    int16_t des[NTRUP_P];

    for(size_t i = 0; i < ITERATIONS; i++){
        t0 = hal_get_time();
        poly_Rq_mul_small(des, src1, src2);
	t1 = hal_get_time();
	times[i] = t1 - t0;
    }
    qsort(times, ITERATIONS, sizeof(uint64_t), cmp_uint64);
    printf("poly_Rq_mul_small: %ld\n", times[ITERATIONS >> 1]);

}



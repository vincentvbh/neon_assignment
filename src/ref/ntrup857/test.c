
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#include "params.h"
#include "poly.h"
#include "hal.h"

#define ITERATIONS 10

static int16_t cmod(int32_t a, int16_t mod){
    int16_t t;
    t = a % mod;
    if(t > (mod >> 1)){
        t -= mod;
    }
    if(t < -(mod >> 1)){
        t += mod;
    }
    return t;
}

static void schoolbook(int16_t des[NTRUP_P], const int16_t src1[NTRUP_P], const int8_t src2[NTRUP_P]){

    int16_t tmp[NTRUP_P * 2];

    for(size_t i = 0; i < NTRUP_P * 2; i++){
        tmp[i] = 0;
    }

    for(size_t i = 0; i < NTRUP_P; i++){
	for(size_t j = 0; j < NTRUP_P; j++){
            tmp[i + j] = cmod((int32_t)src1[i] * src2[j] + tmp[i + j], NTRUP_Q);
	}
    }

    for(size_t i = 2 * NTRUP_P - 2; i >= NTRUP_P; i--){
        tmp[i - NTRUP_P] += tmp[i];
	tmp[i - NTRUP_P + 1] += tmp[i];
    }

    for(size_t i = 0; i < NTRUP_P; i++){
        des[i] = cmod((int32_t)tmp[i], NTRUP_Q);
    }


}



int main(void){

    
    int16_t ref[NTRUP_P];
    int16_t src1[NTRUP_P];
    int8_t  src2[NTRUP_P];
    int16_t des[NTRUP_P];

    for(size_t i = 0; i < ITERATIONS; i++){

        for(size_t j = 0; j < NTRUP_P; j++){
            src1[j] = cmod(rand(), NTRUP_Q);
	    src2[j] = cmod(rand(), 3);
	}

        schoolbook(ref, src1, src2);
        poly_Rq_mul_small(des, src1, src2);

        for(size_t j = 0; j < NTRUP_P; j++){
            assert(ref[j] == des[j]);
	}

    }

    printf("poly_Rq_mul_small finished!\n");

}



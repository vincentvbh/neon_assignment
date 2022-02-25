#ifndef POLY_H
#define POLY_H

#include <stdint.h>

#include "params.h"

typedef struct {
    int32_t coeffs[N];
} poly;

void poly_ntt(poly *a);
void poly_invntt_tomont(poly *a);
void poly_pointwise_montgomery(poly *c, const poly *a, const poly *b);



#endif







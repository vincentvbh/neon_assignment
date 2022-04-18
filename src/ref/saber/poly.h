#ifndef POLY_H
#define POLY_H

#include <stdint.h>

#include "SABER_params.h"

typedef union {
    uint16_t coeffs[SABER_N];
} poly;

void poly_mul(poly *c, const poly *a, const poly *b, const int accumulate);

#endif




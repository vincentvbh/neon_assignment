#ifndef POLY_H
#define POLY_H

#include <stdint.h>

#include "params.h"

typedef struct {
    int32_t coeffs[N];
} poly;

typedef struct {
    poly vec[L];
} polyvecl;

typedef struct {
    poly vec[K];
} polyveck;

void poly_add(poly *c, const poly *a, const poly *b);


void poly_ntt(poly *a);
void poly_invntt_tomont(poly *a);
void poly_pointwise_montgomery(poly *c, const poly *a, const poly *b);
void polyvecl_pointwise_acc_montgomery(poly *w, const polyvecl *u, const polyvecl *v);

#endif








#include "params.h"
#include "poly.h"
#include "ntt.h"
#include "reduce.h"

void poly_ntt(poly *a) {
    ntt(a->coeffs);
}

void poly_invntt_tomont(poly *a) {
    invntt_tomont(a->coeffs);
}


void poly_pointwise_montgomery(poly *c, const poly *a, const poly *b) {
    unsigned int i;
    for (i = 0; i < N; ++i) {
        c->coeffs[i] = montgomery_reduce((int64_t)a->coeffs[i] * b->coeffs[i]);
    }
}





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

void poly_add(poly *c, const poly *a, const poly *b)  {
    unsigned int i;
    for (i = 0; i < N; ++i) {
        c->coeffs[i] = a->coeffs[i] + b->coeffs[i];
    }
}


void polyvecl_pointwise_acc_montgomery(poly *w, const polyvecl *u, const polyvecl *v) {
    unsigned int i;
    poly t;
    poly_pointwise_montgomery(w, &u->vec[0], &v->vec[0]);
    for (i = 1; i < L; ++i) {
        poly_pointwise_montgomery(&t, &u->vec[i], &v->vec[i]);
        poly_add(w, w, &t);
    }
}



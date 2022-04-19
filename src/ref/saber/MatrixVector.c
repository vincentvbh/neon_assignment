
#include <stddef.h>

#include "SABER_params.h"

#include "poly.h"
#include "MatrixVector.h"

void InnerProd(poly *c, const poly b[SABER_L], const poly s[SABER_L]) {
    poly_mul(c, &b[0], &s[0], 0);
    for (size_t i = 1; i < SABER_L; i++) {
        poly_mul(c, &b[i], &s[i], 1);
    }
}

void MatrixVectorMul(poly c[SABER_L], const poly A[SABER_L][SABER_L], const poly s[SABER_L]){
    for (size_t i = 0; i < SABER_L; i++) {
	InnerProd(&c[i], A[i], s);
    }
}

void Enc_MatrixVectorMul_InnerProd(poly bp[SABER_L], poly *c, const poly A[SABER_L][SABER_L], const poly b[SABER_L], const poly s[SABER_L]){
    MatrixVectorMul(bp, (const poly (*)[SABER_L])A, s);
    InnerProd(c, b, s);
}



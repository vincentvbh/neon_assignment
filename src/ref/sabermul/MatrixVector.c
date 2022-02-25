
#include <stddef.h>

#include "SABER_params.h"

#include "poly.h"
#include "MatrixVector.h"

void MatrixVectorMul(poly c[SABER_L], const poly A[SABER_L][SABER_L], const poly s[SABER_L]){
    for (size_t i = 0; i < SABER_L; i++) {
        poly_mul(&c[i], &A[0][i], &s[0], 0);
        for (size_t j = 1; j < SABER_L; j++) {
            poly_mul(&c[i], &A[j][i], &s[j], 1);
        }
    }
}

void InnerProd(poly *c, const poly b[SABER_L], const poly s[SABER_L]) {

    poly_mul(c, &b[0], &s[0], 0);
    for (size_t i = 1; i < SABER_L; i++) {
        poly_mul(c, &b[i], &s[i], 1);
    }
}


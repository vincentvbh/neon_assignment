#ifndef MATRIXVECTOR_H
#define MATRIXVECTOR_H


#include <stdint.h>

#include "SABER_params.h"

#include "poly.h"


void MatrixVectorMul(poly c[SABER_L], const poly A[SABER_L][SABER_L], const poly s[SABER_L]);

void InnerProd(poly *c, const poly b[SABER_L], const poly s[SABER_L]);

void Enc_MatrixVectorMul_InnerProd(poly bp[SABER_L], poly *c, const poly A[SABER_L][SABER_L], const poly b[SABER_L], const poly s[SABER_L]);


#endif

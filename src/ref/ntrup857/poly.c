
#include <stdint.h>

#include "params.h"

#include "poly.h"

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


void poly_Rq_mul_small(int16_t *h, const int16_t *f,const int8_t *g)
{
    int16_t fg[NTRUP_P + NTRUP_P - 1];
    int16_t result;
    int i,j;

    for (i = 0; i < NTRUP_P; i++) {
      result = 0;
      for (j = 0;j <= i;++j) 
          result = cmod(result+f[j]*(int32_t)g[i-j], NTRUP_Q);
      fg[i] = result;
    }
    for (i = NTRUP_P;i < 2 * NTRUP_P - 1;++i) {
      result = 0;
      for (j = i - NTRUP_P + 1; j < NTRUP_P; ++j) 
          result = cmod(result+f[j]*(int32_t)g[i-j], NTRUP_Q);
      fg[i] = result;
    }

    for (i = 2 * NTRUP_P - 2; i >= NTRUP_P; i--) {
      fg[i - NTRUP_P] = cmod(fg[i - NTRUP_P] + fg[i], NTRUP_Q);
      fg[i - NTRUP_P + 1] = cmod(fg[i - NTRUP_P + 1] + fg[i], NTRUP_Q);
    }

    for (i = 0; i < NTRUP_P; ++i) 
        h[i] = fg[i];
}

























#ifndef PARAMS_H
#define PARAMS_H


/* Don't change anything below this line */
#define SABER_L 3
#define SABER_MU 8
#define SABER_ET 4

#define SABER_N 256

#define SABER_EP 10
#define SABER_P (1 << SABER_EP)

#define SABER_EQ 13
#define SABER_Q (1 << SABER_EQ)


#define MODQ(X) ((X) & (SABER_Q - 1))

#endif

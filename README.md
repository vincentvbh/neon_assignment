# neon_assignment

We will focus on implementing the polynomial multiplications and related operations
used in
- Dilithium
- NTRU
- NTRU Prime
- Saber

In particular, we focus on
- `dilithium3`
- `ntruhps2048677`
- `saber`
- `sntrup761/ntrulpr761`

# Polynomial multiplications and related operations
- Dilithium:
    - Stripped from https://github.com/PQClean/PQClean/tree/master/crypto_sign/dilithium3/clean
    - `poly_ntt`
    - `poly_invntt_tomont`
    - `poly_pointwise_montgomery`
    - `polyvecl_pointwise_acc_montgomery`
- NTRU
    - Stripped from https://github.com/jschanck/ntru/tree/master/ref-hps2048677
    - `poly_Rq_mul_small`
- NTRU Prime
- Saber
    - Stripped from https://github.com/PQClean/PQClean/tree/master/crypto_kem/saber/clean
    - `InnerProd`
    - `MatrixVectorMul`

# Raspberry pi 4
- CPU: Cortex-A72
- Architecture: Armv8-A, aarch64
- OS: it is shipped with an OS, but we will use ubuntu

# What you have to do before programming
- Install ubuntu 21.04
- Install gcc 10

# Install ubuntu yourself
- Raspberry pi Imager: https://www.raspberrypi.com/software/
- ubuntu 21.04: https://ubuntu.com/download/raspberry-pi

# Install gcc
```
sudo apt-get install gcc
```
After that, check the version of gcc with
```
gcc --version
```




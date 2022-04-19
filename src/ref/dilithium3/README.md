

# How to compile
```
make
```

# Test for correctness
```
./test
```

## Sample output
```
poly_mul passed!
matrix-to-vector mul passed!
```

# Benchmark
```
./speed
```

## Sample output
```
poly_ntt: 9452
poly_invntt_tomont: 10931
poly_pointwise_montgomery: 1559
polyvecl_pointwise_acc_montgomery: 8631
```

You have to outperform the state of the art.

# State of the art
Paper **Neon NTT: Faster Dilithium, Kyber, and Saber on Cortex-A72 and Apple M1** at
https://tches.iacr.org/index.php/TCHES/article/view/9295.
* `poly_ntt < 2300`
* `poly_invntt_tomont < 2900`
* `poly_pointwise_montgomery < 700`
* `polyvecl_pointwise_acc_montgomery < 1400`










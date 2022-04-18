

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
InnerProd passed!
MatrixVectorMul passed!
```

# Benchmark
```
./speed
```

## Sample output
```
InnerProd (Decrypt): 42427
MatrixVectorMul: 125924
InnerProd (Encrypt) + MatrixVectorMul: 42427 + 125924
```

# State of the art
Paper **Neon NTT: Faster Dilithium, Kyber, and Saber on Cortex-A72 and Apple M1** at
https://tches.iacr.org/index.php/TCHES/article/view/9295.
* `InnerProd (Decrypt) < 16000`
* `MatrixVecotrMul < 36000`
* `InnerProd (Encrypt) + MatrixVectorMul < 9300 + 36000`












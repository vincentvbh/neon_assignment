

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
InnerProd (Encrypt) + MatrixVectorMul passed!
```

# Benchmark
```
./speed
```

## Sample output
```
InnerProd: 42828
MatrixVectorMul: 127860
InnerProd (Enc) + MatrixVectorMul: 168264
```

You have to outperform the state of the art.

# State of the art
Paper **Neon NTT: Faster Dilithium, Kyber, and Saber on Cortex-A72 and Apple M1** at
https://tches.iacr.org/index.php/TCHES/article/view/9295.
* `InnerProd (Decrypt) < 16000`
* `MatrixVecotrMul < 36000`
* `InnerProd (Encrypt) + MatrixVectorMul < 45300`












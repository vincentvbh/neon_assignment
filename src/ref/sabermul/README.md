

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
InnerProd: 42427
MatrixVectorMul: 125924
```

# What you can modify
```
make_opt.mk
poly.h
poly.c
MatrixVectorMul.h
MatrixVectorMul.c
```
If you wish to add your own files for compilation, specify the file names in `make_opt.mk`.

# What you should not modify
```
Makefile
hal-cortexa.c
hal.h
SABER_params.h
speed.c
test.c
```




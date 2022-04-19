
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
poly_Rq_mul_small passed!
```

# Benchmark
```
./speed
```

## Sample output
```
poly_Rq_mul_small: 10687955
```

# What you can modify
```
make_opt.mk
poly.h
poly.c
```
If you wish to add your own files for compilation, specify the file names in `make_opt.mk`.

# What you should not modify
```
Makefile
hal-cortexa.c
hal.h
params.h
speed.c
test.c
```

# Thresholds

You will get 25 points if the following is reached.
TBA

You will get 15 points if the following is reached.
TBA

You will get 5 points if the following is reached.
* `polymul_small < 160000`






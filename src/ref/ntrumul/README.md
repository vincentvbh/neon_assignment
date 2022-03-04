
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
poly_Rq_mul_small: 91562
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

# Criteria

You will get 3 points if all the followings are reached.
* `polymul_small < 48000`

You will get 2 points if all the followings are reached.
* `polymul_small < 62000`

You will get 1 point if all the followings are reached.
* `polymul_small < 78000`







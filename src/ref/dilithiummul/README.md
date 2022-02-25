

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
```

# Benchmark
```
./speed
```

## Sample output
```
poly_ntt: 9462
poly_invntt_tomont: 10950
poly_pointwise_montgomery: 1559
```

# What you can modify
```
make_opt.mk
reduce.h
reduce.c
ntt.h
ntt.c
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
* `poly_ntt < 2800`
* `poly_invntt_tomont < 3200`
* `poly_pointwise_montgomery < TBA`

You will get 2 points if all the followings are reached.
* `poly_ntt < 3500`
* `poly_invntt_tomont < 4000`
* `poly_pointwise_montgomery < TBA`

You will get 1 point if all the followings are reached.
* `poly_ntt < 5000`
* `poly_invntt_tomont < 5500`
* `poly_pointwise_montgomery < TBA`


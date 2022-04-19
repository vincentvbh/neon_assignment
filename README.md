# neon_assignment

We focus on implementing the polynomial multiplications and related operations
used in
- NTRU
- NTRU Prime

In particular, we focus on
- `ntruhps2048677`
- `ntruhps4096821`
- `ntrup761`
- `ntrup857`

# What you should do
- Pick one of `ntruhps2048677`, `ntruhps4096821`, `ntrup761`, and `ntrup857`.
- Optimize the chosen one:
    - You will get 5 points if you reach the first threshold
    - You will get 15 points if you reach the second threshold
    - You will get 25 points if you reach the third threshold

# What you have to do before programming
- Install ubuntu 21.04
- Install gcc 10

# What you have to do every time after booting the Raspberry pi 4
```
cd enable_ccr
make install
```

# Raspberry pi 4
I'll benchmark with the following.
- CPU: Cortex-A72
- Architecture: Armv8.0-A
- OS: ubuntu 21.04

# Install ubuntu yourself
- Raspberry pi Imager: https://www.raspberrypi.com/software/
- ubuntu 21.04: https://ubuntu.com/download/raspberry-pi

# Install gcc
```
sudo apt-get install gcc
```

# Check the architecture of CPU
```
lscpu
```

## Sample output
```
Architecture:                    aarch64
CPU op-mode(s):                  32-bit, 64-bit
Byte Order:                      Little Endian
CPU(s):                          4
On-line CPU(s) list:             0-3
Thread(s) per core:              1
Core(s) per socket:              4
Socket(s):                       1
Vendor ID:                       ARM
Model:                           3
Model name:                      Cortex-A72
Stepping:                        r0p3
CPU max MHz:                     1800.0000
CPU min MHz:                     600.0000
BogoMIPS:                        108.00
Vulnerability Itlb multihit:     Not affected
Vulnerability L1tf:              Not affected
Vulnerability Mds:               Not affected
Vulnerability Meltdown:          Not affected
Vulnerability Spec store bypass: Vulnerable
Vulnerability Spectre v1:        Mitigation; __user pointer sanitization
Vulnerability Spectre v2:        Vulnerable
Vulnerability Srbds:             Not affected
Vulnerability Tsx async abort:   Not affected
Flags:                           fp asimd evtstrm crc32 cpuid

```

# Check the version of ubuntu
```
lsb_release -a
```
## Sample output
```
No LSB modules are available.
Distributor ID:	Ubuntu
Description:	Ubuntu 21.04
Release:	21.04
Codename:	hirsute

```

# Check the verion of gcc
```
gcc --version
```
## Sample output
```
gcc (Ubuntu 10.3.0-1ubuntu1) 10.3.0
Copyright (C) 2020 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```



include make_opt.mk

COMMON_HEADERs = hal.h params.h
COMMON_SOURCEs = hal-cortexa.c

YOUR_HEADERs = $(C_HEADERs) $(ASM_HEADERs)
YOUR_SOURCEs = $(C_SOURCEs) $(ASM_SOURCEs)

HEADERs = $(COMMON_HEADERs) $(YOUR_HEADERs)
SOURCEs = $(COMMON_SOURCEs) $(YOUR_SOURCEs)

all: test speed

test: $(HEADERs) $(SOURCEs) test.c
	$(CC) $(CFLAGS) -o test test.c $(SOURCEs)

speed: $(HEADERs) $(SOURCEs) speed.c
	$(CC) $(CFLAGS) -o speed speed.c $(SOURCEs)


include ../common/make.mk

.PHONY: clean

clean:
	rm -f test
	rm -f speed



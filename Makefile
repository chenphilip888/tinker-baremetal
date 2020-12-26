CROSS_COMPILE = arm-none-eabi-
STARTUP_DEFS=-D__STARTUP_CLEAR_BSS -D__START=main
INCLUDE = -I.
CFLAGS  = -g -march=armv7-a -O1 -Wl,--build-id=none -nostdlib -fno-builtin $(INCLUDE)
LDSCRIPTS=-L. -T gcc.ld -lgcc
LFLAGS= $(LDSCRIPTS)

test: test.img

test.img: test.bin
	mkimage -n rk3288 -T rksd -d $< $@

test.bin: test.elf
	$(CROSS_COMPILE)objcopy -O binary $< $@
	$(CROSS_COMPILE)objdump -S $< > test.list

test.elf: start.S test.c uart.c printf.c pwm.c timer.c clock.c gpio.c i2c.c spi.c gic.c
	$(CROSS_COMPILE)gcc $(CFLAGS) $^ $(LFLAGS) -o $@

.PHONY: burn_sdcard clean test

burn_sdcard: test.bin
	sudo dd if=test.img of=/dev/mmcblk0 seek=64 oflag=sync status=progress

clean:
	rm -f *.img *.bin *.elf *.list

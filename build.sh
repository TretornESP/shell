#!/bin/bash

nasm -f bin boot.asm -o boot.bin
nasm -f elf64 loader.asm -o loader.o

#cc -m64  -ffreestanding -fno-builtin -nostdlib -c main.c
#-Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin
cc -m64 -masm=intel -fno-builtin -c main.c scrn.c
ld  -Ttext 0x100000 -o kernel.elf loader.o main.o scrn.o
objcopy -R .note -R .comment -S -O binary kernel.elf kernel.bin

dd if=/dev/zero of=image.bin bs=512 count=2880
dd if=boot.bin of=image.bin conv=notrunc
dd if=kernel.bin of=image.bin conv=notrunc bs=512 seek=1

rm ./boot.bin ./kernel.bin ./main.o ./loader.o ./kernel.elf

#qemu-system-x86_64 image.bin format=raw

qemu-system-x86_64 -drive file=image.bin,format=raw,index=0,media=disk -m 512

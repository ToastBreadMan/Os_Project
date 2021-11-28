i686-elf-as src/boot/boot.s -o objects/boot.o
i686-elf-gcc -m32 src/kernel/kernel.c -o objects/kernel.bin objects/boot.o -nostdlib -ffreestanding -mno-red-zone -fno-exceptions -nostdlib -T linker.ld
cp objects/kernel.bin iso/boot/kernel.bin
cp grub.cfg iso/boot/grub/grub.cfg
grub-mkrescue -o os.iso iso
qemu-system-x86_64 os.iso

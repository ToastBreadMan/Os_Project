nasm -f elf64 boot.asm -o boot.o
ld -m elf_x86_64 -T linker.ld -o kernel.bin boot.o
qemu-system-x86_64 -hda kernel.bin
rm boot.bin

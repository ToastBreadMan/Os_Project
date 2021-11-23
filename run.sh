nasm -f elf64 boot.asm -o boot.o
gcc -m64 -c kernel.c -o km.o
ld -m elf_x86_64 -T linker.ld -o kernel.bin boot.o km.o
qemu-system-x86_64 -hda kernel.bin


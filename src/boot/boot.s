.set ALIGN,    1 << 0
.set MEMINFO,  1 << 1
#.set VIDINFO,  1 << 2
.set FLAGS,    ALIGN | MEMINFO #| VIDINFO
.set MAGIC,    0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
.long MAGIC
.long FLAGS
.long CHECKSUM
.long 0, 0, 0, 0, 0 # skip flags

.section .text
.global _start

_start:
    .extern kmain
    mov $kernel_stack, %esp
    push %eax
    push %ebx
    call kmain # kernel

_end:
    cli # disable interrupts
    hlt # halt
    jmp _end # infinite loop


.section .bss
.space 2*1024*1024; # reserve some space
kernel_stack:

#include "multiboot.h"
#include "strlen.c"
#include "printf.c"
#include "itoa.c"

extern void kmain(multiboot_info_t * mbd, unsigned int magic) {
	printf("Number of modules provided by GRUB: %d", mbd->mods_count);
}

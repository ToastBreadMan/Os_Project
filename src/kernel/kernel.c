#include "multiboot.h"
#include "len.c"
#include "printf.c"
#include "itoa.c"

extern void kmain(multiboot_info_t * mbd, unsigned int magic) {
	printf("From C!");
}

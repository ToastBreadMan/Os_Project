int kmain () {
	char* vidmem = (char*)0xb8000;
	vidmem[0] = 'H';
	vidmem[1] = 0x04;
}

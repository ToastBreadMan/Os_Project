bits 16
global start
extern kmain	
section .text
start:
	cli
	call kmain
	hlt

times 510 - ($ - $$) db 0
dw 0xAA55

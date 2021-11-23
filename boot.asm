bits 16
global start	
section .text
start:
	mov ah, 0eh
	mov al, 'A'
	int 0x10
	
	jmp $

times 510 - ($ - $$) db 0
dw 0xAA55

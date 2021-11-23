OUTPUT_FORMAT(binary)
ENTRY(start)
SECTIONS

{

. = 2M;

.text : { *(.text) }

.data : { *(.data) }

.bss : { *(.bss) }

}

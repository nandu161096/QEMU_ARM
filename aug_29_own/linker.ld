ENTRY(Reset_handler)

MEMORY
{
    FLASH (rx): ORIGIN = 0x00000000, LENGTH = 128K
    SRAM  (rwx): ORIGIN = 0x20000000, LENGTH = 8K
}

_estack = ORIGIN(SRAM) + LENGTH(SRAM);

SECTIONS
{
    .isr_vector :
    {
        . = ALIGN(4);
	KEEP(*(.isr_vector))
	. = ALIGN(4);
    } > FLASH

    .text :
    {
	. = ALIGN(4);
	*(.text*)
	*(.rodata*)
        . = ALIGN(4);
	_etext = .;
    } > FLASH

    .data :
    {
       . = ALIGN(4);
       _sdata = .;
       *(.data*);
       . = ALIGN(4);
       _edata = .;
    } > SRAM AT > FLASH

    .bss :
    {
       . = ALIGN(4);
       _sbss = .;
       *(.bss*)
       . = ALIGN(4);
       _ebss = .;	
    } > SRAM

}

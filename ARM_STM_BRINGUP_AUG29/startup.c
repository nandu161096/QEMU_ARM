#include <stdint.h>

extern int main(void);

extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;

extern uint32_t _sbss;
extern uint32_t _ebss;

extern uint32_t _estack;

void Reset_Handler(void);
void Default_Handler(void);

void NMI_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));

__attribute__((section(".isr_vector")))
const uint32_t vector_table[] =
{
    (uint32_t)&_estack,
    (uint32_t)Reset_Handler,

    (uint32_t)NMI_Handler,
    (uint32_t)HardFault_Handler,
    (uint32_t)MemManage_Handler,
    (uint32_t)BusFault_Handler,
    (uint32_t)UsageFault_Handler,

    0,
    0,
    0,
    0,

    (uint32_t)Default_Handler,
    (uint32_t)Default_Handler,
    (uint32_t)Default_Handler,
    (uint32_t)Default_Handler,
    (uint32_t)Default_Handler,
};

void Reset_Handler(void)
{
    uint32_t *src;
    uint32_t *dst;

    /* Copy .data from FLASH to SRAM */
    src = &_sidata;
    dst = &_sdata;

    while (dst < &_edata)
    {
        *dst++ = *src++;
    }

    /* Clear .bss */
    dst = &_sbss;

    while (dst < &_ebss)
    {
        *dst++ = 0;
    }

    /* Jump to C main() */
    main();

    /* main should never return */
    while (1)
    {
        __asm volatile ("nop");
    }
}

void Default_Handler(void)
{
    while (1)
    {
        __asm volatile ("nop");
    }
}

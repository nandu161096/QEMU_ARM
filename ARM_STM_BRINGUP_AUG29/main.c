#include <stdint.h>

volatile uint32_t initialized_value = 0x12345678;
volatile uint32_t uninitialized_value;

volatile uint32_t main_entered = 0;

int main(void)
{
    main_entered = 1;

    while (1)
    {
        __asm volatile ("nop");
    }

    return 0;
}

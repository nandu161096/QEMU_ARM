
#include <stdio.h>
#include <stdint.h>

extern int main();
extern uint32_t _estack;
void Reset_handler(void);

__attribute__((section(".isr_vector")))
const uint32_t vector_table[] = 
{
     (uint32_t)&_estack,
     (uint32_t)Reset_handler,
     0,
     0,
};

void Reset_handler(void) {
     main();
}

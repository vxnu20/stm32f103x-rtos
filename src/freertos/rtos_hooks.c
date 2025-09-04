#include "rtos_init.h"

void vApplicationStackOverflowHook(TaskHandle_t t, char *name) 
{
    (void)t; (void)name;
    for(;;);  // set a breakpoint here
}
#include "rtos_init.h"
#include "mcu_init.h"

int main()
{
    mcu_peripherals_init();
    create_tasks();
    vTaskStartScheduler();

    while(1)
    {
    }
    return 0;
}
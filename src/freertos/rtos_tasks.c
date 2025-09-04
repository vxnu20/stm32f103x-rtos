#include "mcu_init.h"
#include "rtos_init.h"

void vTask1_Handler(void* paramaters)
{
    for(;;)
    {    
        gpio_pin_toggle(GPIO_PORTC,13);
        vTaskDelay(1000);
    }
}

void vTask2_Handler(void* paramaters)
{
    for(;;)
    {
        gpio_pin_toggle(GPIO_PORTC,13);
        vTaskDelay(100);
    }
    
}
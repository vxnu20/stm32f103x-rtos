#include "mcu_init.h"
#include "rtos_init.h"
#include "mpu6050.h"


float temp_value = 0;

void vTask_ReadSensors(void* paramaters)
{
    for(;;)
    {   temp_value = mpu6050_get_temperature_celsius();
        gpio_pin_toggle(GPIO_PORTC,13);
        vTaskDelay(100);
    }
}

void vTask_PublishData(void* paramaters)
{
    for(;;)
    {
        //char buffer[40];
        // sprintf(buffer, "temp in C -> %d\n",(uint8_t)temp_value);
        // usart_write_string(USART1,buffer);
        vTaskDelay(500);
    }
    
}
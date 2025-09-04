#include "rtos_init.h"

extern void vTask1_Handler(void *pvParameters);
extern void vTask2_Handler(void *pvParameters);

void create_tasks(void)
{
    TaskHandle_t Task1_Handle = NULL;
    TaskHandle_t Task2_Handle = NULL;
    BaseType_t status;

    status = xTaskCreate(vTask1_Handler, "Task-1", 256, NULL, 3, &Task1_Handle);
    if (status != pdPASS) {
        for (;;); // Failed to create Task 1
    }

    status = xTaskCreate(vTask2_Handler, "Task-2", 256, NULL, 2, &Task2_Handle);
    if (status != pdPASS) {
        for (;;); // Failed to create Task 2
    }
}
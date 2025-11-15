#include "rtos_init.h"

extern void vTask_ReadSensors(void *pvParameters);
extern void vTask_PublishData(void *pvParameters);

void create_tasks(void)
{
    TaskHandle_t Task1_Handle = NULL;
    TaskHandle_t Task2_Handle = NULL;
    BaseType_t status;

    status = xTaskCreate(vTask_ReadSensors, "Task-1", 256, NULL, 3, &Task1_Handle);
    if (status != pdPASS) {
        for (;;); // Failed to create Task 1
    }

    status = xTaskCreate(vTask_PublishData, "Task-2", 256, NULL, 2, &Task2_Handle);
    if (status != pdPASS) {
        for (;;); // Failed to create Task 2
    }
}
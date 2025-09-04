#include <stdint.h>

/* External references */
extern int main(void);

/* FreeRTOS port handlers (implemented in the port) */
extern void SVC_Handler(void);
extern void PendSV_Handler(void);
extern void SysTick_Handler(void);

/* Default handlers (weak) */
void Default_Handler(void);
void NMI_Handler(void)        __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler(void)  __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler(void)   __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler(void)   __attribute__ ((weak, alias("Default_Handler")));

/* Forward declaration of the stack top from the linker script */
extern unsigned long _estack;

/* Reset handler */
__attribute__((noreturn, naked)) void _reset_handler(void)
{
    /* copy .data, zero .bss. Minimal implementation assuming linker sets symbols. */
    extern unsigned long _sdata, _edata, _sidata, _sbss, _ebss;
    unsigned long *src, *dst;

    /* Copy initialized data from flash to SRAM */
    src = &_sidata;
    dst = &_sdata;
    while (dst < &_edata) *dst++ = *src++;

    /* Zero BSS */
    dst = &_sbss;
    while (dst < &_ebss) *dst++ = 0;

    /* Call main (you should initialize clocks before vTaskStartScheduler if needed) */
    main();

    for (;;);
}

/* HardFault handler loop */
void HardFault_Handler(void)
{
    for (;;) { }
}

/* Default handler loop */
void Default_Handler(void)
{
    for (;;) { }
}

/* Vector table placed in .isr_vector (kept by linker script) */
__attribute__ ((section(".isr_vector")))
void (* const g_pfnVectors[])(void) =
{
    (void (*)(void)) &_estack, /* Initial Stack Pointer */
    _reset_handler,            /* Reset Handler */
    NMI_Handler,               /* NMI Handler */
    HardFault_Handler,         /* Hard Fault Handler */
    MemManage_Handler,         /* MPU Fault Handler */
    BusFault_Handler,          /* Bus Fault Handler */
    UsageFault_Handler,        /* Usage Fault Handler */
    0, 0, 0, 0,                /* Reserved */
    SVC_Handler,               /* SVCall Handler */
    DebugMon_Handler,          /* Debug Monitor */
    0,                         /* Reserved */
    PendSV_Handler,            /* PendSV Handler */
    SysTick_Handler,           /* SysTick Handler */

    /* External IRQs (STM32F1 has up to ~60 IRQs) */
    0, /* WWDG */
    0, /* PVD */
    0, /* TAMPER */
    0, /* RTC */
    0, /* FLASH */
    0, /* RCC */
    0, /* EXTI0 */
    0, /* EXTI1 */
    0, /* EXTI2 */
    0, /* EXTI3 */
    0, /* EXTI4 */
    /* ... continue placeholders for all IRQs your device expects ... */
};
#include "mcu_init.h"

void mcu_peripherals_init(void)
{
    /* onboard user led */
    rcc_enable_gpio_clock(GPIO_PORTC);
    gpio_set_mode(GPIO_PORTC, 13, GPIO_MODE_OUT2MHZ, GN_PUSH_PULL);
    
}
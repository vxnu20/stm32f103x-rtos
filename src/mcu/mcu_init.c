#include "mcu_init.h"

void mcu_peripherals_init(void)
{
    /* peripheral clock init */
    rcc_enable_gpio_clock(GPIO_PORTA);
    rcc_enable_gpio_clock(GPIO_PORTB);
    rcc_enable_gpio_clock(GPIO_PORTC);
    rcc_enable_i2c_clock(I2C1);
    rcc_enable_usart_clock(USART1);

    /* usart for logging */
    gpio_set_mode(GPIO_PORTA, 9, GPIO_MODE_OUT2MHZ, ALT_PUSH_PULL);
    gpio_set_mode(GPIO_PORTA, 10, GPIO_MODE_IN, FLOATING_INPUT);
    usart_init(USART1, USART_DEFAULT_BAUD);

    /* onboard user led */
    gpio_set_mode(GPIO_PORTC, 13, GPIO_MODE_OUT2MHZ, GN_PUSH_PULL);

    /* for i2c peripherals */
    gpio_set_mode(GPIO_PORTB, 6, GPIO_MODE_OUT10MHZ, ALT_OPEN_DRAIN);
    gpio_set_mode(GPIO_PORTB, 7, GPIO_MODE_OUT10MHZ, ALT_OPEN_DRAIN);

    /* i2c init */
    i2c_config i2c_cfg = {
        .i2c = I2C1,
        .pfrequency = 8,        // 8MHz APB1 clock
        .ccr_value = 40,        // CCR value for 100kHz
        .rise_time = 9          // TRISE value for 100kHz
    };
    i2c_init(i2c_cfg);
    
}
/*
 * Copyright 2017 Google, Inc
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include "registers.h"
#include "timer.h"
#include "uart.h"
#include "pwm.h"
#include "clock.h"
#include "i2c.h"
#include "gpio.h"
#include "spi.h"
#include "gic.h"

void led_blink( int delay )
{
    // LED on
    *GPIO1_SWPORTA_DR = 0x01000000;
    udelay( delay );

    // LED off
    *GPIO1_SWPORTA_DR = 0;
    udelay( delay );
}

char test_menu( void )
{
    char ch;

    uart_clear();
    printf( "--- select a test ---\r\n" );
    printf( "1. uart test\r\n2. led test\r\n3. button test\r\n4. pwm led test\r\n5. i2c lcd test\r\n6. tongsong\r\n7. servo\r\n8. spi oled test\r\nq. quit\r\n");
    ch = uart_getc();
    if ( ch == 'q' )
        printf( "Goodbye !\r\n" );
    return ch;
}

int main() {
    char ch;
    char test_item;

    uart_init();
    config_GIC( 90, 1 );         // UART3_ISR, CPU0
    timer_init();
    rkclk_init();
    udelay( 50000 );
    // Use rkpwm by default
    *GRF_SOC_CON2 = 0x10001;

    test_item = '\0';
    while( test_item != 'q' ) {
        test_item = test_menu();
        if ( test_item == '1' ) {
            uart_test();
        } else if ( test_item == '2' ) {
            led_test();
        } else if ( test_item == '3' ) {
            button_test();
        } else if ( test_item == '4' ) {
            pwm_led_test();
        } else if ( test_item == '5' ) {
            i2c_lcd_test();
            printf( "press x to exit i2c lcd test\r\n" );
            ch = uart_getc();
        } else if ( test_item == '6' ) {
            tongsong();
        } else if ( test_item == '7' ) {
            servo();
        } else if ( test_item == '8' ) {
            ssd1306_test();
        }
    }

    *GPIO1_SWPORTA_DDR = 0x01000000;

    while (1) {
        led_blink( 1000000 );
    }
    return 0;
}

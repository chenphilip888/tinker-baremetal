/*
 * Copyright 2017 Google, Inc
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include "i2c.h"
#include "timer.h"
/*
 * SCL Divisor = 8 * (CLKDIVL+1 + CLKDIVH+1)
 * SCL = PCLK / SCLK Divisor
 * i2c_rate = PCLK
 */

void rk_i2c_set_clk( int scl_rate )
{
	//int i2c_rate;
	int div, divl, divh;

	//i2c_rate = 74250000; //clk_get_rate(&i2c->clk);

	div = 91; //DIV_ROUND_UP(i2c_rate, scl_rate * 8) - 2;
        divl = div >> 1;
        if ( div & 0x1 ) {
            divh = ( div + 0x1 ) >> 1;
        } else {
            divh = div >> 1;
        }

        *I2C1_CLKDIV = I2C_CLKDIV_VAL(divl, divh);
}

int rk_i2c_send_start_bit( void )
{
        int TimeOut = I2C_TIMEOUT_US;

        *I2C1_IPD = I2C_IPD_ALL_CLEAN;
        *I2C1_CON = I2C_CON_EN | I2C_CON_START;
        *I2C1_IEN = I2C_STARTIEN;

        while (TimeOut--) {
    	    if (*I2C1_IPD & I2C_STARTIPD) {
                *I2C1_IPD = I2C_STARTIPD;
		break;
	    }
	    udelay( 1 );
	}
	if (TimeOut <= 0) {
	    return I2C_ERROR_TIMEOUT;
	}

	return I2C_OK;
}

int rk_i2c_send_stop_bit( void )
{
	int TimeOut = I2C_TIMEOUT_US;

        *I2C1_IPD = I2C_IPD_ALL_CLEAN;
        *I2C1_CON = I2C_CON_EN | I2C_CON_STOP;
        *I2C1_IEN = I2C_CON_STOP;

        while (TimeOut--) {
            if (*I2C1_IPD & I2C_STOPIPD) {
                *I2C1_IPD = I2C_STOPIPD;
	        break;
	    }
	    udelay( 1 );
	}
	if (TimeOut <= 0) {
	    return I2C_ERROR_TIMEOUT;
	}

	return I2C_OK;
}

void rk_i2c_disable( void )
{
        *I2C1_CON = 0x0;
}

int rk_i2c_write( char chip, int reg, int r_len, char *buf, int b_len )
{
	int err = I2C_OK;
	int TimeOut = I2C_TIMEOUT_US;
	char *pbuf = buf;
	int bytes_remain_len = b_len + r_len + 1;
	int bytes_tranfered_len = 0;
	int words_tranfered_len = 0;
	int txdata;
	int i, j;

	err = rk_i2c_send_start_bit();
	if (err != I2C_OK) {
	    return err;
	}

	while (bytes_remain_len) {
	    if (bytes_remain_len > RK_I2C_FIFO_SIZE) {
	        bytes_tranfered_len = 32;
	    } else {
	        bytes_tranfered_len = bytes_remain_len;
	    }
            words_tranfered_len = (bytes_tranfered_len + 3) / 4;

	    for (i = 0; i < words_tranfered_len; i++) {
	        txdata = 0;
	        for (j = 0; j < 4; j++) {
	            if ((i * 4 + j) == bytes_tranfered_len) {
		        break;
		    }

		    if (i == 0 && j == 0) {
		        txdata |= (chip << 1);
		    } else if (i == 0 && j <= r_len) {
		        txdata |= (reg & (0xff << ((j - 1) * 8))) << 8;
		    } else {
		        txdata |= (*pbuf++)<<(j * 8);
		    }
                    *(volatile unsigned int *)(I2C1_TXDATA_BASE + i) = txdata;
		}
	    }

            *I2C1_CON = I2C_CON_EN | I2C_CON_MOD(I2C_MODE_TX);
            *I2C1_MTXCNT = bytes_tranfered_len;
            *I2C1_IEN = I2C_MBTFIEN | I2C_NAKRCVIEN;

	    TimeOut = I2C_TIMEOUT_US;
	    while (TimeOut--) {
	        if (*I2C1_IPD & I2C_NAKRCVIPD) {
                    *I2C1_IPD = I2C_NAKRCVIPD;
	            err = I2C_ERROR_NOACK;
	        }
	        if (*I2C1_IPD & I2C_MBTFIPD) {
                    *I2C1_IPD = I2C_MBTFIPD;
	            break;
		}
		udelay( 1 );
	    }

	    if (TimeOut <= 0) {
	        err =  I2C_ERROR_TIMEOUT;
	        goto i2c_exit;
	    }

	    bytes_remain_len -= bytes_tranfered_len;
        }

i2c_exit:
	rk_i2c_send_stop_bit();
	rk_i2c_disable();

	return err;
}

void rk_i2c_init( int speed )
{
    *GPIO8A = (0x0f00 << 16) | 0x500;
    rk_i2c_set_clk( speed );
}

void wiringPiI2CWriteReg8( char chip, int reg, int bufi )
{
    char buf[1] = {bufi};

    rk_i2c_write( chip, reg, 1, buf, 1 );  
}

void set_backlight( int r, int g, int b )
{
    wiringPiI2CWriteReg8( 0x62, 0, 0 );
    wiringPiI2CWriteReg8( 0x62, 1, 0 );
    wiringPiI2CWriteReg8( 0x62, 8, 0xaa );
    wiringPiI2CWriteReg8( 0x62, 4, r );
    wiringPiI2CWriteReg8( 0x62, 3, g );
    wiringPiI2CWriteReg8( 0x62, 2, b );
}

void textCommand( int cmd )
{
    wiringPiI2CWriteReg8( 0x3e, 0x80, cmd);
}

void setText( char * text )
{
    int i;
    textCommand( 0x01 );        // clear display
    udelay( 50000 );
    textCommand( 0x08 | 0x04 ); // display on, no cursor
    textCommand( 0x28 );        // 2 lines
    udelay( 50000 );
    for (i=0; text[i] != '\0'; i++) {
        if (text[i] == '\n') {
            textCommand( 0xc0 );
        } else {
            wiringPiI2CWriteReg8( 0x3e, 0x40, text[i]);
        }
    }
}

void i2c_lcd_test( void )
{
    int j;

    rk_i2c_init( 100000 );
    textCommand( 0x01 );        // clear display
    udelay( 50000 );
    textCommand( 0x08 | 0x04 ); // display on, no cursor
    textCommand( 0x28 );        // 2 lines
    udelay( 50000 );

    set_backlight( 255, 0, 0 );
    for (j=0; j< 5; j++)
    {
      set_backlight( 255, 0, 0 );
      udelay ( 1000000 );
      set_backlight( 255, 255, 0 );
      udelay ( 1000000 );
      set_backlight( 0, 255, 0 );
      udelay ( 1000000 );
      set_backlight( 0, 255, 255 );
      udelay ( 1000000 );
      set_backlight( 0, 0, 255 );
      udelay ( 1000000 );
      set_backlight( 255, 0, 255 );
      udelay ( 1000000 );
    }
    set_backlight( 128, 255, 0 );
    setText( "Hello world !\nIt works !\n" );
}

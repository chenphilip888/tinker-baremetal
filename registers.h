/*
 * Copyright 2017 Google, Inc
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef __REGISTERS_H__
#define __REGISTERS_H__

#define BUTTON  160
#define LED     161
#define I2C1    252
#define I2C4    233
#define PWM2    238
#define PWM3    239
#define SPI0    166
#define SPI2    257
#define LOW     0
#define HIGH    1
#define INPUT   0
#define OUTPUT  1
#define UART_LSR_THRE   0x20          /* Xmit holding register empty */
#define UART_LSR_DRY    0x1           /* data ready */

#define BOOTROM_BASE            0xffff0000
#define SRAM_BASE               0xff700000

#define irqflagrx               (volatile unsigned int *)0xff703fe0
#define irqdatarx               (volatile unsigned int *)0xff703fe4
/* Distributor Registers */
#define GICD_CTLR               (volatile unsigned int *)0xffc01000
#define GICD_TYPER              (volatile unsigned int *)0xffc01004
#define GICD_IIDR               (volatile unsigned int *)0xffc01008
#define GICD_IGROUPRn           (volatile unsigned int *)0xffc01080
#define GICD_IGROUPRnx                                   0xffc01080
#define GICD_ISENABLERn         (volatile unsigned int *)0xffc01100
#define GICD_ISENABLERnx                                 0xffc01100
#define GICD_ICENABLERn         (volatile unsigned int *)0xffc01180
#define GICD_ISPENDRn           (volatile unsigned int *)0xffc01200
#define GICD_ICPENDRn           (volatile unsigned int *)0xffc01280
#define GICD_ICACTIVERn         (volatile unsigned int *)0xffc01380
#define GICD_IPRIORITYRn        (volatile unsigned int *)0xffc01400
#define GICD_ITARGETSRn         (volatile unsigned int *)0xffc01800
#define GICD_ITARGETSRnx                                 0xffc01800
#define GICD_ICFGR              (volatile unsigned int *)0xffc01c00
#define GICD_SGIR               (volatile unsigned int *)0xffc01f00

/* Cpu Interface Memory Mapped Registers */
#define GICC_CTLR               (volatile unsigned int *)0xffc02000
#define GICC_PMR                (volatile unsigned int *)0xffc02004
#define GICC_BPR                (volatile unsigned int *)0xffc02008
#define GICC_IAR                (volatile unsigned int *)0xffc0200C
#define GICC_EOIR               (volatile unsigned int *)0xffc02010
#define GICC_RPR                (volatile unsigned int *)0xffc02014
#define GICC_HPPIR              (volatile unsigned int *)0xffc02018
#define GICC_ABPR               (volatile unsigned int *)0xffc0201c
#define GICC_IIDR               (volatile unsigned int *)0xffc020fc

#define SPI0_CTRLR0    (volatile unsigned int *)0xff110000
#define SPI0_CTRLR1    (volatile unsigned int *)0xff110004
#define SPI0_ENR       (volatile unsigned int *)0xff110008
#define SPI0_SER       (volatile unsigned int *)0xff11000c
#define SPI0_BAUDR     (volatile unsigned int *)0xff110010
#define SPI0_TXFTLR    (volatile unsigned int *)0xff110014
#define SPI0_RXFTLR    (volatile unsigned int *)0xff110018
#define SPI0_TXFLR     (volatile unsigned int *)0xff11001c
#define SPI0_RXFLR     (volatile unsigned int *)0xff110020
#define SPI0_SR        (volatile unsigned int *)0xff110024
#define SPI0_IPR       (volatile unsigned int *)0xff110028
#define SPI0_IMR       (volatile unsigned int *)0xff11002c
#define SPI0_ISR       (volatile unsigned int *)0xff110030
#define SPI0_RISR      (volatile unsigned int *)0xff110034
#define SPI0_ICR       (volatile unsigned int *)0xff110038
#define SPI0_DMACR     (volatile unsigned int *)0xff11003c
#define SPI0_DMATDLR   (volatile unsigned int *)0xff110040
#define SPI0_DMARDLR   (volatile unsigned int *)0xff110044
#define SPI0_TXDR_BASE (volatile unsigned int *)0xff110400
#define SPI0_RXDR_BASE (volatile unsigned int *)0xff110800
#define SPI2_CTRLR0    (volatile unsigned int *)0xff130000
#define SPI2_CTRLR1    (volatile unsigned int *)0xff130004
#define SPI2_ENR       (volatile unsigned int *)0xff130008
#define SPI2_SER       (volatile unsigned int *)0xff13000c
#define SPI2_BAUDR     (volatile unsigned int *)0xff130010
#define SPI2_TXFTLR    (volatile unsigned int *)0xff130014
#define SPI2_RXFTLR    (volatile unsigned int *)0xff130018
#define SPI2_TXFLR     (volatile unsigned int *)0xff13001c
#define SPI2_RXFLR     (volatile unsigned int *)0xff130020
#define SPI2_SR        (volatile unsigned int *)0xff130024
#define SPI2_IPR       (volatile unsigned int *)0xff130028
#define SPI2_IMR       (volatile unsigned int *)0xff13002c
#define SPI2_ISR       (volatile unsigned int *)0xff130030
#define SPI2_RISR      (volatile unsigned int *)0xff130034
#define SPI2_ICR       (volatile unsigned int *)0xff130038
#define SPI2_DMACR     (volatile unsigned int *)0xff13003c
#define SPI2_DMATDLR   (volatile unsigned int *)0xff130040
#define SPI2_DMARDLR   (volatile unsigned int *)0xff130044
#define SPI2_TXDR_BASE (volatile unsigned int *)0xff130400
#define SPI2_RXDR_BASE (volatile unsigned int *)0xff130800

#define I2C1_CON       (volatile unsigned int *)0xff140000
#define I2C1_CLKDIV    (volatile unsigned int *)0xff140004
#define I2C1_MRXADDR   (volatile unsigned int *)0xff140008
#define I2C1_MRXRADDR  (volatile unsigned int *)0xff14000c
#define I2C1_MTXCNT    (volatile unsigned int *)0xff140010
#define I2C1_MRXCNT    (volatile unsigned int *)0xff140014
#define I2C1_IEN       (volatile unsigned int *)0xff140018
#define I2C1_IPD       (volatile unsigned int *)0xff14001c
#define I2C1_FCNT      (volatile unsigned int *)0xff140020
#define I2C1_TXDATA    (volatile unsigned int *)0xff140100
#define I2C1_RXDATA    (volatile unsigned int *)0xff140200
#define I2C1_TXDATA_BASE (volatile unsigned int *)0xff140100
#define I2C1_RXDATA_BASE (volatile unsigned int *)0xff140200
#define I2C4_CON       (volatile unsigned int *)0xff160000
#define I2C4_CLKDIV    (volatile unsigned int *)0xff160004
#define I2C4_MRXADDR   (volatile unsigned int *)0xff160008
#define I2C4_MRXRADDR  (volatile unsigned int *)0xff16000c
#define I2C4_MTXCNT    (volatile unsigned int *)0xff160010
#define I2C4_MRXCNT    (volatile unsigned int *)0xff160014
#define I2C4_IEN       (volatile unsigned int *)0xff160018
#define I2C4_IPD       (volatile unsigned int *)0xff16001c
#define I2C4_FCNT      (volatile unsigned int *)0xff160020
#define I2C4_TXDATA    (volatile unsigned int *)0xff160100
#define I2C4_RXDATA    (volatile unsigned int *)0xff160200
#define I2C4_TXDATA_BASE (volatile unsigned int *)0xff160100
#define I2C4_RXDATA_BASE (volatile unsigned int *)0xff160200

#define UART1_THR (volatile unsigned int *)0xff190000
#define UART1_DR  (volatile unsigned int *)0xff190000
#define UART1_DLL (volatile unsigned int *)0xff190000
#define UART1_DLM (volatile unsigned int *)0xff190004
#define UART1_IER (volatile unsigned int *)0xff190004
#define UART1_FCR (volatile unsigned int *)0xff190008
#define UART1_IIR (volatile unsigned int *)0xff190008
#define UART1_LCR (volatile unsigned int *)0xff19000c
#define UART1_MCR (volatile unsigned int *)0xff190010
#define UART1_LSR (volatile unsigned int *)0xff190014
#define UART1_MSR (volatile unsigned int *)0xff190018
#define UART3_THR (volatile unsigned int *)0xff1b0000
#define UART3_DR  (volatile unsigned int *)0xff1b0000
#define UART3_DLL (volatile unsigned int *)0xff1b0000
#define UART3_DLM (volatile unsigned int *)0xff1b0004
#define UART3_IER (volatile unsigned int *)0xff1b0004
#define UART3_FCR (volatile unsigned int *)0xff1b0008
#define UART3_IIR (volatile unsigned int *)0xff1b0008
#define UART3_LCR (volatile unsigned int *)0xff1b000c
#define UART3_MCR (volatile unsigned int *)0xff1b0010
#define UART3_LSR (volatile unsigned int *)0xff1b0014
#define UART3_MSR (volatile unsigned int *)0xff1b0018
#define UART4_THR (volatile unsigned int *)0xff1c0000
#define UART4_DR  (volatile unsigned int *)0xff1c0000
#define UART4_DLL (volatile unsigned int *)0xff1c0000
#define UART4_DLM (volatile unsigned int *)0xff1c0004
#define UART4_IER (volatile unsigned int *)0xff1c0004
#define UART4_FCR (volatile unsigned int *)0xff1c0008
#define UART4_IIR (volatile unsigned int *)0xff1c0008
#define UART4_LCR (volatile unsigned int *)0xff1c000c
#define UART4_MCR (volatile unsigned int *)0xff1c0010
#define UART4_LSR (volatile unsigned int *)0xff1c0014
#define UART4_MSR (volatile unsigned int *)0xff1c0018

#define TIMER_LOAD_COUNT0 (volatile unsigned int *)0xff810020
#define TIMER_LOAD_COUNT1 (volatile unsigned int *)0xff810024
#define TIMER_CURR_VALUE0 (volatile unsigned int *)0xff810028
#define TIMER_CURR_VALUE1 (volatile unsigned int *)0xff81002c
#define TIMER_CTRL_REG    (volatile unsigned int *)0xff810030
#define TIMER_INT_STATUS  (volatile unsigned int *)0xff810034

#define PLL0_CON0         (volatile unsigned int *)0xff760000
#define PLL0_CON1         (volatile unsigned int *)0xff760004
#define PLL0_CON2         (volatile unsigned int *)0xff760008
#define PLL0_CON3         (volatile unsigned int *)0xff76000c
#define PLL1_CON0         (volatile unsigned int *)0xff760010
#define PLL1_CON1         (volatile unsigned int *)0xff760014
#define PLL1_CON2         (volatile unsigned int *)0xff760018
#define PLL1_CON3         (volatile unsigned int *)0xff76001c
#define PLL2_CON0         (volatile unsigned int *)0xff760020
#define PLL2_CON1         (volatile unsigned int *)0xff760024
#define PLL2_CON2         (volatile unsigned int *)0xff760028
#define PLL2_CON3         (volatile unsigned int *)0xff76002c
#define PLL3_CON0         (volatile unsigned int *)0xff760030
#define PLL3_CON1         (volatile unsigned int *)0xff760034
#define PLL3_CON2         (volatile unsigned int *)0xff760038
#define PLL3_CON3         (volatile unsigned int *)0xff76003c
#define PLL4_CON0         (volatile unsigned int *)0xff760040
#define PLL4_CON1         (volatile unsigned int *)0xff760044
#define PLL4_CON2         (volatile unsigned int *)0xff760048
#define PLL4_CON3         (volatile unsigned int *)0xff76004c

#define CRU_MODE_CON      (volatile unsigned int *)0xff760050
#define CRU_CLKSEL_CON0   (volatile unsigned int *)0xff760060
#define CRU_CLKSEL_CON1   (volatile unsigned int *)0xff760064
#define CRU_CLKSEL_CON10  (volatile unsigned int *)0xff760088
#define CRU_CLKSEL_CON11  (volatile unsigned int *)0xff76008c
#define CRU_CLKSEL_CON25  (volatile unsigned int *)0xff7600c4
#define CRU_CLKSEL_CON26  (volatile unsigned int *)0xff7600c8
#define CRU_CLKSEL_CON37  (volatile unsigned int *)0xff7600f4
#define CRU_CLKSEL_CON39  (volatile unsigned int *)0xff7600fc
#define CRU_CLKGATE14_CON (volatile unsigned int *)0xff760198
#define CRU_CLKGATE17_CON (volatile unsigned int *)0xff7601a4
#define CRU_SOFTRST_CON10 (volatile unsigned int *)0xff7601e0
#define GRF_SOC_CON0      (volatile unsigned int *)0xff770244
#define GRF_SOC_CON2      (volatile unsigned int *)0xff77024c
#define GRF_SOC_STATUS1   (volatile unsigned int *)0xff770284
#define SGRF_SOC_CON2     (volatile unsigned int *)0xff740008
#define PMU_SYS_REG2      (volatile unsigned int *)0xFF73009c
#define GPIO1_SWPORTA_DR       (volatile unsigned int *)0xff780000
#define GPIO1_SWPORTA_DDR      (volatile unsigned int *)0xff780004
#define GPIO5_SWPORTA_DR       (volatile unsigned int *)0xff7c0000
#define GPIO5_SWPORTA_DDR      (volatile unsigned int *)0xff7c0004
#define GPIO5_EXT_PORTA_OFFSET (volatile unsigned int *)0xff7c0050
#define GPIO5B                 (volatile unsigned int *)0xFF770050
#define GPIO5C                 (volatile unsigned int *)0xFF770054
#define GPIO6A                 (volatile unsigned int *)0xFF77005C
#define GPIO7A                 (volatile unsigned int *)0xFF77006C
#define GPIO7B                 (volatile unsigned int *)0xFF770070
#define GPIO7CL                (volatile unsigned int *)0xFF770074
#define GPIO7CH                (volatile unsigned int *)0xFF770078
#define GPIO8A                 (volatile unsigned int *)0xFF770080
#define GPIO8B                 (volatile unsigned int *)0xFF770084

#define PWM2_CTRL              (volatile unsigned int *)0xFF68002c
#define PWM2_DUTY              (volatile unsigned int *)0xFF680028
#define PWM2_PERIOD            (volatile unsigned int *)0xFF680024
#define PWM3_CTRL              (volatile unsigned int *)0xFF68003c
#define PWM3_DUTY              (volatile unsigned int *)0xFF680038
#define PWM3_PERIOD            (volatile unsigned int *)0xFF680034

#define GPIO7C7_SHIFT            12
#define GPIO7C6_SHIFT            8
#define GPIO7C7_MASK             7
#define GPIO7C7_PWM_3            3

void printf(const char *fmt, ...);

#endif

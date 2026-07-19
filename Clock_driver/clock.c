#include <stdint.h>
#include "clock.h"

// Register Address Definitions

// RCC Base Address
#define RCC_BASE      0x40021000UL

// RCC Registers
#define RCC_IOPENR    (*(volatile uint32_t *)(RCC_BASE + 0x34))
#define RCC_APBENR2   (*(volatile uint32_t *)(RCC_BASE + 0x40))

// Clock Driver
/*
 * clock_init()
 * Target Pins:
 * PA9 - USART1_TX
 * PA10 - USART1_RX
 * GPIOA is connected to the I/O bus.
 * USART1 is connected to the APB2 bus.
 *
 * This function enables the clocks required before
 * configuring GPIOA and USART1.
 */

void clock_init(void)
{
    // Enable clock for GPIOA so its registers can be configured
    RCC_IOPENR |= (1UL << 0);

    // Enable clock for USART1 so its registers can be configured
    RCC_APBENR2 |= (1UL << 14);
}
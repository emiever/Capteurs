/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <stdlib.h>
#include <stdio.h>

// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

// Initialise the digital pin LED1 as an output
#ifdef LED1
    DigitalOut led(LED1);
#else
    bool led;
#endif

InterruptIn bp(BUTTON1);

void allumee()
{
    led = 1;
}

void eteinte()
{
    led = 0;
}

int main()
{
bp.rise(&allumee);
bp.fall(&eteinte);
}

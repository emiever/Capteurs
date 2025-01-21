/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <stdlib.h>
#include <stdio.h>

// Blinking rate in milliseconds
#define BLINKING_RATE     500ms


int main()
{
    // Initialise the digital pin LED1 as an output
#ifdef LED1
    DigitalOut led(LED1);
#else
    bool led;
#endif


DigitalIn bp(BUTTON1);



    while (true) {
        
        printf("valeur de bp1 :%d\n", bp.read());
        if(bp.read() == 1){
            led = 1;
        }
        else{
            led = 0;
        }
        ThisThread::sleep_for(BLINKING_RATE);
    }
}

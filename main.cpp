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

using namespace std::chrono;

Timer timer;
DigitalIn bp(BUTTON1);



int main()
{
    while(1){
        if(bp.read()==1){
            timer.start();
            while(bp.read()==1){}
            timer.stop();
            printf("The time elapsed during button pressed was %llu milliseconds\n", duration_cast<milliseconds>(timer.elapsed_time()).count());
            timer.reset();
        }
       
    }
}


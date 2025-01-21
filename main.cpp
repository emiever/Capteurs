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
InterruptIn bp(BUTTON1);
long long unsigned int val_timer = 0;

void start(){
    timer.start();
}

void stop(){
    timer.stop();
    val_timer = duration_cast<milliseconds>(timer.elapsed_time()).count();
    timer.reset();
}


int main()
{
    bp.rise(&start);
    bp.fall(&stop);
    while(1){
    printf("The time elapsed during button pressed was %llu milliseconds\n", val_timer);
    ThisThread::sleep_for(BLINKING_RATE);
    }
}



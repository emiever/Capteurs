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
microseconds freq = 100ms;
Ticker flipper;

void button(){
    freq = freq + 50ms;
}

void notled(){
    led = !led;
}

int main()
{
    bp.rise(&button);
    //led = 1;
    while(1){
        flipper.attach(&notled, freq);
        ThisThread::sleep_for(BLINKING_RATE);
    }
}


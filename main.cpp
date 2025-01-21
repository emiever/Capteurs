/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <stdlib.h>
#include <stdio.h>
#include "mbed_sensirion-scd4x/scd4x/scd4x.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     500ms




sixtron::SCD4X sensor(P1_I2C_SDA, P1_I2C_SCL);
sixtron::SCD4X::ErrorType err;

//const int SCD4X_ADDR = 0x62 << 1; // 8bit I2C address

static void display_value_result(sixtron::SCD4X::ErrorType err, uint16_t co2, double t, double rh)
{
    if (err != sixtron::SCD4X::ErrorType::Ok) {
        printf("Error reading data: %d\n", err);
    } else {
        printf("CO2: %dppm, Temp: %f°C, RH: %f%%\n", co2, t, rh);
    }
}

int main()
{
    /* Force periodic measurement stop first and wait for its completion (500ms) */
    sensor.start_periodic_measurement();
    while(1){
        sixtron::scd4x_measurement_t res;
        sensor.read_measurement(&res);
        display_value_result(err, res.co2, res.temperature, res.rh);

        ThisThread::sleep_for(BLINKING_RATE);
    }
    sensor.stop_periodic_measurement();
}


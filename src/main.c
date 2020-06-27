/*
 * Copyright (c) 2020 Abhijit Bose <https://boseji.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>

void main(void)
{
    struct device *gpioe;

    /* Get instance of GPIOE */
    gpioe = device_get_binding("GPIOE");
    if (gpioe == NULL) {
        return;
    }

    /* Enabled Pins for Output */
    if (gpio_pin_configure(gpioe, 9, GPIO_OUTPUT_ACTIVE) < 0) {
        return;
    }

    /* Start the Infinite Loop */
    while(1) {
        gpio_pin_toggle(gpioe, 9);
        /* Wait for 1 Second = 1000mS */
        k_msleep(1000);
    }
}

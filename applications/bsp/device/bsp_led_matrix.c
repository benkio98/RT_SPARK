/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2026-03-27     laixiaobin   the first version
 */

/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-5-10      ShiHao       first version
 */

#define LOG_TAG "bsp_led_matrix"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

#include "bsp_led_matrix.h"
#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include <libraries/Board_Drivers/led_matrix/drv_matrix_led.h>

rt_thread_t led_matrix_thread;

static void led_matrix_example_entry()
{
    int count = 0;
    while (1)
    {
        for (int i = EXTERN_LED_0; i <= EXTERN_LED_18; i++)
        {
            switch (count)
            {
            case 0:
                led_matrix_set_color(i, RED);
                break;
            case 1:
                led_matrix_set_color(i, GREEN);
                break;
            case 2:
                led_matrix_set_color(i, BLUE);
                break;
            default:
                return;
                break;
            }
            led_matrix_reflash();
            rt_thread_delay(20);
        }
        count = (count + 1) % 3;
    }
}

int led_matrix_test(void)
{
    led_matrix_thread = rt_thread_create("led matrix demo", led_matrix_example_entry, RT_NULL, 1024, 20, 20);
    if (led_matrix_thread == RT_NULL)
    {
        rt_kprintf("led matrix demo thread creat failed!\n");
        return 0;
    }
    rt_thread_mdelay(200); // avoid multi-thread on LED matrix transmit.
    rt_thread_startup(led_matrix_thread);

    return 0;
}
MSH_CMD_EXPORT(led_matrix_test, led matrix demo);


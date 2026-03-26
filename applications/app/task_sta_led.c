/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2026-03-26     Admin       the first version
 */

#define DBG_TAG "task_sta_led"
#define DBG_LVL         DBG_LOG
#include <rtdbg.h>

#include "task_sta_led.h"
#include <rtdevice.h>
#include <applications/bsp/device/bsp_led.h>

static rt_thread_t led_sta_thread = RT_NULL; // 状态 LED 线程


/* 状态 LED 闪烁任务线程 */
static void led_sta_thread_entry(void *p)
{
    led_init(); // 初始化 LED
    while(1)
    {
        led_toggle();
        rt_thread_mdelay(1000);
    }
}

int led_sta_thread_init(void)
{
    led_sta_thread = rt_thread_create("led_sta", led_sta_thread_entry, RT_NULL, 512, 21, 5);
    if (led_sta_thread != RT_NULL) // 启动线程
    {
        rt_thread_startup(led_sta_thread);
        return RT_EOK;
    }
    else
    {
        LOG_E("led_sta_thread failed\n");
        return -RT_ERROR;
    }
}

INIT_DEVICE_EXPORT(led_sta_thread_init); // 使用自动初始化

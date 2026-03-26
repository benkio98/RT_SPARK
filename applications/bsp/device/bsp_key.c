/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2026-03-26     Admin       the first version
 */

#define DBG_TAG "bsp_key"
#define DBG_LVL         DBG_LOG
#include <rtdbg.h>

#include "bsp_key.h"
#include <rtdevice.h>
#include <applications/bsp/device/bsp_led.h>

static rt_thread_t key_thread = RT_NULL; // key 线程


int key_init(void)
{
    ///\ 设置 KEY0, KEY1, KEY2, WK_UP 引脚的模式为输入上拉模式
    rt_pin_mode(PIN_KEY0, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(PIN_KEY1, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(PIN_KEY2, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(PIN_WK_UP, PIN_MODE_INPUT_PULLUP);
    // LOG_D("key init");
    return 0;
}
INIT_DEVICE_EXPORT(key_init); ///< 使用自动初始化

/* 按键输入任务线程 */
static void key_thread_entry(void *p)
{
    unsigned int count = 1;
    while (count > 0)
    {
        /* 读取按键 KEY0 的引脚状态 */
        if (rt_pin_read(PIN_KEY0) == PIN_LOW)
        {
            rt_thread_mdelay(50);
            if (rt_pin_read(PIN_KEY0) == PIN_LOW)
            {
                /* 按键已被按下，输出 log，点亮 LED 灯 */
                LOG_D("KEY0 pressed!");
                rt_pin_write(PIN_LED_R, PIN_LOW);
            }
        }
        else
        {
            /* 按键没被按下，熄灭 LED 灯 */
            rt_pin_write(PIN_LED_R, PIN_HIGH);
        }
        rt_thread_mdelay(10);
        count++;
    }
}

int key_thread_init(void)
{
    key_thread = rt_thread_create("key", key_thread_entry, RT_NULL, 512, 21, 5);
    if (key_thread != RT_NULL) // 启动线程
    {
        rt_thread_startup(key_thread);
        return RT_EOK;
    }
    else
    {
        LOG_E("key_thread failed\n");
        return -RT_ERROR;
    }
}
// INIT_APP_EXPORT(key_thread_init); // 使用自动初始化
 
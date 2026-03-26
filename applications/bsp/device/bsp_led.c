/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2026-03-26     laixiaobin   the first version
 */

#define DBG_TAG "bsp_led"
#define DBG_LVL         DBG_LOG
#include <rtdbg.h>

#include "bsp_led.h"
#include <rtdevice.h>


int led_init(void)
{
    ///\ 设定 LED 引脚为推挽输出模式
    rt_pin_mode(PIN_LED_R, PIN_MODE_OUTPUT);
    // rt_pin_mode(PIN_LED_B, PIN_MODE_OUTPUT);
    // LOG_D("led init");
    return 0;
}
INIT_DEVICE_EXPORT(led_init); // 使用自动初始化

int led_on(void)
{
    ///\ LED 灯亮
    rt_pin_write(PIN_LED_R, PIN_LOW);
    // LOG_D("led on");
    return 0;
}

int led_off(void)
{
    ///\ LED 灯灭
    rt_pin_write(PIN_LED_R, PIN_HIGH);
    // LOG_D("led off");
    return 0;
}

int led_toggle(void)
{
    ///\ LED 灯状态取反
    rt_pin_write(PIN_LED_R, !rt_pin_read(PIN_LED_R));
    // LOG_D("led toggle");
    return 0;
}


/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2026-03-26     laixiaobin   the first version
 */
#ifndef __BSP_LED_H__
#define __BSP_LED_H__

#include <rtthread.h>
#include <board.h>

/* 配置 LED 灯引脚 */
#define PIN_LED_B              GET_PIN(F, 11)      // PF11 :  LED_B        --> LED
#define PIN_LED_R              GET_PIN(F, 12)      // PF12 :  LED_R        --> LED


int led_init(void);
int led_on(void);
int led_off(void);
int led_toggle(void);


#endif /* __BSP_LED_H__ */

/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-5-10      ShiHao       first version
 */

#include <rtthread.h>
#include <rtdevice.h>

#define DBG_TAG "main"
#define DBG_LVL         DBG_LOG
#include <rtdbg.h>


int main(void)
{
    led_matrix_clear(); ///< 清除LED灯光显示 [bug] 开机 Led1 亮绿灯
    while(1)
    {
        rt_thread_mdelay(1000);
    }

    return 0;
}





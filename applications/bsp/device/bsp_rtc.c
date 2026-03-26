/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2026-03-26     laixiaobin   the first version
 */

#define DBG_TAG "bsp_rtc"
#define DBG_LVL         DBG_LOG
#include <rtdbg.h>

#include "bsp_rtc.h"
#include <rtthread.h>
#include <rtdevice.h>
#include <stdlib.h>

#define RTC_NAME       "rtc"


void user_alarm_callback(rt_alarm_t alarm, time_t timestamp)
{
    rt_kprintf("user alarm callback function.\n");
}

void alarm_sample(void)
{  
    struct rt_alarm_setup setup;
    struct rt_alarm * alarm = RT_NULL;
    static time_t now;
    struct tm p_tm;

    if (alarm != RT_NULL)
        return;

    /* 获取当前时间戳，并把下5秒时间设置为闹钟时间 */
    now = time(NULL) + 5;
    gmtime_r(&now,&p_tm);

    setup.flag = RT_ALARM_ONESHOT;            
    setup.wktime.tm_year = p_tm.tm_year;
    setup.wktime.tm_mon = p_tm.tm_mon;
    setup.wktime.tm_mday = p_tm.tm_mday;
    setup.wktime.tm_wday = p_tm.tm_wday;
    setup.wktime.tm_hour = p_tm.tm_hour;
    setup.wktime.tm_min = p_tm.tm_min;
    setup.wktime.tm_sec = p_tm.tm_sec;   

    alarm = rt_alarm_create(user_alarm_callback, &setup);    
    if(RT_NULL != alarm)
    {
        rt_alarm_start(alarm);
    }
}
/* export msh cmd */
MSH_CMD_EXPORT(alarm_sample,alarm sample);

///\ cmd: set_datetime 2026 3 26 16 21 50
void set_datetime(int argc, char **argv)
{
    if (argc == 7)
    {
        int year   = atoi(argv[1]);
        int month  = atoi(argv[2]);
        int day    = atoi(argv[3]);
        int hour   = atoi(argv[4]);
        int minute = atoi(argv[5]);
        int second = atoi(argv[6]);

        if (set_date(year, month, day) == RT_EOK && set_time(hour, minute, second) == RT_EOK)
        {
            rt_kprintf("Set RTC datetime to %d-%02d-%02d %02d:%02d:%02d success.\n", year, month, day, hour, minute, second);
        }
        else
        {
            rt_kprintf("Set RTC datetime failed!\n");
        }
    }
    else
    {
        rt_kprintf("Usage: set_datetime <year> <month> <day> <hour> <minute> <second>\n");
        rt_kprintf("Example: set_datetime 2026 3 26 16 21 50\n");
    }
}
MSH_CMD_EXPORT(set_datetime, set rtc date and time);

int rtc_init(void)
{
    rt_err_t ret = RT_EOK;
    time_t now;
    rt_device_t device = RT_NULL;

    /* 寻找设备 */
    device = rt_device_find(RTC_NAME);
    if (!device)
    {
        rt_kprintf("find %s failed!", RTC_NAME);
        return RT_ERROR;
    }

    /* 初始化RTC设备 */
    if(rt_device_open(device, 0) != RT_EOK)
    {
        rt_kprintf("open %s failed!", RTC_NAME);
        return RT_ERROR;
    }

    /* 设置日期 */
    ret = set_date(2026, 3, 26);
    if (ret != RT_EOK)
    {
        rt_kprintf("set RTC date failed\n");
        return ret;
    }

    /* 设置时间 */
    ret = set_time(16, 21, 50);
    if (ret != RT_EOK)
    {
        rt_kprintf("set RTC time failed\n");
        return ret;
    }

    /* 获取时间 */
    now = time(RT_NULL);
    rt_kprintf("%s\n", ctime(&now));

    /* 延时1秒 */
    rt_thread_mdelay(1000);

    /* 获取时间 */
    now = time(RT_NULL);
    rt_kprintf("%s\n", ctime(&now));

    return ret;
}
INIT_DEVICE_EXPORT(rtc_init); // 使用自动初始化



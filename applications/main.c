/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-5-10      ShiHao       first version
 */
#if 0
#include <rtthread.h>
#include <rtdevice.h>

#define DBG_TAG "main"
#define DBG_LVL         DBG_LOG
#include <rtdbg.h>


int main(void)
{
    while(1)
    {
        rt_thread_mdelay(1000);
    }

    return 0;
}
#endif

#include <rtthread.h>
#include <fal.h>
#include <dfs_fs.h>
#include <rtdevice.h>

#define LOG_TAG "main"
#define LOG_LVL         LOG_LVL_DBG
#include <ulog.h>

#define FS_PARTITION_NAME "filesystem"

#define APP_VERSION "1.0.0"

/* 重写系统复位函数：拦截重启指令，先硬复位 WIFI 芯片释放 SPI 总线 */
void rt_hw_cpu_reset(void)
{
    LOG_I("Resetting RW007 to release SPI bus before system restart...");
    
    /* 将 Wlan 的 CS (Pin 90) 拉高取消选中，RST (Pin 111) 拉低进行硬复位 */
    rt_pin_mode(RW007_CS_PIN, PIN_MODE_OUTPUT);
    rt_pin_write(RW007_CS_PIN, PIN_HIGH);
    rt_pin_mode(RW007_RST_PIN, PIN_MODE_OUTPUT);
    rt_pin_write(RW007_RST_PIN, PIN_LOW);
    
    rt_thread_mdelay(100);
    
    /* 触发 Cortex-M 内核软复位 (相当于执行 NVIC_SystemReset) */
    *((volatile uint32_t *)0xE000ED0C) = (0x5FA << 16) | (1 << 2);
    while(1);
}

/**
 * Function    ota_app_vtor_reconfig
 * Description Set Vector Table base location to the start addr of app(RT_APP_PART_ADDR).
*/
static int ota_app_vtor_reconfig(void)
{
    #define NVIC_VTOR_MASK 0x3FFFFF80
    #define RT_APP_PART_ADDR 0x08020000
    /* 根据应用设置向量表 */
    SCB->VTOR = RT_APP_PART_ADDR & NVIC_VTOR_MASK;

    return 0;
}
INIT_BOARD_EXPORT(ota_app_vtor_reconfig);


int main(void)
{
    LOG_D("The current version of APP firmware is %s", APP_VERSION);
	
    /* 初始化 fal 功能 */
    fal_init();

    /* 在 spi flash 中名为 "filesystem" 的分区上创建一个块设备 */
    struct rt_device *flash_dev = fal_blk_device_create(FS_PARTITION_NAME);
    if (flash_dev == NULL)
    {
        LOG_E("Can't create a block device on '%s' partition.", FS_PARTITION_NAME);
    }
    else
    {
        LOG_D("Create a block device on the %s partition of flash successful.", FS_PARTITION_NAME);
    }

    /* 挂载 spi flash 中名为 "filesystem" 的分区上的文件系统 */
    if (dfs_mount(flash_dev->parent.name, "/fal", "elm", 0, 0) == 0)
    {
        LOG_I("Filesystem initialized!");
    }
    else
    {
        LOG_E("Failed to initialize filesystem!");
        LOG_D("You should create a filesystem on the block device first!");
    }

    return 0;
}



**Reference_link**

- Spark-1 星火 1 号开发板
https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/hw-board/spark-1/spark-1
- RT-Thread Spark 星火1号开发板 STM32F407嵌入式入门学习开发板
https://item.taobao.com/item.htm?id=726084912488
- [野火®]STM32库开发实战指南——基于野火霸天虎开发板
https://doc.embedfire.com/mcu/stm32/f407batianhu/std/zh/latest/book/USART.html
- 百度网盘：https://pan.baidu.com/s/10Toony2CCGN82_hoX5y5PA?pwd=xh1h 提取码：xh1h
- SDK github：https://github.com/RT-Thread-Studio/sdk-bsp-stm32f407-spark
- SDK gitee：https://gitee.com/RT-Thread-Studio-Mirror/sdk-bsp-stm32f407-spark
- 广成 CAN 总线分析仪资料 https://www.gcan.com.cn/3d05/222b/0cb5/e1f0


## 烧录 boot 和 app1 后按下重启键
[SFUD]Warning: Read SFDP parameter header information failed. The spi is not support JEDEC SFDP.
[SFUD]Warning: This flash device is not found or not support.
[SFUD]Error: spi flash device is initialize fail.

 __  ___     __   __   __  ___ 
|__)  |  __ |__) /  \ /  \  |  
|  \  |     |__) \__/ \__/  |  
2006 - 2019 Copyright by rt-thread team
                0.9.2 build Mar 27 2024
[D/FAL] (fal_flash_init:63) Flash device |    onchip_flash_16k_part | addr: 0x08000000 | len: 0x00020000 | blk_size: 0x00004000 |initialized finish.
[D/FAL] (fal_flash_init:63) Flash device |             onchip_flash | addr: 0x08020000 | len: 0x000e0000 | blk_size: 0x00020000 |initialized finish.
[D/FAL] (fal_flash_init:63) Flash device |                nor_flash | addr: 0x00000000 | len: 0x00000000 | blk_size: 0x00000000 |initialized finish.
[E/FAL] Initialize failed! Partition(download) offset address(524288) out of flash bound(<0).
[I/FAL] ==================== FAL partition table ====================
[I/FAL] | name | flash_dev |   offset   |    length  |
[I/FAL] -------------------------------------------------------------
[I/FAL] =============================================================
[E/FAL] RT-Thread Flash Abstraction Layer (V0.4.0) initialize failed.
[I/FAL] System initialization successful.
[E/FAL] Initialize failed! Partition(download) offset address(524288) out of flash bound(<0).
[I/FAL] ==================== FAL partition table ====================
[I/FAL] | name | flash_dev |   offset   |    length  |
[I/FAL] -------------------------------------------------------------
[I/FAL] =============================================================
[E/FAL] RT-Thread Flash Abstraction Layer (V0.4.0) initialize failed.
[E]Initialize failed! Don't found the partition table.
[E]RT-Thread OTA package(V0.2.1) initialize failed(-1).

[SFUD]Find a Winbond flash chip. Size is 8388608 bytes.
[SFUD]spi flash device is initialize success.

 __  ___     __   __   __  ___ 
|__)  |  __ |__) /  \ /  \  |  
|  \  |     |__) \__/ \__/  |  
2006 - 2019 Copyright by rt-thread team
                0.9.2 build Mar 27 2024
[D/FAL] (fal_flash_init:63) Flash device |    onchip_flash_16k_part | addr: 0x08000000 | len: 0x00020000 | blk_size: 0x00004000 |initialized finish.
[D/FAL] (fal_flash_init:63) Flash device |             onchip_flash | addr: 0x08020000 | len: 0x000e0000 | blk_size: 0x00020000 |initialized finish.
[D/FAL] (fal_flash_init:63) Flash device |                nor_flash | addr: 0x00000000 | len: 0x00800000 | blk_size: 0x00001000 |initialized finish.
[I/FAL] ==================== FAL partition table ====================
[I/FAL] | name     | flash_dev    |   offset   |    length  |
[I/FAL] -------------------------------------------------------------
[I/FAL] | app      | onchip_flash | 0x00000000 | 0x00080000 |
[I/FAL] | download | nor_flash    | 0x00080000 | 0x00080000 |
[I/FAL] =============================================================
[I/FAL] RT-Thread Flash Abstraction Layer (V0.4.0) initialize success.
[I/FAL] System initialization successful.
[I]RT-Thread OTA package(V0.2.1) initialize success.
[E]Get firmware header occur CRC32(calc.crc: 7b93c5c8 != hdr.info_crc32: ffffffff) error on 'download' partition!
[E]Get OTA download partition firmware header failed!
[E]Get firmware header occur CRC32(calc.crc: 7b93c5c8 != hdr.info_crc32: ffffffff) error on 'app' partition!
[I]Begin to execute the program on app partition.
[I/FAL] Find user firmware at app partition 0x08020000 successfully.
[I/FAL] Bootloader jumps to user firmware now.
Cannot find a RTC device!
01-01 08:00:00 I/I2C: I2C bus [i2c2] registered
Cannot find a RTC device!
01-01 08:00:00 I/I2C: I2C bus [i2c3] registered

 \ | /
- RT -     Thread Operating System
 / | \     4.1.1 build Apr  3 2026 17:47:25
 2006 - 2022 Copyright by RT-Thread team
lwIP-2.0.3 initialized!
04-03 19:26:36 I/SFUD: Find a Winbond flash chip. Size is 8388608 bytes.
04-03 19:26:36 I/SFUD: W25Q64 flash device is initialize success.
04-03 19:26:36 I/SFUD: Probe SPI flash W25Q64 by SPI device spi20 success.
Fri Apr  3 19:26:36 2026

Fri Apr  3 19:26:37 2026

04-03 19:26:40 I/sal.skt: Socket Abstraction Layer initialize success.
04-03 19:26:41 I/drv.lcd:  LCD ID:81b3
04-03 19:26:41 D/drv.lcd: backlight 80 percent
[D/FAL] (fal_flash_init:49) Flash device |        onchip_flash_128k | addr: 0x08000000 | len: 0x00100000 | blk_size: 0x00020000 |initialized finish.
[D/FAL] (fal_flash_init:49) Flash device |                   W25Q64 | addr: 0x00000000 | len: 0x00800000 | blk_size: 0x00001000 |initialized finish.
[I/FAL] ==================== FAL partition table ====================
[I/FAL] | name       | flash_dev         |   offset   |    length  |
[I/FAL] -------------------------------------------------------------
[I/FAL] | bootloader | onchip_flash_128k | 0x00000000 | 0x00020000 |
[I/FAL] | app        | onchip_flash_128k | 0x00020000 | 0x00060000 |
[I/FAL] | easyflash  | W25Q64            | 0x00000000 | 0x00080000 |
[I/FAL] | download   | W25Q64            | 0x00080000 | 0x00100000 |
[I/FAL] | wifi_image | W25Q64            | 0x00180000 | 0x00080000 |
[I/FAL] | font       | W25Q64            | 0x00200000 | 0x00300000 |
[I/FAL] | filesystem | W25Q64            | 0x00500000 | 0x00300000 |
[I/FAL] =============================================================
[I/FAL] RT-Thread Flash Abstraction Layer initialize success.
[Flash] (../packages/EasyFlash-v4.1.0/src/ef_env.c:1818) ENV start address is 0x00000000, size is 8192 bytes.
[Flash] EasyFlash V4.1.0 is initialize success.
[Flash] You can get the latest version on https://github.com/armink/EasyFlash .
04-03 19:26:41 D/cmp_fal: ===============================================
04-03 19:26:41 D/cmp_fal: The system now boot 7 times
04-03 19:26:41 D/cmp_fal: ===============================================
msh />04-03 19:26:42 E/[RW007]: The wifi Stage 1 status 0 0 0 1
04-03 19:26:42 I/WLAN.dev: wlan init success
04-03 19:26:42 I/WLAN.lwip: eth device init ok name:w0
04-03 19:26:42 I/WLAN.dev: wlan init success
04-03 19:26:42 I/WLAN.lwip: eth device init ok name:w1

rw007  sn: [rw007a8a355defc584afa9b81]
rw007 ver: [RW007_2.1.0-c7747420-52]

04-03 19:26:42 D/iot_ota_ymodem: The current version of APP firmware is 1.0.0
[I/FAL] The FAL block device (filesystem) created successfully
04-03 19:26:42 D/cmp_fal: Create a block device on the filesystem partition of flash successful.
04-03 19:26:42 I/cmp_fal: Filesystem initialized!


## 升级完代码
msh />ymodem_ota
Save firmware on "download" partition with device "uart1".
Warning: Ymodem has started! This operator will not recovery.
Please select the ota firmware file and use Ymodem to send.
CCCCCCDownload firmware to flash success.
System now will restart...
[SFUD]Warning: Read SFDP parameter header information failed. The spi is not support JEDEC SFDP.
[SFUD]Warning: This flash device is not found or not support.
[SFUD]Error: spi flash device is initialize fail.

 __  ___     __   __   __  ___ 
|__)  |  __ |__) /  \ /  \  |  
|  \  |     |__) \__/ \__/  |  
2006 - 2019 Copyright by rt-thread team
                0.9.2 build Mar 27 2024
[D/FAL] (fal_flash_init:63) Flash device |    onchip_flash_16k_part | addr: 0x08000000 | len: 0x00020000 | blk_size: 0x00004000 |initialized finish.
[D/FAL] (fal_flash_init:63) Flash device |             onchip_flash | addr: 0x08020000 | len: 0x000e0000 | blk_size: 0x00020000 |initialized finish.
[D/FAL] (fal_flash_init:63) Flash device |                nor_flash | addr: 0x00000000 | len: 0x00000000 | blk_size: 0x00000000 |initialized finish.
[E/FAL] Initialize failed! Partition(download) offset address(524288) out of flash bound(<0).
[I/FAL] ==================== FAL partition table ====================
[I/FAL] | name | flash_dev |   offset   |    length  |
[I/FAL] -------------------------------------------------------------
[I/FAL] =============================================================
[E/FAL] RT-Thread Flash Abstraction Layer (V0.4.0) initialize failed.
[I/FAL] System initialization successful.
[E/FAL] Initialize failed! Partition(download) offset address(524288) out of flash bound(<0).
[I/FAL] ==================== FAL partition table ====================
[I/FAL] | name | flash_dev |   offset   |    length  |
[I/FAL] -------------------------------------------------------------
[I/FAL] =============================================================
[E/FAL] RT-Thread Flash Abstraction Layer (V0.4.0) initialize failed.
[E]Initialize failed! Don't found the partition table.
[E]RT-Thread TA package(V0.2.1) initialize
 failed(-1).




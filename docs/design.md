**applications**
├── applications        # 应用程序目录
|   |—— app             # 顶层应用目录（如 task_led, task_beep ）
|   ├── cmd             # 命令行工具/调试命令注册（如 cmd_led, cmd_beep ）
|   |—— lib             # 通用库函数与组件 (如 pid, unpacker, crc16)
|   |—— bsp             # 板级支持包
|   |   |—— chip        # 外部芯片驱动（如 aht20, w25q64 ）
|   |   └── device      # 板载设备驱动（如 led, beep, key ）
|   |—— drivers         # MCU 内部外设驱动（如 uart, spi, i2c, can ）
│   └── main.c          # 应用程序入口
├── docs                # 项目文档存放目录（如 *.md, *.pdf ）

## 自动初始化机制

| 初始化顺序 | 宏接口 | 描述 |
| --- | --- | --- |
| 1 | INIT_BOARD_EXPORT(fn)     | 非常早期的初始化，此时调度器还未启动 |
| 2 | INIT_PREV_EXPORT(fn)      | 主要是用于纯软件的初始化、没有太多依赖的函数 |
| 3 | INIT_DEVICE_EXPORT(fn)    | 外设驱动初始化相关，比如网卡设备 |
| 4 | INIT_COMPONENT_EXPORT(fn) | 组件初始化，比如文件系统或者 LWIP |
| 5 | INIT_ENV_EXPORT(fn)       | 系统环境初始化，比如挂载文件系统 |
| 6 | INIT_APP_EXPORT(fn)       | 应用初始化，比如 GUI 应用 |

``` c
///\ RT-Thread 使用 MSH_CMD_EXPORT() 将命令导出到 msh 命令列表中
MSH_CMD_EXPORT(name, desc);


```

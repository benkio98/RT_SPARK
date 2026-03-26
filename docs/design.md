**applications**
├── applications        # 应用程序目录
|   |—— app             # 顶层应用目录（如 task_led, task_beep ）
|   ├── cmd             # 命令行工具/调试命令注册（如 cmd_led, cmd_beep ）
|   |—— lib             # 通用库函数与组件 (如 pid, unpacker, crc16)
|   |—— bsp             # 板级支持包
|   |   |—— chip        # 外部芯片驱动（如 aht20, w25q64 ）
|   |   └── device      # 板载设备驱动（如 led, beep, key ）
│   └── main.c          # 应用程序入口
├── docs                # 项目文档存放目录（如 *.md, *.pdf ）


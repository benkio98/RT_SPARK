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
https://blog.csdn.net/emqx_broker/article/details/104210524


## 使用 MQTTX 测试 MQTT 客户端
要使用 MQTTX 软件测试你的 RT-Thread MQTT 代码，你需要保持 Broker 等信息与代码一致，并相互订阅和发布。具体操作步骤如下：

### 1. 配置 MQTTX 连接
打开 MQTTX 软件，点击左侧的 `+` 或 `New Connection`（新建连接），填写以下信息以匹配你的代码配置：
*   **Name (名称)**：任意填写，例如 `RT-Thread Test`
*   **Client ID (客户端ID)**：任意填写（只要不和开发板生成的随机 ID 冲突即可）
*   **Host (主机地址)**：`broker.emqx.io` （无需带 `tcp://` 前缀）
*   **Port (端口)**：`1883`
*   Username 和 Password 留空。
*   点击右上角的 **Connect (连接)**。

### 2. 获取开发板的 Topic (主题)
因为你在代码中使用随机生成的客户端 ID 后缀来构建主题：
```c
rt_snprintf(cid, sizeof(cid), "rtthread%d", rt_tick_get());
rt_snprintf(sup_pub_topic, sizeof(sup_pub_topic), "%s%s", MQTT_PUBTOPIC, cid);
```
格式将会是：`/mqtt/test/rtthread[数字]`。
**你需要先查看开发板终端打印的日志内容**，找到类似这样的日志：
> `Start mqtt client and subscribe topic:/mqtt/test/rtthread12345`

记下这个完整的 Topic 字符串（例如 `/mqtt/test/rtthread12345`）。

### 3. 测试接收（开发板 -> MQTTX）
你的代码在成功连接上线后，会自动发布一条 `"Hello,RT-Thread!"` 消息到该 Topic。或者你也可以在开发板终端使用自定义命令发布消息：`msh_mq_publish hello world!`。

为了在 MQTTX 中接收这些消息：
1.  在 MQTTX 连接成功后的界面，点击下方 **New Subscription (添加订阅)**。
2.  在 **Topic** 栏填入你在步骤 2 中获取的开发板 Topic，比如：`/mqtt/test/rtthread12345`。
3.  点击 **Confirm (确认)**。
4.  此时如果在开发板串口终端敲下命令：`msh_mq_publish hello world from RT-Thread`
5.  在 MQTTX 的消息对话框中，你应该就能看到收到这条消息了。

### 4. 测试发送（MQTTX -> 开发板）
你的代码在启动时将 `sup_pub_topic` 既设为了自己发布的 Topic，也同时设为了自己订阅的 Topic (`client.messageHandlers[0].topicFilter = sup_pub_topic;`)。

为了从 MQTTX 发送消息给开发板：
1.  在 MQTTX 界面的右下角，找到发送消息区域。
2.  在消息输入框上方的 **Topic** 栏填写那个同样的 Topic：`/mqtt/test/rtthread12345`。
3.  在格式下拉框选择 `Plaintext` (文本)。
4.  在输入框输入你想发送的消息，比如：`Hello from MQTTX!`。
5.  点击 **发送图标**。
6.  在你的开发板串口终端，应该会打印出如下日志：
    > `Topic: /mqtt/test/rtthread12345 receive a message: Hello from MQTTX!`



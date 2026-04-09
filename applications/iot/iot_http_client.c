/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2026-04-02     laixiaobin   the first version
 */

#include <rtthread.h>
#include <wlan_mgnt.h>
#include <webclient.h>
#include <string.h>

#define LOG_TAG "iot_http_client"
#define LOG_LVL         LOG_LVL_DBG
#include <ulog.h>

#define HTTP_GET_URL  "http://www.rt-thread.com/service/rt-thread.txt"
#define HTTP_POST_URL "http://www.rt-thread.com/service/echo"

static struct rt_semaphore net_ready;
const char *post_data = "RT-Thread is an open source IoT operating system from China!";

// extern void wlan_ready_handler(int event, struct rt_wlan_buff *buff, void *parameter);
// extern void wlan_station_disconnect_handler(int event, struct rt_wlan_buff *buff, void *parameter);
int webclient_get_smpl(const char *uri);
int webclient_post_smpl(const char *uri, const char *post_data, size_t data_len);


static void http_client_app_entry(void *parameter)
{
    #if 0
    int result = RT_EOK;

    result = rt_sem_init(&net_ready, "net_ready", 0, RT_IPC_FLAG_FIFO);
    if (result != RT_EOK)
    {
        return -RT_ERROR;
    }

    /* 注册 wlan 连接网络成功的回调，wlan 连接网络成功后释放 'net_ready' 信号量 */
    rt_wlan_register_event_handler(RT_WLAN_EVT_READY, wlan_ready_handler, RT_NULL);
    /* 注册 wlan 网络断开连接的回调 */
    rt_wlan_register_event_handler(RT_WLAN_EVT_STA_DISCONNECTED, wlan_station_disconnect_handler, RT_NULL);

    /* 等待 wlan 连接网络成功 */
    result = rt_sem_take(&net_ready, RT_WAITING_FOREVER);
    if (result != RT_EOK)
    {
        LOG_E("Wait net ready failed!");
        rt_sem_delete(&net_ready);
        return -RT_ERROR;
    }
    #endif
    /* 轮询等待 Wi-Fi 成功获取到 IP */
    while (!rt_wlan_is_ready())
    {
        rt_thread_mdelay(500);
    }

    /* HTTP GET 请求发送 */
    // webclient_get_smpl(HTTP_GET_URL);
    /* HTTP POST 请求发送 */
    // webclient_post_smpl(HTTP_POST_URL,post_data,rt_strlen(post_data));
}

int iot_http_client_init(void)
{
    /* WebClient 需要较大的栈空间，分配 4096 字节 */
    rt_thread_t tid = rt_thread_create("http_app", http_client_app_entry, RT_NULL, 4096, 23, 10);
    if (tid != RT_NULL)
    {
        rt_thread_startup(tid);
    }
    return 0;
}
INIT_APP_EXPORT(iot_http_client_init);

/**
 * The callback of network ready event
 */
// void wlan_ready_handler(int event, struct rt_wlan_buff *buff, void *parameter)
// {
//     rt_sem_release(&net_ready);
// }

/**
 * The callback of wlan disconected event
 */
// void wlan_station_disconnect_handler(int event, struct rt_wlan_buff *buff, void *parameter)
// {
//     LOG_I("disconnect from the network!");
// }

/* HTTP client download data by GET request */
int webclient_get_smpl(const char *uri)
{
    char *response = RT_NULL;
    size_t resp_len = 0;
    int index;

    if (webclient_request(uri, RT_NULL, RT_NULL, 0, (void **)&response, &resp_len) < 0)
    {
        rt_kprintf("webclient send get request failed.");
        return -RT_ERROR;
    }

    rt_kprintf("webclient send get request by simplify request interface.\n");
    rt_kprintf("webclient get response data: \n");
    for (index = 0; index < rt_strlen(response); index++)
    {
        rt_kprintf("%c", response[index]);
    }
    rt_kprintf("\n");

    if (response)
    {
        web_free(response);
    }

    return 0;
}

/* HTTP client upload data to server by POST request */
int webclient_post_smpl(const char *uri, const char *post_data, size_t data_len)
{
    char *response = RT_NULL;
    char *header = RT_NULL;
    size_t resp_len = 0;
    int index = 0;

    webclient_request_header_add(&header, "Content-Length: %d\r\n", strlen(post_data));
    webclient_request_header_add(&header, "Content-Type: application/octet-stream\r\n");

    if (webclient_request(uri, header, post_data, data_len, (void **)&response, &resp_len) < 0)
    {
        rt_kprintf("webclient send post request failed.");
        web_free(header);
        return -RT_ERROR;
    }

    rt_kprintf("webclient send post request by simplify request interface.\n");
    rt_kprintf("webclient post response data: \n");
    for (index = 0; index < resp_len; index++)
    {
        rt_kprintf("%c", response[index]);
    }
    rt_kprintf("\n");

    if (header)
    {
        web_free(header);
    }

    if (response)
    {
        web_free(response);
    }

    return 0;
}


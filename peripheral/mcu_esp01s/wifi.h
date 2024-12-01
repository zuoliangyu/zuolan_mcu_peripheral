#ifndef __WIFI_H
#define __WIFI_H

#include "main.h"

/*连接AP宏定义*/
#define SSID "Tenda_2B2B20"
#define PWD  "18768803909"

/*连接服务器宏定义*/
#define TCP "TCP"
#define UDP "UDP"
#define IP  "122.114.122.174"
#define PORT 40915

#define Net_SendString(str) u2_printf(str)
#define Net_SendBuf(buf,len) HAL_UART_Transmit(&huart2, buf, len, 10)

uint8_t FindStr(char* dest,char* src,uint16_t retry_nms);

typedef struct
{
	uint8_t *rxbuf;uint16_t rxlen;
	uint8_t *txbuf;uint16_t txlen;
	
	uint8_t (*Check)(void);
	uint8_t (*Init)(uint8_t *prx,uint16_t rxlen,uint8_t *ptx,uint16_t txlen);
	void (*Restore)(void);
	uint8_t (*ConnectAP)(char *ssid,char *pswd);
	uint8_t (*OpenTransmission)(void);
	void (*CloseTransmission)(void);		
	void (*SendString)(char *str);
	void (*SendBuf)(uint8_t *buf,uint16_t len);
}_typdef_net;

extern _typdef_net _net;

#endif

/*********************************************END OF FILE********************************************/


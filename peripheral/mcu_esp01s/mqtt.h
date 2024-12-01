#ifndef __MQTT_H_
#define __MQTT_H_

#include "main.h"

#define BYTE0(dwTemp)       (*( char *)(&dwTemp))
#define BYTE1(dwTemp)       (*((char *)(&dwTemp) + 1))
#define BYTE2(dwTemp)       (*((char *)(&dwTemp) + 2))
#define BYTE3(dwTemp)       (*((char *)(&dwTemp) + 3))

typedef struct
{
	uint8_t *rxbuf;uint16_t rxlen;
	uint8_t *txbuf;uint16_t txlen;
	void (*Init)(uint8_t *prx,uint16_t rxlen,uint8_t *ptx,uint16_t txlen);
	uint8_t (*UserConfig)(char *ClientID,char *Username,char *Password);
    uint8_t (*Connect)(char *MQTT_BrokerAddress);
	uint8_t (*SubscribeTopic)(char *topic,uint8_t qos,uint8_t whether);
	uint8_t (*PublishData)(char *topic, char *message, uint8_t qos);
	void (*SendHeart)(void);
	void (*Disconnect)(void);
    void (*SendString)(char *str);
}_typdef_mqtt;

extern _typdef_mqtt _mqtt;

#endif


#include "mqtt.h"
//#define _DEBUG_MQTT

typedef enum
{
	//名字 	    值 			报文流动方向 	描述
	M_RESERVED1	=0	,	//	禁止	保留
	M_CONNECT		,	//	客户端到服务端	客户端请求连接服务端
	M_CONNACK		,	//	服务端到客户端	连接报文确认
	M_PUBLISH		,	//	两个方向都允许	发布消息
	M_PUBACK		,	//	两个方向都允许	QoS 1消息发布收到确认
	M_PUBREC		,	//	两个方向都允许	发布收到（保证交付第一步）
	M_PUBREL		,	//	两个方向都允许	发布释放（保证交付第二步）
	M_PUBCOMP		,	//	两个方向都允许	QoS 2消息发布完成（保证交互第三步）
	M_SUBSCRIBE		,	//	客户端到服务端	客户端订阅请求
	M_SUBACK		,	//	服务端到客户端	订阅请求报文确认
	M_UNSUBSCRIBE	,	//	客户端到服务端	客户端取消订阅请求
	M_UNSUBACK		,	//	服务端到客户端	取消订阅报文确认
	M_PINGREQ		,	//	客户端到服务端	心跳请求
	M_PINGRESP		,	//	服务端到客户端	心跳响应
	M_DISCONNECT	,	//	客户端到服务端	客户端断开连接
	M_RESERVED2		,	//	禁止	保留
}_typdef_mqtt_message;



//连接成功服务器回应 20 02 00 00
//客户端主动断开连接 e0 00
const uint8_t parket_connetAck[] = {0x20,0x02,0x00,0x00};
const uint8_t parket_disconnet[] = {0xe0,0x00};
const uint8_t parket_heart[] = {0xc0,0x00};
const uint8_t parket_heart_reply[] = {0xc0,0x00};
const uint8_t parket_subAck[] = {0x90,0x03};

static void SendString(char* str);
static void Mqtt_SendBuf(uint8_t *buf,uint16_t len);

static void Init(uint8_t *prx,uint16_t rxlen,uint8_t *ptx,uint16_t txlen);
static uint8_t UserConfig(char *ClientID,char *Username,char *Password);
static uint8_t Connect(char *MQTT_BrokerAddress);
static uint8_t SubscribeTopic(char *topic,uint8_t qos,uint8_t whether);
static uint8_t PublishData(char *topic, char *message, uint8_t qos);
static void SentHeart(void);
static void Disconnect(void);

_typdef_mqtt _mqtt = 
{
	0,0,
	0,0,
	Init,
	UserConfig,
    Connect,
	SubscribeTopic,
	PublishData,
	SentHeart,
	Disconnect,
    SendString,
};

static void Init(uint8_t *prx,uint16_t rxlen,uint8_t *ptx,uint16_t txlen)
{
	_mqtt.rxbuf = prx;_mqtt.rxlen = rxlen;
	_mqtt.txbuf = ptx;_mqtt.txlen = txlen;
	
	memset(_mqtt.rxbuf,0,_mqtt.rxlen);
	memset(_mqtt.txbuf,0,_mqtt.txlen);
}


static uint8_t UserConfig(char *ClientID, char *Username, char *Password)
{
    uint8_t cnt=2;
    while(cnt--)
    {
        sprintf((char*)_mqtt.txbuf,"AT+MQTTUSERCFG=0,1,\"%s\",\"%s\",\"%s\",0,0,\"\"\r\n",ClientID, Username, Password);//用户配置
        _mqtt.SendString((char*)_mqtt.txbuf);              //设置用户配置模式
        printf("\r\n------------start------------Connect send :%s\r\n",_mqtt.txbuf);
        if(FindStr((char*)_mqtt.rxbuf,"OK",4000) != 0)
        {
            printf("UserConfig ask :%s\r\n------------end-------------\r\n",_mqtt.rxbuf);
            break;
        }
    }
    if(cnt) return 1;
        return 0;
}

static uint8_t Connect(char *MQTT_BrokerAddress)
{
    uint8_t cnt = 2;
    while(cnt--)
    {
        memset(_mqtt.txbuf,0,_mqtt.txlen);
        sprintf((char*)_mqtt.txbuf,"AT+MQTTCONN=0,\"%s\",1883,1\r\n", MQTT_BrokerAddress);//用户配置
        _mqtt.SendString((char*)_mqtt.txbuf);              //设置用户配置模式
        printf("\r\n------------start------------Connect send :%s\r\n",_mqtt.txbuf);
        
        if(FindStr((char*)_mqtt.rxbuf,"OK",4000) != 0)
        {
            printf("mqtt ask :%s\r\n------------end-------------\r\n",_mqtt.rxbuf);
            break;
        }
    }
    if(cnt) return 1;
        return 0;
}


//MQTT订阅/取消订阅数据打包函数
//topic       主题 
//qos         消息等级 
//whether     订阅/取消订阅请求包
static uint8_t SubscribeTopic(char *topic,uint8_t qos,uint8_t whether)
{    
	_mqtt.txlen=0;
    int topiclen = strlen(topic);
	
	int DataLen = 2 + (topiclen+2) + (whether?1:0);//可变报头的长度（2字节）加上有效载荷的长度
	//固定报头
	//控制报文类型
    if(whether) _mqtt.txbuf[_mqtt.txlen++] = 0x82; //消息类型和标志订阅
    else	_mqtt.txbuf[_mqtt.txlen++] = 0xA2;    //取消订阅

	//剩余长度
	do
	{
		uint8_t encodedByte = DataLen % 128;
		DataLen = DataLen / 128;
		// if there are more data to encode, set the top bit of this byte
		if ( DataLen > 0 )
			encodedByte = encodedByte | 128;
		_mqtt.txbuf[_mqtt.txlen++] = encodedByte;
	}while ( DataLen > 0 );	
	
	//可变报头
    _mqtt.txbuf[_mqtt.txlen++] = 0;				//消息标识符 MSB
    _mqtt.txbuf[_mqtt.txlen++] = 0x01;           //消息标识符 LSB
	//有效载荷
    _mqtt.txbuf[_mqtt.txlen++] = BYTE1(topiclen);//主题长度 MSB
    _mqtt.txbuf[_mqtt.txlen++] = BYTE0(topiclen);//主题长度 LSB   
	memcpy(&_mqtt.txbuf[_mqtt.txlen],topic,topiclen);
    _mqtt.txlen += topiclen;
    
    if(whether)
    {
        _mqtt.txbuf[_mqtt.txlen++] = qos;//QoS级别
    }
	
	uint8_t cnt=2;
	uint8_t wait;
	while(cnt--)
	{
		memset(_mqtt.rxbuf,0,_mqtt.rxlen);
		Mqtt_SendBuf(_mqtt.txbuf,_mqtt.txlen);
		wait=30;//等待3s时间
		while(wait--)
		{
			if(_mqtt.rxbuf[0]==parket_subAck[0] && _mqtt.rxbuf[1]==parket_subAck[1]) //订阅成功			   
			{
				return 1;//订阅成功
			}
			HAL_Delay(100);			
		}
	}
	if(cnt) return 1;	//订阅成功
	return 0;
}

//MQTT发布数据打包函数
//topic   主题 
//message 消息
//qos     消息等级 
static uint8_t PublishData(char *topic, char *message, uint8_t qos)
{  
    int topicLength = strlen(topic);    
    int messageLength = strlen(message);     
    static uint16_t id=0;
	int DataLen;
	_mqtt.txlen=0;
	//有效载荷的长度这样计算：用固定报头中的剩余长度字段的值减去可变报头的长度
	//QOS为0时没有标识符
	//数据长度             主题名   报文标识符   有效载荷
    if(qos)	DataLen = (2+topicLength) + 2 + messageLength;       
    else	DataLen = (2+topicLength) + messageLength;   

    //固定报头
	//控制报文类型
    _mqtt.txbuf[_mqtt.txlen++] = 0x30;    // MQTT Message Type PUBLISH  

	//剩余长度
	do
	{
		uint8_t encodedByte = DataLen % 128;
		DataLen = DataLen / 128;
		// if there are more data to encode, set the top bit of this byte
		if ( DataLen > 0 )
			encodedByte = encodedByte | 128;
		_mqtt.txbuf[_mqtt.txlen++] = encodedByte;
	}while ( DataLen > 0 );	
	
    _mqtt.txbuf[_mqtt.txlen++] = BYTE1(topicLength);//主题长度MSB
    _mqtt.txbuf[_mqtt.txlen++] = BYTE0(topicLength);//主题长度LSB 
	memcpy(&_mqtt.txbuf[_mqtt.txlen],topic,topicLength);//拷贝主题
    _mqtt.txlen += topicLength;
        
	//报文标识符
    if(qos)
    {
        _mqtt.txbuf[_mqtt.txlen++] = BYTE1(id);
        _mqtt.txbuf[_mqtt.txlen++] = BYTE0(id);
        id++;
    }
	memcpy(&_mqtt.txbuf[_mqtt.txlen],message,messageLength);
    _mqtt.txlen += messageLength;
        
	Mqtt_SendBuf(_mqtt.txbuf,_mqtt.txlen);
    return _mqtt.txlen;
}

static void SendString(char* str)
{
    memset(_mqtt.rxbuf,0,_mqtt.rxlen);
	#ifdef _DEBUG_MQTT
	Usart1_SendString(str);
	#endif	
	u2_printf(str);
}

static void SentHeart(void)
{
	Mqtt_SendBuf((uint8_t *)parket_heart,sizeof(parket_heart));
}

static void Disconnect(void)
{
	Mqtt_SendBuf((uint8_t *)parket_disconnet,sizeof(parket_disconnet));
}

static void Mqtt_SendBuf(uint8_t *buf,uint16_t len)
{
	#ifdef _DEBUG_MQTT
	Usart1_SendBuf(buf,len);
	#endif
	HAL_UART_Transmit(&huart2, buf, len, 10);
}	





/*********************************************END OF FILE********************************************/

#include "mqtt.h"
//#define _DEBUG_MQTT

typedef enum
{
	//���� 	    ֵ 			������������ 	����
	M_RESERVED1	=0	,	//	��ֹ	����
	M_CONNECT		,	//	�ͻ��˵������	�ͻ����������ӷ����
	M_CONNACK		,	//	����˵��ͻ���	���ӱ���ȷ��
	M_PUBLISH		,	//	������������	������Ϣ
	M_PUBACK		,	//	������������	QoS 1��Ϣ�����յ�ȷ��
	M_PUBREC		,	//	������������	�����յ�����֤������һ����
	M_PUBREL		,	//	������������	�����ͷţ���֤�����ڶ�����
	M_PUBCOMP		,	//	������������	QoS 2��Ϣ������ɣ���֤������������
	M_SUBSCRIBE		,	//	�ͻ��˵������	�ͻ��˶�������
	M_SUBACK		,	//	����˵��ͻ���	����������ȷ��
	M_UNSUBSCRIBE	,	//	�ͻ��˵������	�ͻ���ȡ����������
	M_UNSUBACK		,	//	����˵��ͻ���	ȡ�����ı���ȷ��
	M_PINGREQ		,	//	�ͻ��˵������	��������
	M_PINGRESP		,	//	����˵��ͻ���	������Ӧ
	M_DISCONNECT	,	//	�ͻ��˵������	�ͻ��˶Ͽ�����
	M_RESERVED2		,	//	��ֹ	����
}_typdef_mqtt_message;



//���ӳɹ���������Ӧ 20 02 00 00
//�ͻ��������Ͽ����� e0 00
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
        sprintf((char*)_mqtt.txbuf,"AT+MQTTUSERCFG=0,1,\"%s\",\"%s\",\"%s\",0,0,\"\"\r\n",ClientID, Username, Password);//�û�����
        _mqtt.SendString((char*)_mqtt.txbuf);              //�����û�����ģʽ
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
        sprintf((char*)_mqtt.txbuf,"AT+MQTTCONN=0,\"%s\",1883,1\r\n", MQTT_BrokerAddress);//�û�����
        _mqtt.SendString((char*)_mqtt.txbuf);              //�����û�����ģʽ
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


//MQTT����/ȡ���������ݴ������
//topic       ���� 
//qos         ��Ϣ�ȼ� 
//whether     ����/ȡ�����������
static uint8_t SubscribeTopic(char *topic,uint8_t qos,uint8_t whether)
{    
	_mqtt.txlen=0;
    int topiclen = strlen(topic);
	
	int DataLen = 2 + (topiclen+2) + (whether?1:0);//�ɱ䱨ͷ�ĳ��ȣ�2�ֽڣ�������Ч�غɵĳ���
	//�̶���ͷ
	//���Ʊ�������
    if(whether) _mqtt.txbuf[_mqtt.txlen++] = 0x82; //��Ϣ���ͺͱ�־����
    else	_mqtt.txbuf[_mqtt.txlen++] = 0xA2;    //ȡ������

	//ʣ�೤��
	do
	{
		uint8_t encodedByte = DataLen % 128;
		DataLen = DataLen / 128;
		// if there are more data to encode, set the top bit of this byte
		if ( DataLen > 0 )
			encodedByte = encodedByte | 128;
		_mqtt.txbuf[_mqtt.txlen++] = encodedByte;
	}while ( DataLen > 0 );	
	
	//�ɱ䱨ͷ
    _mqtt.txbuf[_mqtt.txlen++] = 0;				//��Ϣ��ʶ�� MSB
    _mqtt.txbuf[_mqtt.txlen++] = 0x01;           //��Ϣ��ʶ�� LSB
	//��Ч�غ�
    _mqtt.txbuf[_mqtt.txlen++] = BYTE1(topiclen);//���ⳤ�� MSB
    _mqtt.txbuf[_mqtt.txlen++] = BYTE0(topiclen);//���ⳤ�� LSB   
	memcpy(&_mqtt.txbuf[_mqtt.txlen],topic,topiclen);
    _mqtt.txlen += topiclen;
    
    if(whether)
    {
        _mqtt.txbuf[_mqtt.txlen++] = qos;//QoS����
    }
	
	uint8_t cnt=2;
	uint8_t wait;
	while(cnt--)
	{
		memset(_mqtt.rxbuf,0,_mqtt.rxlen);
		Mqtt_SendBuf(_mqtt.txbuf,_mqtt.txlen);
		wait=30;//�ȴ�3sʱ��
		while(wait--)
		{
			if(_mqtt.rxbuf[0]==parket_subAck[0] && _mqtt.rxbuf[1]==parket_subAck[1]) //���ĳɹ�			   
			{
				return 1;//���ĳɹ�
			}
			HAL_Delay(100);			
		}
	}
	if(cnt) return 1;	//���ĳɹ�
	return 0;
}

//MQTT�������ݴ������
//topic   ���� 
//message ��Ϣ
//qos     ��Ϣ�ȼ� 
static uint8_t PublishData(char *topic, char *message, uint8_t qos)
{  
    int topicLength = strlen(topic);    
    int messageLength = strlen(message);     
    static uint16_t id=0;
	int DataLen;
	_mqtt.txlen=0;
	//��Ч�غɵĳ����������㣺�ù̶���ͷ�е�ʣ�೤���ֶε�ֵ��ȥ�ɱ䱨ͷ�ĳ���
	//QOSΪ0ʱû�б�ʶ��
	//���ݳ���             ������   ���ı�ʶ��   ��Ч�غ�
    if(qos)	DataLen = (2+topicLength) + 2 + messageLength;       
    else	DataLen = (2+topicLength) + messageLength;   

    //�̶���ͷ
	//���Ʊ�������
    _mqtt.txbuf[_mqtt.txlen++] = 0x30;    // MQTT Message Type PUBLISH  

	//ʣ�೤��
	do
	{
		uint8_t encodedByte = DataLen % 128;
		DataLen = DataLen / 128;
		// if there are more data to encode, set the top bit of this byte
		if ( DataLen > 0 )
			encodedByte = encodedByte | 128;
		_mqtt.txbuf[_mqtt.txlen++] = encodedByte;
	}while ( DataLen > 0 );	
	
    _mqtt.txbuf[_mqtt.txlen++] = BYTE1(topicLength);//���ⳤ��MSB
    _mqtt.txbuf[_mqtt.txlen++] = BYTE0(topicLength);//���ⳤ��LSB 
	memcpy(&_mqtt.txbuf[_mqtt.txlen],topic,topicLength);//��������
    _mqtt.txlen += topicLength;
        
	//���ı�ʶ��
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

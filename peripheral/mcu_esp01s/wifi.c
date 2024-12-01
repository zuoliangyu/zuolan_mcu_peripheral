#include "wifi.h"

//#define _DEBUG_NET

static uint8_t Check(void);
static uint8_t Init(uint8_t *prx,uint16_t rxlen,uint8_t *ptx,uint16_t txlen);
static void Restore(void);
static uint8_t ConnectAP(char* ssid,char* pswd);
static uint8_t ConnectServer(char* mode,char* ip,uint16_t port);
static uint8_t DisconnectServer(void);
static uint8_t OpenTransmission(void);
static void CloseTransmission(void);
static void SendString(char* str);
static void SendBuf(uint8_t* buf,uint16_t len);


_typdef_net _net=
{
	0,0,
	0,0,
	Check,
	Init,
	Restore,
	ConnectAP,
	OpenTransmission,
	CloseTransmission,
	SendString,
	SendBuf
};






uint8_t FindStr(char* dest,char* src,uint16_t retry_nms)
{
    retry_nms/=10;                   //��ʱʱ��

    while(strstr(dest,src)==0 && retry_nms--)//�ȴ����ڽ�����ϻ�ʱ�˳�
    {		
			HAL_Delay(10);
    }
	
   if(retry_nms)     return 1;                       

   return 0; 
}


/**
 * ���ܣ���ʼ��ESP8266
 * ������None
 * ����ֵ����ʼ���������0Ϊ��ʼ���ɹ�,0Ϊʧ��
 */
static uint8_t Init(uint8_t *prx,uint16_t rxlen,uint8_t *ptx,uint16_t txlen)
{
	_net.rxbuf = prx;_net.rxlen = rxlen;
	_net.txbuf = ptx;_net.txlen = txlen;
	
	memset(_net.rxbuf,0,_net.rxlen);
	memset(_net.txbuf,0,_net.txlen);
	
	_net.CloseTransmission();          //�˳�͸�� 
    HAL_Delay(500); 
	_net.SendString("AT+RST\r\n");   //����ESP8266 
    printf("AT+RST\r\n");
	HAL_Delay(800);
    if(_net.Check() == 0)              //ʹ��ATָ����ESP8266�Ƿ����
    {
        printf("ESP8266 None!");
        return 0;
    }
    
    printf("ESP8266 Find!\r\n");
    
    memset(_net.rxbuf,0,_net.rxlen);    //��ս��ջ���
    _net.SendString("ATE0\r\n");     	//�رջ��� 
    if(FindStr((char*)_net.rxbuf,"OK",500)==0)  //���ò��ɹ�
    {
        return 0;      
    }
    return 1;                         //���óɹ�

}

/**
 * ���ܣ��ָ���������
 * ������None
 * ����ֵ��None
 * ˵��:��ʱESP8266�е��û����ý�ȫ����ʧ�ظ��ɳ���״̬
 */
static void Restore(void)
{
    _net.CloseTransmission();           //�˳�͸��
    HAL_Delay(500);
    _net.SendString("AT+RESTORE\r\n");//�ָ����� 	
//    NVIC_SystemReset();                 //ͬʱ������Ƭ��   
}

/**
 * ���ܣ����ESP8266�Ƿ�����
 * ������None
 * ����ֵ��ESP8266����״̬
 *        ��0 ESP8266����
 *        0 ESP8266������  
 */
static uint8_t Check(void)
{
	uint8_t check_cnt=5;
	while(check_cnt--)
	{
		memset(_net.rxbuf,0,_net.rxlen); 	 //��ս��ջ���
		_net.SendString("AT\r\n");     		 //����AT����ָ��	
        printf("Check send : AT\r\n");
        if(FindStr((char*)_net.rxbuf,"OK",200) != 0)
        {
            printf("Check recv OK\r\n");
            return 1;
        }
    }
    return 0;
}

/**
 * ���ܣ������ȵ�
 * ������
 *         ssid:�ȵ���
 *         pwd:�ȵ�����
 * ����ֵ��
 *         ���ӽ��,��0���ӳɹ�,0����ʧ��
 * ˵���� 
 *         ʧ�ܵ�ԭ�������¼���(UARTͨ�ź�ESP8266���������)
 *         1. WIFI�������벻��ȷ
 *         2. ·���������豸̫��,δ�ܸ�ESP8266����IP
 */
static uint8_t ConnectAP(char* ssid,char* pswd)
{
	uint8_t cnt=5;
	while(cnt--)
	{
		memset(_net.rxbuf,0,_net.rxlen);     
		_net.SendString("AT+CWMODE=1\r\n");              //����ΪSTATIONģʽ	
		if(FindStr((char*)_net.rxbuf,"OK",200) != 0)
		{
			break;
		}
	}
	if(cnt == 0) 
		return 0;

	cnt=2;
	while(cnt--)
	{
		memset(_net.txbuf,0,_net.txlen);                            //��շ��ͻ���
		memset(_net.rxbuf,0,_net.rxlen);                            //��ս��ջ���
		sprintf((char*)_net.txbuf,"AT+CWJAP=\"%s\",\"%s\"\r\n",ssid,pswd);//����Ŀ��AP
		_net.SendString((char*)_net.txbuf);	
		if(FindStr((char*)_net.rxbuf,"OK",8000)!=0)                      //���ӳɹ��ҷ��䵽IP
		{
			return 1;
		}
	}
	return 0;
}

///**
// * ���ܣ�ʹ��ָ��Э��(TCP/UDP)���ӵ�������
// * ������
// *         mode:Э������ "TCP","UDP"
// *         ip:Ŀ�������IP
// *         port:Ŀ���Ƿ������˿ں�
// * ����ֵ��
// *         ���ӽ��,��0���ӳɹ�,0����ʧ��
// * ˵���� 
// *         ʧ�ܵ�ԭ�������¼���(UARTͨ�ź�ESP8266���������)
// *         1. Զ�̷�����IP�Ͷ˿ں�����
// *         2. δ����AP
// *         3. �������˽�ֹ���(һ�㲻�ᷢ��)
// */
//static uint8_t ConnectServer(char* mode,char* ip,uint16_t port)
//{
//	uint8_t cnt;
//   
//    _net.CloseTransmission();                   //����������˳�͸��
//    HAL_Delay(500);

//	//���ӷ�����
//	cnt=2;
//	while(cnt--)
//	{
//		memset(_net.rxbuf,0,_net.rxlen);      
//		memset(_net.txbuf,0,_net.txlen);   
//		sprintf((char*)_net.txbuf,"AT+CIPSTART=\"%s\",\"%s\",%d\r\n",mode,ip,port);
//		_net.SendString((char*)_net.txbuf);
//		if(FindStr((char*)_net.rxbuf,"CONNECT",8000) !=0 )
//		{
//			break;
//		}
//	}
//	if(cnt == 0) 
//		return 0;
//	
//	//����͸��ģʽ
//	if(_net.OpenTransmission()==0) return 0;
//	
//	//��������״̬
//	cnt=2;
//	while(cnt--)
//	{
//		memset(_net.rxbuf,0,_net.rxlen); 
//		_net.SendString("AT+CIPSEND\r\n");//��ʼ����͸������״̬
//		if(FindStr((char*)_net.rxbuf,">",200)!=0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}

///**
// * ���ܣ������ͷ������Ͽ�����
// * ������None
// * ����ֵ��
// *         ���ӽ��,��0�Ͽ��ɹ�,0�Ͽ�ʧ��
// */
//static uint8_t DisconnectServer(void)
//{
//	uint8_t cnt;
//    _net.CloseTransmission();	//�˳�͸��
//    HAL_Delay(500);
//	while(cnt--)
//	{
//		memset(_net.rxbuf,0,_net.rxlen);  
//		_net.SendString("AT+CIPCLOSE\r\n");//�ر�����

//		if(FindStr((char*)_net.rxbuf,"CLOSED",200)!=0)//�����ɹ�,�ͷ������ɹ��Ͽ�
//		{
//			break;
//		}
//	}
//	if(cnt) return 1;
//	return 0;
//}

/**
 * ���ܣ�͸��ģʽ�µ����ݷ��ͺ���
 * ������
 *      buffer:����������
 * ����ֵ��None
 */
static void SendBuf(uint8_t* buf,uint16_t len)
{
    memset(_net.rxbuf,0,_net.rxlen);
	#ifdef _DEBUG_NET
	Usart1_SendBuf(buf,len);
	#endif	
	HAL_UART_Transmit(&huart2, buf, len, 10);
}


/**
 * ���ܣ�͸��ģʽ�µ����ݷ��ͺ���
 * ������
 *      buffer:����������
 * ����ֵ��None
 */
static void SendString(char* str)
{
    memset(_net.rxbuf,0,_net.rxlen);
	#ifdef _DEBUG_NET
	Usart1_SendString(str);
	#endif	
	u2_printf(str);
}

static uint8_t OpenTransmission(void)
{
	//����͸��ģʽ
	uint8_t cnt=2;
	while(cnt--)
	{
        memset(_net.rxbuf,0,_net.rxlen);    
        _net.SendString("AT+CIPMODE=1\r\n");  
        if(FindStr((char*)_net.rxbuf,"OK",200)!=0)
        {	
			return 1;
		}
	}
	return 0;
}
//�˳�͸��
static void CloseTransmission(void)
{
	_net.SendString("+++"); HAL_Delay(50);
	_net.SendString("+++"); HAL_Delay(50);
}
/*********************************************END OF FILE********************************************/


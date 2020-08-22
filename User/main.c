#include "system.h"
#include "SysTick.h"
#include "usart.h"
#include "motor.h"

void delay1(u32 i)
{ while(i--);
}
	
int main()
{
	u16 t=0;
	u16 len=0;
	
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //中断优先级分组 分2组
	USART1_Init(9600);
	MotorInit();
	
	while(1)
	{
		if(USART1_RX_STA&0x8000)
		{					   
			len=USART1_RX_STA&0x3fff;//得到此次接收到的数据长度
			for(t=0;t<len;t++)
			{
				USART_SendData(USART1, USART1_RX_BUF[t]);         //向串口1发送数据
				while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束
				
			}
			USART1_RX_STA=0;
		}
		
}
}


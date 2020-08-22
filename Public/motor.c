#include "STM32F10X.h"
#include "motor.h"

void MotorInit(void)
{
	
	//初始化和使能单片机上的GPIO端口，保证可以正常给端口高低电平
	GPIO_InitTypeDef GPIO_InitStructure;
//前电机	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13;//左：10、11 右：12、13
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOB,GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12 | GPIO_Pin_13);
	
//后电机
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;//左：2、3 右：4、5
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOA,GPIO_Pin_3|GPIO_Pin_5|GPIO_Pin_2 | GPIO_Pin_4);
	
}


//停止模式
void Stop(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_10);
	GPIO_ResetBits(GPIOB,GPIO_Pin_11);
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	GPIO_ResetBits(GPIOB,GPIO_Pin_13);
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	GPIO_ResetBits(GPIOA,GPIO_Pin_3);
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);
}


//左转模式 -> 左电机正转，右电机反转
void Turnleft(void)
{ 
	GPIO_SetBits(GPIOB,GPIO_Pin_11); 
	GPIO_ResetBits(GPIOB,GPIO_Pin_10);
	GPIO_SetBits(GPIOA,GPIO_Pin_3); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	GPIO_SetBits(GPIOB,GPIO_Pin_12); 
	GPIO_ResetBits(GPIOB,GPIO_Pin_13);
	GPIO_SetBits(GPIOA,GPIO_Pin_4); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);
	
}

//右转模式 -> 左电机反转，右电机正转
void Turnright(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_10); 
	GPIO_ResetBits(GPIOB,GPIO_Pin_11);
	GPIO_SetBits(GPIOA,GPIO_Pin_2); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_3);
	GPIO_SetBits(GPIOB,GPIO_Pin_13); 
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	GPIO_SetBits(GPIOA,GPIO_Pin_5); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
}

//后退模式 -> 左电机反转，右电机反转
void Turnback(void)
{
	
	GPIO_SetBits(GPIOB,GPIO_Pin_11); 
	GPIO_ResetBits(GPIOB,GPIO_Pin_10);
	GPIO_SetBits(GPIOA,GPIO_Pin_3); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	GPIO_SetBits(GPIOB,GPIO_Pin_13); 
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	GPIO_SetBits(GPIOA,GPIO_Pin_5); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
	
}

//前进模式 -> 左电机正转，右电机正转
void Turnfront(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_10); 
	GPIO_ResetBits(GPIOB,GPIO_Pin_11);
	GPIO_SetBits(GPIOA,GPIO_Pin_2); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_3);
	GPIO_SetBits(GPIOB,GPIO_Pin_12); 
	GPIO_ResetBits(GPIOB,GPIO_Pin_13);
	GPIO_SetBits(GPIOA,GPIO_Pin_4); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);
}

//左移
void Leftaround(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_10); 
	GPIO_ResetBits(GPIOB,GPIO_Pin_11);
	GPIO_SetBits(GPIOA,GPIO_Pin_3); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	GPIO_SetBits(GPIOB,GPIO_Pin_13); 
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	GPIO_SetBits(GPIOA,GPIO_Pin_4); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);
	
}

//右移
void Rightaround(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_11); 
	GPIO_ResetBits(GPIOB,GPIO_Pin_10);
	GPIO_SetBits(GPIOA,GPIO_Pin_2); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_3);
	GPIO_SetBits(GPIOB,GPIO_Pin_12); 
	GPIO_ResetBits(GPIOB,GPIO_Pin_13);
	GPIO_SetBits(GPIOA,GPIO_Pin_5); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
	
}

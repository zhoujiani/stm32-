#include "STM32F10X.h"
#include "motor.h"

void MotorInit(void)
{
	
	//��ʼ����ʹ�ܵ�Ƭ���ϵ�GPIO�˿ڣ���֤�����������˿ڸߵ͵�ƽ
	GPIO_InitTypeDef GPIO_InitStructure;
//ǰ���	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13;//��10��11 �ң�12��13
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOB,GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12 | GPIO_Pin_13);
	
//����
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;//��2��3 �ң�4��5
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOA,GPIO_Pin_3|GPIO_Pin_5|GPIO_Pin_2 | GPIO_Pin_4);
	
}


//ֹͣģʽ
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


//��תģʽ -> ������ת���ҵ����ת
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

//��תģʽ -> ������ת���ҵ����ת
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

//����ģʽ -> ������ת���ҵ����ת
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

//ǰ��ģʽ -> ������ת���ҵ����ת
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

//����
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

//����
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

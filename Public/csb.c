#include "csb.h"

#include "stm32f10x.h"
#include "usart.h"
#include "SysTick.h"

/*��¼��ʱ���������*/
uint overcount=0;

/*�����ж����ȼ�*/
void NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructer;

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	NVIC_InitStructer.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitStructer.NVIC_IRQChannelSubPriority=0;
	NVIC_InitStructer.NVIC_IRQChannel=TIM4_IRQn;
	NVIC_InitStructer.NVIC_IRQChannelCmd=ENABLE;

	NVIC_Init(&NVIC_InitStructer);
}

/*��ʼ��ģ���GPIO�Լ���ʼ����ʱ��TIM2*/
void CH_SR04_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructer;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructer;

	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	/*TRIG�����ź�*/
	GPIO_InitStructer.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructer.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructer.GPIO_Pin=GPIO_Pin_8;
	GPIO_Init(GPIOB, &GPIO_InitStructer);

	/*ECOH�����ź�*/
	GPIO_InitStructer.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStructer.GPIO_Pin=GPIO_Pin_9;
	GPIO_Init(GPIOB, & GPIO_InitStructer);

	/*��ʱ��TIM2��ʼ��*/
	TIM_DeInit(TIM4);
	TIM_TimeBaseInitStructer.TIM_Period=999;//��ʱ����Ϊ1000
	TIM_TimeBaseInitStructer.TIM_Prescaler=71; //��Ƶϵ��72
	TIM_TimeBaseInitStructer.TIM_ClockDivision=TIM_CKD_DIV1;//����Ƶ
	TIM_TimeBaseInitStructer.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStructer);

	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);//���������ж�
	NVIC_Config();
	TIM_Cmd(TIM4,DISABLE);//�رն�ʱ��ʹ��

}



float Senor_Using(void)
{
	float length=0,sum=0;
	u16 tim;
	uint i=0;
	/*��5�����ݼ���һ��ƽ��ֵ*/
	while(i!=5)
	{
		PBout(8)=1; //�����źţ���Ϊ�����ź�
		delay_us(20); //�ߵ�ƽ�źų���10us
		PBout(8)=0;
		/*�ȴ������ź�*/
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==RESET);
		TIM_Cmd(TIM4,ENABLE);//�����źŵ�����������ʱ������

		i+=1; //ÿ�յ�һ�λ����ź�+1���յ�5�ξͼ����ֵ
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==SET);//�����ź���ʧ
		TIM_Cmd(TIM4,DISABLE);//�رն�ʱ��

		tim=TIM_GetCounter(TIM4);//��ȡ��TIM4���Ĵ����еļ���ֵ��һ�߼�������ź�ʱ��

		length=(tim+overcount*1000)/58.0;//ͨ�������źż������

		sum=length+sum;
		TIM4->CNT=0; //��TIM4�����Ĵ����ļ���ֵ����
		overcount=0; //�ж������������
		delay_ms(10);
	}
	length=sum/5;
	return length;//������Ϊ��������ֵ
}



void TIM4_IRQHandler(void) //�жϣ��������źźܳ��ǣ�����ֵ������ظ����������ж��������������
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update)!=RESET)
	 {
	TIM_ClearITPendingBit(TIM4,TIM_IT_Update);//����жϱ�־
	overcount++;

	 }
}


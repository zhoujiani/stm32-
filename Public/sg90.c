#include "sg90.h"

void SG90_pwm_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;   
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	/* ����ʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

	/*  ����GPIO��ģʽ��IO�� */
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;// PA1
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//�����������
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//TIM3��ʱ����ʼ��
	TIM_TimeBaseInitStructure.TIM_Period = 199; //PWM Ƶ��=72000/(199+1)=36Khz//�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7199;//����������ΪTIMxʱ��Ƶ��Ԥ��Ƶֵ
	TIM_TimeBaseInitStructure.TIM_ClockDivision = 0;//����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;	//TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2, & TIM_TimeBaseInitStructure);


	//PWM��ʼ��	  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;//PWM���ʹ��
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;

	TIM_OC2Init(TIM2,&TIM_OCInitStructure);
	//ע��˴���ʼ��ʱTIM_OC1Init������TIM_OCInit������������Ϊ�̼���İ汾��һ����
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);//ʹ�ܻ���ʧ��TIMx��CCR1�ϵ�Ԥװ�ؼĴ���
	TIM_Cmd(TIM2,ENABLE);//ʹ�ܻ���ʧ��TIMx����
}

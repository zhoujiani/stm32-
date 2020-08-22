#include "sg90.h"

void SG90_pwm_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;   
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	/* 开启时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

	/*  配置GPIO的模式和IO口 */
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;// PA1
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//复用推挽输出
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//TIM3定时器初始化
	TIM_TimeBaseInitStructure.TIM_Period = 199; //PWM 频率=72000/(199+1)=36Khz//设置自动重装载寄存器周期的值
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7199;//设置用来作为TIMx时钟频率预分频值
	TIM_TimeBaseInitStructure.TIM_ClockDivision = 0;//设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;	//TIM向上计数模式
	TIM_TimeBaseInit(TIM2, & TIM_TimeBaseInitStructure);


	//PWM初始化	  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;//PWM输出使能
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;

	TIM_OC2Init(TIM2,&TIM_OCInitStructure);
	//注意此处初始化时TIM_OC1Init而不是TIM_OCInit，否则会出错。因为固件库的版本不一样。
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);//使能或者失能TIMx在CCR1上的预装载寄存器
	TIM_Cmd(TIM2,ENABLE);//使能或者失能TIMx外设
}

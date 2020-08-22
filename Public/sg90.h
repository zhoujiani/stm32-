#ifndef __SG90_H
#define	__SG90_H

#include "stm32f10x.h"

   
#define   SG90_Right_90     TIM_SetCompare2(TIM2, 195)		//��ת90��
#define   SG90_Right_45		TIM_SetCompare2(TIM2, 190)		
#define   SG90_Front		TIM_SetCompare2(TIM2, 185)		//�������
#define   SG90_Left_45		TIM_SetCompare2(TIM2, 180)		//��ת45��
#define   SG90_Left_90		TIM_SetCompare2(TIM2, 175)
		
void SG90_pwm_init(void);  //���pwm��ʼ��

#endif

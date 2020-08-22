#ifndef __SG90_H
#define	__SG90_H

#include "stm32f10x.h"

   
#define   SG90_Right_90     TIM_SetCompare2(TIM2, 195)		//右转90度
#define   SG90_Right_45		TIM_SetCompare2(TIM2, 190)		
#define   SG90_Front		TIM_SetCompare2(TIM2, 185)		//舵机摆正
#define   SG90_Left_45		TIM_SetCompare2(TIM2, 180)		//左转45度
#define   SG90_Left_90		TIM_SetCompare2(TIM2, 175)
		
void SG90_pwm_init(void);  //舵机pwm初始化

#endif

#include "stm32f10x.h"
#include "sg90.h"
#include "system.h"
#include "SysTick.h"
#include "csb.h"
#include "motor.h"

void bz_on(void)
{
	
	float  length_res[5];  //用来存放测距结果
	
	SG90_pwm_init();  //舵机pwm	    TIM2
	CH_SR04_Init();  //超声波定时器    TIM4
	
   while(1)
	{	
		
		SG90_Front;   //舵机摆正
		delay_ms(100);
    length_res[0] =Senor_Using();  //测前方距离放在数组里
		delay_ms(100);
		
		if(length_res[0]>30.00)       //如果前方距离大于30cm  前进
			{
			Turnfront();
			}	
				
		if(length_res[0]<30.00)     //如果前方距离小于30厘米  停车测左右距离
			{
			Stop();  
			SG90_Left_45;      //舵机左转45度测距
			delay_ms(700);		
			length_res[1] =Senor_Using();    //把测量结果放进数组
			
            SG90_Right_45;     //舵机右转45度测距
			delay_ms(700);	
            length_res[4] =Senor_Using();     //把测量结果放进数组				
				
			SG90_Front;           //舵机摆正
			delay_ms(100); 
			if(length_res[1]>length_res[4])    //如果左边的距离大于右边的距离
				{
					do                        //舵机摆正
					{
					SG90_Front;
					delay_ms(10);
					length_res[0] =Senor_Using();	//重复测前方的距离同时左转
					delay_ms(10);	
          Turnback();
					delay_ms(10);
					Turnleft();
					delay_ms(50);
					}
					while(length_res[0]<30.00);		//一直转到前方距离大于30cm		
				}
		   if(length_res[1]<length_res[4])    //如果右边的距离大于左边的距离
				{
					do
					{
					SG90_Front;
					delay_ms(10);
					length_res[0] =Senor_Using();  //重复测前方的距离同时右转
					delay_ms(10);						
					Turnback();
					delay_ms(10);
					Turnright();
					delay_ms(50);
					}
					while(length_res[0]<30.00);		//一直转到前方距离大于30cm
				}
				
			}		
	
	}	

}

void bz_off()
{
  
}

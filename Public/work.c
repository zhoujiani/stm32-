#include "stm32f10x.h"
#include "sg90.h"
#include "system.h"
#include "SysTick.h"
#include "csb.h"
#include "motor.h"

void bz_on(void)
{
	
	float  length_res[5];  //������Ų����
	
	SG90_pwm_init();  //���pwm	    TIM2
	CH_SR04_Init();  //��������ʱ��    TIM4
	
   while(1)
	{	
		
		SG90_Front;   //�������
		delay_ms(100);
    length_res[0] =Senor_Using();  //��ǰ���������������
		delay_ms(100);
		
		if(length_res[0]>30.00)       //���ǰ���������30cm  ǰ��
			{
			Turnfront();
			}	
				
		if(length_res[0]<30.00)     //���ǰ������С��30����  ͣ�������Ҿ���
			{
			Stop();  
			SG90_Left_45;      //�����ת45�Ȳ��
			delay_ms(700);		
			length_res[1] =Senor_Using();    //�Ѳ�������Ž�����
			
            SG90_Right_45;     //�����ת45�Ȳ��
			delay_ms(700);	
            length_res[4] =Senor_Using();     //�Ѳ�������Ž�����				
				
			SG90_Front;           //�������
			delay_ms(100); 
			if(length_res[1]>length_res[4])    //�����ߵľ�������ұߵľ���
				{
					do                        //�������
					{
					SG90_Front;
					delay_ms(10);
					length_res[0] =Senor_Using();	//�ظ���ǰ���ľ���ͬʱ��ת
					delay_ms(10);	
          Turnback();
					delay_ms(10);
					Turnleft();
					delay_ms(50);
					}
					while(length_res[0]<30.00);		//һֱת��ǰ���������30cm		
				}
		   if(length_res[1]<length_res[4])    //����ұߵľ��������ߵľ���
				{
					do
					{
					SG90_Front;
					delay_ms(10);
					length_res[0] =Senor_Using();  //�ظ���ǰ���ľ���ͬʱ��ת
					delay_ms(10);						
					Turnback();
					delay_ms(10);
					Turnright();
					delay_ms(50);
					}
					while(length_res[0]<30.00);		//һֱת��ǰ���������30cm
				}
				
			}		
	
	}	

}

void bz_off()
{
  
}

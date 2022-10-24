#include <at89c51RC2.h>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int PassWord,Count;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"PassWord:");
	while(1)
	{
	KeyNum=MatrixKey();
		if(KeyNum)
		{
			if(KeyNum<=10)	//如果s1~s10被按下，输入密码
			{
				if(Count<4)	//计次判断
				{
					PassWord*=10;	//密码左移一位
					PassWord+=KeyNum%10;//获取一位密码
				
				}
				Count++;	//计次加一
				LCD_ShowNum(2,1,PassWord,4); //更新显示
			}
			if(KeyNum==11)	//定义s11为确认键
			{
				if(PassWord==0001)	//判断密码正确性并设置密码
				{
					LCD_ShowString(1,11,"OK   ");	//显示正确
					Count=0;	//计次清零
					PassWord=0;	//密码清零
					LCD_ShowNum(2,1,PassWord,4); //更新显示
				}
				else
				{
					LCD_ShowString(1,11,"ERROR");		//显示错误
					Count=0;	//计次清零
					PassWord=0;	//密码清零
					LCD_ShowNum(2,1,PassWord,4); //更新显示
				}
			}
			if(KeyNum==12)
			{
				Count=0;	//计次清零
				PassWord=0;	//密码清零
				LCD_ShowNum(2,1,PassWord,4); //更新显示
			}

		}
	}
}
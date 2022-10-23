#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
int Result;

int main()
{
	LCD_Init();
	Result=0;
	LCD_ShowNum(1,1,Result,3);
	while(1)
	{
	Result++;
		Delay(1000);
		LCD_ShowNum(1,1,Result,3);
	}
}
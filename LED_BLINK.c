#include<reg52.h>
#include"LED_BLINK.h"
sbit LED = P2^0;
sbit LED1 = P2^1;

void main()
{
	while(1)
	{
		LED = 0;
		LED1=0;
		delay();
		LED = 1;
		LED1 = 1;
		delay();
	}
}
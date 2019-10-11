//8_bit counter
#include<reg51.h>

void delay()
{
	unsigned int i,j;
	for(i=0;i<100;i++)
		for(j=0;j<1000;<j++);
}

void main()
{
	x=0x00;
	while(1)
	{
		P1=x;
		delay();
		x=++;
	}
}
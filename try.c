#inlcude<reg51.h>
void delay();
void main()
{
	unsigned char x=0x00;
	for(x=0x00;x<0x10;x++)
	{
		delay();
	}
}

void delay()
{
	unsigned int i;
	for(i=0;i<10000;i++)
}
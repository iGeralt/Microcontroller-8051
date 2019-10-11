#include<reg51.h>
sbit ph1=P1^0;
sbit ph11=P1^1;
sbit ph2=P1^2;
sbit ph22=P1^3;
sbit ph4=P1^4;
sbit ph5=P1^5;
sbit ph6=P1^6;
sbit ph7=P1^7;

void delay(int d)
{
	unsigned int i,j,t;
	for(i=0;i<1000*d;i++)
		for(j=0;j<100;j++);
}

phase1()
{
		ph1=1;
		delay(5);
		ph5=1;
		delay(1);
		
		
}
/*phase2()
{
		ph11=1;
		delay(5);
		ph6=1;
		delay(1);
}
phase3()
{
		ph2=1;
		delay(5);
		ph7=1;
		delay(1);
}
phase4()
{
		ph22=1;
		delay(5);
		ph4=1;
		delay(1);
}*/

void clear()
{
	ph1=ph11=ph2=ph22=ph4=ph5=ph6=ph7=0;
}
void main()
{
	while(1){
		clear();
		phase1();
		clear();
		/*phase2();
		clear();
		phase3();
		clear();
		phase4();
		clear();*/
	}
}
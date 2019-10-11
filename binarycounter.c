/******************************************************************************
 *  File Name : binarycounter                                                 *
 *	Name			: Maurya Sujeet																								  *
 *	Roll no.	:	17BCS016                                                      *
 *	Project		: To make binary counter using led                              *
 *  Date			: 12 September 2018                    													*
 *****************************************************************************/
#include<reg51.h>	// Include register definitions for the Intel 8051
/*Delay function*/
void delay()
{
	unsigned int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<10000;j++);		
}
void main()
{
	while(1)								//infinte loop so that counter runs for infinite time
	{	
		unsigned int i;
		for(i=0;i<15;i++)			//loop for passing every value to be displayed
		{
			P1=i;								//sending value to port 1 for displaying
			delay();						//calling delay function
		}
	}
}
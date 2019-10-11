/******************************************************************************
 *  File Name : ledblinking                                                   *
 *	Name			: Maurya Sujeet																								  *
 *	Roll no.	:	17BCS016                                                      *
 *	Project		: Led blinking                                                  *
 *  Date			: 12 September 2018                    													*
 *****************************************************************************/
#include<reg51.h>	// Include register definitions for the Intel 8051

sbit LED=P1^0;    //to access the pin 0 of port 1
/*Delay function*/

 void delay()
 {
		unsigned int i,j;
		for(i=0;i<100;i++)
			for(j=0;j<100;j++);
 }
 
 void main()
 {
	 while(1){
		LED = 1;      //switching on the led
		delay();			// calling delay , time gap between on and off
		LED = 0;			//switching off the led
	 }
 }

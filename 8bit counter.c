/******************************************************************************
 *  File Name : bitcounter                                                    *
 *	Name			: Maurya Sujeet																								  *
 *	Roll no.	:	17BCS016                                                      *
 *	Project		: To make 8-bit counter using led                               *
 *  Date			: 12 September 2018                    													*
 *****************************************************************************/

// AT89C51 jeader file
#include <REG51.H>

// Delay function limit for inner for loop.
#define INT_MAX 10000

 void delay();
 
 void main() {
	 unsigned char x;  /* Variable to hold value for on/off */
	 x = 0x01;
	 
	 /* 
		* Value of x is started with 0x01 so that pin 1 of port 1 
		* is in logic level 1 hence switching LED 1 on. Then Left
	  * operations is used to pass ON state to each pin of the 
		* posrt one after the another. After all pins are done 
	  * pin 1 is again set to value 1
		*/
	 while(1) {
		 P1 = x;
		 delay();
		 x = x<<1;
		 if(x == 0x00)
				x = 0x01;
	 }
	 
 }
 
 /* Delay function of limit 10*10000 */
 void delay() {
	 int i,j;
	 for(i=0; i<10; i++)
			for(j=0; j<INT_MAX; j++);
 }
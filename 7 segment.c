/******************************************************************************
 *  File Name : clock                                                         *
 *	Name			: Maurya Sujeet																								  *
 *	Roll no.	:	17BCS016                                                      *
 *	Project		: To make a 12 hour clock on a seven segment                    * 
 *  Date			: 19 September 2018                    													*
 *****************************************************************************/

/* AT89C51 header file */
#include <REG51.H>

/* Delay inner loop range */
#define RANGE 1000

 /* Delay function */
 void delay();
 
 /*
	* Intially both xand y variable are initialized with 0x00
	* and they keep on incrementing with delay.
	* Thre are 4 BCD 7 segment displays used with each port used
	* for 2 of them. higher 4 bits to higher order value display
	* and lower order bits of the port to lower order bits display
	* in the  BCD 7 segemnt display 
	*/
	
 void main() {
	 /* Variable x for hours and y for minutes */
	 unsigned char x=0x00, y=0x00;
	 
	 /* Infinitr loop wich works the clock */
	 while(1) {
		 /* Outer for loop for hours */
		 for(x=0x00; x<0x12; x++){
			 /* 
			  * If the value of lowe 4 bits become 0x0a the 8 bits are
			  * incremented with 0x10 and lower 4 bits made 0.
			  */
			 if((x&0x0f) == 0x0a)
				 x = 0x10 + (x&0xf0);
			 P3 = x; /* P3 port for Hours */
			 for(y=0x00; y<0x60; y++) {
				 /* 
				  * Similar to the above for loop to keep the count between 
					* 0-9, each bit displayed by single Display
				  */
				  if((y&0x0f) == 0x0a)
						y = 0x10 + (y&0xf0);
					/* to break the inner for loop as soon as minutes turn 0x60 */
					if(y == 0x60)
						break;
					P1 = y;  /* P1 port for minutes */
					delay(); /* Delay at each minute */
			 }
		 }
	 }
 }
 
 /* Delay loop with range 1*10000 */
 void delay() {
	 int i, j;
	 for(i=0; i<1; i++)
			for(j=0; j<RANGE; j++);
 }
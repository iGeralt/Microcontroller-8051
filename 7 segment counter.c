/******************************************************************************
 *  File Name : 7 segment counter                                             *
 *	Name			: Maurya Sujeet																								  *
 *	Roll no.	:	17BCS016                                                      *
 *	Project		: To make 7 segment led counter                                 *
 *  Date			: 19 September 2018                    													*
 *****************************************************************************/

// AT89C51 Header file
#include <REG51.H>

// Delay inner loop range
#define RANGE 10000

 // Delay function
 void delay();
 
 void main() {
	 /* value that is incremented and fed to the port */
	 unsigned char x;
	 x = 0x00;
	 while(1) {
		 P1 = x;
		 
		 delay ();
		 x++; /* incrementing the variable */
		 
		 /*
			*	if the value of x gets to 0x0a i.e 10 in binary 
			*	restart the counter from 0.	
			*/
		 if(x == 0x0a) 
			 x = 0x00;
	 }
 }
 
 /* Delay function of the range 2*10000 */
 void delay() {
	 int i, j;
	 for(i=0; i<2; i++)
			for(j=0; j<RANGE; j++);
 }
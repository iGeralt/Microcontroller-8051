/*******************************************************************
 *  File Name : calculator                                         *
 *	Name			: Maurya Sujeet		  						 									   *
 *	Roll no.	:	17BCS016                                           *
 *	Project		: To make calculator using keypad and 7 segment led  *
 *	Date			: 26 September 2018                    					 	   *
 *******************************************************************/
#include<reg51.h>	// Include register definitions for the Intel 8051

sbit RowA=P2^0;  	//to access pin 0 of port 2
sbit RowB=P2^1;		//to access pin 1 of port 2
sbit RowC=P2^2;		//to access pin 2 of port 2
sbit RowD=P2^3;		//to access pin 3 of port 2
sbit C1=P2^4;			//to access pin 4 of port 2
sbit C2=P2^5;			//to access pin 5 of port 2
sbit C3=P2^6;			//to access pin 6 of port 2 
sbit C4=P2^7;			//to access pin 7 of port 2

int x1=0,x2=0,count=0,q; 			//declare global variable and assign value if needed

/*delay function
*	to give time delay between different fucntion or process*/

void delay() 
{
	int i,j;
	for(i=0;i<100;i++)
		for(j=0;j<100;j++);
}
/*	display function
*		To display the content taken as input from keypad
*   To display the final answer */

void display(int y)
{ 
	if(count == 0)   				// count=0 so that value wil be stored in first variable
	{	
		x1=y;									//assing the input(value) taken from keypad to first variable
		P1 = x1;							//to display value of first variable
		count ++;							//increase the counter so that value passed from keypad will be stored in second variable
	}
	else if(count == 1)			// count=1 so that value wil be stored in second variable
	{				
		x2 = y;								//assing the input(value) taken from keypad to second variable
		P1 = x2;							//to display the value of second variable
		count++;							//increase the counter so that value passed from keypad will be stored in third variable
	}
	else if (count == 2)		// count = 2 so that value will be stored in third variable
	{
	 int msb = 0;						//declare msb variable and assing it to 0.
	 if(y < 0)							//check if the value passed is negative
		 y *= (-1);						//if it is negative make it positive by multiplying (-1)
	 msb = y/10;						//to get msb of the digit
	 msb = msb<<4;					//shift the msb digit to higher 4 bits
	 y %= 10;								//to get lsb of the digit
	 y += msb;							//add the lsb(lower 4 bits) and msb which contains higher 4 bits
	 P1=y;									//display it on the led
	 count = 0;							//set the counter to 0 so that we can take next input in variable 1 and so on.
		
	}	
}
/*Function to do arithmetic operation */
void result()
{
  int s;
	if(q==1)						//if value of q is  1 then perform division 
	{	s = x1/x2;
		display(s);				//pass the calculated value to display function for displaying
	}
	else if(q==4)				//if value of 1 is 4 the perform addition
	{	s = x1+x2;
		display(s);				//pass the calculated value to display function to display
	}
	else if(q==3)				//if value of q is 3 then perform subtraction
	{	s = x1-x2;
		display(s);				//pass the calculated value to display function
	}
	else if(q==2)				//if value of q is 2 then perform multiplication
	{	s = x1*x2;
		display(s);				//pass the calculated value to display function
	}
}


void main()
{
		P1=0x00;         	//initialize the port 1 for output
while(1)
{
	/* making row and column to zero means setting them low*/
	
	RowA = 0; RowB = 1; RowC = 1; RowD = 1; 	//Test Row A
 
	if (C1 == 0) { delay(); while (C1==0); display(7); }		//if column 1 is 0 and rowa is 0 then 7 will be passed to display function
	if (C2 == 0) { delay(); while (C2==0); display(8); }		//if column 2 is 0 and rowa is 0 then 8 will be passed to display function
	if (C3 == 0) { delay(); while (C3==0); display(9); }		//if column 3 is 0 and rowa is 0 then 9 will be passed to display function
	if (C4 == 0) { delay(); while (C4==0); q=1; }						//if column 4 is 0 and rowa is 0 then q value will be set as 1 (/ button) 
 
	RowA = 1; RowB = 0; RowC = 1; RowD = 1; 	//Test Row B
 
	if (C1 == 0) { delay(); while (C1==0); display(4); }		//if column 1 is 0 and rowb is 0 then 4 will be passed to display function
	if (C2 == 0) { delay(); while (C2==0); display(5); }		//if column 2 is 0 and rowb is 0 then 5 will be passed to display function
	if (C3 == 0) { delay(); while (C3==0); display(6); }		//if column 3 is 0 and rowb is 0 then 6 will be passed to display function
	if (C4 == 0) { delay(); while (C4==0); q=2; }						//if column 4 is 0 and rowb is 0 then q value will be set as 2 (* button)
	
	RowA = 1; RowB = 1; RowC = 0; RowD = 1; 	//Test Row C
 
	if (C1 == 0) { delay(); while (C1==0); display(1); }		//if column 1 is 0 and rowc is 0 then 1 will be passed to display function
	if (C2 == 0) { delay(); while (C2==0); display(2); }		//if column 2 is 0 and rowc is 0 then 2 will be passed to display function
	if (C3 == 0) { delay(); while (C3==0); display(3); }		//if column 3 is 0 and rowc is 0 then 3 will be passed to display function
	if (C4 == 0) { delay(); while (C4==0); q=3; }						//if column 4 is 0 and rowc is 0 then q will be set as 3 (- button)
	
	RowA = 1; RowB = 1; RowC = 1; RowD = 0; 	//Test Row D
 
	if (C1 == 0) { delay(); while (C1==0); display(0);x1=0;x2=0;count=0; } 	//to reset the value of all variable
	if (C2 == 0) { delay(); while (C2==0); display(0); }										//if column 2 is 0 and rowd is 0 then 0 will be passed to display function
	if (C3 == 0) { delay(); while (C3==0); result(); }											//to perform calculation (= button)
	if (C4 == 0) { delay(); while (C4==0); q=4; }														//if column 4 is 0 and rowd is 0 then q will be set as 4 (+ button)
 
	}
}
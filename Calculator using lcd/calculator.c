/******************************************************************************
 *  File Name : calculator_lcd                                                *
 *	Name			: Maurya Sujeet																								  *
 *	Roll no.	:	17BCS016                                                      *
 *	Project		: To make calculator using lcd and keypad												*
 *	Date			: 3 October 2018                      													*
 *****************************************************************************/

#include<reg51.h> // Includes register definitions for the Intel 8051

/* Configure the data bus and Control pins as per the hardware connection 
   Databus is connected to P2_0:P2_7 and control bus P0_0:P0_2*/

sbit LCD_RS = P1^0;
sbit LCD_RW = P1^1;
sbit LCD_EN = P1^2;
sbit RowA=P3^0;
sbit RowB=P3^1;
sbit RowC=P3^2;
sbit RowD=P3^3;
sbit C1=P3^4;
sbit C2=P3^5;
sbit C3=P3^6;
sbit C4=P3^7;

/*declaring global variables
*intialising values of the variables
*/
char x1='\0',x2='\0',op='\0',x3='\0';
int count=0, p=0, q=0;

/* local function to generate delay */
void delay_us(int cnt)
{
    int i;
    for(i=0;i<cnt;i++);
}

/* Function to send the command to LCD */

void Lcd_CmdWrite( char cmd)
{
    P2=cmd;    					// Send the command to LCD
    LCD_RS=0;          	// Select the Command Register by pulling RS LOW
    LCD_RW=0;          	// Select the Write Operation  by pulling RW LOW
    LCD_EN=1;						// Send a High-to-Low Pusle at Enable Pin
    delay_us(10);				// calling delay function
    LCD_EN=0;						//	Send a low to high pulse at enable pin
}

/*function to write data on lcd*/

void Lcd_DataWrite()
{
		LCD_RS=1;	      		// Select the Data Register by pulling RS HIGH
    LCD_RW=0;          	// Select the Write Operation by pulling RW LOW
    LCD_EN=1;	      		// Send a High-to-Low Pusle at Enable Pin
    delay_us(10);				// calling delay function
    LCD_EN=0;						//	Send a low to high pulse at enable pin

}

/* Function to send the Data to LCD */
/*	counters are used to save the values of in different variables*/
void display( char y)
{
	if(count == 0)				 //if count = 0 then value will be stored in first variable
	{	
		x1=y;
		P2 = x1;						//displaying value of first variable on lcd
		p = x1 -'0';				//converting value  from ascii format to int
		Lcd_DataWrite();		//calling data write function
		count ++;						//increasing the counter so that next value is stored in second variable
		
	}
	else if(count == 1)		//to store the operand and display it if count = 1
	{
		char i,a[]={"Invalid operation"};
		if ( op == '/' || op == '*' || op == '-' || op == '+')    //checks which operand is passed by the keypad
		{
			op = y;									//assigns the operand to op variable
			P2 = op;								//displays the operand on screen
			Lcd_DataWrite();				//calling data write function		
			count++;								// increasing the counter so that next value is stored in third variable
		}
		else											//if value is not an operand then it will display error
		{
			Lcd_CmdWrite(0xc0);        //Go to Next line and display 
			for(i=0;a[i]!=0;i++)			//to display the content of the array a[]
			{
				y=a[i];
        P2=y;										//displays the content of the array on the screen	
				Lcd_DataWrite();				//calling the data write function
			}
		}	
	}
	else if(count == 2)						//to store the value of third variable and display it		
	{
		x2 = y;
		P2 = x2;										//display the value of the third variable on screen 
		q = x2 - '0';								//convert the value of third variable from ascii format to int
		Lcd_DataWrite();						//calling data write function
		count++;										//increasing the counter 
	}	
	else if(count == 3)						//displays = sign on screen
	{
		P2=y;
		Lcd_DataWrite();
		count++;
	}	
	else if (count == 4)					//displays the answer on the screen
	{
		P2=y;
		Lcd_DataWrite();
	}
}
/*Funtion to do the arithmetic calculation
* '0' is added to int to  convert int to ascii format
*/
void result()
{
  int s;
	if(op=='/')							//if op = / ,then division will take place
	{	s = p/q;
		x1 = s + '0';					//converting to ascii format
		display(x1);					//calling display function
	}
	else if(op=='+')				//if op = +,then addition will take place
	{	s = p+q;
		if(s>9)								//if the number is greater than 9 then number is displayed digit by digit
		{
			x1 = s/10 + '0';		// tens' digit
			display(x1);				// passing ten's digit to display function
			x1 = s%10 + '0';		//unit's digit
			display(x1);				//passing unit's digit to display function
		}
		else									//if number is not greater than 9 then it will be displayed directly
		{
			x1 = s + '0';
			display(x1);
		}
	}
	else if(op=='-')				// if op = - ,then subtraction will take place
	{	s = p-q;
		x1 = s + '0';
		display(x1);
	}
	else if(op=='*')			// if op = *,then multiplication will take place
	{	s = p*q;
		if(s>9)							//if value is greater than 9 then value will be displayed digit by digit
		{
			x1 = s/10 + '0';	//tens' digit
			display(x1);			//passing  tens digit to display function
			x1 = s%10 + '0';	//unit's digit
			display(x1);			//passing the units digit
		}
		else								// if it is less than or equal to 9 then it will be displayed directly
		{
			x1 = s + '0';
			display(x1);
		}
	}
		
}

int main()
{
    Lcd_CmdWrite(0x38);        // enable 5x7 mode for chars 
    Lcd_CmdWrite(0x0E);        // display OFF, Cursor ON
    Lcd_CmdWrite(0x01);        // Clear display
    Lcd_CmdWrite(0x80);        // Move the cursor to beginning of first line

	while(1)
	{
		/*Testing row and column
		*if row and column is equal to 0 ,it means that particluar button is pressed*/
		
		RowA = 0; RowB = 1; RowC = 1; RowD = 1; 	//Test Row A

		if (C1 == 0) {while (C1==0); display('7'); }
		if (C2 == 0) {while (C2==0); display('8'); }
		if (C3 == 0) {while (C3==0); display('9'); }
		if (C4 == 0) {while (C4==0); op = '/';display('/'); }

		RowA = 1; RowB = 0; RowC = 1; RowD = 1; 	//Test Row B

		if (C1 == 0) {  while (C1==0); display('4'); }
		if (C2 == 0) {  while (C2==0); display('5'); }
		if (C3 == 0) {  while (C3==0); display('6'); }
		if (C4 == 0) {  while (C4==0);op = '*'; display('*'); }

		RowA = 1; RowB = 1; RowC = 0; RowD = 1; 	//Test Row C

		if (C1 == 0) {  while (C1==0); display('1'); }
		if (C2 == 0) {  while (C2==0); display('2'); }
		if (C3 == 0) {  while (C3==0); display('3'); }
		if (C4 == 0) {  while (C4==0); op = '-';display('-'); }

		RowA = 1; RowB = 1; RowC = 1; RowD = 0; 	//Test Row D

		if (C1 == 0) {  while (C1==0); Lcd_CmdWrite(0x01);x1='\0',x2='\0',op='\0',count=0;x3='\0'; }
		if (C2 == 0) {  while (C2==0); display('0'); }
		if (C3 == 0) {  while (C3==0); display('=');Lcd_CmdWrite(0xc0);result();}
		if (C4 == 0) {  while (C4==0); op = '+';display('+');}

	}
}
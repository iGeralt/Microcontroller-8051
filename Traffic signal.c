/******************************************************************************
 *  File Name : traffic_signal                                                *
 *	Name			: Maurya Sujeet																								  *
 *	Roll no.	:	17BCS016                                                      *
 *	Project		: To make 4 way traffic signal		                              *	
 *  Date			: 12 September 2018                    													*
 *****************************************************************************/
#include<reg51.h>	// Include register definitions for the Intel 8051

/*connect the pins on hardware as per below's pin assingment 
* connect red leds to port 1's 0,3,6 pin and port 2's 1
* connect green leds to port 1's 2,5 pin and port 2's 0,3
* connect yellow leds to port  2's 1,4,7* and port 2's 2*/
sbit R1=P1^0; 
sbit Y1=P1^1; 
sbit G1=P1^2; 
sbit R2=P1^3; 
sbit Y2=P1^4; 
sbit G2=P1^5; 
sbit R3=P1^6; 
sbit Y3=P1^7; 
sbit G3=P2^0; 
sbit R4=P2^1; 
sbit Y4=P2^2; 
sbit G4=P2^3; 

/*Delay function*/

void delay() 
{ 
	int i,j;  
	for(i=0;i<300;i++) 
	for(j=0;j<1000;j++); 
} 

/*clear function to reset all the values*/
void clear() 
{ 
	R1=0; R2=0; R3=0; R4=0; 
	Y1=0; Y2=0; Y3=0; Y4=0; 
	G1=0; G2=0; G3=0; G4=0; 
}  

/*In this phase ,1'st traffic light will have green light on 
* traffic light 2,3 and 4 will be red
* traffic light 2 will be in ready position after certain delay*/
void phase1() 
{ 
	R3=1; 
	R2=1; 
	G1=1; 
	R4=1; 
	delay(); 
	Y2=1; 
	delay(); 
} 
/*In this phase ,2'nd traffic light will have green light on 
* traffic light 1,3 and 4 will be red
* traffic light 3 will be in ready position after certain delay*/
void phase2() 
{ 
	G2=1; R1=1; R3=1; R4=1; 
	delay(); 
	Y3=1; 
	delay();  
} 
/*In this phase ,3rd traffic light will have green light on 
* traffic light 1,2 and 4 will be red
* traffic light 4 will be in ready position after certain delay*/
void phase3() 
{ 
R1=1; G3=1; R2=1; R4=1; 
	delay(); 
	Y4=1; 
	delay();  
} 
/*In this phase 4 traffic light will have green light on 
* traffic light 2,3 and 1 will be red
* traffic light 1 will be in ready position after certain delay*/
void phase4() 
{ 
	R1=1; G4=1; R3=1; R2=1; 
	delay(); 
	Y1=1; 
	delay(); 
} 

void main() 
{
	/*intilising port 1 and port 2 for output*/	
	P1=0x00;
	P2=0x00;
	while(1)  	//infinite low to run the traffic light for infinite time
		{ 
		 phase1();	//calling phase 1
		 clear();		//calling clear function to set all the values of the variable to 0
		 phase2(); 	//calling phase 2
		 clear();		//calling clear function to set all the values of the variable to 0
		 phase3(); 	//calling phase 3
		 clear(); 	//calling clear function to set all the values of the variable to 0
		 phase4(); 	//calling phase 4
		 clear(); 	//calling clear function to set all the values of the variable to 0
		}  

}
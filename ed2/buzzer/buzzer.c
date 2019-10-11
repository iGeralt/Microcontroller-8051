/******************************************************************************
 *  File Name : Buzzer                                                        *
 *	Name			: Maurya Sujeet																								  *
 *	Roll no.	:	17BCS016                                                      *
 *	Project		: To make a Buzzer                                              *
 *  Date			:    November 2018                    													*
 *****************************************************************************/
 /* A Buzzer is connected to portline P0.5. Timer0 is used to generate delay */
 /* to produce a tone. Vary OFF time & ON timer to different tones. */

 #include "at89c51xd2.h"
 #define off_time = 14
 #define on_time = 14

 sbit buzz = P0^5; // Buzzer is connected to the portline P0.5

 idata unsigned int i;
 void main ()
 {

 TMOD = 0x01; // Timer0 is configured in Mode-1,

 TL0 = 0x00; // Load Timer-0 value for 0.7s Delay
 TH0 = 0x00;

 TCON = 0x00; // Clearing All Flags
 TF0 = 0; // Clear Timesr-0 overflow flag


 while(1)
 {

 buzz = 1; // make P2.4 high i.e. Buzzer ON
 for(i=0;i<on_time;i++)
 {
 TL0 = 0x00; // Reload timer count for 2msec
 TH0 = 0x00;
 TR0 =1; // Turn ON timer-0
 while(!TF0); // Wait untill Timer-0 overfolws
 TF0 = 0; // Clear Tiemr-0 overflow flag
 TR0=0; // Turn OFF timer-0
 }


 buzz = 0; // make P2.4 low i.e Buzzer OFF
 for(i=0;i<off_time;i++)
 {
 TL0 = 0x00; // Reload timer count for 2msec
 TH0 = 0x00;
 TR0 =1; // Turn ON timer-0
 while(!TF0); // Wait untill Timer-0 overfolws
 TF0 = 0; // Clear Tiemr-0 overflow flag
 TR0=0; // Turn OFF timer-0
 }

 }
}
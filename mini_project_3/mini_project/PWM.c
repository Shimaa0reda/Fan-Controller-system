/*
 * PWM.c
 *
 *  Created on: Oct 7, 2022
 *      Author: Mahmoud Reda
 */
#include"PWM.h"
#include<avr\io.h>/* to access the registers*/
/*PWM_Timer0_Init
  description: the fun is responsible for initialize the characteristics of the PWM
 input: the port number, pin number and the  wanted direction
  return void
 */
void PWM_Timer0_Init(unsigned char speed)
{//timer start to count from zero
	TCNT0 = 0;

	//Set Compare value
	OCR0  = (speed*255/100);

	//set the pin as output so 	PWM can be read from it
	DDRB  = DDRB | (1<<PB3);

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */

	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

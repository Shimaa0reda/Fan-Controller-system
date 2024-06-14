/*
 * adc.c
 *
 *  Created on: Oct 1, 2022
 *      Author: Mahmoud Reda
 */

#include"adc.h"
#include<avr/io.h>
#include"common_macros.h"
#include <avr/interrupt.h>
//volatile uint16 g_adcResult = 0;
/*DcMotor_Init
 * description: the fun is responsible for initialize ADC characteristics
 *input: pointer to structure which contain the characteristics of the ADC needed for this app
 * return void
 */
void ADC_init(const ADC_ConfigType * Config_Ptr)
{

	ADMUX=(ADMUX&0X3F)|((Config_Ptr->ref_volt)<<6);

	//enable the ADC module
	SET_BIT(ADCSRA,ADEN);

	//to make the driver configurable
	//this condition is activated in case of using interrupt not polling by setting the interrupt enable
#if(INTERRUPT_ENABLE)
	SET_BIT(ADCSRA,ADIF);
#endif

	//to make the driver configurable
	//this condition is activated in case of using toggle pin
#if(ADC_AUTO_TRIGGER)
	SET_BIT(ADCSRA,ADATE);
#endif
	ADMUX=(ADMUX&0XF8)|(Config_Ptr->prescaler);
}


/*ADC_readChannel
 * description: the fun is responsible for read the analog signal
 * from the channel entered and then convert its value to digital using ADC
 *input: the number of channel
 * return the digital value
 */
uint16 ADC_readChannel(uint8 ch_num)
{
	/* Input channel number must be from 0 --> 7 */
	/* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	/* Choose the correct channel by setting the channel number in MUX4:0 bits */
	ADMUX=(ADMUX&0XE0)|(ch_num&0x07);

	//start  the conversion
	SET_BIT(ADCSRA,ADSC);

	//to make the driver configurable
	//this condition is activated in case of using polling
#if(POLLING_ENABLE)

	//wait until ADC finish the conversion
	while(BIT_IS_CLEAR(ADCSRA,ADIF));

	///* Clear ADIF by write '1' to it :) */
	SET_BIT(ADCSRA,ADIF);
#endif

	return ADC;

}

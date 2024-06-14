/*
 * lm_35.c
 *
 *  Created on: Oct 7, 2022
 *      Author: Mahmoud Reda
 */
#include"lm_35.h"
#include"adc.h"
#include<util\delay.h>//to use delay functions
/*LM35_GetTemperature
  description: the fun is responsible for get the signal from temp sensor and pass it to adc to convert it to digital value
 input: void
  return the digital value of temperature
 */
uint8 LM35_GetTemperature(void)
{
	uint8 temp_value = 0;
	uint16 adc_value = 0;

	//pass the number of channel which the sensor connected to ADC to convert the analog signal to digital
	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

	//to make the driver configurable
	//this condition is activated in case of using interrupt
#if(INTERRUPT_ENABLE)
	_delay_ms(5);
#endif

	//equation to calculate the digital value of the temp and then return it
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
	return temp_value;
}


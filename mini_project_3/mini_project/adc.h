/*
 * adc.h
 *
 *  Created on: Oct 1, 2022
 *      Author: Mahmoud Reda
 */

#ifndef ADC_H_
#define ADC_H_
#include"std_types.h"
#define INTERRUPT_ENABLE 0
#define POLLING_ENABLE 1
#define ADC_AUTO_TRIGGER 0
//extern volatile uint16 g_adcResult;
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

//enum which contain all cases of the prescaler
typedef enum
{
	PRESCALER2=1,PRESCALER4,PRESCALER8,PRESCALER16,PRESCALER32,PRESCALER64,PRESCALER128
}ADC_Prescaler;

//enum which contain all cases of the ref volt
typedef enum
{
	AREF,AVCC,RESERVED,INTERNAL
}ADC_ReferenceVolatge;

//structure contain the changing characteristics of adc
typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*ADC_readChannel
 * description: the fun is responsible for read the analog signal
 * from the channel entered and then convert its value to digital using ADC*/
uint16 ADC_readChannel(uint8 ch_num);


/*DcMotor_Init
 * description: the fun is responsible for initialize ADC characteristics*/
void ADC_init(const ADC_ConfigType * Config_Ptr);
#endif /* ADC_H_ */

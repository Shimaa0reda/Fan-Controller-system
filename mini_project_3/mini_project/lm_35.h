/*
 * lm_35.h
 *
 *  Created on: Oct 6, 2022
 *      Author: Mahmoud Reda
 */

#ifndef LM_35_H_
#define LM_35_H_
#include "std_types.h"

/*LM35_GetTemperature
  description: the fun is responsible for get the signal from temp sensor and pass it to adc to convert it to digital value*/
uint8 LM35_GetTemperature(void);

#define SENSOR_CHANNEL_ID 2
#define SENSOR_MAX_TEMPERATURE 150
#define SENSOR_MAX_VOLT_VALUE 1.5

#endif /* LM_35_H_ */

#include"adc.h"
#include"dc_motor.h"
#include"gpio.h"
#include"lcd.h"
#include"lm_35.h"
#include"PWM.h"
int main()
{

	uint8 temp;
	//determine the characteristics of ADC which needed in this app
	ADC_ConfigType  Config_Ptr ={INTERNAL,PRESCALER8};
	/* initialize all the modules used in this app*/
ADC_init(&Config_Ptr);
	DcMotor_Init();
	LCD_init();

	while(1)
	{
		/*first store the value of temp in a variable
		 * */
		temp=LM35_GetTemperature();
		/*if the value of temp less than 30 first stop the motor and print the temp on lcd
		 * */
		if(temp<30)
		{
			DcMotor_Rotate(stop, 0);
			LCD_displayStringRowColumn(0, 3, "FAN IS OFF");
			LCD_displayStringRowColumn(1, 3,"TEMP =");
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

		}
		/*if the value of temp larger than or equal 30 and less than 60 first move the motor clockwise and print the temp on lcd
				 * */
		else if((temp>=30)&&(temp<60))
		{
			//rotate the dc motor with a specific speed
			DcMotor_Rotate(clockwise, 25);
						LCD_displayStringRowColumn(0, 3, "FAN IS ON ");

						LCD_displayStringRowColumn(1, 3,"TEMP =");
						LCD_intgerToString(temp);
						LCD_displayCharacter(' ');

		}
		/*if the value of temp larger than or equal 60 and less than 90 first move the motor clockwise and print the temp on lcd*/
		else if((temp>=60)&&(temp<90))
		{
			DcMotor_Rotate(clockwise, 50);
									LCD_displayStringRowColumn(0, 3, "FAN IS ON ");

									LCD_displayStringRowColumn(1, 3,"TEMP =");
									LCD_intgerToString(temp);
									LCD_displayCharacter(' ');

		}
		/*if the value of temp larger than or equal 90 and less than 120 first move the motor clockwise and print the temp on lcd*/
		else if((temp>=90)&&(temp<120))
		{
			DcMotor_Rotate(clockwise, 75);
									LCD_displayStringRowColumn(0, 3, "FAN IS ON ");

									LCD_displayStringRowColumn(1, 3,"TEMP =");
									LCD_intgerToString(temp);
									LCD_displayCharacter(' ');

		}
		/*if the value of temp larger than or equal 30  first move the motor clockwise and print the temp on lcd*/
		else if((temp>=120))
				{
					DcMotor_Rotate(clockwise, 100);
											LCD_displayStringRowColumn(0, 3, "FAN IS ON");

											LCD_displayStringRowColumn(1, 3,"TEMP =");
											LCD_intgerToString(temp);
											LCD_displayCharacter(' ');

				}
	}


}

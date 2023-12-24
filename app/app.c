/*
 * app.c
 *
 *  Created on: Nov 4, 2023
 *      Author: hamada
 */

#include "app.h"


chr_lcd_4bit_t lcd ;


int main(void)
{
	components_init();






	while(1)
	{


	}


	return 0 ;
}
/*
 * @brief : Initialize any components in our application
 * @param : void
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType components_init(void)
{

	{
		// lcd initialization
		lcd.lcd_rs.port = PORTC_INDEX;
		lcd.lcd_rs.pin = GPIO_PIN0 ;
		lcd.lcd_rs.direction = GPIO_DIRECTION_OUTPUT;
		lcd.lcd_rs.logic = GPIO_LOW;

		lcd.lcd_en.port = PORTC_INDEX;
		lcd.lcd_en.pin = GPIO_PIN1 ;
		lcd.lcd_en.direction = GPIO_DIRECTION_OUTPUT;
		lcd.lcd_en.logic = GPIO_LOW;

		lcd.lcd_data[0].port = PORTC_INDEX ;
		lcd.lcd_data[0].pin = GPIO_PIN2;
		lcd.lcd_data[0].direction = GPIO_DIRECTION_OUTPUT ;
		lcd.lcd_data[0].logic = GPIO_LOW;

		lcd.lcd_data[1].port = PORTC_INDEX ;
		lcd.lcd_data[1].pin = GPIO_PIN3;
		lcd.lcd_data[1].direction = GPIO_DIRECTION_OUTPUT ;
		lcd.lcd_data[1].logic = GPIO_LOW;

		lcd.lcd_data[2].port = PORTC_INDEX ;
		lcd.lcd_data[2].pin = GPIO_PIN4;
		lcd.lcd_data[2].direction = GPIO_DIRECTION_OUTPUT ;
		lcd.lcd_data[2].logic = GPIO_LOW;

		lcd.lcd_data[3].port = PORTC_INDEX ;
		lcd.lcd_data[3].pin = GPIO_PIN5;
		lcd.lcd_data[3].direction = GPIO_DIRECTION_OUTPUT ;
		lcd.lcd_data[3].logic = GPIO_LOW;

		lcd_4bit_intialize(&lcd);
	}



	return E_OK;
}

/**
 * @file main.c
 * @author Ezz
 * @date 2026-08-31
 * @brief Main function
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#define F_CPU 1000000
#include <util/delay.h>
#include "ADC_int.h"
#include "LCD_int.h"
#include "KEYPAD_int.h"
#include "TIMER0_int.h"
#include "TIMER1_int.h"
#include "TIMER0_private.h"
#include "TIMER1_private.h"

int main(){
   
DIO_voidSetPinDirection(DPORTC,PIN0,OUTPUT);		
	while (1)
	{
		DIO_voidSetPinValue(DPORTC,PIN0,HIGH);
		_delay_ms(5000);
		DIO_voidSetPinValue(DPORTC,PIN0,LOW);
		_delay_ms(5000);
	}
		
}






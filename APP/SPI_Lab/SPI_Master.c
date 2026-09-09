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
#include "USART_int.h"
#include "SPI_int.h"

int main(){
   
    
	DIO_voidSetPinDirection(DPORTB, PIN4,OUTPUT);
	DIO_voidSetPinDirection(DPORTB, PIN5,OUTPUT);
	DIO_voidSetPinDirection(DPORTB, PIN6,INPUT);
	DIO_voidSetPinDirection(DPORTB, PIN7,OUTPUT);
	
	SPI_voidInitMaster();
	while (1)
	{
     SPI_voidSendAndReceive('1');
	
     SPI_voidSendAndReceive('2');
	
     SPI_voidSendAndReceive('3');
	 
	
	}
		
}






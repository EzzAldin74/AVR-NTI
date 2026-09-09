/**
 * @file main.c
 * @author Ezz
 * @date 2026-09-09
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

int main(){

    DIO_voidSetPinDirection(DPORTB,PIN0,OUTPUT);
    DIO_voidSetPinDirection(DPORTB,PIN2,OUTPUT);
    DIO_voidSetPinDirection(DPORTB,PIN3,OUTPUT);
    USART_voidInit();
    u8 data_rec=0;
    while(1) {
       data_rec = USART_u8ReceiveChar();
       if (data_rec=='1') {
       DIO_voidTogglePinValue(DPORTB,PIN0);
       }
       else if (data_rec=='2') {
       DIO_voidTogglePinValue(DPORTB,PIN1);
       }
       else if (data_rec=='3') {
       DIO_voidTogglePinValue(DPORTB,PIN2);
       }
       else{

       }
    //    _delay_ms(200);
    }

    return 0;
}

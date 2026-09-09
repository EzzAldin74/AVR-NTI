/**
 * @file main.c
 * @author Ezz
 * @date 2026-08-31
 * @brief Main function
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#define F_CPU  8000000
#include <util/delay.h>
#include "ADC_int.h"
#include "LCD_int.h"
#include "KEYPAD_int.h"
#include "TIMER0_int.h"
#include <avr/interrupt.h>

static u8 count=0;
int main(){
TIMER0_voidInit();
DIO_voidSetPinDirection(DPORTB, PIN7, OUTPUT);
while(1){
 
}
}

ISR(TIMER0_OVF_vect){
    count++;
    if(count==30){
        DIO_voidTogglePinValue(DPORTB,PIN7);
        count=0;
    }
}




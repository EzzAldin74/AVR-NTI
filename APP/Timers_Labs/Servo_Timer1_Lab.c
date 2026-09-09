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
    TIMER0_voidInit();
ADC_voidInit();

TIMER1_voidInit();
DIO_voidSetPinDirection(DPORTD, PIN5, OUTPUT);

while(1){
        
}
}






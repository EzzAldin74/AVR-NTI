/**
 * @file main.c
 * @author Ezz
 * @date 2026-08-31
 * @brief Main function
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include <util/delay.h>
#include "EXTI_int.h"
#include <avr/interrupt.h>
int main(){
    EXTI_voidInti();
    DIO_voidSetPinDirection(DPORTC,PIN0,OUTPUT);
    DIO_voidSetPinDirection(DPORTC,PIN1,OUTPUT);


while(1){

}
}

ISR(INT0_vect){
  DIO_voidTogglePinValue(DPORTC, PIN0);
}

ISR(INT1_vect){
  DIO_voidTogglePinValue(DPORTC, PIN1);
}
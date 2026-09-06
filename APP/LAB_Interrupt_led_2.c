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
#include <avr/interrupt.h>
#include "EXTI_int.h"




const u8 arr [8] = {
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
};
int main(){
    EXTI_voidInit();
    DIO_voidSetPinDirection(DPORTC,PIN0,OUTPUT);
    DIO_voidSetPinDirection(DPORTC,PIN1,OUTPUT);
    DIO_voidSetPinDirection(DPORTC,PIN2,OUTPUT);
    DIO_voidSetPinDirection(DPORTC,PIN3,OUTPUT);
    DIO_voidSetPinDirection(DPORTC,PIN4,OUTPUT);
    DIO_voidSetPinDirection(DPORTC,PIN5,OUTPUT);
    DIO_voidSetPinDirection(DPORTC,PIN6,OUTPUT);
    DIO_voidSetPinDirection(DPORTC,PIN7,OUTPUT);

while(1){
    for(s8 i=0;i<8;i++){
        for(s8 j=0;j<8;j++){
            DIO_voidSetPinValue(DPORTC,arr[j],LOW);
        }
        _delay_ms(2000);
        DIO_voidSetPinValue(DPORTC, arr[i], HIGH);
        _delay_ms(2000);
    }
}
}

ISR(INT0_vect){
    for(s8 i=7;i>=0;i--){
        for(s8 j=7;j>=0;j--){
            DIO_voidSetPinValue(DPORTC,arr[j],LOW);
        }
        _delay_ms(2000);
        DIO_voidSetPinValue(DPORTC, arr[i], HIGH);
        _delay_ms(2000);
    }
}


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

int main(){

DIO_voidDDRInitialization();
DIO_voidSetPinPullUp(DPORTD,PIN1);

while(1){

    //Pull Down External Resistor Test
    if (DIO_u8ReadPinValue(DPORTA,PIN1)==HIGH) {
        DIO_voidSetPinValue(DPORTB, PIN0,HIGH);
    }
    else if (DIO_u8ReadPinValue(DPORTA,PIN1)==LOW) {
        DIO_voidSetPinValue(DPORTB, PIN0,LOW);
    }

    //Pull Up Internal Resistor Test
    if (DIO_u8ReadPinValue(DPORTD,PIN1)==LOW) {
        DIO_voidSetPinValue(DPORTB, PIN0,HIGH);
    }
    else if (DIO_u8ReadPinValue(DPORTD,PIN1)==HIGH) {
        DIO_voidSetPinValue(DPORTB, PIN0,LOW);
    }
    
}
}
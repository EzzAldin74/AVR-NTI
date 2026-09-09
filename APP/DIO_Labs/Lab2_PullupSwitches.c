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
DIO_voidSetPinPullUp(DPORTA,PIN0);
DIO_voidSetPinPullUp(DPORTA,PIN1);
DIO_voidSetPinPullUp(DPORTA,PIN2);
DIO_voidSetPinPullUp(DPORTA,PIN3);
while(1){

    //SW1
    if (DIO_u8ReadPinValue(DPORTA,PIN0)==LOW) {
        DIO_voidSetPinValue(DPORTC, PIN0,HIGH);
    }
    else if (DIO_u8ReadPinValue(DPORTA,PIN0)==HIGH) {
        DIO_voidSetPinValue(DPORTC, PIN0,LOW);
    }
    else{
        /*NOCODE*/
    }

    //SW2
    if (DIO_u8ReadPinValue(DPORTA,PIN1)==LOW) {
        DIO_voidSetPinValue(DPORTC, PIN1,HIGH);
    }
    else if (DIO_u8ReadPinValue(DPORTA,PIN1)==HIGH) {
        DIO_voidSetPinValue(DPORTC, PIN1,LOW);
    }
    else{
        /*NOCODE*/
    }

    //SW3
    if (DIO_u8ReadPinValue(DPORTA,PIN2)==LOW) {
        DIO_voidSetPinValue(DPORTC, PIN2,HIGH);
    }
    else if (DIO_u8ReadPinValue(DPORTA,PIN2)==HIGH) {
        DIO_voidSetPinValue(DPORTC, PIN2,LOW);
    }
    else{
        /*NOCODE*/
    }

    //SW4
    if (DIO_u8ReadPinValue(DPORTA,PIN3)==LOW) {
        DIO_voidSetPinValue(DPORTC, PIN0,HIGH);
        DIO_voidSetPinValue(DPORTC, PIN1,HIGH);
        DIO_voidSetPinValue(DPORTC, PIN2,HIGH);
    }
    else if (DIO_u8ReadPinValue(DPORTA,PIN2)==HIGH) {
        DIO_voidSetPinValue(DPORTC, PIN0,LOW);
        DIO_voidSetPinValue(DPORTC, PIN1,LOW);
        DIO_voidSetPinValue(DPORTC, PIN2,LOW);
    }
    else{
        /*NOCODE*/
    }


}
}
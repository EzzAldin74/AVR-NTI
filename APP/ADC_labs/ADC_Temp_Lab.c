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
#include "ADC_int.h"





int main(){

DIO_voidSetPinDirection(DPORTC,PIN0,OUTPUT);
DIO_voidSetPinDirection(DPORTC,PIN1,OUTPUT);
DIO_voidSetPinDirection(DPORTC,PIN2,OUTPUT);
ADC_voidInit();

while(1){
        u16 adc_value = ADC_u16Read();

       
        if (adc_value>0 && adc_value <= 41) {
           
            DIO_voidSetPinValue(DPORTC, PIN0, HIGH);
            DIO_voidSetPinValue(DPORTC, PIN1, LOW);
            DIO_voidSetPinValue(DPORTC, PIN2, LOW);
        }
        else if (adc_value >= 42 && adc_value <= 82) {
            
            DIO_voidSetPinValue(DPORTC, PIN0, LOW);
            DIO_voidSetPinValue(DPORTC, PIN1, HIGH);
            DIO_voidSetPinValue(DPORTC, PIN2, LOW);
        }
        else if (adc_value >= 83) {
            
            DIO_voidSetPinValue(DPORTC, PIN0, LOW);
            DIO_voidSetPinValue(DPORTC, PIN1, LOW);
            DIO_voidSetPinValue(DPORTC, PIN2, HIGH);
        }
        else {
            DIO_voidSetPinValue(DPORTC, PIN0, LOW);
            DIO_voidSetPinValue(DPORTC, PIN1, LOW);
            DIO_voidSetPinValue(DPORTC, PIN2, LOW);
        }
    } 
    
}



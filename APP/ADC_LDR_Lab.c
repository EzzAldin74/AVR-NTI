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
#include "LCD_int.h"





int main(){
DIO_voidSetPinDirection(DPORTD, PIN3, OUTPUT);
LCD_voidInit();
ADC_voidInit();

while(1){
         u16 adc_value = ADC_u16Read();
         u32 VOLT_value = ((u32)adc_value*5000UL)/1023UL;
        LCD_voidWriteNumber(VOLT_value);
        LCD_voidWriteString((u8*)"mV");
        if(adc_value<=410)
         {
            DIO_voidSetPinValue(DPORTD,PIN3,HIGH);
         }
         else {
            DIO_voidSetPinValue(DPORTD,PIN3,LOW);
         }
        
         _delay_ms(1000);
         LCD_voidWriteCommand(CLEAR_DISPLAY);
}


}



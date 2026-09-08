#include "STD_TYPES.h"
#include "BIT_MATH.h"
//Driver files
#include "DIO_int.h"
#include "ADC_int.h"
#include "ADC_private.h"
#include "ADC_config.h"

void ADC_voidInit(void){
    //make the pin for the selected ADC channel as input pin
    DIO_voidSetPinDirection(DPORTA,PIN0,INPUT);
    //Turn on the ADC module 
    SET_BIT(ADCSRA,ADEN);
    //Prescalar Selection //DIV by 128 
    SET_BIT(ADCSRA,ADPS0);
    SET_BIT(ADCSRA,ADPS1);
    SET_BIT(ADCSRA,ADPS2);
    //select voltage reference AVCC with external capacitor at AREF pin
    SET_BIT(ADMUX,REFS0);
    CLR_BIT(ADMUX,REFS1);
    //Select the ADC input channel in ADMUX
    CLR_BIT(ADMUX,MUX0);
    CLR_BIT(ADMUX,MUX1);
    CLR_BIT(ADMUX,MUX2);
    CLR_BIT(ADMUX,MUX3);
    CLR_BIT(ADMUX,MUX4);
    //activate the start conversion bit 
    SET_BIT(ADCSRA,ADSC);
    //
    CLR_BIT(ADMUX,ADLAR);
}

u16 ADC_u16Read(void){
    //activate the start conversion bit 
    SET_BIT(ADCSRA,ADSC);
    u16 read_reg=0x0000;
        while (!READ_BIT(ADCSRA,ADIF)) {
        
        }
        read_reg  =  ADCL;
        read_reg |= (ADCH<<8);
    SET_BIT(ADCSRA,ADIF);
        return read_reg;
        
}
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//Driver files
#include "DIO_int.h"
#include "TIMER1_int.h"
#include "TIMER1_private.h"
#include "TIMER1_config.h"

void TIMER1_voidInit(void){
    //Set the prescalar at 8
    CLR_BIT(TCCR1B,CS10);
    SET_BIT(TCCR1B,CS11);
    CLR_BIT(TCCR1B,CS12);

    CLR_BIT(TCCR1A,WGM10);
    SET_BIT(TCCR1A,WGM11);
    SET_BIT(TCCR1B,WGM12);
    SET_BIT(TCCR1B,WGM13);

    CLR_BIT(TCCR1A,COM1A0);
    SET_BIT(TCCR1A,COM1A1);
    //2499
    ICR1H=0b00001001;
    ICR1L=0b11000011;
    //187
    OCR1AH=0x00;
    OCR1AL=186;

}
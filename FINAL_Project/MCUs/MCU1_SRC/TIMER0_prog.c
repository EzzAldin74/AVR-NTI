#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_int.h"

#include "TIMER0_int.h"
#include "TIMER0_config.h"
#include "TIMER0_private.h"

void TIMER0_voidInit(void)
{
    if(TIMER0_MODE==CTC)
    {
        Set_Bit(TCCR0, 3);
        Clear_Bit(TCCR0, 6);

        Set_Bit(TIMSK, 1);
        Set_Bit(TCCR0, 0);
        Clear_Bit(TCCR0, 1);
        Set_Bit(TCCR0, 2);
    }
    else
    {
        Clear_Bit(TCCR0, 3);
        Clear_Bit(TCCR0, 6);
    }

}

void TIMER0_voidDelay1Sec(void)
{

    //prescalar 1024 , tick time 1024/8mhz = 128micro sec
    Set_Bit(TCCR0, 0);
    Clear_Bit(TCCR0, 1);
    Set_Bit(TCCR0, 2);

    for(u8 count = 0; count < 50; count++)
    {
        //start from 100 and when reach 256 overflow , okay u now access 156 tik in one count , at 50 count u achieve 7800 tik an tik time is 128micro
        //it equal now 1sec  
        TCNT0 = 256-156;
        //wait until overflow flag becomes 1
        while(Get_Bit(TIFR, 0) == 0);
        //clear the flag from bit TOV0 for next iteration
        Set_Bit(TIFR, 0);
    }
    //stop the timer
    TCCR0 &= 0xF8;
}

void TIMER0_voidSetCompare(u8 Val)
{
    OCR0 = Val;
}



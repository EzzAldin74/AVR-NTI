#include "STD_TYPES.h"
#include "BIT_MATH.h"
//Driver files
#include "DIO_int.h"
#include "TIMER0_int.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"

void TIMER0_voidInit(void){
    //Set the prescalar at 1024
   SET_BIT(TCCR0,CS00);
   CLR_BIT(TCCR0,CS01);
   SET_BIT(TCCR0,CS02);
    //Set the PIE
   #if  TIMER_MODE==OVF
   SET_BIT(TIMSK,TOIE0);
   #elif TIMER_MODE==CTC
   CLR_BIT(TCCR0,WGM00);
   SET_BIT(TCCR0,WGM01);

        #if   OC0_MODE==NORMAL
            CLR_BIT(TCCR0,COM00);
            CLR_BIT(TCCR0,COM01);
        #elif OC0_MODE==TOGGLE
            SET_BIT(TCCR0,COM00);
            CLR_BIT(TCCR0,COM01);
        // #elif OC0_MODE==CLEAR
        //     CLR_BIT(TCCR0,COM00);
        //     SET_BIT(TCCR0,COM01);
        // #elif OC0_MODE==SET
        //     SET_BIT(TCCR0,COM00);
        //     SET_BIT(TCCR0,COM01);
        #endif
   #endif
    //Set the GIE
   SET_BIT(SREG,IBIT);
}
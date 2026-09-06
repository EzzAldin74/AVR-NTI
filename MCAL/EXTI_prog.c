#include "STD_TYPES.h"
#include "BIT_MATH.h"
//Driver files
#include "DIO_int.h"
#include "EXTI_int.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include <avr/interrupt.h>

void EXTI_voidInit(void){

DIO_voidSetPinPullUp(DPORTD, PIN2);
DIO_voidSetPinPullUp(DPORTD, PIN3);
DIO_voidSetPinDirection(DPORTD,PIN2,INPUT);
DIO_voidSetPinDirection(DPORTD,PIN3,INPUT);


SET_BIT(GICR,INT0);
SET_BIT(GICR,INT1);

SET_BIT(MCUCR,ISC00);
CLR_BIT(MCUCR,ISC01);
SET_BIT(MCUCR,ISC10);
CLR_BIT(MCUCR,ISC11);

SET_BIT(SREG,IBIT);

}
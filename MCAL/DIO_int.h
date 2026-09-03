#ifndef _DIO_INT_H_ 
#define _DIO_INT_H_ 

//PIN OR PORT
#define INPUT 0
#define OUTPUT 1

//5 V OR ZERO V
#define LOW 0
#define HIGH 1

//BIT NUMBER
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

// DPORT referes to PORT&DDR&PIN as a single element
#define DPORTA 0
#define DPORTB 1
#define DPORTC 2
#define DPORTD 3



void DIO_voidDDRInitialization(void);

void DIO_voidSetPinDirection(u8 PortID,u8 PinID,u8 Direction);
void DIO_voidSetPinValue(u8 PortID,u8 PinID,u8 value);
u8 DIO_u8ReadPinValue(u8 PortID,u8 PinID);

void DIO_voidSetPinPullUp(u8 PortID,u8 PinID);

void DIO_voidSetPortDirection(u8 PortID,u8 Direction);
void DIO_voidSetPortValue(u8 PortID,u8 Value);
u8 DIO_u8ReadPortValue(u8 PortID);

#endif
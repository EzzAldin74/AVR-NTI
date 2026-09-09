#ifndef _TIMER1_PRIVATE_
#define _TIMER1_PRIVATE_


#define TCCR1A    *((volatile u8*) 0x4F)
#define TCCR1B    *((volatile u8*) 0x4E)
#define TCNT1H    *((volatile u8*) 0x4D)
#define TCNT1L    *((volatile u8*) 0x4C)
#define ICR1H     *((volatile u8*) 0x47)
#define ICR1L     *((volatile u8*) 0x46)
#define TIMSK     *((volatile u8*) 0x59)
#define SREG      *((volatile u8*) 0x5F)
#define OCR1AH    *((volatile u8*) 0x4B)
#define OCR1AL    *((volatile u8*) 0x4A)
#define OCR1BH    *((volatile u8*) 0x49)
#define OCR1BL    *((volatile u8*) 0x48)

#define WGM10  0
#define WGM11  1
#define WGM12  3
#define WGM13  4

#define COM1A0  6
#define COM1A1  7

#define CS10   0    
#define CS11   1
#define CS12   2

#define IBIT   7



#endif
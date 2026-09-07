#ifndef _EXTI_PRIVATE_
#define _EXTI_PRIVATE_


#define MCUCSR  *((volatile u8*)0x54)
#define MCUCR   *((volatile u8*)0x55)
#define GIFR    *((volatile u8*)0x5A)
#define GICR    *((volatile u8*)0x5B)
#define SREG    *((volatile u8*)0x5F)


// MCUCR Bits
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3

// MCUCSR Bits
#define ISC2    6

// GICR Bits
#define INT0    6
#define INT1    7
#define INT2    5

#define IBIT    7

#endif
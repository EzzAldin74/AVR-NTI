#ifndef _EXTI_PRIVATE_
#define _EXTI_PRIVATE_

#define MCUCR   *((volatile u8*)0x55)
#define MCUCSR  *((volatile u8*)0x54)
#define SREG    *((volatile u8*)0x5F)
#define GICR    *((volatile u8*)0x5B)
#define GIFR    *((volatile u8*)0x5A)

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

#define IBIT 7

#endif
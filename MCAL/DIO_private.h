#ifndef _DIO_PRIVATE_H_ 
#define _DIO_PRIVATE_H_ 

#define PIND     *((volatile u8*)0x30)
#define DDRD     *((volatile u8*)0x31)
#define PORTD    *((volatile u8*)0x32)

#define PINC     *((volatile u8*)0x33)
#define DDRC     *((volatile u8*)0x34)
#define PORTC    *((volatile u8*)0x35)

#define PINB     *((volatile u8*)0x36)
#define DDRB     *((volatile u8*)0x37)
#define PORTB    *((volatile u8*)0x38)

#define PINA     *((volatile u8*)0x39)
#define DDRA     *((volatile u8*)0x3A)
#define PORTA    *((volatile u8*)0x3B)


#define HELPER_CONCAT(b7, b6, b5, b4, b3, b2, b1, b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONCAT(b7, b6, b5, b4, b3, b2, b1, b0)        HELPER_CONCAT(b7, b6, b5, b4, b3, b2, b1, b0)

#define DIO_PA_DIR CONCAT(DIO_PA7_DIR, DIO_PA6_DIR, DIO_PA5_DIR, DIO_PA4_DIR, DIO_PA3_DIR, DIO_PA2_DIR, DIO_PA1_DIR, DIO_PA0_DIR)
#define DIO_PB_DIR CONCAT(DIO_PB7_DIR, DIO_PB6_DIR, DIO_PB5_DIR, DIO_PB4_DIR, DIO_PB3_DIR, DIO_PB2_DIR, DIO_PB1_DIR, DIO_PB0_DIR)
#define DIO_PC_DIR CONCAT(DIO_PC7_DIR, DIO_PC6_DIR, DIO_PC5_DIR, DIO_PC4_DIR, DIO_PC3_DIR, DIO_PC2_DIR, DIO_PC1_DIR, DIO_PC0_DIR)
#define DIO_PD_DIR CONCAT(DIO_PD7_DIR, DIO_PD6_DIR, DIO_PD5_DIR, DIO_PD4_DIR, DIO_PD3_DIR, DIO_PD2_DIR, DIO_PD1_DIR, DIO_PD0_DIR)

#endif

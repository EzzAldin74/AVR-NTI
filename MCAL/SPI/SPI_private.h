#ifndef _SPI_PRIVATE_
#define _SPI_PRIVATE_


#define SPCR     *((volatile u8*) 0x2D)
#define SPSR     *((volatile u8*) 0x2E)
#define SPDR     *((volatile u8*) 0x2F)

//BITS FOR SPCR
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7
//BITS FOR SPSR
#define SPI2X   0
#define WCOL    6
#define SPIF    7
//BITS FOR SPDR
#define LSB    0
#define MSB    7


#endif
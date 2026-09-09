#include "STD_TYPES.h"
#include "BIT_MATH.h"
//Driver files
#include "DIO_int.h"
#include "SPI_int.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_voidInitMaster(void){
  //SPI Enable
  SET_BIT(SPCR,SPE);
  //the MSB of the data word is transmitted first.
  CLR_BIT(SPCR,DORD);
  // Master SPI mode
  SET_BIT(SPCR,MSTR);
  //SCK is low when idle.
  CLR_BIT(SPCR,CPOL);
  //Leading (Positive) Edge Sample
  CLR_BIT(SPCR,CPHA);
  //SPI Clock Rate
  CLR_BIT(SPCR,SPR0);
  CLR_BIT(SPCR,SPR1);
  CLR_BIT(SPSR,SPI2X);

}

void SPI_voidInitSlave(void){
  //SPI Enable
  SET_BIT(SPCR,SPE);
  //the MSB of the data word is transmitted first.
  CLR_BIT(SPCR,DORD);
  // Slave SPI mode
  CLR_BIT(SPCR,MSTR);
  //SCK is low when idle.
  CLR_BIT(SPCR,CPOL);
  //Leading (Positive) Edge Sample
  CLR_BIT(SPCR,CPHA);
  //SPI Clock Rate
  CLR_BIT(SPCR,SPR0);
  CLR_BIT(SPCR,SPR1);
  CLR_BIT(SPSR,SPI2X);

}

u8 SPI_voidSendAndReceive(u8 send_data){
    SPDR=send_data;
    while(READ_BIT(SPSR,SPIF)==LOW);
    u8 received_data=SPDR;
    return received_data;
  }


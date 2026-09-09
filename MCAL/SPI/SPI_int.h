#ifndef _SPI_INT_
#define _SPI_INT_

void SPI_voidInitMaster(void);
void SPI_voidInitSlave(void);
u8 SPI_voidSendAndReceive(u8 send_data);

#endif
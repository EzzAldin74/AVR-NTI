#include "STD_TYPES.h"
#include "BIT_MATH.h"
//Driver files
#include "DIO_int.h"
#include "USART_int.h"
#include "USART_private.h"
#include "USART_config.h"

void USART_voidInit(void){
   //he URSEL must be one when writing the UCSRC
   SET_BIT(UCSRC,URSEL);
   //Asynchronous Operation
   CLR_BIT(UCSRC,UMSEL);
  //Disabled Parity Mode
   CLR_BIT(UCSRC,UPM0);
   CLR_BIT(UCSRC,UPM1);
  //Stop Bit Select 1bit
   CLR_BIT(UCSRC,USBS);
  //Sets the number of data bits 8bit
   SET_BIT(UCSRC,UCSZ0);
   SET_BIT(UCSRC,UCSZ1);
   CLR_BIT(UCSRB,UCSZ2);
   //USART Baud Rate Register 9600bps
   UBRRL=6;
   //Transmitter Enable
   SET_BIT(UCSRB,TXEN);
   //Receiver Enable
   SET_BIT(UCSRB,RXEN);
}

void USART_voidSendChar(u8 send_data){
    while(READ_BIT(UCSRA,UDRE)==LOW);
    UDR=send_data;
}

u8 USART_u8ReceiveChar(void){
   u8 read_Data=0; 
   //This flag bit is set when there are unread data لما يبقي في داتا لسه متقراتش فبتكون ب1 ولما الدتا تتقري بتبقي ب0  
  while(READ_BIT(UCSRA,RXC)==LOW);
    read_Data=UDR;
  return read_Data;
}
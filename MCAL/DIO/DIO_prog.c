//Service files
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//Driver files
#include "DIO_int.h"
#include "DIO_config.h"
#include "DIO_private.h"

void DIO_voidDDRInitialization(void){
    DDRA = DIO_PA_DIR;
    DDRB = DIO_PB_DIR;
    DDRC = DIO_PC_DIR;
    DDRD = DIO_PD_DIR;
}
                            // PortID referes to the DDR&PORT&PIN as a single element 
                            // PinID  referes to the number of the bit want to change

void DIO_voidSetPinDirection(u8 PortID,u8 PinID,u8 Direction){
    if(PortID<4 && PinID<8){
        if(Direction==OUTPUT){ // OUTPUT MEANS 1 IN DDR LET'S USE SET_BIT
            switch(PortID){
                case DPORTA: SET_BIT(DDRA,PinID); break;
                case DPORTB: SET_BIT(DDRB,PinID); break;
                case DPORTC: SET_BIT(DDRC,PinID); break;
                case DPORTD: SET_BIT(DDRD,PinID); break;
            }
        }
        else if (Direction==INPUT){
            switch(PortID){  // INPUT MEANS 0 IN DDR LET'S USE CLR_BIT
                case DPORTA: CLR_BIT(DDRA,PinID); break;
                case DPORTB: CLR_BIT(DDRB,PinID); break;
                case DPORTC: CLR_BIT(DDRC,PinID); break;
                case DPORTD: CLR_BIT(DDRD,PinID); break;
            }
        }
        else{
            /*NOCODE*/
        }
    }
    else{
        /*NOCODE*/
    }
}

void DIO_voidSetPinValue(u8 PortID,u8 PinID,u8 Value){ 
    if(PortID<4 && PinID<8){
        if(Value==HIGH){
            switch(PortID){ // 
                case DPORTA: SET_BIT(PORTA,PinID); break;
                case DPORTB: SET_BIT(PORTB,PinID); break;
                case DPORTC: SET_BIT(PORTC,PinID); break;
                case DPORTD: SET_BIT(PORTD,PinID); break;
            }
        }
        else if (Value==LOW){
            switch(PortID){
                case DPORTA: CLR_BIT(PORTA,PinID); break;
                case DPORTB: CLR_BIT(PORTB,PinID); break;
                case DPORTC: CLR_BIT(PORTC,PinID); break;
                case DPORTD: CLR_BIT(PORTD,PinID); break;
            }
        }
        else{
            /*NOCODE*/
        }
    }
    else{
        /*NOCODE*/
    }
}

u8 DIO_u8ReadPinValue(u8 PortID,u8 PinID){
   u8 PinValue=0;
   if(PortID<4 && PinID<8){
            switch(PortID){
                case DPORTA:PinValue = READ_BIT(PINA,PinID); break;
                case DPORTB:PinValue = READ_BIT(PINB,PinID); break;
                case DPORTC:PinValue = READ_BIT(PINC,PinID); break;
                case DPORTD:PinValue = READ_BIT(PIND,PinID); break;
     }
    }
    else{
        /*NOCODE*/
    } 
    return PinValue;
}

void DIO_voidTogglePinValue(u8 PortID,u8 PinID){

   if(PortID<4 && PinID<8){
            switch(PortID){
                case DPORTA:TOGGLE_BIT(PORTA,PinID); break;
                case DPORTB:TOGGLE_BIT(PORTB,PinID); break;
                case DPORTC:TOGGLE_BIT(PORTC,PinID); break;
                case DPORTD:TOGGLE_BIT(PORTD,PinID); break;
     }
    }
    else{
        /*NOCODE*/
    } 
}

//after initialization u can change the direction and don't depend on the config 
void DIO_voidSetPortDirection(u8 PortID,u8 Direction){
    if(PortID<4){
        if(Direction==OUTPUT){ // OUTPUT MEANS 1 IN DDR LET'S USE SET_BIT
            switch(PortID){
                case DPORTA: SET_REG(DDRA); break;
                case DPORTB: SET_REG(DDRB); break;
                case DPORTC: SET_REG(DDRC); break;
                case DPORTD: SET_REG(DDRD); break;
            }
        }
        else if (Direction==INPUT){
            switch(PortID){  // INPUT MEANS 0 IN DDR LET'S USE CLR_BIT
                case DPORTA: CLR_REG(DDRA); break;
                case DPORTB: CLR_REG(DDRB); break;
                case DPORTC: CLR_REG(DDRC); break;
                case DPORTD: CLR_REG(DDRD); break;
            }
        }
        else{
             /*NOCODE*/
        }
    }
    else{
        /*NOCODE*/
    } 
}


u8 DIO_u8ReadPortValue(u8 PortID){
    u8 PortValue=0x00;
   if(PortID<4){
            switch(PortID){
                case DPORTA:PortValue = READ_REG(PINA); break;
                case DPORTB:PortValue = READ_REG(PINB); break;
                case DPORTC:PortValue = READ_REG(PINC); break;
                case DPORTD:PortValue = READ_REG(PIND); break;
     }
    }
    else{
        /*NOCODE*/
    } 
    return PortValue;
}

void DIO_voidSetPinPullUp(u8 PortID,u8 PinID){
     DIO_voidSetPinValue(PortID,PinID,HIGH);
}

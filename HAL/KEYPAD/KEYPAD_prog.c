//Service files
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//MCAL file
#include "DIO_int.h"
//Driver files
#include "KEYPAD_int.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"

//HAL file
//GLOBAL file
#include <util/delay.h>

void KEYPAD_voidInit(){
    DIO_voidDDRInitialization();
    
    DIO_voidSetPinPullUp(KEYPAD_A_PORTID, KEYPAD_A_PINID);
    DIO_voidSetPinPullUp(KEYPAD_B_PORTID, KEYPAD_B_PINID);
    DIO_voidSetPinPullUp(KEYPAD_C_PORTID, KEYPAD_C_PINID);
    DIO_voidSetPinPullUp(KEYPAD_D_PORTID, KEYPAD_D_PINID);

    DIO_voidSetPinDirection(KEYPAD_A_PORTID, KEYPAD_A_PINID, INPUT);
    DIO_voidSetPinDirection(KEYPAD_B_PORTID, KEYPAD_B_PINID, INPUT);
    DIO_voidSetPinDirection(KEYPAD_C_PORTID, KEYPAD_C_PINID, INPUT);
    DIO_voidSetPinDirection(KEYPAD_D_PORTID, KEYPAD_D_PINID, INPUT);
    DIO_voidSetPinDirection(KEYPAD_1_PORTID, KEYPAD_1_PINID, OUTPUT);
    DIO_voidSetPinDirection(KEYPAD_2_PORTID, KEYPAD_2_PINID, OUTPUT);
    DIO_voidSetPinDirection(KEYPAD_3_PORTID, KEYPAD_3_PINID, OUTPUT);
    DIO_voidSetPinDirection(KEYPAD_4_PORTID, KEYPAD_4_PINID, OUTPUT);
}


u8 KEYPAD_u8GetButton(){
    for(s8 i=0;i<KEYPAD_COLUMN_NUM;i++){
        DIO_voidSetPinValue(KEYPAD_1_PORTID,KEYPAD_1_PINID,HIGH);
        DIO_voidSetPinValue(KEYPAD_2_PORTID,KEYPAD_2_PINID,HIGH);
        DIO_voidSetPinValue(KEYPAD_3_PORTID,KEYPAD_3_PINID,HIGH);
        DIO_voidSetPinValue(KEYPAD_4_PORTID,KEYPAD_4_PINID,HIGH);

        DIO_voidSetPinValue(KEYPAD_Au8_OUTPUTS_PORTID[i],KEYPAD_Au8_OUTPUTS_PINID[i],LOW);

        for (s8 j=0;j<KEYPAD_ROW_NUM;j++) {
            if(DIO_u8ReadPinValue(KEYPAD_Au8_INPUTS_PORTID[j],KEYPAD_Au8_INPUTS_PINID[j])==LOW){
                _delay_ms(20);
                while(DIO_u8ReadPinValue(KEYPAD_Au8_INPUTS_PORTID[j],KEYPAD_Au8_INPUTS_PINID[j])==LOW){
                        //For time release and bouncing 
                }
                return KEYPAD_u8Buttons[j][i];
            }
            else{
                /**/
            }
        }
    }
    return 0x00 ;

}
//Service files
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//Driver files
#include "SEVEN_SEG_int.h"
#include "SEVEN_SEG_config.h"
#include "SEVEN_SEG_private.h"
//MCAL file
#include "DIO_int.h"
void SEVEN_SEG_voidInit(){
    DIO_voidDDRInitialization();
}

void SEVEN_SEG_voidSetValue(u8 Num){
    // if(){
        DIO_voidSetPinValue(SEG_A_PORTID,SEG_A_PINID,(READ_BIT(SevSegCode[Num],SEG_A_PINID)));
        DIO_voidSetPinValue(SEG_B_PORTID,SEG_B_PINID,(READ_BIT(SevSegCode[Num],SEG_B_PINID)));
        DIO_voidSetPinValue(SEG_C_PORTID,SEG_C_PINID,(READ_BIT(SevSegCode[Num],SEG_C_PINID)));
        DIO_voidSetPinValue(SEG_D_PORTID,SEG_D_PINID,(READ_BIT(SevSegCode[Num],SEG_D_PINID)));
        DIO_voidSetPinValue(SEG_E_PORTID,SEG_E_PINID,(READ_BIT(SevSegCode[Num],SEG_E_PINID)));
        DIO_voidSetPinValue(SEG_F_PORTID,SEG_F_PINID,(READ_BIT(SevSegCode[Num],SEG_F_PINID)));
        DIO_voidSetPinValue(SEG_G_PORTID,SEG_G_PINID,(READ_BIT(SevSegCode[Num],SEG_G_PINID)));
        // }
        // else{
        //     /*NOCODE*/
        // }
}


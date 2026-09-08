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
    DIO_voidSetPinDirection(SEG_A_PORTID,SEG_A_PINID,OUTPUT);
    DIO_voidSetPinDirection(SEG_B_PORTID,SEG_B_PINID,OUTPUT);
    DIO_voidSetPinDirection(SEG_C_PORTID,SEG_C_PINID,OUTPUT);
    DIO_voidSetPinDirection(SEG_D_PORTID,SEG_D_PINID,OUTPUT);
    DIO_voidSetPinDirection(SEG_E_PORTID,SEG_E_PINID,OUTPUT);
    DIO_voidSetPinDirection(SEG_F_PORTID,SEG_F_PINID,OUTPUT);
    DIO_voidSetPinDirection(SEG_G_PORTID,SEG_G_PINID,OUTPUT);
}

void SEVEN_SEG_voidDisplay(u8 val){
        u8 BinaryCode = SEVEN_SEG_u8GetBitCode(val);
        DIO_voidSetPinValue(SEG_A_PORTID,SEG_A_PINID,(READ_BIT(BinaryCode,SEG_A_PINID)));
        DIO_voidSetPinValue(SEG_B_PORTID,SEG_B_PINID,(READ_BIT(BinaryCode,SEG_B_PINID)));
        DIO_voidSetPinValue(SEG_C_PORTID,SEG_C_PINID,(READ_BIT(BinaryCode,SEG_C_PINID)));
        DIO_voidSetPinValue(SEG_D_PORTID,SEG_D_PINID,(READ_BIT(BinaryCode,SEG_D_PINID)));
        DIO_voidSetPinValue(SEG_E_PORTID,SEG_E_PINID,(READ_BIT(BinaryCode,SEG_E_PINID)));
        DIO_voidSetPinValue(SEG_F_PORTID,SEG_F_PINID,(READ_BIT(BinaryCode,SEG_F_PINID)));
        DIO_voidSetPinValue(SEG_G_PORTID,SEG_G_PINID,(READ_BIT(BinaryCode,SEG_G_PINID)));
       
}

static u8 SEVEN_SEG_u8GetBitCode (u8 value){
    u8 local_tmp = 0;
        switch (value) {
            case  0 :case '0':local_tmp = SevSegCode[0]; break;
            case  1 :case '1':local_tmp = SevSegCode[1]; break;
            case  2 :case '2':local_tmp = SevSegCode[2]; break;
            case  3 :case '3':local_tmp = SevSegCode[3]; break;
            case  4 :case '4':local_tmp = SevSegCode[4]; break;
            case  5 :case '5':local_tmp = SevSegCode[5]; break;
            case  6 :case '6':local_tmp = SevSegCode[6]; break;
            case  7 :case '7':local_tmp = SevSegCode[7]; break;
            case  8 :case '8':local_tmp = SevSegCode[8]; break;
            case  9 :case '9':local_tmp = SevSegCode[9]; break; 
            case 'A':case 'a':local_tmp = SevSegCode[10];break;
            case 'B':case 'b':local_tmp = SevSegCode[11];break;
            case 'C':case 'c':local_tmp = SevSegCode[12];break;
            case 'D':case 'd':local_tmp = SevSegCode[13];break;
            case 'E':case 'e':local_tmp = SevSegCode[14];break;
            case 'F':case 'f':local_tmp = SevSegCode[15];break;
            case '-'         :local_tmp = SevSegCode[16];break;
            case '='         :local_tmp = SevSegCode[17];break;
            default          :local_tmp = 0x00;break;
        }
    return local_tmp;
}



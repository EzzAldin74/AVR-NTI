//Service files
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//Driver files
#include "LCD_int.h"
#include "LCD_config.h"
#include "LCD_private.h"
//MCAL file
#include "DIO_int.h"
#include <util/delay.h>
//Global LIB
#define _GNU_SOURCE
#include <stdlib.h>

void LCD_voidInit (){
    // DIO_voidDDRInitialization();
    //CTR PINS
    DIO_voidSetPinDirection(RS_PORTID, RS_PINID, OUTPUT);
    DIO_voidSetPinDirection(RW_PORTID, RW_PINID, OUTPUT);
    DIO_voidSetPinDirection(EN_PORTID, EN_PINID, OUTPUT);
    //DATA PINS
    DIO_voidSetPinDirection(LCD_D0_PORTID,LCD_D0_PINID,OUTPUT);
    DIO_voidSetPinDirection(LCD_D1_PORTID,LCD_D1_PINID,OUTPUT);
    DIO_voidSetPinDirection(LCD_D2_PORTID,LCD_D2_PINID,OUTPUT);
    DIO_voidSetPinDirection(LCD_D3_PORTID,LCD_D3_PINID,OUTPUT);
    DIO_voidSetPinDirection(LCD_D4_PORTID,LCD_D4_PINID,OUTPUT);
    DIO_voidSetPinDirection(LCD_D5_PORTID,LCD_D5_PINID,OUTPUT);
    DIO_voidSetPinDirection(LCD_D6_PORTID,LCD_D6_PINID,OUTPUT);
    DIO_voidSetPinDirection(LCD_D7_PORTID,LCD_D7_PINID,OUTPUT);
    //DELAY AFTER POWER ON
    _delay_ms(40);
    LCD_voidWriteCommand(FUNC_SET);
    _delay_ms(1);
    LCD_voidWriteCommand(ON_OFF_DISPLAY_CTR);
    _delay_ms(1);
    LCD_voidWriteCommand(CLEAR_DISPLAY);
    _delay_ms(2);

}

void LCD_voidWriteCommand (u8 Command){
    // reset RS w RW 
    DIO_voidSetPinValue(RS_PORTID, RS_PINID, LOW);
    DIO_voidSetPinValue(RW_PORTID, RW_PINID, LOW);

    // Send command across data port pins
    DIO_voidSetPinValue(LCD_D0_PORTID, LCD_D0_PINID, READ_BIT(Command,LCD_D0_PINID));
    DIO_voidSetPinValue(LCD_D1_PORTID, LCD_D1_PINID, READ_BIT(Command,LCD_D1_PINID));
    DIO_voidSetPinValue(LCD_D2_PORTID, LCD_D2_PINID, READ_BIT(Command,LCD_D2_PINID));
    DIO_voidSetPinValue(LCD_D3_PORTID, LCD_D3_PINID, READ_BIT(Command,LCD_D3_PINID));
    DIO_voidSetPinValue(LCD_D4_PORTID, LCD_D4_PINID, READ_BIT(Command,LCD_D4_PINID));
    DIO_voidSetPinValue(LCD_D5_PORTID, LCD_D5_PINID, READ_BIT(Command,LCD_D5_PINID));
    DIO_voidSetPinValue(LCD_D6_PORTID, LCD_D6_PINID, READ_BIT(Command,LCD_D6_PINID));
    DIO_voidSetPinValue(LCD_D7_PORTID, LCD_D7_PINID, READ_BIT(Command,LCD_D7_PINID));

    // set the Enable pin for 1ms and then reset it 
    DIO_voidSetPinValue(EN_PORTID, EN_PINID, HIGH);
    _delay_ms(1);
    DIO_voidSetPinValue(EN_PORTID, EN_PINID, LOW);
}

void LCD_voidWriteChar (u8 Data){
   //Set RS , Reset RW and Set the enable
    DIO_voidSetPinValue(RS_PORTID, RS_PINID, HIGH);
    DIO_voidSetPinValue(RW_PORTID, RW_PINID, LOW);
    DIO_voidSetPinValue(EN_PORTID, EN_PINID, HIGH);

    //Send data across data port pins
    DIO_voidSetPinValue(LCD_D0_PORTID, LCD_D0_PINID, READ_BIT(Data,LCD_D0_PINID));
    DIO_voidSetPinValue(LCD_D1_PORTID, LCD_D1_PINID, READ_BIT(Data,LCD_D1_PINID));
    DIO_voidSetPinValue(LCD_D2_PORTID, LCD_D2_PINID, READ_BIT(Data,LCD_D2_PINID));
    DIO_voidSetPinValue(LCD_D3_PORTID, LCD_D3_PINID, READ_BIT(Data,LCD_D3_PINID));
    DIO_voidSetPinValue(LCD_D4_PORTID, LCD_D4_PINID, READ_BIT(Data,LCD_D4_PINID));
    DIO_voidSetPinValue(LCD_D5_PORTID, LCD_D5_PINID, READ_BIT(Data,LCD_D5_PINID));
    DIO_voidSetPinValue(LCD_D6_PORTID, LCD_D6_PINID, READ_BIT(Data,LCD_D6_PINID));
    DIO_voidSetPinValue(LCD_D7_PORTID, LCD_D7_PINID, READ_BIT(Data,LCD_D7_PINID));

    //Reset the enable pin for 5ms and then Set it 
    DIO_voidSetPinValue(EN_PORTID, EN_PINID, LOW);
    _delay_ms(5);
    DIO_voidSetPinValue(EN_PORTID, EN_PINID, HIGH);

}

void LCD_voidWriteString(u8* Str){
    s32 i=0;
    while(Str[i]!='\0'){
        LCD_voidWriteChar(Str[i]);
        i++;
    }
}

void LCD_voidGoToXY(u8 x, u8 y){
    u32 target_add=0;
    if(x<16&&x>=0){
        if(y<2&&y>=0){
            if(y==0){
               target_add = x+(0x00)+(DDRAM_ADDR_CMD);
               LCD_voidWriteCommand(target_add);
            }
            else if(y==1){
               target_add = x+(0x40)+(DDRAM_ADDR_CMD);
               LCD_voidWriteCommand(target_add);
            }
            else {
                 /*NOCODE*/
                }
        }
        else {
        /*NOCODE*/
        }
    }
    else{
        /*NOCODE*/
    }

}

// void LCD_voidWriteNumber(s32 Num){
//     u8 tmp_Store [12];
//     itoa(Num,(u8*)tmp_Store,10);
//     LCD_voidWriteString((u8*)tmp_Store);
// }


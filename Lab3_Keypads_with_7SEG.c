/**
 * @file main.c
 * @author Ezz
 * @date 2026-08-31
 * @brief Main function
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "KEYPAD_int.h"
#include "SEVEN_SEG_int.h"
#include "LCD_int.h"

// #include "LCD_int.h"
#include <util/delay.h>

int main(){


SEVEN_SEG_voidInit();
KEYPAD_voidInit();
LCD_voidInit();


while(1){
    u8 Button_Triggered=KEYPAD_u8GetButton();
    if(Button_Triggered!=0x00){ // this 0x00 not equal to '0' that why when u click 0 it appear , 0x00 means no button trigger exist now
    SEVEN_SEG_voidDisplay(Button_Triggered);
    LCD_voidWriteChar(Button_Triggered);
    }
}
}
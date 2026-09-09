/**
 * @file main.c
 * @author Ezz
 * @date 2026-08-31
 * @brief Main function
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "KEYPAD_int.h"
#include "LCD_int.h"

// #include "LCD_int.h"
#include <util/delay.h>

void Reset (u8*state_r,s32*First_num_r,s32*Second_num_r,u8*OP_r,u8*flag_1r,u8*flag_2r,u8*flag_3r);

int main(){
KEYPAD_voidInit();
LCD_voidInit();
      
const u8 state_1=1;
const u8 state_2=2;
const u8 state_3=3;
      u8 state=state_1;

s32 First_Num=0;
s32 Second_Num=0;
s32 result=0;

u8 OP = 0;

u8 First_num_Getflag = 0;
u8 Second_num_Getflag = 0;

u8 equal_clicked=0;

while(1){

    u8 Button_Triggered=KEYPAD_u8GetButton();

    if(Button_Triggered==0xFF){
        continue;
    }else{
        /**/
    }

    if(Button_Triggered=='C'){
        LCD_voidWriteCommand(CLEAR_DISPLAY);
        Reset(&state,&First_Num,&Second_Num,&OP,&equal_clicked,&First_num_Getflag,&Second_num_Getflag);
    }else
    {
     // enter first number and then move forward by enter the operation 
        if (state==state_1) {
            if (!equal_clicked) { 
                if(Button_Triggered>='0'&&Button_Triggered<='9'){
                     LCD_voidWriteChar(Button_Triggered);
                     First_Num=(First_Num*10)+(Button_Triggered-'0');
                     First_num_Getflag=1;
                }
                else if(!First_num_Getflag) {
                    if(Button_Triggered=='+'||Button_Triggered=='-'){
                        LCD_voidWriteChar(Button_Triggered);
                    }
                } 
                else if(Button_Triggered=='+'||Button_Triggered=='-'||Button_Triggered=='*'||Button_Triggered=='/'){
                     LCD_voidWriteChar(Button_Triggered);
                     OP=Button_Triggered;
                     state=state_2;
                    }
                else if(Button_Triggered=='='){
                     LCD_voidGoToXY(0, 1);
                     LCD_voidWriteNumber(First_Num); //need edit
                    Reset(&state,&First_Num,&Second_Num,&OP,&equal_clicked,&First_num_Getflag,&Second_num_Getflag);
                }
            }
            else{
                /**/
            }
        }
  
        else if (state==state_2) {
            
            if(Button_Triggered>='0'&&Button_Triggered<='9'){
            LCD_voidWriteChar(Button_Triggered);
            Second_Num=(Second_Num*10)+(Button_Triggered-'0');
            Second_num_Getflag=1;
            }
            else if(Button_Triggered=='+'||Button_Triggered=='-'||Button_Triggered=='*'||Button_Triggered=='/'){
               
            }   
            else if(Button_Triggered=='='){
                if (Second_num_Getflag==0) {
                    LCD_voidWriteCommand(CLEAR_DISPLAY);
                    LCD_voidGoToXY(0, 1);
                    LCD_voidWriteString((u8*)"MATH ERROR");
                    Reset(&state,&First_Num,&Second_Num,&OP,&equal_clicked,&First_num_Getflag,&Second_num_Getflag);
                }else{
                state = state_3;
                }
            }
        }


        else if (state==state_3) {
                if (Second_Num==0&&OP=='/') {
                    LCD_voidWriteCommand(CLEAR_DISPLAY);
                    LCD_voidGoToXY(0, 1);
                    LCD_voidWriteString((u8*)" MATH ERROR");
                    Reset(&state,&First_Num,&Second_Num,&OP,&equal_clicked,&First_num_Getflag,&Second_num_Getflag);
                    
                }else {
                    switch (OP) {
                    case '+':result=First_Num+Second_Num  ;break;
                    case '-':result=First_Num-Second_Num  ;break;
                    case '*':result=First_Num*Second_Num  ;break;
                    case '/':result=First_Num/Second_Num  ;break;
                    }
                    LCD_voidGoToXY(0, 1);
                    LCD_voidWriteNumber(result);
                    Reset(&state,&First_Num,&Second_Num,&OP,&equal_clicked,&First_num_Getflag,&Second_num_Getflag); 
                }
        }
        
    }

}
}

void Reset (u8*state_r,s32*First_num_r,s32*Second_num_r,u8*OP_r,u8*flag_1r,u8*flag_2r,u8*flag_3r){
        *state_r      = 1;
        *First_num_r  = 0;
        *Second_num_r = 0;
        *OP_r         = 0;
        *flag_1r      = 0;
        *flag_2r      = 0;
        *flag_3r      = 0;    
}
#ifndef _KEYPAD_PRIVATE_H_ 
#define _KEYPAD_PRIVATE_H_ 

static const u8 KEYPAD_u8Buttons [KEYPAD_ROW_NUM][KEYPAD_COLUMN_NUM] = {
    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'C', '0', '=', '+'}
};

 static const u8 KEYPAD_Au8_OUTPUTS_PORTID [KEYPAD_COLUMN_NUM] = {
    KEYPAD_1_PORTID,
    KEYPAD_2_PORTID,
    KEYPAD_3_PORTID,
    KEYPAD_4_PORTID
};

 static const u8 KEYPAD_Au8_OUTPUTS_PINID [KEYPAD_COLUMN_NUM] = {
    KEYPAD_1_PINID,
    KEYPAD_2_PINID,
    KEYPAD_3_PINID,
    KEYPAD_4_PINID
};

 static const u8 KEYPAD_Au8_INPUTS_PORTID [KEYPAD_ROW_NUM] = {
    KEYPAD_A_PORTID,
    KEYPAD_B_PORTID,
    KEYPAD_C_PORTID,
    KEYPAD_D_PORTID
};

static const  u8 KEYPAD_Au8_INPUTS_PINID [KEYPAD_ROW_NUM] = {
    KEYPAD_A_PINID,
    KEYPAD_B_PINID,
    KEYPAD_C_PINID,
    KEYPAD_D_PINID
};

#endif

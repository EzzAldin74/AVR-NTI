#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_int.h"

#include "ADC_int.h"
#include "ADC_config.h"
#include "ADC_private.h"

void ADC_voidInit(void)
{
    Clear_Bit(ADMUX, REFS1);
    Set_Bit(ADMUX, REFS0);

    Clear_Bit(ADMUX, ADLAR);

    Set_Bit(ADCSRA, ADPS2);
    Set_Bit(ADCSRA, ADPS1);
    Clear_Bit(ADCSRA, ADPS0);

    Set_Bit(ADCSRA, ADEN);
}

u16 ADC_u16Read(u8 Channel)
{
    //save the ADMUX value of REFS1,REFS0,ADLAR
    ADMUX &= 0xE0;
    // add the ADC channel number to the ADMUX
    ADMUX |= (Channel & 0x07);
    // ADC Enable
    Set_Bit(ADCSRA, ADSC);
    //polling until the ADSC become 0
    while (Get_Bit(ADCSRA, ADSC) == 1);
    
    u16 low_byte = ADCL;
    u16 high_byte = ADCH;
    u16 final_result = low_byte | (high_byte << 8);

    return ADC_DATA;
}
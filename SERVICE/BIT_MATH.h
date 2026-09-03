    #ifndef _BIT_MATH_H_  
    #define _BIT_MATH_H_ 

    #define SET_BIT(REG,BIT)   ((REG)|=(1<<BIT))
    #define CLR_BIT(REG,BIT)   ((REG)&=~(1<<BIT))
    #define READ_BIT(REG,BIT)  ((REG>>BIT)&0x01)

    #define SET_REG(REG)       (REG=0xFF)
    #define CLR_REG(REG)       (REG=0x00)
    #define READ_REG(REG)      (REG)
    
    #endif


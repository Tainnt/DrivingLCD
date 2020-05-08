#include "lcd.h"

void LCD_Setup()
{
    // LCD_FREQ = ACLK/32/4, LCD Mux 4, turn on LCD
    LCDCCTL0 = LCDDIV_31 | LCDPRE_1 | LCD4MUX | LCDON;
    //Charge pump disabled
    LCDCVCTL = 0x00;
    /*
     //Charge pump generated internally at 2.96V, external bias (V2-V4) generation
     //Internal reference for charge pump
     LCDCVCTL = LCDCPEN | VLCD_2_96;
     REFCTL0 &= ~REFMSTR;
     */
}

void LCD_SetSegPin()
{
    LCDCCTL0 ^= LCDON;
    LCDCPCTL0 = 0x0000;
    LCDCPCTL1 = 0xFFF8;
    LCDCPCTL2 = 0x0007;
    LCDCCTL0 ^= LCDON;
}

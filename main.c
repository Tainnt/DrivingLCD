#include "MSP430F5xx_6xx/device_init.h"
#include <stdbool.h>
#include "msp430.h"
#include "MSP430F5xx_6xx/lcd.h"

const unsigned char LCD_Num_Map[] = {
BIT0 | BIT1 | BIT3 | BIT5 | BIT6 | BIT7,                    // '0'
        BIT5 | BIT6,                                        // '1'
        BIT0 | BIT1 | BIT2 | BIT6 | BIT7,                   // '2'
        BIT0 | BIT2 | BIT5 | BIT6 | BIT7,                   // '3'
        BIT2 | BIT3 | BIT5 | BIT6,                          // '4'
        BIT0 | BIT2 | BIT3 | BIT5 | BIT7,                   // '5'
        BIT0 | BIT1 | BIT2 | BIT3 | BIT5 | BIT7,            // '6'
        BIT5 | BIT6 | BIT7,                                 // '7'
        BIT0 | BIT1 | BIT2 | BIT3 | BIT5 | BIT6 | BIT7,     // '8'
        BIT0 | BIT2 | BIT3 | BIT5 | BIT6 | BIT7             // '9'
};

void main(void)
{
    volatile unsigned char i;
    WDTCTL = WDTPW + WDTHOLD;
    WDT_A_hold(WDT_A_BASE);
    HHM_SetMCLK();

    IOInit();
    LCD_Setup();
    LCD_SetSegPin();

    while (1)
    {
        for (i = 0; i < sizeof(LCD_Num_Map); ++i)
        {
            LCDM10 = 0x00;
            LCDM11 = 0x00;
            LCDM12 = 0x00;
            LCDM13 = 0x00;
            LCDM14 = 0x00;
            LCDM15 = 0x00;
            LCDM16 = 0x00;
            LCDM17 = 0x00;
            LCDM18 = 0x00;

            LCDM10 = LCD_Num_Map[i]  & 0xF0;
            LCDM11 = LCD_Num_Map[i];
            LCDM12 = LCD_Num_Map[i];
            LCDM13 = LCD_Num_Map[i];
            LCDM14 = LCD_Num_Map[i];
            LCDM15 = LCD_Num_Map[i];
            LCDM16 = LCD_Num_Map[i];
            LCDM17 = LCD_Num_Map[i];
            LCDM18 = LCD_Num_Map[i] & 0x0F;
            __delay_cycles(6000000);
        }
    }
}

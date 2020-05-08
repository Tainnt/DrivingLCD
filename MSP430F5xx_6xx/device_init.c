#include "device_init.h"

#include <assert.h>

#if 1  //IO config

//*****************************************************************************
//
//! \brief Private function for determining correct base address
//!
//! Private function for determing correct base address. Called at the
//! beginning of all GPIO functions.
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//!
//! \return 0xFFFF if the selectedPort is invalid otherwise the baseAddress
//
//*****************************************************************************
static uint32_t privateGPIOGetBaseAddress(uint8_t selectedPort)
{
        uint32_t baseAddress = 0xFFFF;

        switch (selectedPort) {

#ifdef __MSP430_HAS_PORT1_R__
        case GPIO_PORT_P1: baseAddress = __MSP430_BASEADDRESS_PORT1_R__; break;
#endif
#ifdef __MSP430_HAS_PORT2_R__
        case GPIO_PORT_P2: baseAddress = __MSP430_BASEADDRESS_PORT2_R__; break;
#endif
#ifdef __MSP430_HAS_PORT3_R__
        case GPIO_PORT_P3: baseAddress = __MSP430_BASEADDRESS_PORT3_R__; break;
#endif
#ifdef __MSP430_HAS_PORT4_R__
        case GPIO_PORT_P4: baseAddress = __MSP430_BASEADDRESS_PORT4_R__; break;
#endif
#ifdef __MSP430_HAS_PORT5_R__
        case GPIO_PORT_P5: baseAddress = __MSP430_BASEADDRESS_PORT5_R__; break;
#endif
#ifdef __MSP430_HAS_PORT6_R__
        case GPIO_PORT_P6: baseAddress = __MSP430_BASEADDRESS_PORT6_R__; break;
#endif
#ifdef __MSP430_HAS_PORT7_R__
        case GPIO_PORT_P7: baseAddress = __MSP430_BASEADDRESS_PORT7_R__; break;
#endif
#ifdef __MSP430_HAS_PORT8_R__
        case GPIO_PORT_P8: baseAddress = __MSP430_BASEADDRESS_PORT8_R__; break;
#endif
#ifdef __MSP430_HAS_PORT9_R__
        case GPIO_PORT_P9: baseAddress = __MSP430_BASEADDRESS_PORT9_R__; break;
#endif
#ifdef __MSP430_HAS_PORT10_R__
        case GPIO_PORT_P10: baseAddress = __MSP430_BASEADDRESS_PORT10_R__; break;
#endif
#ifdef __MSP430_HAS_PORT11_R__
        case GPIO_PORT_P11: baseAddress = __MSP430_BASEADDRESS_PORT11_R__; break;
#endif
#ifdef __MSP430_HAS_PORTA_R__
        case GPIO_PORT_PA: baseAddress = __MSP430_BASEADDRESS_PORTA_R__; break;
#endif
#ifdef __MSP430_HAS_PORTB_R__
        case GPIO_PORT_PB: baseAddress = __MSP430_BASEADDRESS_PORTB_R__; break;
#endif
#ifdef __MSP430_HAS_PORTC_R__
        case GPIO_PORT_PC: baseAddress = __MSP430_BASEADDRESS_PORTC_R__; break;
#endif
#ifdef __MSP430_HAS_PORTD_R__
        case GPIO_PORT_PD: baseAddress = __MSP430_BASEADDRESS_PORTD_R__; break;
#endif
#ifdef __MSP430_HAS_PORTE_R__
        case GPIO_PORT_PE: baseAddress = __MSP430_BASEADDRESS_PORTE_R__; break;
#endif
#ifdef __MSP430_HAS_PORTF_R__
        case GPIO_PORT_PF: baseAddress = __MSP430_BASEADDRESS_PORTF_R__; break;
#endif
#ifdef __MSP430_HAS_PORTJ_R__
        case GPIO_PORT_PJ: baseAddress = __MSP430_BASEADDRESS_PORTJ_R__; break;
#endif
        default:
                baseAddress = 0xFFFF;
        }
        return baseAddress;
}

//*****************************************************************************
//
//! \brief This function configures the selected Pin as output pin
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxDIR register and bits of \b PxSEL register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setAsOutputPin( uint8_t selectedPort,
                          uint16_t selectedPins
                          )
{

        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {

        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1SEL) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1DIR) |= (uint8_t)selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2SEL) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2DIR) |= (uint8_t)selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PASEL) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PADIR) |= selectedPins;
                break;
        }

}

//*****************************************************************************
//
//! \brief This function configures the selected Pin as input pin
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxDIR register and bits of \b PxSEL register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setAsInputPin(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1SEL) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1DIR) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1REN) &=  (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2SEL) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2DIR) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2REN) &=  (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PASEL) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PADIR) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PAREN) &= ~selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function configures the peripheral module function in output
//! direction for the selected pin.
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxDIR register and bits of \b PxSEL register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setAsPeripheralModuleFunctionOutputPin(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1SEL) |=  (uint8_t)selectedPins;
                HWREG8(baseAddress + OFS_P1DIR) |=  (uint8_t)selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2SEL) |=  (uint8_t)selectedPins;
                HWREG8(baseAddress + OFS_P2DIR) |=  (uint8_t)selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PASEL) |= selectedPins;
                HWREG16(baseAddress + OFS_PADIR) |= selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function configures the peripheral module function in input
//! direction for the selected pin.
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxDIR register and bits of \b PxSEL register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setAsPeripheralModuleFunctionInputPin(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;


        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1SEL) |=  (uint8_t)selectedPins;
                HWREG8(baseAddress + OFS_P1DIR) &=  (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2SEL) |=  (uint8_t)selectedPins;
                HWREG8(baseAddress + OFS_P2DIR) &=  (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PASEL) |= selectedPins;
                HWREG16(baseAddress + OFS_PADIR) &= ~selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function sets output HIGH on the selected Pin
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxOUT register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setOutputHighOnPin(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1OUT) |=  (uint8_t)selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2OUT) |=  (uint8_t)selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PAOUT) |= selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function sets output LOW on the selected Pin
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxOUT register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setOutputLowOnPin(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1OUT) &=  (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2OUT) &=  (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PAOUT) &= ~selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function toggles the output on the selected Pin
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxOUT register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_toggleOutputOnPin(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) ||
               (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) ||
               (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) ||
               (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) ||
               (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) ||
               (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) ||
               (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) ||
               (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) ||
               (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) ||
               (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1OUT) ^=  (uint8_t)selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2OUT) ^=  (uint8_t)selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PAOUT) ^= selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function sets the selected Pin in input Mode wuth Pull Down
//! resistor
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxDIR register, bits of \b PxOUT register and bits of
//! \b PxREN register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setAsInputPinWithPullDownresistor(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1SEL) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1DIR) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1REN) |=  (uint8_t)selectedPins;
                HWREG8(baseAddress + OFS_P1OUT) &=  (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2SEL) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2DIR) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2REN) |=  (uint8_t)selectedPins;
                HWREG8(baseAddress + OFS_P2OUT) &=  (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PASEL) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PADIR) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PAREN) |= selectedPins;
                HWREG16(baseAddress + OFS_PAOUT) &= ~selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function sets the selected Pin in input Mode wuth Pull Up
//! resistor
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxDIR register, bits of \b PxOUT register and bits of
//! \b PxREN register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setAsInputPinWithPullUpresistor(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1SEL) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1DIR) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1REN) |=  (uint8_t)selectedPins;
                HWREG8(baseAddress + OFS_P1OUT) |=  (uint8_t)selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2SEL) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2DIR) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2REN) |=  (uint8_t)selectedPins;
                HWREG8(baseAddress + OFS_P2OUT) |=  (uint8_t)selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PASEL) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PADIR) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PAREN) |= selectedPins;
                HWREG16(baseAddress + OFS_PAOUT) |= selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function gets the input value on the selected pin
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxIN register.
//!
//! \return One of the following:
//!         - \b GPIO_INPUT_PIN_HIGH
//!         - \b GPIO_INPUT_PIN_LOW
//!         \n indicating the input value of the pin
//
//*****************************************************************************
uint8_t GPIO_getInputPinValue(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );


        uint16_t inputPinValue = 0;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                inputPinValue = HWREG8(baseAddress + OFS_P1IN) &  ((uint8_t)selectedPins);
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                inputPinValue = HWREG8(baseAddress + OFS_P2IN) & ((uint8_t)selectedPins);
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                inputPinValue = HWREG16(baseAddress + OFS_PAIN) & selectedPins;
                break;
        }

        if (inputPinValue > 0)
                return GPIO_INPUT_PIN_HIGH;
        return GPIO_INPUT_PIN_LOW;
}

//*****************************************************************************
//
//! \brief This function enables the port interrupt on the selected pin. Note
//! that only Port 1,2, A have this capability. Does not clear interrupt flags.
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxIE register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_enableInterrupt(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_PA == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
                HWREG8(baseAddress + OFS_P1IE) |= (uint8_t)selectedPins;
                break;
        case GPIO_PORT_P2:
                HWREG8(baseAddress + OFS_P2IE) |= (uint8_t)selectedPins;
                break;
        case GPIO_PORT_PA:
                HWREG16(baseAddress + OFS_PAIE) |= selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function disables the port interrupt on the selected pin. Note
//! that only Port 1,2, A have this capability
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxIE register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_disableInterrupt(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_PA == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;
        switch (selectedPort) {
        case GPIO_PORT_P1:
                HWREG8(baseAddress + OFS_P1IE) &= (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_P2:
                HWREG8(baseAddress + OFS_P2IE) &= (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_PA:
                HWREG16(baseAddress + OFS_PAIE) &= ~selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function gets the interrupt status of the selected pin. Note
//! that only Port 1,2, A have this capability
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! \return Logical OR of any of the following:
//!         - \b GPIO_PIN0
//!         - \b GPIO_PIN1
//!         - \b GPIO_PIN2
//!         - \b GPIO_PIN3
//!         - \b GPIO_PIN4
//!         - \b GPIO_PIN5
//!         - \b GPIO_PIN6
//!         - \b GPIO_PIN7
//!         - \b GPIO_PIN8
//!         - \b GPIO_PIN9
//!         - \b GPIO_PIN10
//!         - \b GPIO_PIN11
//!         - \b GPIO_PIN12
//!         - \b GPIO_PIN13
//!         - \b GPIO_PIN14
//!         - \b GPIO_PIN15
//!         \n indicating the interrupt status of the selected pins [Default:
//!         0]
//
//*****************************************************************************
uint16_t GPIO_getInterruptStatus(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_PA == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );

        uint8_t returnValue = 0x0;

        switch (selectedPort) {
        case GPIO_PORT_P1:
                returnValue = (HWREG8(baseAddress + OFS_P1IFG) & ((uint8_t)selectedPins));
                break;
        case GPIO_PORT_P2:
                returnValue = (HWREG8(baseAddress + OFS_P2IFG) & ((uint8_t)selectedPins));
                break;
        case GPIO_PORT_PA:
                returnValue = (HWREG16(baseAddress + OFS_PAIFG) & ((uint8_t)selectedPins));
                break;
        }

        return returnValue;
}

//*****************************************************************************
//
//! \brief This function clears the interrupt flag on the selected pin. Note
//! that only Port 1,2, A have this capability
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxIFG register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_clearInterruptFlag(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_PA == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;


        switch (selectedPort) {
        case GPIO_PORT_P1:
                HWREG8(baseAddress + OFS_P1IFG) &= (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_P2:
                HWREG8(baseAddress + OFS_P2IFG) &= (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_PA:
                HWREG16(baseAddress + OFS_PAIFG) &= ~selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function selects on what edge the port interrupt flag should be
//! set for a transition Note that only Port 1,2, A have this capability
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//! \param edgeSelect specifies what tranistion sets the interrupt flag
//!        Valid values are:
//!        - \b GPIO_HIGH_TO_LOW_TRANSITION
//!        - \b GPIO_LOW_TO_HIGH_TRANSITION
//!
//! Modified bits of \b PxIES register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_interruptEdgeSelect(
        uint8_t selectedPort,
        uint16_t selectedPins,
        uint8_t edgeSelect
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        assert((edgeSelect == GPIO_HIGH_TO_LOW_TRANSITION) ||
               (edgeSelect == GPIO_LOW_TO_HIGH_TRANSITION)
               );

        switch (selectedPort) {
        case GPIO_PORT_P1:
                if (GPIO_LOW_TO_HIGH_TRANSITION == edgeSelect)
                        HWREG8(baseAddress + OFS_P1IES) &= (uint8_t) ~selectedPins;
                else
                        HWREG8(baseAddress + OFS_P1IES) |= (uint8_t)selectedPins;
                break;

        case GPIO_PORT_P2:
                if (GPIO_LOW_TO_HIGH_TRANSITION == edgeSelect)
                        HWREG8(baseAddress + OFS_P2IES) &= (uint8_t) ~selectedPins;
                else
                        HWREG8(baseAddress + OFS_P2IES) |= (uint8_t)selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function sets the drive strength for the selected port pin.
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//! \param driveStrength specifies the drive strength of the pin
//!        Valid values are:
//!        - \b GPIO_REDUCED_OUTPUT_DRIVE_STRENGTH
//!        - \b GPIO_FULL_OUTPUT_DRIVE_STRENGTH
//!
//! Modified bits of \b PxDS register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setDriveStrength(
        uint8_t selectedPort,
        uint16_t selectedPins,
        uint8_t driveStrength
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;
        assert((driveStrength == GPIO_REDUCED_OUTPUT_DRIVE_STRENGTH) ||
               (driveStrength == GPIO_FULL_OUTPUT_DRIVE_STRENGTH)
               );

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                if (GPIO_REDUCED_OUTPUT_DRIVE_STRENGTH == driveStrength)
                        HWREG8(baseAddress + OFS_P1DS) &= (uint8_t) ~selectedPins;
                else
                        HWREG8(baseAddress + OFS_P1DS) |= (uint8_t)selectedPins;
                break;

        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                if (GPIO_REDUCED_OUTPUT_DRIVE_STRENGTH == driveStrength)
                        HWREG8(baseAddress + OFS_P2DS) &= (uint8_t) ~selectedPins;
                else
                        HWREG8(baseAddress + OFS_P2DS) |= (uint8_t)selectedPins;
                break;
        }
}

void IOInit()
{
    GPIO_setAsOutputPin(GPIO_PORT_P3,GPIO_PIN6); //mor ra la tat den do
//    GPIO_setAsOutputPin(GPIO_PORT_P3,GPIO_PIN0); //mor ra la tat den xanh

////    Init P4.1 to P4.7, P5.0 to P5.7 and P6.0 to P6.7
//    uint8_t i;
//    for (i = 0; i < 8; i++) {
//        if (i != 0) {
//            GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN0 << i);
//        }
//        GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN0 << i);
//        GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN0 << i);
//    }
//
//    // Init P7.0 to P7.2
//    GPIO_setAsOutputPin(GPIO_PORT_P7, GPIO_PIN0);
//    GPIO_setAsOutputPin(GPIO_PORT_P7, GPIO_PIN1);
//    GPIO_setAsOutputPin(GPIO_PORT_P7, GPIO_PIN2);
//
    // Init P1.6 and P1.7
//    P1SEL |=  BIT6 | BIT7;
//    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN6);
//    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN7);
}


#if 1

void WDT_A_hold(uint32_t baseAddress)
{
        //Set Hold bit
        uint8_t newWDTStatus = ( HWREG8(baseAddress + OFS_WDTCTL_L) | WDTHOLD );
        HWREG16(baseAddress + OFS_WDTCTL) = WDTPW + newWDTStatus;
}



#endif

#if 1// SYS clock connfig

void HHM_SetMCLK (void)
{
	UCS_clockSignalInit(UCS_BASE, UCS_FLLREF,UCS_XT1CLK_SELECT, UCS_CLOCK_DIVIDER_1 );
	UCS_clockSignalInit(UCS_BASE,UCS_MCLK  ,UCS_DCOCLK_SELECT , UCS_CLOCK_DIVIDER_1 );
	UCS_initFLLSettle( UCS_BASE, 12000, 366 );

}

void UCS_clockSignalInit( uint32_t baseAddress,
                          uint8_t selectedClockSignal,
                          uint16_t clockSource,
                          uint16_t clockSourceDivider
                          )
{



        switch (selectedClockSignal) {
        case UCS_ACLK:
                HWREG16(baseAddress + OFS_UCSCTL4) &= ~(SELA_7);
                clockSource = clockSource << 8;
                HWREG16(baseAddress + OFS_UCSCTL4) |= (clockSource);

                HWREG16(baseAddress + OFS_UCSCTL5) &= ~(DIVA_7);
                clockSourceDivider = clockSourceDivider << 8;
                HWREG16(baseAddress + OFS_UCSCTL5) |= clockSourceDivider;
                break;
        case UCS_SMCLK:
                HWREG16(baseAddress + OFS_UCSCTL4) &= ~(SELS_7);
                clockSource = clockSource << 4;
                HWREG16(baseAddress + OFS_UCSCTL4) |= (clockSource);

                HWREG16(baseAddress + OFS_UCSCTL5) &= ~(DIVS_7);
                clockSourceDivider = clockSourceDivider << 4;
                HWREG16(baseAddress + OFS_UCSCTL5) |= clockSourceDivider;
                break;
        case UCS_MCLK:
                HWREG16(baseAddress + OFS_UCSCTL4) &= ~(SELM_7);
                HWREG16(baseAddress + OFS_UCSCTL4) |= (clockSource);

                HWREG16(baseAddress + OFS_UCSCTL5) &= ~(DIVM_7);
                HWREG16(baseAddress + OFS_UCSCTL5) |= clockSourceDivider;
                break;
        case UCS_FLLREF:

                HWREG8(baseAddress + OFS_UCSCTL3) &=  ~(SELREF_7);

                clockSource = clockSource << 4;
                HWREG8(baseAddress + OFS_UCSCTL3) |= (clockSource);

                HWREG8(baseAddress + OFS_UCSCTL3) &= ~(FLLREFDIV_7);
                //Note that dividers for FLLREF are slightly different
                //Hence handled differently from other CLK signals
                switch (clockSourceDivider) {
                case UCS_CLOCK_DIVIDER_12:
                        HWREG8(baseAddress + OFS_UCSCTL3) |= FLLREFDIV__12;
                        break;
                case UCS_CLOCK_DIVIDER_16:
                        HWREG8(baseAddress + OFS_UCSCTL3) |= FLLREFDIV__16;
                        break;
                default:
                        HWREG8(baseAddress + OFS_UCSCTL3) |= clockSourceDivider;
                        break;
                }

                break;
        }
}

void UCS_initFLL( uint32_t baseAddress,
                  uint16_t fsystem,
                  uint16_t ratio
                  )
{
        uint16_t d, dco_div_bits;
        uint16_t mode = 0;

        //Save actual state of FLL loop control, then disable it. This is needed to
        //prevent the FLL from acting as we are making fundamental modifications to
        //the clock setup.
        uint16_t srRegisterState = __get_SR_register() & SCG0;

        d = ratio;
        //Have at least a divider of 2
        dco_div_bits = FLLD__2;

        if (fsystem > 16000) {
                d >>= 1;
                mode = 1;
        } else
                //fsystem = fsystem * 2
                fsystem <<= 1;

        while (d > 512) {
                //Set next higher div level
                dco_div_bits = dco_div_bits + FLLD0;
                d >>= 1;
        }

        // Disable FLL
        __bis_SR_register(SCG0);

        //Set DCO to lowest Tap
        HWREG8(baseAddress + OFS_UCSCTL0_H) = 0x0000;

        //Reset FN bits
        HWREG16(baseAddress + OFS_UCSCTL2) &= ~(0x03FF);
        HWREG16(baseAddress + OFS_UCSCTL2) = dco_div_bits | (d - 1);

        if (fsystem <= 630)             //fsystem < 0.63MHz
                HWREG8(baseAddress + OFS_UCSCTL1) = DCORSEL_0;
        else if (fsystem <  1250)       //0.63MHz < fsystem < 1.25MHz
                HWREG8(baseAddress + OFS_UCSCTL1) = DCORSEL_1;
        else if (fsystem <  2500)       //1.25MHz < fsystem <  2.5MHz
                HWREG8(baseAddress + OFS_UCSCTL1) = DCORSEL_2;
        else if (fsystem <  5000)       //2.5MHz  < fsystem <    5MHz
                HWREG8(baseAddress + OFS_UCSCTL1) = DCORSEL_3;
        else if (fsystem <  10000)      //5MHz    < fsystem <   10MHz
                HWREG8(baseAddress + OFS_UCSCTL1) = DCORSEL_4;
        else if (fsystem <  20000)      //10MHz   < fsystem <   20MHz
                HWREG8(baseAddress + OFS_UCSCTL1) = DCORSEL_5;
        else if (fsystem <  40000)      //20MHz   < fsystem <   40MHz
                HWREG8(baseAddress + OFS_UCSCTL1) = DCORSEL_6;
        else
                HWREG8(baseAddress + OFS_UCSCTL1) = DCORSEL_7;

        // Re-enable FLL
        __bic_SR_register(SCG0);

        while (HWREG8(baseAddress + OFS_UCSCTL7_L) & DCOFFG) {
                //Clear OSC flaut Flags
                HWREG8(baseAddress + OFS_UCSCTL7_L) &= ~(DCOFFG);

                //Clear OFIFG fault flag
                HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;
        }

        // Restore previous SCG0
        __bis_SR_register(srRegisterState);

        if (mode == 1) {
                //fsystem > 16000
                //Select DCOCLK
                HWREG16(baseAddress + OFS_UCSCTL4) &=  ~(SELM_7 + SELS_7);
                HWREG16(baseAddress + OFS_UCSCTL4) |= SELM__DCOCLK + SELS__DCOCLK;
        } else {
                //Select DCODIVCLK
                HWREG16(baseAddress + OFS_UCSCTL4) &=  ~(SELM_7 + SELS_7);
                HWREG16(baseAddress + OFS_UCSCTL4) |= SELM__DCOCLKDIV + SELS__DCOCLKDIV;
        }

}

void UCS_initFLLSettle( uint32_t baseAddress,
                        uint16_t fsystem,
                        uint16_t ratio
                        )
{
        volatile uint16_t x = ratio * 32;

        UCS_initFLL(baseAddress, fsystem, ratio);

        while (x--)
                __delay_cycles(30);
}
#endif

#endif




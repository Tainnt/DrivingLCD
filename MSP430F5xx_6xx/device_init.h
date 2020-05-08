#ifndef __device_init__
#define __device_init__
#include "inc/hw_memmap.h"

//*****************************************************************************
//
// The following are values that can be passed to the selectedPort parameter
// for functions: GPIO_setAsOutputPin(), GPIO_setAsInputPin(),
// GPIO_setAsPeripheralModuleFunctionOutputPin(),
// GPIO_setAsPeripheralModuleFunctionInputPin(), GPIO_setOutputHighOnPin(),
// GPIO_setOutputLowOnPin(), GPIO_toggleOutputOnPin(),
// GPIO_setAsInputPinWithPullDownresistor(),
// GPIO_setAsInputPinWithPullUpresistor(), GPIO_getInputPinValue(),
// GPIO_enableInterrupt(), GPIO_disableInterrupt(), GPIO_getInterruptStatus(),
// GPIO_clearInterruptFlag(), GPIO_interruptEdgeSelect(), and
// GPIO_setDriveStrength().
//
//*****************************************************************************
#define GPIO_PORT_P1                                                          1
#define GPIO_PORT_P2                                                          2
#define GPIO_PORT_P3                                                          3
#define GPIO_PORT_P4                                                          4
#define GPIO_PORT_P5                                                          5
#define GPIO_PORT_P6                                                          6
#define GPIO_PORT_P7                                                          7
#define GPIO_PORT_P8                                                          8
#define GPIO_PORT_P9                                                          9
#define GPIO_PORT_P10                                                        10
#define GPIO_PORT_P11                                                        11
#define GPIO_PORT_PA                                                         12
#define GPIO_PORT_PB                                                         13
#define GPIO_PORT_PC                                                         14
#define GPIO_PORT_PD                                                         15
#define GPIO_PORT_PE                                                         16
#define GPIO_PORT_PF                                                         17
#define GPIO_PORT_PJ                                                         18

//*****************************************************************************
//
// The following are values that can be passed to the selectedPins parameter
// for functions: GPIO_setAsOutputPin(), GPIO_setAsInputPin(),
// GPIO_setAsPeripheralModuleFunctionOutputPin(),
// GPIO_setAsPeripheralModuleFunctionInputPin(), GPIO_setOutputHighOnPin(),
// GPIO_setOutputLowOnPin(), GPIO_toggleOutputOnPin(),
// GPIO_setAsInputPinWithPullDownresistor(),
// GPIO_setAsInputPinWithPullUpresistor(), GPIO_getInputPinValue(),
// GPIO_enableInterrupt(), GPIO_disableInterrupt(), GPIO_getInterruptStatus(),
// GPIO_clearInterruptFlag(), GPIO_interruptEdgeSelect(), and
// GPIO_setDriveStrength() as well as returned by the GPIO_getInterruptStatus()
// function.
//
//*****************************************************************************
#define GPIO_PIN0                                                          0x01
#define GPIO_PIN1                                                          0x02
#define GPIO_PIN2                                                          0x04
#define GPIO_PIN3                                                          0x08
#define GPIO_PIN4                                                          0x10
#define GPIO_PIN5                                                          0x20
#define GPIO_PIN6                                                          0x40
#define GPIO_PIN7                                                          0x80
#define GPIO_PIN8                                                         0x100
#define GPIO_PIN9                                                         0x200
#define GPIO_PIN10                                                        0x400
#define GPIO_PIN11                                                        0x800
#define GPIO_PIN12                                                       0x1000
#define GPIO_PIN13                                                       0x2000
#define GPIO_PIN14                                                       0x4000
#define GPIO_PIN15                                                       0x8000

//*****************************************************************************
//
// The following are values that can be passed to the edgeSelect parameter for
// functions: GPIO_interruptEdgeSelect().
//
//*****************************************************************************
#define GPIO_HIGH_TO_LOW_TRANSITION                                        0x01
#define GPIO_LOW_TO_HIGH_TRANSITION                                        0x00

//*****************************************************************************
//
// The following are values that can be passed to the driveStrength parameter
// for functions: GPIO_setDriveStrength().
//
//*****************************************************************************
#define GPIO_REDUCED_OUTPUT_DRIVE_STRENGTH                                 0x00
#define GPIO_FULL_OUTPUT_DRIVE_STRENGTH                                    0x01

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the GPIO_getInputPinValue() function.
//
//*****************************************************************************
#define GPIO_INPUT_PIN_HIGH                                                0x01
#define GPIO_INPUT_PIN_LOW                                                 0x00

#define HWREG16(x)                                                             \
        (*((volatile uint16_t*)((uint16_t)x)))
#define HWREG8(x)                                                             \
        (*((volatile uint8_t*)((uint16_t)x)))



//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void GPIO_setAsOutputPin(uint8_t selectedPort,
                                uint16_t selectedPins);

extern void GPIO_setAsInputPin(uint8_t selectedPort,
                               uint16_t selectedPins);

extern void GPIO_setAsPeripheralModuleFunctionOutputPin(uint8_t selectedPort,
                                                        uint16_t selectedPins);

extern void GPIO_setAsPeripheralModuleFunctionInputPin(uint8_t selectedPort,
                                                       uint16_t selectedPins);

extern void GPIO_setOutputHighOnPin(uint8_t selectedPort,
                                    uint16_t selectedPins);

extern void GPIO_setOutputLowOnPin(uint8_t selectedPort,
                                   uint16_t selectedPins);

extern void GPIO_toggleOutputOnPin(uint8_t selectedPort,
                                   uint16_t selectedPins);

extern void GPIO_setAsInputPinWithPullDownresistor(uint8_t selectedPort,
                                                   uint16_t selectedPins);

extern void GPIO_setAsInputPinWithPullUpresistor(uint8_t selectedPort,
                                                 uint16_t selectedPins);

extern uint8_t GPIO_getInputPinValue(uint8_t selectedPort,
                                     uint16_t selectedPins);

extern void GPIO_enableInterrupt(uint8_t selectedPort,
                                 uint16_t selectedPins);

extern void GPIO_disableInterrupt(uint8_t selectedPort,
                                  uint16_t selectedPins);

extern uint16_t GPIO_getInterruptStatus(uint8_t selectedPort,
                                        uint16_t selectedPins);

extern void GPIO_clearInterruptFlag(uint8_t selectedPort,
                                    uint16_t selectedPins);

extern void GPIO_interruptEdgeSelect(uint8_t selectedPort,
                                     uint16_t selectedPins,
                                     uint8_t edgeSelect);

extern void GPIO_setDriveStrength(uint8_t selectedPort,
                                  uint16_t selectedPins,
                                  uint8_t driveStrength);
extern void IOInit();

extern void WDT_A_hold(uint32_t baseAddress);


#if 1  //SYS clock

#define UCS_VLOCLK_FREQUENCY                                              10000
#define UCS_REFOCLK_FREQUENCY                                             32768
#define UCS_CLOCK_DIVIDER_1                                             DIVM__1
#define UCS_CLOCK_DIVIDER_2                                             DIVM__2
#define UCS_CLOCK_DIVIDER_4                                             DIVM__4
#define UCS_CLOCK_DIVIDER_8                                             DIVM__8
#define UCS_CLOCK_DIVIDER_12                                           DIVM__32
#define UCS_CLOCK_DIVIDER_16                                           DIVM__16
#define UCS_CLOCK_DIVIDER_32                                           DIVM__32
#define UCS_ACLK                                                           0x01
#define UCS_MCLK                                                           0x02
#define UCS_SMCLK                                                          0x04
#define UCS_FLLREF                                                         0x08
#define UCS_XT1CLK_SELECT                                          SELM__XT1CLK
#define UCS_VLOCLK_SELECT                                          SELM__VLOCLK
#define UCS_REFOCLK_SELECT                                        SELM__REFOCLK
#define UCS_DCOCLK_SELECT                                          SELM__DCOCLK
#define UCS_DCOCLKDIV_SELECT                                    SELM__DCOCLKDIV
#define UCS_XT2CLK_SELECT                                          SELM__XT2CLK
#define UCS_XCAP_0                                                       XCAP_0
#define UCS_XCAP_1                                                       XCAP_1
#define UCS_XCAP_2                                                       XCAP_2
#define UCS_XCAP_3                                                       XCAP_3
#define UCS_XT1_DRIVE0                                               XT1DRIVE_0
#define UCS_XT1_DRIVE1                                               XT1DRIVE_1
#define UCS_XT1_DRIVE2                                               XT1DRIVE_2
#define UCS_XT1_DRIVE3                                               XT1DRIVE_3
#define UCS_XT1_HIGH_FREQUENCY                                              XTS
#define UCS_XT1_LOW_FREQUENCY                                              0x00
#define UCS_XT2DRIVE_4MHZ_8MHZ                                       XT2DRIVE_0
#define UCS_XT2DRIVE_8MHZ_16MHZ                                      XT2DRIVE_1
#define UCS_XT2DRIVE_16MHZ_24MHZ                                     XT2DRIVE_2
#define UCS_XT2DRIVE_24MHZ_32MHZ                                     XT2DRIVE_3
#define UCS_ACLK                                                           0x01
#define UCS_SMCLK                                                          0x04
#define UCS_MCLK                                                           0x02
#define UCS_MODOSC                                                  MODOSCREQEN
#define UCS_XT2OFFG                                                     XT2OFFG
#define UCS_XT1HFOFFG                                                 XT1HFOFFG
#define UCS_XT1LFOFFG                                                 XT1LFOFFG
#define UCS_DCOFFG                                                       DCOFFG

extern void HHM_SetMCLK (void);
extern void UCS_clockSignalInit( uint32_t baseAddress,
                          uint8_t selectedClockSignal,
                          uint16_t clockSource,
                          uint16_t clockSourceDivider);
extern void UCS_initFLLSettle( uint32_t baseAddress,
                        uint16_t fsystem,
                        uint16_t ratio);
#endif

#endif

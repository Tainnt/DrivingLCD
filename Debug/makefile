################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/ti/ccs901/ccs/tools/compiler/ti-cgt-msp430_15.12.7.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./MSP430F5xx_6xx/device_init.obj" \
"./MSP430F5xx_6xx/lcd.obj" \
"../lnk_msp430f6736.cmd" \
$(GEN_CMDS__FLAG) \
-llibmath.a \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include MSP430F5xx_6xx/subdir_vars.mk
-include subdir_rules.mk
-include MSP430F5xx_6xx/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
MSP430F6736-DrivingLCD.out \

EXE_OUTPUTS__QUOTED += \
"MSP430F6736-DrivingLCD.out" \

BIN_OUTPUTS += \
MSP430F6736-DrivingLCD.txt \

BIN_OUTPUTS__QUOTED += \
"MSP430F6736-DrivingLCD.txt" \


# All Target
all: MSP430F6736-DrivingLCD.out secondary-outputs

# Tool invocations
MSP430F6736-DrivingLCD.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: MSP430 Linker'
	"D:/ti/ccs901/ccs/tools/compiler/ti-cgt-msp430_15.12.7.LTS/bin/cl430" -vmspx --data_model=restricted -O4 --opt_for_speed=1 --use_hw_mpy=F5 --advice:power=all -g --define=__MSP430F6736__ --display_error_number --diag_wrap=off --diag_warning=225 --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal -z -m"MSP430F6736-DrivingLCD.map" --heap_size=80 --stack_size=80 --cinit_hold_wdt=on -i"D:/ti/ccs901/ccs/ccs_base/msp430/include" -i"D:/ti/ccs901/ccs/ccs_base/msp430/lib/5xx_6xx_FRxx" -i"D:/ti/ccs901/ccs/tools/compiler/ti-cgt-msp430_15.12.7.LTS/lib" -i"D:/ti/ccs901/ccs/tools/compiler/ti-cgt-msp430_15.12.7.LTS/include" --reread_libs --display_error_number --diag_wrap=off --warn_sections --xml_link_info="MSP430F6736-DrivingLCD_linkInfo.xml" --use_hw_mpy=F5 --rom_model -o "MSP430F6736-DrivingLCD.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

MSP430F6736-DrivingLCD.txt: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: MSP430 Hex Utility'
	"D:/ti/ccs901/ccs/tools/compiler/ti-cgt-msp430_15.12.7.LTS/bin/hex430" --memwidth=8 --romwidth=8 --ti_txt -o "MSP430F6736-DrivingLCD.txt" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.obj" "MSP430F5xx_6xx\device_init.obj" "MSP430F5xx_6xx\lcd.obj" 
	-$(RM) "main.d" "MSP430F5xx_6xx\device_init.d" "MSP430F5xx_6xx\lcd.d" 
	-@echo 'Finished clean'
	-@echo ' '

secondary-outputs: $(BIN_OUTPUTS)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets


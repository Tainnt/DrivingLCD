################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccs901/ccs/tools/compiler/ti-cgt-msp430_15.12.7.LTS/bin/cl430" -vmspx --data_model=restricted -O4 --opt_for_speed=1 --use_hw_mpy=F5 --include_path="D:/ti/ccs901/ccs/ccs_base/msp430/include" --include_path="D:/ti/ccs901/ccs/tools/compiler/ti-cgt-msp430_15.12.7.LTS/include" --advice:power=all -g --define=__MSP430F6736__ --display_error_number --diag_wrap=off --diag_warning=225 --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '



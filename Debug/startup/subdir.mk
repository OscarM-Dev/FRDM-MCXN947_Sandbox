################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../startup/boot_multicore_slave.c \
../startup/startup_mcxn947_cm33_core0.c 

C_DEPS += \
./startup/boot_multicore_slave.d \
./startup/startup_mcxn947_cm33_core0.d 

OBJS += \
./startup/boot_multicore_slave.o \
./startup/startup_mcxn947_cm33_core0.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.c startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DMCUXPRESSO_SDK -DCPU_MCXN947VDF_cm33_core0 -DSDK_DEBUGCONSOLE=1 -DMCUX_META_BUILD -DMCXN947_cm33_core0_SERIES -DCPU_MCXN947VDF -DCPU_MCXN947VDF_cm33 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"C:\Users\Familia\Documents\Especialidad_ITESO\Semestre_2\RTOS\repo\FRDM-MCXN947_Sandbox\source" -I"C:\Users\Familia\Documents\Especialidad_ITESO\Semestre_2\RTOS\repo\FRDM-MCXN947_Sandbox\source\StateMachine\include" -I"C:\Users\Familia\Documents\Especialidad_ITESO\Semestre_2\RTOS\repo\FRDM-MCXN947_Sandbox\source\Queue\include" -I"C:\Users\Familia\Documents\Especialidad_ITESO\Semestre_2\RTOS\repo\FRDM-MCXN947_Sandbox\drivers" -I"C:\Users\Familia\Documents\Especialidad_ITESO\Semestre_2\RTOS\repo\FRDM-MCXN947_Sandbox\CMSIS" -I"C:\Users\Familia\Documents\Especialidad_ITESO\Semestre_2\RTOS\repo\FRDM-MCXN947_Sandbox\CMSIS\m-profile" -I"C:\Users\Familia\Documents\Especialidad_ITESO\Semestre_2\RTOS\repo\FRDM-MCXN947_Sandbox\device" -I"C:\Users\Familia\Documents\Especialidad_ITESO\Semestre_2\RTOS\repo\FRDM-MCXN947_Sandbox\device\periph" -I"C:\Users\Familia\Documents\Especialidad_ITESO\Semestre_2\RTOS\repo\FRDM-MCXN947_Sandbox\utilities" -I"C:\Users\Familia\Documents\Especialidad_ITESO\Semestre_2\RTOS\repo\FRDM-MCXN947_Sandbox\utilities\str" -I"C:\Users\Familia\Documents\Especialidad_ITESO\Semestre_2\RTOS\repo\FRDM-MCXN947_Sandbox\utilities\debug_console_lite" -I"C:\Users\Familia\Documents\Especialidad_ITESO\Semestre_2\RTOS\repo\FRDM-MCXN947_Sandbox\component\uart" -I"C:\Users\Familia\Documents\Especialidad_ITESO\Semestre_2\RTOS\repo\FRDM-MCXN947_Sandbox\board" -O0 -fno-common -g3 -gdwarf-4 -mcpu=cortex-m33 -c -ffunction-sections -fdata-sections -fno-builtin -imacros "C:\Users\Familia\Documents\Especialidad_ITESO\Semestre_2\RTOS\repo\FRDM-MCXN947_Sandbox\source\mcux_config.h" -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-startup

clean-startup:
	-$(RM) ./startup/boot_multicore_slave.d ./startup/boot_multicore_slave.o ./startup/startup_mcxn947_cm33_core0.d ./startup/startup_mcxn947_cm33_core0.o

.PHONY: clean-startup


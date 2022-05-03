#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Proyecto.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Proyecto.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../oscilator.c ../timers.c ../UART2_RS232.c ../LCD.c ../utilidades.c ../memoria.c ../main_Proy.c ../ADC1.c ../i2c_funciones.c ../CN.c ../GPIO.c ../PWM.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/oscilator.o ${OBJECTDIR}/_ext/1472/timers.o ${OBJECTDIR}/_ext/1472/UART2_RS232.o ${OBJECTDIR}/_ext/1472/LCD.o ${OBJECTDIR}/_ext/1472/utilidades.o ${OBJECTDIR}/_ext/1472/memoria.o ${OBJECTDIR}/_ext/1472/main_Proy.o ${OBJECTDIR}/_ext/1472/ADC1.o ${OBJECTDIR}/_ext/1472/i2c_funciones.o ${OBJECTDIR}/_ext/1472/CN.o ${OBJECTDIR}/_ext/1472/GPIO.o ${OBJECTDIR}/_ext/1472/PWM.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/oscilator.o.d ${OBJECTDIR}/_ext/1472/timers.o.d ${OBJECTDIR}/_ext/1472/UART2_RS232.o.d ${OBJECTDIR}/_ext/1472/LCD.o.d ${OBJECTDIR}/_ext/1472/utilidades.o.d ${OBJECTDIR}/_ext/1472/memoria.o.d ${OBJECTDIR}/_ext/1472/main_Proy.o.d ${OBJECTDIR}/_ext/1472/ADC1.o.d ${OBJECTDIR}/_ext/1472/i2c_funciones.o.d ${OBJECTDIR}/_ext/1472/CN.o.d ${OBJECTDIR}/_ext/1472/GPIO.o.d ${OBJECTDIR}/_ext/1472/PWM.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/oscilator.o ${OBJECTDIR}/_ext/1472/timers.o ${OBJECTDIR}/_ext/1472/UART2_RS232.o ${OBJECTDIR}/_ext/1472/LCD.o ${OBJECTDIR}/_ext/1472/utilidades.o ${OBJECTDIR}/_ext/1472/memoria.o ${OBJECTDIR}/_ext/1472/main_Proy.o ${OBJECTDIR}/_ext/1472/ADC1.o ${OBJECTDIR}/_ext/1472/i2c_funciones.o ${OBJECTDIR}/_ext/1472/CN.o ${OBJECTDIR}/_ext/1472/GPIO.o ${OBJECTDIR}/_ext/1472/PWM.o

# Source Files
SOURCEFILES=../oscilator.c ../timers.c ../UART2_RS232.c ../LCD.c ../utilidades.c ../memoria.c ../main_Proy.c ../ADC1.c ../i2c_funciones.c ../CN.c ../GPIO.c ../PWM.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Proyecto.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24HJ256GP610A
MP_LINKER_FILE_OPTION=,--script=p24HJ256GP610A.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/oscilator.o: ../oscilator.c  .generated_files/flags/default/dfb6f2c717234141254e9caa32467e843fba1553 .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/oscilator.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/oscilator.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../oscilator.c  -o ${OBJECTDIR}/_ext/1472/oscilator.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/oscilator.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/timers.o: ../timers.c  .generated_files/flags/default/cddca828d5adead84cbdd794bd0b593b77e609f9 .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/timers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../timers.c  -o ${OBJECTDIR}/_ext/1472/timers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/timers.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/UART2_RS232.o: ../UART2_RS232.c  .generated_files/flags/default/3d44ec897f10f05667ca3d3b7f3fab7fbfbe238d .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/UART2_RS232.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/UART2_RS232.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../UART2_RS232.c  -o ${OBJECTDIR}/_ext/1472/UART2_RS232.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/UART2_RS232.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/LCD.o: ../LCD.c  .generated_files/flags/default/f5e7d2ece4d2cf54ba1873b11dd4d374a38a86f4 .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../LCD.c  -o ${OBJECTDIR}/_ext/1472/LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/LCD.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/utilidades.o: ../utilidades.c  .generated_files/flags/default/fdb96dc250ef7f4b4f15be502921c80f15d7114b .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/utilidades.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/utilidades.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../utilidades.c  -o ${OBJECTDIR}/_ext/1472/utilidades.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/utilidades.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/memoria.o: ../memoria.c  .generated_files/flags/default/fcac2fec1bcebbb0118cb0fa41a840784c3107b7 .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/memoria.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/memoria.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../memoria.c  -o ${OBJECTDIR}/_ext/1472/memoria.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/memoria.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/main_Proy.o: ../main_Proy.c  .generated_files/flags/default/cca1a3da945dcdb45569df23284bec17be83102b .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main_Proy.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main_Proy.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../main_Proy.c  -o ${OBJECTDIR}/_ext/1472/main_Proy.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/main_Proy.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/ADC1.o: ../ADC1.c  .generated_files/flags/default/6712543c3a5932e8012c7d5887eca6a76a2eae41 .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ADC1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ADC1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ADC1.c  -o ${OBJECTDIR}/_ext/1472/ADC1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/ADC1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/i2c_funciones.o: ../i2c_funciones.c  .generated_files/flags/default/cf76440d13cc484b1642b3faa713e128e922252e .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/i2c_funciones.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/i2c_funciones.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../i2c_funciones.c  -o ${OBJECTDIR}/_ext/1472/i2c_funciones.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/i2c_funciones.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/CN.o: ../CN.c  .generated_files/flags/default/3ef94439a0ca24575ce3a30ec503e66ce3dc3053 .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/CN.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/CN.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../CN.c  -o ${OBJECTDIR}/_ext/1472/CN.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/CN.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/GPIO.o: ../GPIO.c  .generated_files/flags/default/a72b3b225bbbd5ed9857b14eb4d14a06fe2e3ac3 .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/GPIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../GPIO.c  -o ${OBJECTDIR}/_ext/1472/GPIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/GPIO.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/PWM.o: ../PWM.c  .generated_files/flags/default/8aa0c440d95bfc2fb43d9edf6fab1cc3fa4d0483 .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/PWM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PWM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../PWM.c  -o ${OBJECTDIR}/_ext/1472/PWM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/PWM.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/1472/oscilator.o: ../oscilator.c  .generated_files/flags/default/1a2722823efd482f92ac2721ef5a618a3e1f876b .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/oscilator.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/oscilator.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../oscilator.c  -o ${OBJECTDIR}/_ext/1472/oscilator.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/oscilator.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/timers.o: ../timers.c  .generated_files/flags/default/1889090eef6437804b4b4c873df91c9c13e107ae .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/timers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../timers.c  -o ${OBJECTDIR}/_ext/1472/timers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/timers.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/UART2_RS232.o: ../UART2_RS232.c  .generated_files/flags/default/e4c67ce111d223c731d13047c08756858e46ee9a .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/UART2_RS232.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/UART2_RS232.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../UART2_RS232.c  -o ${OBJECTDIR}/_ext/1472/UART2_RS232.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/UART2_RS232.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/LCD.o: ../LCD.c  .generated_files/flags/default/2109ad70afaaf7a5ee648101d752673580fa1ea5 .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../LCD.c  -o ${OBJECTDIR}/_ext/1472/LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/LCD.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/utilidades.o: ../utilidades.c  .generated_files/flags/default/ac9e6dd13fe6d68d250fa81aa023de2b6e454bf4 .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/utilidades.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/utilidades.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../utilidades.c  -o ${OBJECTDIR}/_ext/1472/utilidades.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/utilidades.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/memoria.o: ../memoria.c  .generated_files/flags/default/2b2e37e50e9dfdcae4c99b6c5007ebd31a9149e9 .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/memoria.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/memoria.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../memoria.c  -o ${OBJECTDIR}/_ext/1472/memoria.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/memoria.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/main_Proy.o: ../main_Proy.c  .generated_files/flags/default/3e9bcd37c628657c1d23d2b36b42b378dc669418 .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main_Proy.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main_Proy.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../main_Proy.c  -o ${OBJECTDIR}/_ext/1472/main_Proy.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/main_Proy.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/ADC1.o: ../ADC1.c  .generated_files/flags/default/46793a8f8d4f2eb553dc100ee12b3e95aab93b9b .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ADC1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ADC1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ADC1.c  -o ${OBJECTDIR}/_ext/1472/ADC1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/ADC1.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/i2c_funciones.o: ../i2c_funciones.c  .generated_files/flags/default/1855440e6c34958e109b63b378b9ab2d5cd4cff6 .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/i2c_funciones.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/i2c_funciones.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../i2c_funciones.c  -o ${OBJECTDIR}/_ext/1472/i2c_funciones.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/i2c_funciones.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/CN.o: ../CN.c  .generated_files/flags/default/3e62ba5faefcfd2187d399e37b049256be58baae .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/CN.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/CN.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../CN.c  -o ${OBJECTDIR}/_ext/1472/CN.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/CN.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/GPIO.o: ../GPIO.c  .generated_files/flags/default/c57fda028505f934d56505301c41c2027a0b4f2c .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/GPIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../GPIO.c  -o ${OBJECTDIR}/_ext/1472/GPIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/GPIO.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/PWM.o: ../PWM.c  .generated_files/flags/default/8522cd2c66401410c00e581dc7fdefadcfd16d0f .generated_files/flags/default/d5824b4ff755718293ec9fe1ef749f9e9908baab
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/PWM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PWM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../PWM.c  -o ${OBJECTDIR}/_ext/1472/PWM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/PWM.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Proyecto.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/Proyecto.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h"  -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_REAL_ICE=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/Proyecto.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/Proyecto.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../../../Applications/microchip/xc16/v1.61/support/PIC24H/h" -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}/xc16-bin2hex ${DISTDIR}/Proyecto.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif

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
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/mamba3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/mamba3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/drivers/delay.c src/drivers/mma8450.c src/drivers/sysclk.c src/drivers/sw_i2c.c src/drivers/uart.c src/drivers/eeprom.c src/drivers/adc.c src/modules/rd_buffer.c src/modules/timers.c src/modules/device_config.c src/modules/scheduler.c src/modules/serialport.c src/modules/string_utils.c src/modules/syntax.c src/modules/classic_detector.c src/modules/peak_detector.c src/modules/detection.c src/modules/on_parameter_found.c src/startup/startup.c src/interrupts.c src/main.c src/drivers/gpio.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/drivers/delay.p1 ${OBJECTDIR}/src/drivers/mma8450.p1 ${OBJECTDIR}/src/drivers/sysclk.p1 ${OBJECTDIR}/src/drivers/sw_i2c.p1 ${OBJECTDIR}/src/drivers/uart.p1 ${OBJECTDIR}/src/drivers/eeprom.p1 ${OBJECTDIR}/src/drivers/adc.p1 ${OBJECTDIR}/src/modules/rd_buffer.p1 ${OBJECTDIR}/src/modules/timers.p1 ${OBJECTDIR}/src/modules/device_config.p1 ${OBJECTDIR}/src/modules/scheduler.p1 ${OBJECTDIR}/src/modules/serialport.p1 ${OBJECTDIR}/src/modules/string_utils.p1 ${OBJECTDIR}/src/modules/syntax.p1 ${OBJECTDIR}/src/modules/classic_detector.p1 ${OBJECTDIR}/src/modules/peak_detector.p1 ${OBJECTDIR}/src/modules/detection.p1 ${OBJECTDIR}/src/modules/on_parameter_found.p1 ${OBJECTDIR}/src/startup/startup.p1 ${OBJECTDIR}/src/interrupts.p1 ${OBJECTDIR}/src/main.p1 ${OBJECTDIR}/src/drivers/gpio.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/src/drivers/delay.p1.d ${OBJECTDIR}/src/drivers/mma8450.p1.d ${OBJECTDIR}/src/drivers/sysclk.p1.d ${OBJECTDIR}/src/drivers/sw_i2c.p1.d ${OBJECTDIR}/src/drivers/uart.p1.d ${OBJECTDIR}/src/drivers/eeprom.p1.d ${OBJECTDIR}/src/drivers/adc.p1.d ${OBJECTDIR}/src/modules/rd_buffer.p1.d ${OBJECTDIR}/src/modules/timers.p1.d ${OBJECTDIR}/src/modules/device_config.p1.d ${OBJECTDIR}/src/modules/scheduler.p1.d ${OBJECTDIR}/src/modules/serialport.p1.d ${OBJECTDIR}/src/modules/string_utils.p1.d ${OBJECTDIR}/src/modules/syntax.p1.d ${OBJECTDIR}/src/modules/classic_detector.p1.d ${OBJECTDIR}/src/modules/peak_detector.p1.d ${OBJECTDIR}/src/modules/detection.p1.d ${OBJECTDIR}/src/modules/on_parameter_found.p1.d ${OBJECTDIR}/src/startup/startup.p1.d ${OBJECTDIR}/src/interrupts.p1.d ${OBJECTDIR}/src/main.p1.d ${OBJECTDIR}/src/drivers/gpio.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/drivers/delay.p1 ${OBJECTDIR}/src/drivers/mma8450.p1 ${OBJECTDIR}/src/drivers/sysclk.p1 ${OBJECTDIR}/src/drivers/sw_i2c.p1 ${OBJECTDIR}/src/drivers/uart.p1 ${OBJECTDIR}/src/drivers/eeprom.p1 ${OBJECTDIR}/src/drivers/adc.p1 ${OBJECTDIR}/src/modules/rd_buffer.p1 ${OBJECTDIR}/src/modules/timers.p1 ${OBJECTDIR}/src/modules/device_config.p1 ${OBJECTDIR}/src/modules/scheduler.p1 ${OBJECTDIR}/src/modules/serialport.p1 ${OBJECTDIR}/src/modules/string_utils.p1 ${OBJECTDIR}/src/modules/syntax.p1 ${OBJECTDIR}/src/modules/classic_detector.p1 ${OBJECTDIR}/src/modules/peak_detector.p1 ${OBJECTDIR}/src/modules/detection.p1 ${OBJECTDIR}/src/modules/on_parameter_found.p1 ${OBJECTDIR}/src/startup/startup.p1 ${OBJECTDIR}/src/interrupts.p1 ${OBJECTDIR}/src/main.p1 ${OBJECTDIR}/src/drivers/gpio.p1

# Source Files
SOURCEFILES=src/drivers/delay.c src/drivers/mma8450.c src/drivers/sysclk.c src/drivers/sw_i2c.c src/drivers/uart.c src/drivers/eeprom.c src/drivers/adc.c src/modules/rd_buffer.c src/modules/timers.c src/modules/device_config.c src/modules/scheduler.c src/modules/serialport.c src/modules/string_utils.c src/modules/syntax.c src/modules/classic_detector.c src/modules/peak_detector.c src/modules/detection.c src/modules/on_parameter_found.c src/startup/startup.c src/interrupts.c src/main.c src/drivers/gpio.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/mamba3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F45K20
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/drivers/delay.p1: src/drivers/delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/drivers" 
	@${RM} ${OBJECTDIR}/src/drivers/delay.p1.d 
	@${RM} ${OBJECTDIR}/src/drivers/delay.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/drivers/delay.p1  src/drivers/delay.c 
	@-${MV} ${OBJECTDIR}/src/drivers/delay.d ${OBJECTDIR}/src/drivers/delay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/drivers/delay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/drivers/mma8450.p1: src/drivers/mma8450.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/drivers" 
	@${RM} ${OBJECTDIR}/src/drivers/mma8450.p1.d 
	@${RM} ${OBJECTDIR}/src/drivers/mma8450.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/drivers/mma8450.p1  src/drivers/mma8450.c 
	@-${MV} ${OBJECTDIR}/src/drivers/mma8450.d ${OBJECTDIR}/src/drivers/mma8450.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/drivers/mma8450.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/drivers/sysclk.p1: src/drivers/sysclk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/drivers" 
	@${RM} ${OBJECTDIR}/src/drivers/sysclk.p1.d 
	@${RM} ${OBJECTDIR}/src/drivers/sysclk.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/drivers/sysclk.p1  src/drivers/sysclk.c 
	@-${MV} ${OBJECTDIR}/src/drivers/sysclk.d ${OBJECTDIR}/src/drivers/sysclk.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/drivers/sysclk.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/drivers/sw_i2c.p1: src/drivers/sw_i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/drivers" 
	@${RM} ${OBJECTDIR}/src/drivers/sw_i2c.p1.d 
	@${RM} ${OBJECTDIR}/src/drivers/sw_i2c.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/drivers/sw_i2c.p1  src/drivers/sw_i2c.c 
	@-${MV} ${OBJECTDIR}/src/drivers/sw_i2c.d ${OBJECTDIR}/src/drivers/sw_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/drivers/sw_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/drivers/uart.p1: src/drivers/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/drivers" 
	@${RM} ${OBJECTDIR}/src/drivers/uart.p1.d 
	@${RM} ${OBJECTDIR}/src/drivers/uart.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/drivers/uart.p1  src/drivers/uart.c 
	@-${MV} ${OBJECTDIR}/src/drivers/uart.d ${OBJECTDIR}/src/drivers/uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/drivers/uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/drivers/eeprom.p1: src/drivers/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/drivers" 
	@${RM} ${OBJECTDIR}/src/drivers/eeprom.p1.d 
	@${RM} ${OBJECTDIR}/src/drivers/eeprom.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/drivers/eeprom.p1  src/drivers/eeprom.c 
	@-${MV} ${OBJECTDIR}/src/drivers/eeprom.d ${OBJECTDIR}/src/drivers/eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/drivers/eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/drivers/adc.p1: src/drivers/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/drivers" 
	@${RM} ${OBJECTDIR}/src/drivers/adc.p1.d 
	@${RM} ${OBJECTDIR}/src/drivers/adc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/drivers/adc.p1  src/drivers/adc.c 
	@-${MV} ${OBJECTDIR}/src/drivers/adc.d ${OBJECTDIR}/src/drivers/adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/drivers/adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/rd_buffer.p1: src/modules/rd_buffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/rd_buffer.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/rd_buffer.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/rd_buffer.p1  src/modules/rd_buffer.c 
	@-${MV} ${OBJECTDIR}/src/modules/rd_buffer.d ${OBJECTDIR}/src/modules/rd_buffer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/rd_buffer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/timers.p1: src/modules/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/timers.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/timers.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/timers.p1  src/modules/timers.c 
	@-${MV} ${OBJECTDIR}/src/modules/timers.d ${OBJECTDIR}/src/modules/timers.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/timers.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/device_config.p1: src/modules/device_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/device_config.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/device_config.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/device_config.p1  src/modules/device_config.c 
	@-${MV} ${OBJECTDIR}/src/modules/device_config.d ${OBJECTDIR}/src/modules/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/scheduler.p1: src/modules/scheduler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/scheduler.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/scheduler.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/scheduler.p1  src/modules/scheduler.c 
	@-${MV} ${OBJECTDIR}/src/modules/scheduler.d ${OBJECTDIR}/src/modules/scheduler.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/scheduler.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/serialport.p1: src/modules/serialport.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/serialport.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/serialport.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/serialport.p1  src/modules/serialport.c 
	@-${MV} ${OBJECTDIR}/src/modules/serialport.d ${OBJECTDIR}/src/modules/serialport.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/serialport.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/string_utils.p1: src/modules/string_utils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/string_utils.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/string_utils.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/string_utils.p1  src/modules/string_utils.c 
	@-${MV} ${OBJECTDIR}/src/modules/string_utils.d ${OBJECTDIR}/src/modules/string_utils.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/string_utils.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/syntax.p1: src/modules/syntax.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/syntax.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/syntax.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/syntax.p1  src/modules/syntax.c 
	@-${MV} ${OBJECTDIR}/src/modules/syntax.d ${OBJECTDIR}/src/modules/syntax.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/syntax.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/classic_detector.p1: src/modules/classic_detector.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/classic_detector.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/classic_detector.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/classic_detector.p1  src/modules/classic_detector.c 
	@-${MV} ${OBJECTDIR}/src/modules/classic_detector.d ${OBJECTDIR}/src/modules/classic_detector.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/classic_detector.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/peak_detector.p1: src/modules/peak_detector.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/peak_detector.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/peak_detector.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/peak_detector.p1  src/modules/peak_detector.c 
	@-${MV} ${OBJECTDIR}/src/modules/peak_detector.d ${OBJECTDIR}/src/modules/peak_detector.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/peak_detector.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/detection.p1: src/modules/detection.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/detection.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/detection.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/detection.p1  src/modules/detection.c 
	@-${MV} ${OBJECTDIR}/src/modules/detection.d ${OBJECTDIR}/src/modules/detection.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/detection.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/on_parameter_found.p1: src/modules/on_parameter_found.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/on_parameter_found.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/on_parameter_found.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/on_parameter_found.p1  src/modules/on_parameter_found.c 
	@-${MV} ${OBJECTDIR}/src/modules/on_parameter_found.d ${OBJECTDIR}/src/modules/on_parameter_found.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/on_parameter_found.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/startup/startup.p1: src/startup/startup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/startup" 
	@${RM} ${OBJECTDIR}/src/startup/startup.p1.d 
	@${RM} ${OBJECTDIR}/src/startup/startup.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/startup/startup.p1  src/startup/startup.c 
	@-${MV} ${OBJECTDIR}/src/startup/startup.d ${OBJECTDIR}/src/startup/startup.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/startup/startup.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/interrupts.p1: src/interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/interrupts.p1.d 
	@${RM} ${OBJECTDIR}/src/interrupts.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/interrupts.p1  src/interrupts.c 
	@-${MV} ${OBJECTDIR}/src/interrupts.d ${OBJECTDIR}/src/interrupts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/interrupts.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/main.p1: src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.p1.d 
	@${RM} ${OBJECTDIR}/src/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/main.p1  src/main.c 
	@-${MV} ${OBJECTDIR}/src/main.d ${OBJECTDIR}/src/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/drivers/gpio.p1: src/drivers/gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/drivers" 
	@${RM} ${OBJECTDIR}/src/drivers/gpio.p1.d 
	@${RM} ${OBJECTDIR}/src/drivers/gpio.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/drivers/gpio.p1  src/drivers/gpio.c 
	@-${MV} ${OBJECTDIR}/src/drivers/gpio.d ${OBJECTDIR}/src/drivers/gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/drivers/gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/src/drivers/delay.p1: src/drivers/delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/drivers" 
	@${RM} ${OBJECTDIR}/src/drivers/delay.p1.d 
	@${RM} ${OBJECTDIR}/src/drivers/delay.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/drivers/delay.p1  src/drivers/delay.c 
	@-${MV} ${OBJECTDIR}/src/drivers/delay.d ${OBJECTDIR}/src/drivers/delay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/drivers/delay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/drivers/mma8450.p1: src/drivers/mma8450.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/drivers" 
	@${RM} ${OBJECTDIR}/src/drivers/mma8450.p1.d 
	@${RM} ${OBJECTDIR}/src/drivers/mma8450.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/drivers/mma8450.p1  src/drivers/mma8450.c 
	@-${MV} ${OBJECTDIR}/src/drivers/mma8450.d ${OBJECTDIR}/src/drivers/mma8450.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/drivers/mma8450.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/drivers/sysclk.p1: src/drivers/sysclk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/drivers" 
	@${RM} ${OBJECTDIR}/src/drivers/sysclk.p1.d 
	@${RM} ${OBJECTDIR}/src/drivers/sysclk.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/drivers/sysclk.p1  src/drivers/sysclk.c 
	@-${MV} ${OBJECTDIR}/src/drivers/sysclk.d ${OBJECTDIR}/src/drivers/sysclk.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/drivers/sysclk.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/drivers/sw_i2c.p1: src/drivers/sw_i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/drivers" 
	@${RM} ${OBJECTDIR}/src/drivers/sw_i2c.p1.d 
	@${RM} ${OBJECTDIR}/src/drivers/sw_i2c.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/drivers/sw_i2c.p1  src/drivers/sw_i2c.c 
	@-${MV} ${OBJECTDIR}/src/drivers/sw_i2c.d ${OBJECTDIR}/src/drivers/sw_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/drivers/sw_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/drivers/uart.p1: src/drivers/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/drivers" 
	@${RM} ${OBJECTDIR}/src/drivers/uart.p1.d 
	@${RM} ${OBJECTDIR}/src/drivers/uart.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/drivers/uart.p1  src/drivers/uart.c 
	@-${MV} ${OBJECTDIR}/src/drivers/uart.d ${OBJECTDIR}/src/drivers/uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/drivers/uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/drivers/eeprom.p1: src/drivers/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/drivers" 
	@${RM} ${OBJECTDIR}/src/drivers/eeprom.p1.d 
	@${RM} ${OBJECTDIR}/src/drivers/eeprom.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/drivers/eeprom.p1  src/drivers/eeprom.c 
	@-${MV} ${OBJECTDIR}/src/drivers/eeprom.d ${OBJECTDIR}/src/drivers/eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/drivers/eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/drivers/adc.p1: src/drivers/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/drivers" 
	@${RM} ${OBJECTDIR}/src/drivers/adc.p1.d 
	@${RM} ${OBJECTDIR}/src/drivers/adc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/drivers/adc.p1  src/drivers/adc.c 
	@-${MV} ${OBJECTDIR}/src/drivers/adc.d ${OBJECTDIR}/src/drivers/adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/drivers/adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/rd_buffer.p1: src/modules/rd_buffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/rd_buffer.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/rd_buffer.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/rd_buffer.p1  src/modules/rd_buffer.c 
	@-${MV} ${OBJECTDIR}/src/modules/rd_buffer.d ${OBJECTDIR}/src/modules/rd_buffer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/rd_buffer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/timers.p1: src/modules/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/timers.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/timers.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/timers.p1  src/modules/timers.c 
	@-${MV} ${OBJECTDIR}/src/modules/timers.d ${OBJECTDIR}/src/modules/timers.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/timers.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/device_config.p1: src/modules/device_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/device_config.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/device_config.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/device_config.p1  src/modules/device_config.c 
	@-${MV} ${OBJECTDIR}/src/modules/device_config.d ${OBJECTDIR}/src/modules/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/scheduler.p1: src/modules/scheduler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/scheduler.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/scheduler.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/scheduler.p1  src/modules/scheduler.c 
	@-${MV} ${OBJECTDIR}/src/modules/scheduler.d ${OBJECTDIR}/src/modules/scheduler.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/scheduler.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/serialport.p1: src/modules/serialport.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/serialport.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/serialport.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/serialport.p1  src/modules/serialport.c 
	@-${MV} ${OBJECTDIR}/src/modules/serialport.d ${OBJECTDIR}/src/modules/serialport.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/serialport.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/string_utils.p1: src/modules/string_utils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/string_utils.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/string_utils.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/string_utils.p1  src/modules/string_utils.c 
	@-${MV} ${OBJECTDIR}/src/modules/string_utils.d ${OBJECTDIR}/src/modules/string_utils.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/string_utils.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/syntax.p1: src/modules/syntax.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/syntax.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/syntax.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/syntax.p1  src/modules/syntax.c 
	@-${MV} ${OBJECTDIR}/src/modules/syntax.d ${OBJECTDIR}/src/modules/syntax.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/syntax.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/classic_detector.p1: src/modules/classic_detector.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/classic_detector.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/classic_detector.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/classic_detector.p1  src/modules/classic_detector.c 
	@-${MV} ${OBJECTDIR}/src/modules/classic_detector.d ${OBJECTDIR}/src/modules/classic_detector.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/classic_detector.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/peak_detector.p1: src/modules/peak_detector.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/peak_detector.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/peak_detector.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/peak_detector.p1  src/modules/peak_detector.c 
	@-${MV} ${OBJECTDIR}/src/modules/peak_detector.d ${OBJECTDIR}/src/modules/peak_detector.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/peak_detector.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/detection.p1: src/modules/detection.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/detection.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/detection.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/detection.p1  src/modules/detection.c 
	@-${MV} ${OBJECTDIR}/src/modules/detection.d ${OBJECTDIR}/src/modules/detection.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/detection.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/modules/on_parameter_found.p1: src/modules/on_parameter_found.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/on_parameter_found.p1.d 
	@${RM} ${OBJECTDIR}/src/modules/on_parameter_found.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/modules/on_parameter_found.p1  src/modules/on_parameter_found.c 
	@-${MV} ${OBJECTDIR}/src/modules/on_parameter_found.d ${OBJECTDIR}/src/modules/on_parameter_found.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/modules/on_parameter_found.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/startup/startup.p1: src/startup/startup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/startup" 
	@${RM} ${OBJECTDIR}/src/startup/startup.p1.d 
	@${RM} ${OBJECTDIR}/src/startup/startup.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/startup/startup.p1  src/startup/startup.c 
	@-${MV} ${OBJECTDIR}/src/startup/startup.d ${OBJECTDIR}/src/startup/startup.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/startup/startup.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/interrupts.p1: src/interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/interrupts.p1.d 
	@${RM} ${OBJECTDIR}/src/interrupts.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/interrupts.p1  src/interrupts.c 
	@-${MV} ${OBJECTDIR}/src/interrupts.d ${OBJECTDIR}/src/interrupts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/interrupts.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/main.p1: src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.p1.d 
	@${RM} ${OBJECTDIR}/src/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/main.p1  src/main.c 
	@-${MV} ${OBJECTDIR}/src/main.d ${OBJECTDIR}/src/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/drivers/gpio.p1: src/drivers/gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/drivers" 
	@${RM} ${OBJECTDIR}/src/drivers/gpio.p1.d 
	@${RM} ${OBJECTDIR}/src/drivers/gpio.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/src/drivers/gpio.p1  src/drivers/gpio.c 
	@-${MV} ${OBJECTDIR}/src/drivers/gpio.d ${OBJECTDIR}/src/drivers/gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/drivers/gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/mamba3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/mamba3.X.${IMAGE_TYPE}.map  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     --rom=default,-7dc0-7fff --ram=default,-5f4-5ff,-f9c-f9c,-fd4-fd4,-fdb-fdf,-fe3-fe7,-feb-fef,-ffd-fff  -odist/${CND_CONF}/${IMAGE_TYPE}/mamba3.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/mamba3.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/mamba3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/mamba3.X.${IMAGE_TYPE}.map  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 -I"src" -I"src/init" -I"src/drivers" -I"src/startup" -I"src/modules" --warn=0 --asmlist --summary=default,-psect,-class,+mem,+hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+download,+config,+clib,+plib "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -odist/${CND_CONF}/${IMAGE_TYPE}/mamba3.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif

/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : LEDG.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : LED
**     Version     : Component 01.063, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-12-29, 14:20, # CodeGen: 231
**     Abstract    :
**          This component implements a universal driver for a single LED.
**     Settings    :
**          Component name                                 : LEDG
**          Turned On with initialization                  : no
**          HW Interface                                   : 
**            On/Off                                       : Disabled
**            PWM                                          : Enabled
**              PWM                                        : PWM
**            High Value means ON                          : no
**          Shell                                          : Enabled
**            Shell                                        : FSSH1
**            Utility                                      : UTIL1
**     Contents    :
**         On           - void LEDG_On(void);
**         Off          - void LEDG_Off(void);
**         Neg          - void LEDG_Neg(void);
**         Get          - byte LEDG_Get(void);
**         Put          - void LEDG_Put(byte val);
**         Init         - void LEDG_Init(void);
**         Deinit       - void LEDG_Deinit(void);
**         ParseCommand - byte LEDG_ParseCommand(const unsigned char *cmd, bool *handled, const...
**         SetRatio16   - void LEDG_SetRatio16(word ratio);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Copyright Erich Styger, 2012, all rights reserved.
**     This an open source software implementing an LED driver using Processor Expert.
**     This is a free software and is opened for education, research and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/

#ifndef __LEDG_H
#define __LEDG_H

/* MODULE LEDG. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "Inhr2.h"
#include "FSSH1.h"
#include "UTIL1.h"

#include "Cpu.h"

#define LEDG_ClrVal()    Inhr2_SetRatio16(0x0) /* put the pin on low level */
#define LEDG_SetVal()    Inhr2_SetRatio16(0xffff) /* put the pin on high level */
#define LEDG_SetInput()  /* not possible! */ /* use the pin as input pin */
#define LEDG_SetOutput() /* not possible! */ /* use the pin as ouput pin */
extern uint16_t LEDG_currPWM; /* current 16bit PWM value */

#define LEDG_PARSE_COMMAND_ENABLED  1  /* set to 1 if method ParseCommand() is present, 0 otherwise */


#define LEDG_On() LEDG_SetRatio16(0xffff)
/*
** ===================================================================
**     Method      :  LEDG_On (component LED)
**
**     Description :
**         This turns the LED on.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LEDG_Off() LEDG_SetRatio16(0x0)
/*
** ===================================================================
**     Method      :  LEDG_Off (component LED)
**
**     Description :
**         This turns the LED off.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LEDG_Neg() LEDG_SetRatio16(0xffff-LEDG_currPWM)
/*
** ===================================================================
**     Method      :  LEDG_Neg (component LED)
**
**     Description :
**         This negates/toggles the LED
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LEDG_Get() (LEDG_currPWM!=0)
/*
** ===================================================================
**     Method      :  LEDG_Get (component LED)
**
**     Description :
**         This returns logical 1 in case the LED is on, 0 otherwise.
**     Parameters  : None
**     Returns     :
**         ---             - Status of the LED (on or off)
** ===================================================================
*/

#define LEDG_Init() LEDG_Off()
/*
** ===================================================================
**     Method      :  LEDG_Init (component LED)
**
**     Description :
**         Performs the LED driver initialization.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LEDG_Put(val)  ((val) ? LEDG_On() : LEDG_Off())
/*
** ===================================================================
**     Method      :  LEDG_Put (component LED)
**
**     Description :
**         Turns the LED on or off.
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - value to define if the LED has to be on or
**                           off.
**     Returns     : Nothing
** ===================================================================
*/

void LEDG_Deinit(void);
/*
** ===================================================================
**     Method      :  LEDG_Deinit (component LED)
**
**     Description :
**         Deinitializes the driver
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

byte LEDG_ParseCommand(const unsigned char *cmd, bool *handled, const FSSH1_StdIOType *io);
/*
** ===================================================================
**     Method      :  LEDG_ParseCommand (component LED)
**
**     Description :
**         Shell Command Line parser
**     Parameters  :
**         NAME            - DESCRIPTION
**       * cmd             - Pointer to command string
**       * handled         - Pointer to variable which tells if
**                           the command has been handled or not
**       * io              - Pointer to I/O structure
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

void LEDG_SetRatio16(word ratio);
/*
** ===================================================================
**     Method      :  LEDG_SetRatio16 (component LED)
**
**     Description :
**         Method to specify the duty cylce. If using a PWM pin, this
**         means the duty cycle is set. For On/off pins, values smaller
**         0x7FFF means off, while values greater means on.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ratio           - Ratio value, where 0 means 'off' and
**                           0xffff means 'on'
**     Returns     : Nothing
** ===================================================================
*/

/* END LEDG. */

#endif
/* ifndef __LEDG_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

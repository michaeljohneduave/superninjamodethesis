/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Inhr3.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : PWM
**     Version     : Component 02.238, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-12-28, 18:30, # CodeGen: 215
**     Abstract    :
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
**     Settings    :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       53            |  TSI0_CH11/PTB18/TPM2_CH0
**             ----------------------------------------------------
**
**         Timer name                  : TPM2_CNT [16-bit]
**         Counter                     : TPM2_CNT  [0x4003A004]
**         Mode register               : TPM2_SC   [0x4003A000]
**         Run register                : TPM2_SC   [0x4003A000]
**         Prescaler                   : TPM2_SC   [0x4003A000]
**         Compare register            : TPM2_C0V  [0x4003A010]
**         Flip-flop register          : TPM2_C0SC [0x4003A00C]
**
**         User handling procedure     : not specified
**
**         Port name                   : PTB
**         Bit number (in port)        : 18
**         Bit mask of the port        : 0x00040000
**         Port data register          : GPIOB_PDOR [0x400FF040]
**         Port control register       : GPIOB_PDDR [0x400FF054]
**
**         Initialization:
**              Output level           : low
**              Timer                  : Enabled
**              Event                  : Enabled
**         High speed mode
**             Prescaler               : divide-by-[driven by slave component]
**             Clock                   : [driven by slave component] Hz
**           Initial value of            period     pulse width
**             Xtal ticks              : ---        ---
**             microseconds            : ---        ---
**             milliseconds            : 2          1
**             seconds                 : ---        ---
**             seconds (real)          : 2          1
**
**     Contents    :
**         Enable     - byte Inhr3_Enable(void);
**         Disable    - byte Inhr3_Disable(void);
**         SetRatio16 - byte Inhr3_SetRatio16(word Ratio);
**         SetDutyUS  - byte Inhr3_SetDutyUS(word Time);
**         SetDutyMS  - byte Inhr3_SetDutyMS(word Time);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __Inhr3_H
#define __Inhr3_H

/* MODULE Inhr3. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "PwmLdd1.h"

#include "Cpu.h"


#define Inhr3_PERIOD_VALUE PwmLdd1_PERIOD_VALUE /* Initial period value in ticks of the timer. It is available only if the bean is enabled in high speed mode. */
#define Inhr3_PERIOD_VALUE_HIGH PwmLdd1_PERIOD_VALUE_0 /* Period value in ticks of the timer in high speed mode. It is available only if the bean is enabled in high speed mode. */


/*
** ===================================================================
**     Method      :  Inhr3_Enable (component PWM)
**
**     Description :
**         This method enables the component - it starts the signal
**         generation. Events may be generated (<DisableEvent>
**         /<EnableEvent>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define Inhr3_Enable() (PwmLdd1_Enable(PwmLdd1_DeviceData))

/*
** ===================================================================
**     Method      :  Inhr3_Disable (component PWM)
**
**     Description :
**         This method disables the component - it stops the signal
**         generation and events calling. When the timer is disabled,
**         it is possible to call <ClrValue> and <SetValue> methods.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define Inhr3_Disable() (PwmLdd1_Disable(PwmLdd1_DeviceData))

/*
** ===================================================================
**     Method      :  Inhr3_SetRatio16 (component PWM)
**
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. 0 - FFFF value is
**         proportional to ratio 0 - 100%. The method is available
**         only if it is not selected list of predefined values in
**         <Starting pulse width> property. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ratio           - Ratio to set. 0 - 65535 value is
**                           proportional to ratio 0 - 100%
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define Inhr3_SetRatio16(Ratio) (PwmLdd1_SetRatio16(PwmLdd1_DeviceData, Ratio))

/*
** ===================================================================
**     Method      :  Inhr3_SetDutyUS (component PWM)
**
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in microseconds as a 16-bit
**         unsigned integer number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Time            - Duty to set [in microseconds]
**                      (0 to --- us in high speed mode)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
#define Inhr3_SetDutyUS(Time) (PwmLdd1_SetDutyUS(PwmLdd1_DeviceData, Time))

/*
** ===================================================================
**     Method      :  Inhr3_SetDutyMS (component PWM)
**
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in milliseconds as a 16-bit
**         unsigned integer number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Time            - Duty to set [in milliseconds]
**                      (0 to 2 ms in high speed mode)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
#define Inhr3_SetDutyMS(Time) (PwmLdd1_SetDutyMS(PwmLdd1_DeviceData, Time))

/* END Inhr3. */

#endif 
/* ifndef __Inhr3_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

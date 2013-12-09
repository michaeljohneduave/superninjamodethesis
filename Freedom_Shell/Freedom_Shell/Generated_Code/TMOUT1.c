/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : TMOUT1.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Timeout
**     Version     : Component 01.021, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-12-28, 13:16, # CodeGen: 180
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         GetCounter     - TMOUT1_CounterHandle TMOUT1_GetCounter(TMOUT1_CounterType nofTicks);
**         LeaveCounter   - void TMOUT1_LeaveCounter(TMOUT1_CounterHandle handle);
**         Value          - TMOUT1_CounterType TMOUT1_Value(TMOUT1_CounterHandle handle);
**         CounterExpired - bool TMOUT1_CounterExpired(TMOUT1_CounterHandle handle);
**         AddTick        - void TMOUT1_AddTick(void);
**         Init           - void TMOUT1_Init(void);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Copyright Erich Styger, 2011, all rights reserved.
**     This an open source software implementing timeout routines using Processor Expert.
**     This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for   personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/

/* MODULE TMOUT1. */

#include "TMOUT1.h"

#define TMOUT1_NOF_COUNTERS  2         /* number of timeout counters available */

static TMOUT1_CounterType TMOUT1_Counters[TMOUT1_NOF_COUNTERS]; /* array of timeout counters */
static bool TMOUT1_FreeCounters[TMOUT1_NOF_COUNTERS]; /* array to indicate which counters are free */

/*
** ===================================================================
**     Method      :  TMOUT1_GetCounter (component Timeout)
**
**     Description :
**         Initializes a new timeout counter and returns the handle to
**         it. At the end, use LeaveCounter() to free up the ressource.
**     Parameters  :
**         NAME            - DESCRIPTION
**         nofTicks        - Number of ticks for the counter
**                           until it expires.
**     Returns     :
**         ---             - Handle to the counter, to be used for
**                           further API calls.
** ===================================================================
*/
TMOUT1_CounterHandle TMOUT1_GetCounter(TMOUT1_CounterType nofTicks)
{
  TMOUT1_CounterHandle handle;

  handle = 0;
  EnterCritical();
  while (!TMOUT1_FreeCounters[handle] && handle<TMOUT1_NOF_COUNTERS) {
    handle++;
  }
  if (handle<TMOUT1_NOF_COUNTERS) {
    TMOUT1_FreeCounters[handle]=FALSE;
    TMOUT1_Counters[handle] = nofTicks;
  }
  ExitCritical();
  if (handle==TMOUT1_NOF_COUNTERS) {
    return TMOUT1_OUT_OF_HANDLE;
  }
  return handle;
}

/*
** ===================================================================
**     Method      :  TMOUT1_LeaveCounter (component Timeout)
**
**     Description :
**         To be called to return the counter. Note that a counter
**         always should be returned so it can be reused.
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - Counter handle
**     Returns     : Nothing
** ===================================================================
*/
void TMOUT1_LeaveCounter(TMOUT1_CounterHandle handle)
{
  if (handle==TMOUT1_OUT_OF_HANDLE) {
    return;
  }
  EnterCritical();
  TMOUT1_Counters[handle] = 0;
  TMOUT1_FreeCounters[handle]=TRUE;
  ExitCritical();
}

/*
** ===================================================================
**     Method      :  TMOUT1_CounterExpired (component Timeout)
**
**     Description :
**         Returns true if the timeout counter has been expired
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - The timeout handle retrieved using
**                           GetCounter()
**     Returns     :
**         ---             - Returns TRUE if the counter has been
**                           expired, FALSE otherwise
** ===================================================================
*/
bool TMOUT1_CounterExpired(TMOUT1_CounterHandle handle)
{
  bool res;

  if (handle==TMOUT1_OUT_OF_HANDLE) {
    return TRUE;
  }
  EnterCritical();
  res = (bool)(TMOUT1_Counters[handle]==0);
  ExitCritical();
  return res;
}

/*
** ===================================================================
**     Method      :  TMOUT1_AddTick (component Timeout)
**
**     Description :
**         Method to be called from a priodic timer or interrupt. It
**         will decrement all current counters by one down to zero.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TMOUT1_AddTick(void)
{
  byte i;

  EnterCritical();
  for(i=0;i<TMOUT1_NOF_COUNTERS;i++) {
    if (TMOUT1_Counters[i]>0) {
      TMOUT1_Counters[i]--;
    }
  }
  ExitCritical();
}

/*
** ===================================================================
**     Method      :  TMOUT1_Init (component Timeout)
**
**     Description :
**         Initialization of the driver
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TMOUT1_Init(void)
{
  byte i;

  for(i=0;i<TMOUT1_NOF_COUNTERS;i++) {
    TMOUT1_Counters[i] = 0;
    TMOUT1_FreeCounters[i] = TRUE;
  }
}

/*
** ===================================================================
**     Method      :  TMOUT1_Value (component Timeout)
**
**     Description :
**         Return the current value of the counter (in ticks)
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - Handle of the timeout counter
**     Returns     :
**         ---             - none
** ===================================================================
*/
TMOUT1_CounterType TMOUT1_Value(TMOUT1_CounterHandle handle)
{
  TMOUT1_CounterType res;

  EnterCritical();
  res = TMOUT1_Counters[handle];
  ExitCritical();
  return res;
}

/* END TMOUT1. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
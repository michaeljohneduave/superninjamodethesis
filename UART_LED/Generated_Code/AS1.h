/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : AS1.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Serial_LDD
**     Version     : Component 01.168, Driver 01.11, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-12-11, 14:38, # CodeGen: 1
**     Abstract    :
**         This component "Serial_LDD" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial communication channel.
**     Settings    :
**          Component name                                 : AS1
**          Device                                         : UART0
**          Interrupt service/event                        : Disabled
**          Settings                                       : 
**            Data width                                   : 8 bits
**            Parity                                       : Odd
**            Stop bits                                    : 1
**            Loop mode                                    : Normal
**            Baud rate                                    : 38400 baud
**            Wakeup condition                             : Idle line wakeup
**            Stop in wait mode                            : no
**            Idle line mode                               : Starts after start bit
**            Transmitter output                           : Not inverted
**            Receiver input                               : Not inverted
**            Break generation length                      : 10/11 bits
**            Receiver                                     : Enabled
**              RxD                                        : TSI0_CH2/PTA1/UART0_RX/TPM2_CH0
**              RxD pin signal                             : 
**            Transmitter                                  : Enabled
**              TxD                                        : TSI0_CH3/PTA2/UART0_TX/TPM2_CH1
**              TxD pin signal                             : 
**            Flow control                                 : None
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnBlockSent                                : Enabled
**              OnBlockReceived                            : Disabled
**              OnTxComplete                               : Enabled
**              OnError                                    : Disabled
**              OnBreak                                    : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init                - LDD_TDeviceData* AS1_Init(LDD_TUserData *UserDataPtr);
**         Deinit              - void AS1_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SendBlock           - LDD_TError AS1_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         ReceiveBlock        - LDD_TError AS1_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         GetSentDataNum      - uint16_t AS1_GetSentDataNum(LDD_TDeviceData *DeviceDataPtr);
**         GetReceivedDataNum  - uint16_t AS1_GetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr);
**         GetTxCompleteStatus - bool AS1_GetTxCompleteStatus(LDD_TDeviceData *DeviceDataPtr);
**         Main                - void AS1_Main(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file AS1.h
** @version 01.11
** @brief
**         This component "Serial_LDD" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial communication channel.
*/         
/*!
**  @addtogroup AS1_module AS1 module documentation
**  @{
*/         

#ifndef __AS1_H
#define __AS1_H

/* MODULE AS1. */


#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif


/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define AS1_PRPH_BASE_ADDRESS  0x4006A000U
  
/*! Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define AS1_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_AS1_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define AS1_Init_METHOD_ENABLED        /*!< Init method of the component AS1 is enabled (generated) */
#define AS1_Deinit_METHOD_ENABLED      /*!< Deinit method of the component AS1 is enabled (generated) */
#define AS1_SendBlock_METHOD_ENABLED   /*!< SendBlock method of the component AS1 is enabled (generated) */
#define AS1_ReceiveBlock_METHOD_ENABLED /*!< ReceiveBlock method of the component AS1 is enabled (generated) */
#define AS1_GetSentDataNum_METHOD_ENABLED /*!< GetSentDataNum method of the component AS1 is enabled (generated) */
#define AS1_GetReceivedDataNum_METHOD_ENABLED /*!< GetReceivedDataNum method of the component AS1 is enabled (generated) */
#define AS1_GetTxCompleteStatus_METHOD_ENABLED /*!< GetTxCompleteStatus method of the component AS1 is enabled (generated) */
#define AS1_Main_METHOD_ENABLED        /*!< Main method of the component AS1 is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define AS1_OnBlockSent_EVENT_ENABLED  /*!< OnBlockSent event of the component AS1 is enabled (generated) */
#define AS1_OnTxComplete_EVENT_ENABLED /*!< OnTxComplete event of the component AS1 is enabled (generated) */

#define ENABLED_TX_INT        0x01U    /*!< TX interrupt enabled      */
#define BREAK_DETECTED        0x02U    /*!< Break detected            */
#define TX_COMPLETED          0x04U    /*!< Transmission completed    */
#define ENABLE_TX_COMPLETE    0x10U    /*!< Enable/Disable of TX complete detection. Used in the polling mode only */

/*! Device data structure type */
typedef struct {
  uint16_t SerFlag;                    /*!< Flags for serial communication */
  uint16_t InpRecvDataNum;             /*!< The counter of received characters */
  uint8_t *InpDataPtr;                 /*!< The buffer pointer for received characters */
  uint16_t InpDataNumReq;              /*!< The counter of characters to receive by ReceiveBlock() */
  uint16_t OutSentDataNum;             /*!< The counter of sent characters */
  uint8_t *OutDataPtr;                 /*!< The buffer pointer for data to be transmitted */
  uint16_t OutDataNumReq;              /*!< The counter of characters to be send by SendBlock() */
  LDD_TUserData *UserDataPtr;          /*!< Pointer to user data */
} AS1_TDeviceData;

typedef AS1_TDeviceData *AS1_TDeviceDataPtr ; /*!< Pointer to the device data structure. */

/*
** ===================================================================
**     Method      :  AS1_Init (component Serial_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the "Enable
**         in init. code" is set to "yes" value then the device is also
**         enabled(see the description of the Enable() method). In this
**         case the Enable() method is not necessary and needn't to be
**         generated. 
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Device data structure pointer.
*/
/* ===================================================================*/
LDD_TDeviceData* AS1_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  AS1_Deinit (component Serial_LDD)
*/
/*!
**     @brief
**          Deinitializes the device. Switches off the device, frees
**         the device data structure memory, interrupts vectors, etc.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
*/
/* ===================================================================*/
void AS1_Deinit(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  AS1_ReceiveBlock (component Serial_LDD)
*/
/*!
**     @brief
**         Specifies the number of data to receive. The method returns
**         ERR_BUSY until the specified number of characters is
**         received. Method <CancelBlockReception> can be used to
**         cancel a running receive operation.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         BufferPtr       - Pointer to a buffer where
**                           received characters will be stored.
**     @param
**         Size            - Number of characters to receive
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_PARAM_SIZE - Parameter Size is out of
**                           expected range.
**                           ERR_DISABLED - The component or device is
**                           disabled.
**                           ERR_BUSY - The previous receive request is
**                           pending.
*/
/* ===================================================================*/
LDD_TError AS1_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size);

/*
** ===================================================================
**     Method      :  AS1_SendBlock (component Serial_LDD)
*/
/*!
**     @brief
**         Sends a block of characters. The method returns ERR_BUSY
**         when the previous block transmission is not completed.
**         Method <CancelBlockTransmission> can be used to cancel a
**         transmit operation. This method is available only if the
**         transmitter property is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         BufferPtr       - Pointer to a buffer from where
**                           data will be sent.
**     @param
**         Size            - Number of characters in the buffer.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_PARAM_SIZE - Parameter Size is out of
**                           expected range.
**                           ERR_DISABLED - The component or device is
**                           disabled.
**                           ERR_BUSY - The previous transmit request is
**                           pending.
*/
/* ===================================================================*/
LDD_TError AS1_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size);

/*
** ===================================================================
**     Method      :  AS1_GetReceivedDataNum (component Serial_LDD)
*/
/*!
**     @brief
**         Returns the number of received characters in the receive
**         buffer. 
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Number of received characters in the receive
**                           buffer.
*/
/* ===================================================================*/
uint16_t AS1_GetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  AS1_GetSentDataNum (component Serial_LDD)
*/
/*!
**     @brief
**         Returns the number of sent characters.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - The number of sent characters.
*/
/* ===================================================================*/
uint16_t AS1_GetSentDataNum(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  AS1_GetTxCompleteStatus (component Serial_LDD)
*/
/*!
**     @brief
**         Returns whether the transmitter has transmitted all
**         characters and there are no other characters in the
**         transmitter's HW FIFO or the shift register. The status flag
**         is accumulated, after calling this method the status is
**         returned and cleared (set to "false" state). This method is
**         available only if a peripheral supports this feature.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Possible values:
**                           <true> - Data block is completely
**                           transmitted.
**                           <false> - Data block isn't completely
**                           transmitted.
*/
/* ===================================================================*/
bool AS1_GetTxCompleteStatus(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  AS1_Main (component Serial_LDD)
*/
/*!
**     @brief
**         This method is available only in the polling mode (Interrupt
**         service/event = 'no'). If interrupt service is disabled this
**         method replaces the interrupt handler. This method should be
**         called if Receive/SendBlock was invoked before in order to
**         run the reception/transmission. The end of the
**         receiving/transmitting is indicated by OnBlockSent or
**         OnBlockReceived event. 
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
*/
/* ===================================================================*/
void AS1_Main(LDD_TDeviceData *DeviceDataPtr);

/* END AS1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif
/* ifndef __AS1_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

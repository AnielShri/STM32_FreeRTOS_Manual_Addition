/*
 * rtos_main.h
 *
 *  Created on: Mar 6, 2022
 *      Author: Aniel
 */

#ifndef INC_RTOS_MAIN_H_
#define INC_RTOS_MAIN_H_

#include "main.h"
#include "FreeRTOS.h"
#include "task.h"

//================================================================================================+
//	typedefs
//================================================================================================+

// based on CMIS RTOS
typedef enum
{
  tskPriorityIdle          =  tskIDLE_PRIORITY,  		///< Reserved for Idle thread.
  tskPriorityLow           = (tskIDLE_PRIORITY + 8),	///< Priority: low
  tskPriorityBelowNormal   = (tskIDLE_PRIORITY + 16),   ///< Priority: below normal
  tskPriorityNormal        = (tskIDLE_PRIORITY + 24),   ///< Priority: normal
  tskPriorityAboveNormal   = (tskIDLE_PRIORITY + 32),   ///< Priority: above normal
  tskPriorityHigh          = (tskIDLE_PRIORITY + 40),   ///< Priority: high
  tskPriorityRealtime      = (tskIDLE_PRIORITY + 48),   ///< Priority: realtime
  tskPriorityISR           = (tskIDLE_PRIORITY + 56),	///< Reserved for ISR deferred thread.
  tskPriorityError         = -1,         				///< System cannot determine priority or illegal priority.
  tskPriorityReserved      = 0x7FFFFFFF  				///< Prevents enum down-size compiler optimization.
} tskPriority;


//================================================================================================+
//	functions
//================================================================================================+

uint8_t rtos_configure();
void rtos_start();


#endif /* INC_RTOS_MAIN_H_ */

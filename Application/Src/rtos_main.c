/*
 * rtos_main.c
 *
 *  Created on: Mar 6, 2022
 *      Author: Aniel
 */


#include "rtos_main.h"

//================================================================================================+
//	Task decelerations
//================================================================================================+

static void vTaskBlinky(void *pvParameters);

//================================================================================================+
//	Public functions
//================================================================================================+

/**
 * @brief:	Configure FreeRTOS tasks
 */
uint8_t rtos_configure()
{
	uint8_t result = OK;

	if (result == OK)
	{
		BaseType_t ret = xTaskCreate(vTaskBlinky, "Blinky Task", configMINIMAL_STACK_SIZE, NULL, tskPriorityNormal, NULL);
		if (ret != pdPASS)
		{
			result = ERROR;
		}
	}

	return result;
}


/**
 * @brief:	wrapper to start FreeRTOS
 */
void rtos_start()
{
	vTaskStartScheduler();
}

//================================================================================================+
//	Private functions
//================================================================================================+

/**
 * Blinky task
 */
static void vTaskBlinky(void *pvParameters)
{
	for(;;)
	{
		HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
		vTaskDelay(500);
	}
}

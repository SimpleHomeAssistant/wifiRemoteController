/*
 * user_main.c
 *
 *  Created on: Jan 27, 2022
 *      Author: jx
 */

#include "freertos/FreeRTOS.h"
#include "ir_transmission.h"
#include "mqtt_executor.h"
#include "wifi_station.h"


void app_main(void)
{
	wifi_init_sta();
	mqtt_start();  //todo handle command
    xTaskCreate(ir_rx_task, "ir_rx_task", 2048, NULL, 10, NULL);
    //xTaskCreate(ir_tx_task, "ir_tx_task", 2048, NULL, 10, NULL);
}

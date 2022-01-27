/*
 * mqtt_executor.h
 *
 *  Created on: Jan 25, 2022
 *      Author: jx
 */

#ifndef MQTT_EXECUTOR_H_
#define MQTT_EXECUTOR_H_



#endif /* MQTT_EXECUTOR_H_ */

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "esp_wifi.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_netif.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"

#include "lwip/sockets.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"

#include "esp_log.h"
#include "mqtt_client.h"


#define CONFIG_BROKER_URL "49.232.13.66:1883"

void mqtt_start(void);

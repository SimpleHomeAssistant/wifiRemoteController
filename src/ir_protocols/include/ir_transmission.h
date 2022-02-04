/*
 * ir_transmission.h
 *
 *  Created on: Jan 27, 2022
 *      Author: jx
 */

#ifndef IR_TRANSMISSION_H_
#define IR_TRANSMISSION_H_



#endif /* IR_TRANSMISSION_H_ */


#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/rmt.h"
#include "ir_tools.h"

#define IR_TX_GPIO 18
#define IR_RX_GPIO 19

void ir_rx_task(void *arg);
void ir_tx_task(void *arg);

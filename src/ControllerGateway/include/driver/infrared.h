#ifndef INFRARED_H
#define INFRARED_H 
#endif

#include "esp_common.h"
#include "gpio.h"

// init infrared with specific gpio pin
void infrared_init();
// send infrared signal
void infrared_send(uint32_t data);
// recv infrared signal
uint32_t infrared_receive(void);
// read infrared data, return 0 if no data
uint32_t infrared_read(void);

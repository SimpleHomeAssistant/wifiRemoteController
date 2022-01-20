#include "driver/infrared.h"
#include "driver/oled.h"
#include "gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_system.h"

u16 gpio_ir_recv_pin = 5;
u16 gpio_ir_send_pin = 13;


// recieve gpio interrupt handler
void gpio_intr_handler(void *arg)
{
    OLED_Clear();
    OLED_ShowString(0, 0, "IR interrupt");
    // clear gpio interrupt
    gpio_pin_intr_state_set(GPIO_ID_PIN(gpio_ir_recv_pin), GPIO_PIN_INTR_DISABLE);
    gpio_pin_intr_state_set(GPIO_ID_PIN(gpio_ir_recv_pin), GPIO_PIN_INTR_POSEDGE);
    os_printf("gpio_intr_handler\n");
    OLED_ShowString(0, 2, "ir interrupt done");
}

void setup_interrupt(void)
{
    GPIO_ConfigTypeDef io_conf;
    //disable interrupt
    io_conf.GPIO_IntrType = GPIO_PIN_INTR_NEGEDGE;
    //set as output mode
    io_conf.GPIO_Mode = GPIO_Mode_Input;
    //bit mask of the pins that you want to set,e.g.GPIO15/16
    io_conf.GPIO_Pin = GPIO_Pin_5;
    // disable pull-up mode
    io_conf.GPIO_Pullup = GPIO_PullUp_DIS;

    //configure GPIO with the given settings
    gpio_config(&io_conf);

    gpio_intr_handler_register(gpio_intr_handler, NULL);
}


void infrared_init()
{
    OLED_Clear();
    
    OLED_ShowString(0, 0, "ir init");
    setup_interrupt();
    OLED_ShowString(0, 2, "ir init done");
}

// send a unit32 data via infrared transmission
void infrared_send(uint32_t data)
{
    return ;
    u8 i;
    for(i=0;i<32;i++)
    {
        gpio16_output_set(data&0x01);
        data>>=1;
        os_delay_us(10);
        gpio16_output_set(0);
        os_delay_us(10);
    }
}

uint32_t infrared_recv(void)
{
    return 100; // for debug only
    uint32_t data=0;
    u8 i;
    for(i=0;i<32;i++)
    {
        data<<=1;
        os_delay_us(10);
        gpio16_output_set(1);
        os_delay_us(10);
        if(gpio16_input_get())
        {
            data|=0x01;
        }
        gpio16_output_set(0);
    }
    return data;
}


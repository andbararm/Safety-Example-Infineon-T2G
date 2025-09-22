#include <stdio.h>
#include "RTE_Components.h"             // Component selection
#include CMSIS_device_header            // Device header
#include "main.h"
#include "cmsis_os2.h"
#include "cmsis_vio.h"

/* Thread attributes for the app_main thread */
static const osThreadAttr_t thread_attr_main = { .name = "app_main" };

/*
  Application main thread.
*/
__NO_RETURN void app_main_thread (void *argument) {
  (void)argument;

  for (;;) {
    vioSetSignal(vioLED2, vioLEDoff);   // Switch LED2 off
    osDelay(250U) ;
    vioSetSignal(vioLED2, vioLEDon);    // Switch LED2 on
    osDelay(250U) ;
  }
}

/*
  Application initialization.
*/
int app_main (void) {

  osKernelInitialize();                 // Initialize CMSIS-RTOS2
  osThreadNew(app_main_thread, NULL, &thread_attr_main);
  osKernelStart();                      // Start thread execution
  return 0;
}

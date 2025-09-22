/*---------------------------------------------------------------------------
 * Copyright (c) 2025 Arm Limited (or its affiliates).
 * All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *---------------------------------------------------------------------------*/

#include "hw_watchdog.h"

#ifdef   _RTE_
#include "RTE_Components.h"
#endif
#include CMSIS_device_header

#include "cy_wdt.h"

/* Initialize hardware watchdog with specified timeout in milliseconds */
void HwWatchdogInit (uint32_t timeout) {

  // Configure watchdog to reset the system if it is not fed (kicked) during timeout interval.
  // Watchdog peripheral clock is 32768 Hz.
  // Watchdog will reset the system when counter reaches upper limit.
  Cy_WDT_Unlock();
  Cy_WDT_Disable();
  Cy_WDT_SetLowerLimit(0U);
  Cy_WDT_SetUpperLimit((timeout * 32768U) / 1000U);
  Cy_WDT_SetWarnLimit(0U);
  Cy_WDT_SetLowerAction(CY_WDT_LOW_UPPER_LIMIT_ACTION_NONE);
  Cy_WDT_SetUpperAction(CY_WDT_LOW_UPPER_LIMIT_ACTION_RESET);
  Cy_WDT_SetWarnAction(CY_WDT_WARN_ACTION_NONE);
  Cy_WDT_SetAutoService(CY_WDT_DISABLE);  // Disable auto service
  Cy_WDT_SetDebugRun(CY_WDT_DISABLE);     // Stop running while debugging
  Cy_WDT_Enable();                        // Enable WDT
  Cy_WDT_Lock();                          // Lock WDT registers, disable further changes
}

/* Feed hardware watchdog */
void HwWatchdogFeed (void) {

  Cy_WDT_ClearWatchdog();
}

/*---------------------------------------------------------------------------
 * Copyright (c) 2020-2025 Arm Limited (or its affiliates).
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

#ifdef   _RTE_
#include "RTE_Components.h"
#endif
#include CMSIS_device_header

#include "zones.h"

#include "cmsis_os2.h"
#include "Driver_ETH_MAC.h"

/* Local function */
void svcNVIC_Handler (uint32_t func_index, IRQn_Type IRQn, uint32_t arg);

#define USER_SVC_COUNT          1       // Number of user SVC functions

/* Function used for wrapping NVIC functions:
   - NVIC_EnableIRQ
   - NVIC_DisableIRQ 
   - NVIC_SetPriority
   to be called as SCVs */
void svcNVIC_func (uint32_t func_index, IRQn_Type IRQn, uint32_t arg) { 
  __ASM volatile ( "svc 1" : : "r"(func_index), "r"(IRQn), "r"(arg) );
}

/* SVC handler for NVIC functions: 
   - NVIC_EnableIRQ
   - NVIC_DisableIRQ 
   - NVIC_SetPriority
   it enables these functions to be executed in privileged mode */
void svcNVIC_Handler (uint32_t func_index, IRQn_Type IRQn, uint32_t arg) { 

  /* Only Ethernet IRQ handling from Zone Com is allowed */
  if (IRQn == NvicMux3_IRQn) {
    if (osThreadGetZone(osThreadGetId()) == ZONE_COM) {
      switch (func_index) {
        case 2U:
          __NVIC_EnableIRQ(IRQn);
          break;
        case 4U:
          __NVIC_DisableIRQ(IRQn);
          break;
        case 9U:
          __NVIC_SetPriority(IRQn, arg);
          break;
        default:
          // If not a valid function index then just ignore it
          break;
      }
    }
  }
}

extern void * const osRtxUserSVC[1+USER_SVC_COUNT];
       void * const osRtxUserSVC[1+USER_SVC_COUNT] = {
  (void *)USER_SVC_COUNT,
  (void *)svcNVIC_Handler               /* user SVC function */
// ...
};

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

#ifndef SVC_NVIC_H_
#define SVC_NVIC_H_

#include <stdint.h>

#ifdef   _RTE_
#include "RTE_Components.h"
#endif
#include CMSIS_device_header

extern void svcNVIC_func (uint32_t func_index, IRQn_Type IRQn, uint32_t arg);

#define NVIC_SetPriorityGrouping        __NVIC_SetPriorityGrouping
#define NVIC_GetPriorityGrouping        __NVIC_GetPriorityGrouping
#define NVIC_EnableIRQ(IRQn)            svcNVIC_func(2U, IRQn, 0U)
#define NVIC_GetEnableIRQ               __NVIC_GetEnableIRQ
#define NVIC_DisableIRQ(IRQn)           svcNVIC_func(4U, IRQn, 0U)
#define NVIC_GetPendingIRQ              __NVIC_GetPendingIRQ
#define NVIC_SetPendingIRQ              __NVIC_SetPendingIRQ
#define NVIC_ClearPendingIRQ            __NVIC_ClearPendingIRQ
#define NVIC_GetActive                  __NVIC_GetActive
#define NVIC_SetPriority(IRQn,prio)     svcNVIC_func(9U, IRQn, prio)
#define NVIC_GetPriority                __NVIC_GetPriority
#define NVIC_SystemReset                __NVIC_SystemReset

#endif

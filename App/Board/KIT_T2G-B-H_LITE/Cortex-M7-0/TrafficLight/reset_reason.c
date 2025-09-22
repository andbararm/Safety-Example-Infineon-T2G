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

#include "reset_reason.h"

#ifdef   _RTE_
#include "RTE_Components.h"
#endif
#include CMSIS_device_header

#include "cy_pdl.h"

/* Get reset reason */
uint32_t GetResetReason (void) {
  uint32_t reset_reason = 0U;
  uint32_t cy_reset_reason;

  cy_reset_reason = Cy_SysLib_GetResetReason();
  if ((cy_reset_reason & CY_SYSLIB_RESET_SOFT) != 0U) {
    /* If system was reset by a software reset */
    reset_reason |= RESET_REASON_SOFTWARE;
  } else if ((cy_reset_reason & CY_SYSLIB_RESET_HWWDT) != 0U) {
    /* If system was reset by a hardware watchdog reset */
    reset_reason |= RESET_REASON_HARDWARE;
  }

  Cy_SysLib_ClearResetReason();

  return reset_reason;
}

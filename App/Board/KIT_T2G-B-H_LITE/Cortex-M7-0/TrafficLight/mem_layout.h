// Vendor:    Infineon
// Device:    CYT4BF8CDS
// Processor: Cortex-M7
// Project:   TrafficLight

#ifndef MEM_LAYOUT_H
#define MEM_LAYOUT_H

#define REGION_FLASH_START                      0x10080000
#define REGION_FLASH_SIZE                       0x00200000

#define REGION_RAM_NO_INIT_VECTORS_START        0x28004000
#define REGION_RAM_NO_INIT_VECTORS_SIZE         0x00000080

#define REGION_RAM_NO_INIT_SYSTEM_START         0x28004080
#define REGION_RAM_NO_INIT_SYSTEM_SIZE          0x00003F80

#define REGION_RAM_PRIVILEGED_START             0x28008000
#define REGION_RAM_PRIVILEGED_SIZE              0x00008000

#define REGION_RAM_COM_START                    0x28010000
#define REGION_RAM_COM_SIZE                     0x00010000

#define REGION_RAM_SHARED_START                 0x28020000
#define REGION_RAM_SHARED_SIZE                  0x00003000

#define REGION_RAM_NO_INIT_EVR_START            0x28023000
#define REGION_RAM_NO_INIT_EVR_SIZE             0x00001000

#define REGION_RAM_NORMAL_OP_START              0x28024000
#define REGION_RAM_NORMAL_OP_SIZE               0x00001000

#define REGION_RAM_VERIFY_OP_START              0x28025000
#define REGION_RAM_VERIFY_OP_SIZE               0x00001000

#define REGION_RAM_SAFE_OP_START                0x28026000
#define REGION_RAM_SAFE_OP_SIZE                 0x00001000

#define REGION_RAM_TIMER_START                  0x28027000
#define REGION_RAM_TIMER_SIZE                   0x00001000

#define REGION_RAM_IDLE_START                   0x28028000
#define REGION_RAM_IDLE_SIZE                    0x00001000

#define REGION_ARM_LIB_STACK_START              0x280CB000
#define REGION_ARM_LIB_STACK_SIZE               0x00001000

#endif

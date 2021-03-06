/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios_system_nios2_gen2' in SOPC Builder design 'top_qsys'
 * SOPC Builder design path: C:/Users/kedic/Desktop/em023_mucilage/top_qsys.sopcinfo
 *
 * Generated: Wed Apr 20 20:59:15 TRT 2022
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00040820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x13
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00020020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x13
#define ALT_CPU_NAME "nios_system_nios2_gen2"
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x00020000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00040820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x13
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00020020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x13
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x00020000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_GEN2
#define __I2C_OPENCORES


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone V"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/nios_system_jtag_uart"
#define ALT_STDERR_BASE 0x410b8
#define ALT_STDERR_DEV nios_system_jtag_uart
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/nios_system_jtag_uart"
#define ALT_STDIN_BASE 0x410b8
#define ALT_STDIN_DEV nios_system_jtag_uart
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/nios_system_jtag_uart"
#define ALT_STDOUT_BASE 0x410b8
#define ALT_STDOUT_DEV nios_system_jtag_uart
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "top_qsys"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK NIOS_SYSTEM_TIMER
#define ALT_TIMESTAMP_CLK none


/*
 * nios_system_jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_nios_system_jtag_uart altera_avalon_jtag_uart
#define NIOS_SYSTEM_JTAG_UART_BASE 0x410b8
#define NIOS_SYSTEM_JTAG_UART_IRQ 0
#define NIOS_SYSTEM_JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define NIOS_SYSTEM_JTAG_UART_NAME "/dev/nios_system_jtag_uart"
#define NIOS_SYSTEM_JTAG_UART_READ_DEPTH 64
#define NIOS_SYSTEM_JTAG_UART_READ_THRESHOLD 8
#define NIOS_SYSTEM_JTAG_UART_SPAN 8
#define NIOS_SYSTEM_JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define NIOS_SYSTEM_JTAG_UART_WRITE_DEPTH 64
#define NIOS_SYSTEM_JTAG_UART_WRITE_THRESHOLD 8


/*
 * nios_system_led_pio configuration
 *
 */

#define ALT_MODULE_CLASS_nios_system_led_pio altera_avalon_pio
#define NIOS_SYSTEM_LED_PIO_BASE 0x1000
#define NIOS_SYSTEM_LED_PIO_BIT_CLEARING_EDGE_REGISTER 0
#define NIOS_SYSTEM_LED_PIO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NIOS_SYSTEM_LED_PIO_CAPTURE 0
#define NIOS_SYSTEM_LED_PIO_DATA_WIDTH 8
#define NIOS_SYSTEM_LED_PIO_DO_TEST_BENCH_WIRING 0
#define NIOS_SYSTEM_LED_PIO_DRIVEN_SIM_VALUE 0
#define NIOS_SYSTEM_LED_PIO_EDGE_TYPE "NONE"
#define NIOS_SYSTEM_LED_PIO_FREQ 50000000
#define NIOS_SYSTEM_LED_PIO_HAS_IN 0
#define NIOS_SYSTEM_LED_PIO_HAS_OUT 1
#define NIOS_SYSTEM_LED_PIO_HAS_TRI 0
#define NIOS_SYSTEM_LED_PIO_IRQ -1
#define NIOS_SYSTEM_LED_PIO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NIOS_SYSTEM_LED_PIO_IRQ_TYPE "NONE"
#define NIOS_SYSTEM_LED_PIO_NAME "/dev/nios_system_led_pio"
#define NIOS_SYSTEM_LED_PIO_RESET_VALUE 0
#define NIOS_SYSTEM_LED_PIO_SPAN 16
#define NIOS_SYSTEM_LED_PIO_TYPE "altera_avalon_pio"


/*
 * nios_system_light_i2c_opencores configuration
 *
 */

#define ALT_MODULE_CLASS_nios_system_light_i2c_opencores i2c_opencores
#define NIOS_SYSTEM_LIGHT_I2C_OPENCORES_BASE 0x41020
#define NIOS_SYSTEM_LIGHT_I2C_OPENCORES_IRQ 5
#define NIOS_SYSTEM_LIGHT_I2C_OPENCORES_IRQ_INTERRUPT_CONTROLLER_ID 0
#define NIOS_SYSTEM_LIGHT_I2C_OPENCORES_NAME "/dev/nios_system_light_i2c_opencores"
#define NIOS_SYSTEM_LIGHT_I2C_OPENCORES_SPAN 32
#define NIOS_SYSTEM_LIGHT_I2C_OPENCORES_TYPE "i2c_opencores"


/*
 * nios_system_light_int configuration
 *
 */

#define ALT_MODULE_CLASS_nios_system_light_int altera_avalon_pio
#define NIOS_SYSTEM_LIGHT_INT_BASE 0x41090
#define NIOS_SYSTEM_LIGHT_INT_BIT_CLEARING_EDGE_REGISTER 0
#define NIOS_SYSTEM_LIGHT_INT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NIOS_SYSTEM_LIGHT_INT_CAPTURE 1
#define NIOS_SYSTEM_LIGHT_INT_DATA_WIDTH 1
#define NIOS_SYSTEM_LIGHT_INT_DO_TEST_BENCH_WIRING 0
#define NIOS_SYSTEM_LIGHT_INT_DRIVEN_SIM_VALUE 0
#define NIOS_SYSTEM_LIGHT_INT_EDGE_TYPE "FALLING"
#define NIOS_SYSTEM_LIGHT_INT_FREQ 50000000
#define NIOS_SYSTEM_LIGHT_INT_HAS_IN 1
#define NIOS_SYSTEM_LIGHT_INT_HAS_OUT 0
#define NIOS_SYSTEM_LIGHT_INT_HAS_TRI 0
#define NIOS_SYSTEM_LIGHT_INT_IRQ 3
#define NIOS_SYSTEM_LIGHT_INT_IRQ_INTERRUPT_CONTROLLER_ID 0
#define NIOS_SYSTEM_LIGHT_INT_IRQ_TYPE "EDGE"
#define NIOS_SYSTEM_LIGHT_INT_NAME "/dev/nios_system_light_int"
#define NIOS_SYSTEM_LIGHT_INT_RESET_VALUE 0
#define NIOS_SYSTEM_LIGHT_INT_SPAN 16
#define NIOS_SYSTEM_LIGHT_INT_TYPE "altera_avalon_pio"


/*
 * nios_system_mpu_i2c_opencores configuration
 *
 */

#define ALT_MODULE_CLASS_nios_system_mpu_i2c_opencores i2c_opencores
#define NIOS_SYSTEM_MPU_I2C_OPENCORES_BASE 0x41040
#define NIOS_SYSTEM_MPU_I2C_OPENCORES_IRQ 4
#define NIOS_SYSTEM_MPU_I2C_OPENCORES_IRQ_INTERRUPT_CONTROLLER_ID 0
#define NIOS_SYSTEM_MPU_I2C_OPENCORES_NAME "/dev/nios_system_mpu_i2c_opencores"
#define NIOS_SYSTEM_MPU_I2C_OPENCORES_SPAN 32
#define NIOS_SYSTEM_MPU_I2C_OPENCORES_TYPE "i2c_opencores"


/*
 * nios_system_mpu_int configuration
 *
 */

#define ALT_MODULE_CLASS_nios_system_mpu_int altera_avalon_pio
#define NIOS_SYSTEM_MPU_INT_BASE 0x410a0
#define NIOS_SYSTEM_MPU_INT_BIT_CLEARING_EDGE_REGISTER 0
#define NIOS_SYSTEM_MPU_INT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NIOS_SYSTEM_MPU_INT_CAPTURE 1
#define NIOS_SYSTEM_MPU_INT_DATA_WIDTH 1
#define NIOS_SYSTEM_MPU_INT_DO_TEST_BENCH_WIRING 0
#define NIOS_SYSTEM_MPU_INT_DRIVEN_SIM_VALUE 0
#define NIOS_SYSTEM_MPU_INT_EDGE_TYPE "FALLING"
#define NIOS_SYSTEM_MPU_INT_FREQ 50000000
#define NIOS_SYSTEM_MPU_INT_HAS_IN 1
#define NIOS_SYSTEM_MPU_INT_HAS_OUT 0
#define NIOS_SYSTEM_MPU_INT_HAS_TRI 0
#define NIOS_SYSTEM_MPU_INT_IRQ 2
#define NIOS_SYSTEM_MPU_INT_IRQ_INTERRUPT_CONTROLLER_ID 0
#define NIOS_SYSTEM_MPU_INT_IRQ_TYPE "EDGE"
#define NIOS_SYSTEM_MPU_INT_NAME "/dev/nios_system_mpu_int"
#define NIOS_SYSTEM_MPU_INT_RESET_VALUE 0
#define NIOS_SYSTEM_MPU_INT_SPAN 16
#define NIOS_SYSTEM_MPU_INT_TYPE "altera_avalon_pio"


/*
 * nios_system_onchip_memory2 configuration
 *
 */

#define ALT_MODULE_CLASS_nios_system_onchip_memory2 altera_avalon_onchip_memory2
#define NIOS_SYSTEM_ONCHIP_MEMORY2_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define NIOS_SYSTEM_ONCHIP_MEMORY2_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define NIOS_SYSTEM_ONCHIP_MEMORY2_BASE 0x20000
#define NIOS_SYSTEM_ONCHIP_MEMORY2_CONTENTS_INFO ""
#define NIOS_SYSTEM_ONCHIP_MEMORY2_DUAL_PORT 0
#define NIOS_SYSTEM_ONCHIP_MEMORY2_GUI_RAM_BLOCK_TYPE "AUTO"
#define NIOS_SYSTEM_ONCHIP_MEMORY2_INIT_CONTENTS_FILE "top_qsys_nios_system_onchip_memory2"
#define NIOS_SYSTEM_ONCHIP_MEMORY2_INIT_MEM_CONTENT 1
#define NIOS_SYSTEM_ONCHIP_MEMORY2_INSTANCE_ID "NONE"
#define NIOS_SYSTEM_ONCHIP_MEMORY2_IRQ -1
#define NIOS_SYSTEM_ONCHIP_MEMORY2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NIOS_SYSTEM_ONCHIP_MEMORY2_NAME "/dev/nios_system_onchip_memory2"
#define NIOS_SYSTEM_ONCHIP_MEMORY2_NON_DEFAULT_INIT_FILE_ENABLED 1
#define NIOS_SYSTEM_ONCHIP_MEMORY2_RAM_BLOCK_TYPE "AUTO"
#define NIOS_SYSTEM_ONCHIP_MEMORY2_READ_DURING_WRITE_MODE "DONT_CARE"
#define NIOS_SYSTEM_ONCHIP_MEMORY2_SINGLE_CLOCK_OP 0
#define NIOS_SYSTEM_ONCHIP_MEMORY2_SIZE_MULTIPLE 1
#define NIOS_SYSTEM_ONCHIP_MEMORY2_SIZE_VALUE 131072
#define NIOS_SYSTEM_ONCHIP_MEMORY2_SPAN 131072
#define NIOS_SYSTEM_ONCHIP_MEMORY2_TYPE "altera_avalon_onchip_memory2"
#define NIOS_SYSTEM_ONCHIP_MEMORY2_WRITABLE 1


/*
 * nios_system_rh_temp_drdy_n configuration
 *
 */

#define ALT_MODULE_CLASS_nios_system_rh_temp_drdy_n altera_avalon_pio
#define NIOS_SYSTEM_RH_TEMP_DRDY_N_BASE 0x41080
#define NIOS_SYSTEM_RH_TEMP_DRDY_N_BIT_CLEARING_EDGE_REGISTER 0
#define NIOS_SYSTEM_RH_TEMP_DRDY_N_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NIOS_SYSTEM_RH_TEMP_DRDY_N_CAPTURE 0
#define NIOS_SYSTEM_RH_TEMP_DRDY_N_DATA_WIDTH 1
#define NIOS_SYSTEM_RH_TEMP_DRDY_N_DO_TEST_BENCH_WIRING 0
#define NIOS_SYSTEM_RH_TEMP_DRDY_N_DRIVEN_SIM_VALUE 0
#define NIOS_SYSTEM_RH_TEMP_DRDY_N_EDGE_TYPE "NONE"
#define NIOS_SYSTEM_RH_TEMP_DRDY_N_FREQ 50000000
#define NIOS_SYSTEM_RH_TEMP_DRDY_N_HAS_IN 1
#define NIOS_SYSTEM_RH_TEMP_DRDY_N_HAS_OUT 0
#define NIOS_SYSTEM_RH_TEMP_DRDY_N_HAS_TRI 0
#define NIOS_SYSTEM_RH_TEMP_DRDY_N_IRQ -1
#define NIOS_SYSTEM_RH_TEMP_DRDY_N_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NIOS_SYSTEM_RH_TEMP_DRDY_N_IRQ_TYPE "NONE"
#define NIOS_SYSTEM_RH_TEMP_DRDY_N_NAME "/dev/nios_system_rh_temp_drdy_n"
#define NIOS_SYSTEM_RH_TEMP_DRDY_N_RESET_VALUE 0
#define NIOS_SYSTEM_RH_TEMP_DRDY_N_SPAN 16
#define NIOS_SYSTEM_RH_TEMP_DRDY_N_TYPE "altera_avalon_pio"


/*
 * nios_system_rh_temp_i2c_opencores configuration
 *
 */

#define ALT_MODULE_CLASS_nios_system_rh_temp_i2c_opencores i2c_opencores
#define NIOS_SYSTEM_RH_TEMP_I2C_OPENCORES_BASE 0x41000
#define NIOS_SYSTEM_RH_TEMP_I2C_OPENCORES_IRQ 6
#define NIOS_SYSTEM_RH_TEMP_I2C_OPENCORES_IRQ_INTERRUPT_CONTROLLER_ID 0
#define NIOS_SYSTEM_RH_TEMP_I2C_OPENCORES_NAME "/dev/nios_system_rh_temp_i2c_opencores"
#define NIOS_SYSTEM_RH_TEMP_I2C_OPENCORES_SPAN 32
#define NIOS_SYSTEM_RH_TEMP_I2C_OPENCORES_TYPE "i2c_opencores"


/*
 * nios_system_shared_memory configuration
 *
 */

#define ALT_MODULE_CLASS_nios_system_shared_memory altera_avalon_onchip_memory2
#define NIOS_SYSTEM_SHARED_MEMORY_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define NIOS_SYSTEM_SHARED_MEMORY_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define NIOS_SYSTEM_SHARED_MEMORY_BASE 0x2000
#define NIOS_SYSTEM_SHARED_MEMORY_CONTENTS_INFO ""
#define NIOS_SYSTEM_SHARED_MEMORY_DUAL_PORT 1
#define NIOS_SYSTEM_SHARED_MEMORY_GUI_RAM_BLOCK_TYPE "AUTO"
#define NIOS_SYSTEM_SHARED_MEMORY_INIT_CONTENTS_FILE "top_qsys_nios_system_shared_memory"
#define NIOS_SYSTEM_SHARED_MEMORY_INIT_MEM_CONTENT 0
#define NIOS_SYSTEM_SHARED_MEMORY_INSTANCE_ID "NONE"
#define NIOS_SYSTEM_SHARED_MEMORY_IRQ -1
#define NIOS_SYSTEM_SHARED_MEMORY_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NIOS_SYSTEM_SHARED_MEMORY_NAME "/dev/nios_system_shared_memory"
#define NIOS_SYSTEM_SHARED_MEMORY_NON_DEFAULT_INIT_FILE_ENABLED 0
#define NIOS_SYSTEM_SHARED_MEMORY_RAM_BLOCK_TYPE "AUTO"
#define NIOS_SYSTEM_SHARED_MEMORY_READ_DURING_WRITE_MODE "OLD_DATA"
#define NIOS_SYSTEM_SHARED_MEMORY_SINGLE_CLOCK_OP 1
#define NIOS_SYSTEM_SHARED_MEMORY_SIZE_MULTIPLE 1
#define NIOS_SYSTEM_SHARED_MEMORY_SIZE_VALUE 4096
#define NIOS_SYSTEM_SHARED_MEMORY_SPAN 4096
#define NIOS_SYSTEM_SHARED_MEMORY_TYPE "altera_avalon_onchip_memory2"
#define NIOS_SYSTEM_SHARED_MEMORY_WRITABLE 1


/*
 * nios_system_sysid_qsys configuration
 *
 */

#define ALT_MODULE_CLASS_nios_system_sysid_qsys altera_avalon_sysid_qsys
#define NIOS_SYSTEM_SYSID_QSYS_BASE 0x410b0
#define NIOS_SYSTEM_SYSID_QSYS_ID 305419896
#define NIOS_SYSTEM_SYSID_QSYS_IRQ -1
#define NIOS_SYSTEM_SYSID_QSYS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NIOS_SYSTEM_SYSID_QSYS_NAME "/dev/nios_system_sysid_qsys"
#define NIOS_SYSTEM_SYSID_QSYS_SPAN 8
#define NIOS_SYSTEM_SYSID_QSYS_TIMESTAMP 1650456823
#define NIOS_SYSTEM_SYSID_QSYS_TYPE "altera_avalon_sysid_qsys"


/*
 * nios_system_timer configuration
 *
 */

#define ALT_MODULE_CLASS_nios_system_timer altera_avalon_timer
#define NIOS_SYSTEM_TIMER_ALWAYS_RUN 0
#define NIOS_SYSTEM_TIMER_BASE 0x41060
#define NIOS_SYSTEM_TIMER_COUNTER_SIZE 32
#define NIOS_SYSTEM_TIMER_FIXED_PERIOD 0
#define NIOS_SYSTEM_TIMER_FREQ 50000000
#define NIOS_SYSTEM_TIMER_IRQ 1
#define NIOS_SYSTEM_TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define NIOS_SYSTEM_TIMER_LOAD_VALUE 49999
#define NIOS_SYSTEM_TIMER_MULT 0.001
#define NIOS_SYSTEM_TIMER_NAME "/dev/nios_system_timer"
#define NIOS_SYSTEM_TIMER_PERIOD 1
#define NIOS_SYSTEM_TIMER_PERIOD_UNITS "ms"
#define NIOS_SYSTEM_TIMER_RESET_OUTPUT 0
#define NIOS_SYSTEM_TIMER_SNAPSHOT 1
#define NIOS_SYSTEM_TIMER_SPAN 32
#define NIOS_SYSTEM_TIMER_TICKS_PER_SEC 1000
#define NIOS_SYSTEM_TIMER_TIMEOUT_PULSE_OUTPUT 0
#define NIOS_SYSTEM_TIMER_TYPE "altera_avalon_timer"


/*
 * nios_system_water_i2c configuration
 *
 */

#define ALT_MODULE_CLASS_nios_system_water_i2c i2c_opencores
#define NIOS_SYSTEM_WATER_I2C_BASE 0x41100
#define NIOS_SYSTEM_WATER_I2C_IRQ 7
#define NIOS_SYSTEM_WATER_I2C_IRQ_INTERRUPT_CONTROLLER_ID 0
#define NIOS_SYSTEM_WATER_I2C_NAME "/dev/nios_system_water_i2c"
#define NIOS_SYSTEM_WATER_I2C_SPAN 32
#define NIOS_SYSTEM_WATER_I2C_TYPE "i2c_opencores"

#endif /* __SYSTEM_H_ */

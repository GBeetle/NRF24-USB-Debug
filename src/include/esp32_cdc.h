/*
 * This file is part of welkin project (https://github.com/GBeetle/welkin).
 * Copyright (c) 2022 GBeetle.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _ESP32_CDC__
#define _ESP32_CDC__

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

#define     USB_TIMEOUT                1000    /* 1000 ms is plenty and we have no backup strategy anyway. */
#define     WRITE_EP                   0x02
#define     READ_EP                    0x82
#define     ESP32_CDC_PACKET_LENGTH    0x20

#define     CH341A_CMD_I2C_STREAM        0xAA
#define     CH341A_CMD_I2C_STM_SET        0x60 // bit 2: SPI with two data pairs D5,D4=out, D7,D6=in
#define     CH341A_CMD_I2C_STM_END        0x00

int esp32_cdc_init(void);
int esp32_cdc_shutdown(void);
int esp32_cdc_send_command(unsigned int writecnt, unsigned int readcnt, const unsigned char *writearr, unsigned char *readarr);
#if 0
int enable_pins(bool enable);
int config_stream(unsigned int speed);
#endif

#endif


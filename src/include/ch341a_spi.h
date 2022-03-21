/*
 * Copyright (C) 2018-2021 McMCC <mcmcc@mail.ru>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */
#ifndef __CH341_SPI_H__
#define __CH341_SPI_H__

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

//#define min(a,b) (((a)<(b))?(a):(b))
//#define max(a,b) (((a)>(b))?(a):(b))

#define     USB_TIMEOUT            1000    /* 1000 ms is plenty and we have no backup strategy anyway. */
#define     WRITE_EP            0x02
#define     READ_EP            0x82

#define     CH341_PACKET_LENGTH        0x20
#define     CH341_MAX_PACKETS        256
#define     CH341_MAX_PACKET_LEN        (CH341_PACKET_LENGTH * CH341_MAX_PACKETS)

#define     CH341A_CMD_SET_OUTPUT        0xA1
#define     CH341A_CMD_IO_ADDR        0xA2
#define     CH341A_CMD_PRINT_OUT        0xA3
#define     CH341A_CMD_SPI_STREAM        0xA8
#define     CH341A_CMD_SIO_STREAM        0xA9
#define     CH341A_CMD_I2C_STREAM        0xAA
#define     CH341A_CMD_UIO_STREAM        0xAB

#define     CH341A_CMD_I2C_STM_START    0x74
#define     CH341A_CMD_I2C_STM_STOP    0x75
#define     CH341A_CMD_I2C_STM_OUT        0x80
#define     CH341A_CMD_I2C_STM_IN        0xC0
#define     CH341A_CMD_I2C_STM_MAX        ( min( 0x3F, CH341_PACKET_LENGTH ) )
#define     CH341A_CMD_I2C_STM_SET        0x60 // bit 2: SPI with two data pairs D5,D4=out, D7,D6=in
#define     CH341A_CMD_I2C_STM_US        0x40
#define     CH341A_CMD_I2C_STM_MS        0x50
#define     CH341A_CMD_I2C_STM_DLY        0x0F
#define     CH341A_CMD_I2C_STM_END        0x00

#define     CH341A_CMD_UIO_STM_IN        0x00
#define     CH341A_CMD_UIO_STM_DIR        0x40
#define     CH341A_CMD_UIO_STM_OUT        0x80
#define     CH341A_CMD_UIO_STM_US        0xC0
#define     CH341A_CMD_UIO_STM_END        0x20

#define     CH341A_STM_I2C_20K        0x00
#define     CH341A_STM_I2C_100K        0x01
#define     CH341A_STM_I2C_400K        0x02
#define     CH341A_STM_I2C_750K        0x03
#define     CH341A_STM_SPI_DBL        0x04

int ch341a_spi_init(void);
int ch341a_spi_shutdown(void);
int ch341a_spi_send_command(unsigned int writecnt, unsigned int readcnt, const unsigned char *writearr, unsigned char *readarr);
int enable_pins(bool enable);
int config_stream(unsigned int speed);

#endif /* __CH341_SPI_H__ */
/* End of [ch341a_spi.h] package */

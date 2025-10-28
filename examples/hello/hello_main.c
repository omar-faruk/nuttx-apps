/****************************************************************************
 * apps/examples/hello/hello_main.c
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <stdio.h>
#include <fcntl.h>
#include <nuttx/sensors/as5600.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * hello_main
 ****************************************************************************/

int main(int argc, FAR char *argv[])
{
  printf("Hello, NuttX world!\n");

  int as5600_fd  = open("/dev/as5600", O_RDWR);
  if (as5600_fd < 0)
  {
    printf("Failed to open /dev/as5600\n");
    return -1;
  }
  struct as5600_reg_io_s reg_io;
  uint8_t buff[2];
  reg_io.reg = 0x0C; // Example register address
  reg_io.buflen = 2;    // Number of bytes to read
  reg_io.data   = buff; // Pointer to store read data

  ioctl(as5600_fd, AS5600_IOC_READ_REG, &reg_io); // Fill in with appropriate arguments

  printf("Read data from AS5600 register 0x%02X: %x, %x ", reg_io.reg, reg_io.data[0], reg_io.data[1]);

  
  close(as5600_fd);
}

/*
 * @file VNC_M5STICKC.h
 * @date 02.05.2020
 * @author Arrowmeiwaracing
 *
 * Copyright (c) 2020 Arrowmeiwaracing. All rights reserved.
 * This file is part of the VNC client for Arduino.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, a copy can be downloaded from
 * http://www.gnu.org/licenses/gpl.html, or obtained by writing to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 *
 */

#include <M5StickC.h>
#include "VNC_config.h"
#include "VNC.h"

class M5STICKCVNC: public VNCdisplay {
    public:
        M5STICKCVNC(void);

        bool hasCopyRect(void);
        uint32_t getHeight(void);
        uint32_t getWidth(void);
        void draw_area(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint8_t *data);
        void draw_rect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint16_t color);
        void copy_rect(uint32_t src_x, uint32_t src_y, uint32_t dest_x, uint32_t dest_y, uint32_t w, uint32_t h);
        void area_update_start(uint32_t x, uint32_t y, uint32_t w, uint32_t h);
        void area_update_data(char *data, uint32_t pixel);
        void area_update_end(void);

    private:
        uint32_t area_x, area_y, area_w, area_h;

};

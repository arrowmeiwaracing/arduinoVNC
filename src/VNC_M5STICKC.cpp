/*
 * @file VNC_M5STICKC.cpp
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
#include "VNC_M5STICKC.h"

M5STICKCVNC::M5STICKCVNC(void) {
}

bool M5STICKCVNC::hasCopyRect(void) {
    return false;
}

uint32_t M5STICKCVNC::getHeight(void) {
    return 80;
}

uint32_t M5STICKCVNC::getWidth(void) {
    return 160;
}

void M5STICKCVNC::draw_area(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint8_t *data) {
    M5STICKCVNC::area_update_start(x, y, w, h);
    M5STICKCVNC::area_update_data((char *)data, (w*h));
    M5STICKCVNC::area_update_end();
}


void M5STICKCVNC::draw_rect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint16_t color) {
    M5.Lcd.fillRect(x, y, w, h, ((((color) & 0xff) << 8) | (((color) >> 8))));
}

void M5STICKCVNC::copy_rect(uint32_t src_x, uint32_t src_y, uint32_t dest_x, uint32_t dest_y, uint32_t w, uint32_t h) {

}

void M5STICKCVNC::area_update_start(uint32_t x, uint32_t y, uint32_t w, uint32_t h) {
    area_x = x;
    area_y = y;
    area_w = w;
    area_h = h;
}

void M5STICKCVNC::area_update_data(char *data, uint32_t pixel){
   M5.Lcd.drawBitmap(area_x, area_y, area_w, area_h, (uint16_t*)data);
}

void M5STICKCVNC::area_update_end(void){
}

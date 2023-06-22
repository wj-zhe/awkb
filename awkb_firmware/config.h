/*
Copyright 2023 Jz_Wong <@wj-zhe>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Serial communication settings */
#define USE_SERIAL
#define SOFT_SERIAL_PIN GP1

/* //#define SPLIT_LAYER_STATE_ENABLE */
/* //#define SPLIT_USB_DETECT */
/* #define SERIAL_USE_MULTI_TRANSACTION */
/* /1* communication between sides *1/ */
/* #define SERIAL_PIO_USE_PIO1 */

/* Split side setting */
#define EE_HANDS

/* Top left key on left half */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0
/* Top right key on right half */
#define BOOTMAGIC_LITE_ROW_RIGHT 4
#define BOOTMAGIC_LITE_COLUMN_RIGHT 4


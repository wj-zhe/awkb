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

/* /1* Serial communication settings *1/ */
/* #define SERIAL_USART_TX_PIN GP1 */

/* Indicator light */
#define SPLIT_LED_STATE_ENABLE

/* RGB light */
#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_DISABLE_KEYCODES // disable keycodes for RGB Light controls, only status LED is supported
/* #    define PICA40_RGBLIGHT_TIMEOUT 5 // turn RGB off after N minutes */
#    define RGBLIGHT_LIMIT_VAL 128
#endif


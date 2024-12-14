/*
Copyright 2020 Jz_Wong <@wj-zhe>

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

/* Split side setting */
#define MASTER_RIGHT

/* Pointing Device */
#ifdef POINTING_DEVICE_ENABLE
#   define POINTING_DEVICE_RIGHT
#   define PMW33XX_CPI 600
#   define POINTING_DEVICE_ROTATION_90
#   define POINTING_DEVICE_INVERT_X
//
// #   define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// #   define AUTO_MOUSE_TIME 200
// #   define AUTO_MOUSE_DELAY 100
// #   define AUTO_MOUSE_THRESHOLD 2
//
#endif

/* Indicator light sync for split keyboard */
#define SPLIT_LED_STATE_ENABLE

/* RGB light */
#ifdef RGBLIGHT_ENABLE
#   define RGBLIGHT_SLEEP
#   define RGBLIGHT_SPLIT
#   define RGBLIGHT_LIMIT_VAL 100
#endif

/* tap-hold option */
/* #define TAPPING_TERM 175 */
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

/* Combo option */
/* #define COMBO_TERM 40 */
/* #define COMBO_STRICT_TIMER */
/* #define COMBO_ONLY_FROM_LAYER 0 */

/* Auto-Shift option */
#ifdef AUTO_SHIFT_ENABLE
#   define AUTO_SHIFT_TIMEOUT 165
/* #   define NO_AUTO_SHIFT_SPECIAL */
#   define NO_AUTO_SHIFT_NUMERIC
#   define NO_AUTO_SHIFT_ALPHA
#   define NO_AUTO_SHIFT_TAB
#endif

/* One-shot-key option */
#define ONESHOT_TIMEOUT 1000  /* Time (in ms) before the one shot key is released */


/* Copyright 2024 @wj-zhe */

#pragma once

/* Cirque trackpad config */
#ifdef POINTING_DEVICE_ENABLE
// #   define CIRQUE_PINNACLE_SPI_CS_PIN D2
// #   define CIRQUE_PINNACLE_SPI_DIVISOR 50
//
#   define CIRQUE_PINNACLE_DIAMETER_MM 23
#   define POINTING_DEVICE_ROTATION_180
#   define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_3X
//
#   define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#   define AUTO_MOUSE_TIME 150
#   define AUTO_MOUSE_DELAY 100
//
// #   define CIRQUE_PINNACLE_TAP_ENABLE
// #   define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
// #   define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
//
#   define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
// #   define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
//
#   ifdef CONSOLE_ENABLE
#       define POINTING_DEVICE_DEBUG
#   endif
#endif

/* OLED config */
#ifdef OLED_ENABLE
#   define OLED_BRIGHTNESS 128
#   define OLED_TIMEOUT 10000
#endif

// /* RGB underglow options */
// #ifdef RGBLIGHT_ENABLE
// #   define RGBLIGHT_SLEEP
// /* #define RGBLIGHT_LIMIT_VAL 120 */
// /* #define RGBLIGHT_HUE_STEP 10 */
// /* #define RGBLIGHT_SAT_STEP 17 */
// /* #define RGBLIGHT_VAL_STEP 17 */
// #endif


/* tap-hold option */
// #define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// one-shot key/layer
#define ONESHOT_TIMEOUT 1000

// Manual OS switch
// #define OS_SWITCH_ENABLE

/* Copyright 2024 @wj-zhe */

#pragma once

// Split variant config
#ifdef SPLIT_KEYBOARD
#   define MASTER_RIGHT
#endif

/* Cirque trackpad config */
#ifdef POINTING_DEVICE_ENABLE
#   define POINTING_DEVICE_CS_PIN D2
#   define CIRQUE_PINNACLE_DIAMETER_MM 23
// #   define CIRQUE_PINNACLE_CURVED_OVERLAY
// #   define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_2X
// #   define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE
#   define CIRQUE_PINNACLE_TAP_ENABLE
#   define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
// #   define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
#   define POINTING_DEVICE_DEBUG
#endif

/* OLED config */
#ifdef OLED_ENABLE
#   define OLED_BRIGHTNESS 128
#   define OLED_TIMEOUT 8000
#endif

/* RGB underglow options */
#ifdef RGBLIGHT_ENABLE
#   define RGBLIGHT_SLEEP
/* #define RGBLIGHT_LIMIT_VAL 120 */
/* #define RGBLIGHT_HUE_STEP 10 */
/* #define RGBLIGHT_SAT_STEP 17 */
/* #define RGBLIGHT_VAL_STEP 17 */
#endif


/* tap-hold option */
// #define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// one-shot key/layer
#define ONESHOT_TIMEOUT 1000

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


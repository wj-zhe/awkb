/* Copyright 2024 @wj-zhe */

#pragma once

// Split variant config
#ifdef SPLIT_KEYBOARD
#   define MASTER_RIGHT
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


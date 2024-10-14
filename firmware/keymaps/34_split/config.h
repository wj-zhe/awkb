// Copyright 2024 @wj-zhe

#pragma once

#define MASTER_RIGHT

// RGB underglow options
#ifdef RGBLIGHT_ENABLE
#   define RGBLIGHT_SLEEP
#endif


// tap-hold option
// #define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// one-shot key/layer
#define ONESHOT_TIMEOUT 1000


// 34-monosplit keymap

#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE
#   include "../common/oled_custom.c"
#endif // #ifdef OLED_ENABLE

#ifdef POINTING_DEVICE_ENABLE
#   include "../common/cirque_trackpad.c"
#endif // #ifdef POINTING_DEVICE_ENABLE

#include "../common/keymap_34.c"

// Tapping-term per key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(TD_L1):
            return 255;
        case LCTL_T(KC_A):
            return 165;
        case LCTL_T(KC_SCLN):
            return 155;
        case LALT_T(KC_BSPC): case LALT_T(KC_SPC):
        case LSFT_T(KC_Z): case LSFT_T(KC_SLSH):
        //     return 145;
        // case LT(2,KC_TAB):
            return 135;
        default:
            return TAPPING_TERM;
    }
};

// bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case LSFT_T(KC_Z): case LSFT_T(KC_SLSH):
//         case LT(2,KC_TAB): case LALT_T(KC_BSPC):
//             // Immediately select the hold action when another key is pressed.
//             return true;
//         default:
//             // Do not select the hold action when another key is pressed.
//             return false;
//     }
// }

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_Z): case LSFT_T(KC_SLSH):
        case LT(2,KC_TAB): case LALT_T(KC_BSPC):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}


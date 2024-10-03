// 34-key keymap

#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE
#   include "../common/oled_custom.c"
#endif // #ifdef OLED_ENABLE

#include "../common/keymap_34.c"

// Tapping-term per key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_A): case LCTL_T(KC_SCLN):
            return 175;
        case LALT_T(KC_BSPC): case LALT_T(KC_SPC):
            return 150;
        case LSFT_T(KC_Z): case LSFT_T(KC_F1):
        case LSFT_T(KC_SLSH):
            return 135;
        default:
            return TAPPING_TERM;
    }
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_Z): case LSFT_T(KC_F1): case LSFT_T(KC_SLSH):
        case LT(2,KC_TAB):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

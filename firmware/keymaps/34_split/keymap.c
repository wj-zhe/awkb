// 34-key custom keymap

#include "../common/keymap_34.c"

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
#   include "../common/rgblight.c"
#endif // defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)

/* Tapping-term per key */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_Q): case LGUI_T(KC_P):
        case LCTL_T(KC_A): case LCTL_T(KC_SCLN):
            return 175;
        case LALT_T(KC_BSPC): case LALT_T(KC_SPC):
            return 150;
        case LSFT_T(KC_SLSH):
        case LSFT_T(KC_Z): // case LSFT_T(KC_F1):
            return 135;
        default:
            return TAPPING_TERM;
    }
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_Z): // case LSFT_T(KC_F1):
        case LSFT_T(KC_SLSH):
        case LT(2,KC_TAB):
        case LALT_T(KC_BSPC): case LALT_T(KC_SPC):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}


// Layer state related ..
layer_state_t layer_state_set_user(layer_state_t state) {

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
    rgblight_set_layer_state_user(state);
#endif // defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)

    return state;

}


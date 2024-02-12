
#include QMK_KEYBOARD_H

#define ___ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_3(
        LGUI_T(KC_Q), KC_W, KC_E, KC_R, KC_T,
        KC_Y, KC_U, KC_I, KC_O, LGUI_T(KC_P),

        LCTL_T(KC_A), KC_S, KC_D, KC_F, KC_G,
        KC_H, KC_J, KC_K, KC_L, LCTL_T(KC_SCLN),

        LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B,
        KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH),

        LT(2,KC_TAB), LALT_T(KC_BSPC), KC_NO,
        KC_NO, LALT_T(KC_SPC), LT(1, KC_ENT)
    ),

};

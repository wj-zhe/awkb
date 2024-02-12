/* Keymap for thrfv */

#include QMK_KEYBOARD_H

#define ___ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2(
        LGUI_T(KC_Q), KC_W, KC_E, KC_R, KC_T,
        KC_Y, KC_U, KC_I, KC_O, LGUI_T(KC_P),

        LCTL_T(KC_A), KC_S, KC_D, KC_F, KC_G,
        KC_H, KC_J, KC_K, KC_L, LCTL_T(KC_SCLN),

        LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B,
        KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH),

        LT(2,KC_TAB), LALT_T(KC_BSPC),
        LALT_T(KC_SPC), LT(1, KC_ENT)
    ),

    [1] = LAYOUT_split_3x5_2(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,
        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,

        LCTL_T(KC_1), KC_2, KC_3, KC_4, KC_5,
        KC_6, KC_7, KC_8, KC_9, LCTL_T(KC_0),

        KC_LSFT, KC_NO, KC_NO, KC_EQL, LT(3,KC_PLUS),
        KC_UNDS, KC_MINS, ___, ___, ___,

        ___, ___,
        ___, TG(1)
    ),

    [2] = LAYOUT_split_3x5_2(
        LGUI_T(KC_F9), KC_F10, KC_F11, KC_F12, KC_PSCR,
        KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_LGUI,

        LCTL_T(KC_F5), KC_F6, KC_F7, KC_F8, KC_NO,
        KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_LCTL,

        LSFT_T(KC_F1), KC_F2, KC_F3, KC_F4, TO(3),
        KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_RSFT,

        TG(2), ___,
        ___, ___
    ),

    [3] = LAYOUT_split_3x5_2(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NUM,
        KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS,

        KC_NO, KC_NO, QK_BOOT, KC_NO, TG(3),
        KC_P0, KC_P1, KC_P2, KC_P3, KC_DOT,

        TO(2), ___,
        KC_BSPC, KC_ESC
    )
};

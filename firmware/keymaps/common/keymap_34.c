// 34-key keymap

#ifdef CONSOLE_ENABLE
#   include "print.h"
#endif

#include "tap_dances.h"
#include "combo.h"

// Key code alias
#define ___ KC_TRNS

/* keymaps */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_34(
            LGUI_T(KC_Q), KC_W, KC_E, KC_R, KC_T,          KC_Y, KC_U, KC_I, KC_O, LGUI_T(KC_P),
            LCTL_T(KC_A), KC_S, KC_D, KC_F, KC_G,          KC_H, KC_J, KC_K, KC_L, LCTL_T(KC_SCLN),
            LSFT_T(KC_Z), KC_X, KC_C, KC_V, LT(3,KC_B),    LSG_T(KC_N), KC_M, KC_COMM, KC_DOT, LSFT_T(KC_SLSH),
                         LT(2,KC_TAB), LALT_T(KC_BSPC),    LALT_T(KC_SPC), TD(TD_L1)

            ),

    [1] = LAYOUT_34(
            KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
            LCTL_T(KC_1), KC_2, KC_3, KC_4, KC_5,          KC_6, KC_7, KC_8, KC_9, LCTL_T(KC_0),
            KC_LSFT, KC_GRV, KC_BSLS, KC_LBRC, KC_RBRC,    KC_EQL, KC_MINS, ___, ___, ___,
                                              ___, ___,    ___, TG(1)

            ),

    [2] = LAYOUT_34(
            LGUI_T(KC_F9), KC_F10, KC_F11, KC_F12, KC_BTN2,    KC_HOME, KC_PGDN, KC_PGUP, KC_END, LGUI_T(KC_WBAK),
            LCTL_T(KC_F5), KC_F6, KC_F7, KC_F8, KC_BTN1,       KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, LCTL_T(KC_WFWD),
            LSFT_T(KC_F1), KC_F2, KC_F3, KC_F4, TO(3),         TD(TD_MD_ULT), KC_VOLD, KC_VOLU, KC_MUTE, KC_LSFT,
                                                  ___, ___,    ___, ___

            ),

    [3] = LAYOUT_34(
            KC_NO, KC_HOME, KC_UP, KC_PGUP, KC_NUM,         KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS,
            KC_END, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,    KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS,
            KC_BRIU, KC_BRIU, KC_VOLU, KC_VOLD, TG(3),      KC_P0, KC_P1, KC_P2, KC_P3, LSFT_T(KC_DOT),
                                               ___, ___,    ___, KC_BSPC

            ),

};


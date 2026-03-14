// 34-split custom keymap

#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
#   include "print.h"
#endif

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
#   include "rgblight.c"
#endif // defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)

#ifdef TAP_DANCE_ENABLE
#   include "tap_dances.h"
#endif

#ifdef COMBO_ENABLE
#   include "combo.h"
#endif

// Key code alias
#define ___ KC_TRNS

/* keymaps */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_34(
            LGUI_T(KC_Q), KC_W, KC_E, KC_R, KC_T,          KC_Y, KC_U, KC_I, KC_O, LGUI_T(KC_P),
            LCTL_T(KC_A), KC_S, KC_D, KC_F, KC_G,          KC_H, KC_J, KC_K, KC_L, LCTL_T(KC_SCLN),
            LSFT_T(KC_Z), KC_X, KC_C, KC_V, LT(3,KC_B),    KC_N, KC_M, KC_COMM, KC_DOT, LSFT_T(KC_SLSH),
                         LT(2,KC_TAB), LALT_T(KC_BSPC),    LALT_T(KC_SPC), TD(TD_L1)

            ),

    [1] = LAYOUT_34(
            KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
            LCTL_T(KC_1), KC_2, KC_3, KC_4, KC_5,          KC_6, KC_7, KC_8, KC_9, LCTL_T(KC_0),
            KC_LSFT, KC_GRV, KC_BSLS, KC_LBRC, KC_RBRC,    KC_EQL, KC_MINS, ___, ___, ___,
                                          KC_LGUI, ___,    ___, TG(1)

            ),

    [2] = LAYOUT_34(
            LGUI_T(KC_F9), KC_F10, KC_F11, KC_F12, KC_PSCR,    KC_HOME, KC_PGDN, KC_PGUP, KC_END, LGUI_T(KC_WBAK),
            LCTL_T(KC_F5), KC_F6, KC_F7, KC_F8, KC_INS,        KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, LCTL_T(KC_WFWD),
            LSFT_T(KC_F1), KC_F2, KC_F3, KC_F4, TO(3),         TD(TD_MD_ULT), KC_VOLD, KC_VOLU, KC_MUTE, KC_LSFT,
                                                  ___, ___,    ___, KC_DEL

            ),

    [3] = LAYOUT_34(
            KC_NO, KC_HOME, KC_UP, KC_PGUP, KC_NUM,         KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS,
            KC_END, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,    KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS,
            UG_TOGG, UG_PREV, UG_NEXT, KC_NO, TG(3),        KC_P0, KC_P1, KC_P2, KC_P3, LSFT_T(KC_DOT),
                                               ___, ___,    KC_BSPC, KC_NO

            ),

};

// Custom keycode
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case KC_BSPC: case LALT_T(KC_BSPC): {
            // Initialize a boolean variable that keeps track
            // of the delete key status: registered or not?
            static bool delkey_registered;
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_BSPC keycode as usual outside of shift
            return true;
        };

    };

    // for debug mode only
    #ifdef CONSOLE_ENABLE
        dprintf("KL: kc: 0x%04X, col: %u, row: %u,"
            "pressed: %b, time: %u, interrupt: %b, count: %u\n",
            keycode, record->event.key.col, record->event.key.row,
            record->event.pressed, record->event.time,
            record->tap.interrupted, record->tap.count
            );
    #endif

    return true;
};

#ifdef CONSOLE_ENABLE
void keyboard_post_init_user(void) {
  // Customize these values to desired behavior
  debug_enable=true;
  // debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;
}
#endif


/* Tapping-term per key */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_Q): case LGUI_T(KC_P):
        case LCTL_T(KC_A): case LCTL_T(KC_SCLN):
            return 175;
        case LALT_T(KC_BSPC): case LALT_T(KC_SPC):
            return 150;
        case LSFT_T(KC_Z): // case LSFT_T(KC_F1):
        case LSFT_T(KC_SLSH):
            return 135;
        default:
            return TAPPING_TERM;
    }
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_Z): case LSFT_T(KC_SLSH):
        case LT(2,KC_TAB):
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


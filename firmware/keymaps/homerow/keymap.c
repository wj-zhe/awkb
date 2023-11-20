
#include QMK_KEYBOARD_H

#ifdef COMBO_ENABLE
#   include "g/keymap_combo.h"
#endif

#ifdef TAP_DANCE_ENABLE
#   include "tap_dances.h"
#endif

// A 'transparent' key code (that falls back to the layers below it).
#define __T KC_TRANSPARENT
#define ___ KC_NO

/* keymaps */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2(
            LGUI_T(KC_Q), KC_W, KC_E, KC_R, KC_T,          KC_Y, KC_U, KC_I, KC_O, LGUI_T(KC_P),
            KC_A, KC_S, KC_D, LCTL_T(KC_F), KC_G,          KC_H, LCTL_T(KC_J), KC_K, KC_L, KC_SCLN,
            LSFT_T(KC_Z), KC_X, KC_C, KC_V, LT(3,KC_B),    KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH),
                         LT(2,KC_TAB), LALT_T(KC_BSPC),    LALT_T(KC_SPC), TD(TD_L1)
            ),

    [1] = LAYOUT_split_3x5_2(
            KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
            KC_1, KC_2, KC_3, LCTL_T(KC_4), KC_5,        KC_6, LCTL_T(KC_7), KC_8, KC_9, KC_0,
            KC_LSFT, ___, ___, KC_LBRC, KC_RBRC,         KC_EQL, KC_MINS, __T, __T, __T,
                                            __T, __T,    __T, __T
            ),

    [2] = LAYOUT_split_3x5_2(
            LGUI_T(KC_F9), KC_F10, KC_F11, KC_F12, KC_BTN2,    KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_LGUI,
            KC_F5, KC_F6, KC_F7, LCTL_T(KC_F8), KC_BTN1,       KC_LEFT, LCTL_T(KC_DOWN), KC_UP, KC_RGHT, KC_CAPS,
            LSFT_T(KC_F1), KC_F2, KC_F3, KC_F4, TO(3),         KC_MUTE, KC_VOLD, KC_VOLU, KC_WBAK, RSFT_T(KC_WFWD),
                                    TG(2), LALT_T(KC_PSCR),    LALT_T(KC_MPLY), TD(TD_MD_NX_PR)
            ),

    [3] = LAYOUT_split_3x5_2(
            ___, KC_HOME, KC_UP, KC_PGUP, ___,             KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS,
            KC_END, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,    KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS,
            ___, ___, ___, ___, TG(3),                     KC_P0, KC_P1, KC_P2, KC_P3, KC_DOT,
                                            __T, __T,      KC_BSPC, KC_ESC
            ),

};

/* Tapping-term per key */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFT_T(KC_SLSH): case LSFT_T(KC_Z): case LSFT_T(KC_F1):
        case LALT_T(KC_BSPC):
            return 115;
        case LALT_T(KC_SPC):
            return 135;
        /* case LCTL_T(KC_F): case LCTL_T(KC_J): */
        /*     return 150; */
        default:
            return TAPPING_TERM;
    }
};

/* /1* per-key ignore mod tap configuration *1/ */
/* bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         // Do not force the mod-tap key press to be handled as a modifier */
/*         // if any other key was pressed while the mod-tap key is held down. */
/*         case LGUI_T(KC_Q): case LGUI_T(KC_P): */
/*         case LCTL_T(KC_A): case LCTL_T(KC_SCLN): */
/*         case LCTL_T(KC_F5): */
/*         case LSFT_T(KC_Z): */
/*         case LSFT_T(KC_COMM): case RSFT_T(KC_DOT): */
/*         case LSFT_T(KC_F1): */
/*             return true; */
/*         // Force the mod-tap key press to be handled as a modifier if any */
/*         // other key was pressed while the mod-tap key is held down. */
/*         default: */
/*             return false; */
/*     } */
/* }; */

/* /1* per-key permissive setting *1/ */
/* bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         case LT(2,KC_TAB): */
/*         /1* case RSFT_T(KC_SLSH): case LSFT_T(KC_Z): case LSFT_T(KC_F1): *1/ */
/*         /1* case LALT_T(KC_BSPC): case LALT_T(KC_SPC): *1/ */
/*             // Immediately select the hold action when another key is tapped. */
/*             return true; */
/*         default: */
/*             // Do not select the hold action when another key is tapped. */
/*             return false; */
/*     } */
/* } */

/* Custom keycode */
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case KC_BSPC: case LALT_T(KC_BSPC): case LGUI_T(KC_BSPC): {
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

        case KC_ESC: case LALT_T(KC_ESC): case LGUI_T(KC_ESC): {
            // Detect the activation of only SHIFT key
            if ( (get_mods() & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT) ) {
                if (record->event.pressed) {
                    tap_code(KC_GRV);
                }
                else {
                    unregister_code(KC_GRV);
                }
                // Do not let QMK process the keycode further
                return false;
            }
            // Else, let QMK process the standard keycode as usual
            return true;
        };
    };

    return true;
};

/* lights */
 #if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)

// Light LEDs 0 when keyboard layer X is active;
// for more color options, see: https://github.com/qmk/qmk_firmware/blob/master/quantum/color.h
const rgblight_segment_t PROGMEM layer_1[] = RGBLIGHT_LAYER_SEGMENTS( {0, 1, HSV_YELLOW} );
const rgblight_segment_t PROGMEM layer_2[] = RGBLIGHT_LAYER_SEGMENTS( {0, 1, HSV_PURPLE} );
const rgblight_segment_t PROGMEM layer_3[] = RGBLIGHT_LAYER_SEGMENTS( {0, 1, HSV_CYAN} );

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        layer_1,
        layer_2,
        layer_3
        );

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

/* bool led_update_user(led_t led_state) { */
/*     rgblight_set_layer_state(0, led_state.caps_lock); */
/*     return true; */
/* } */

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 1));
    rgblight_set_layer_state(1, layer_state_cmp(state, 2));
    rgblight_set_layer_state(2, layer_state_cmp(state, 3));
    return state;
}

#endif // defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)


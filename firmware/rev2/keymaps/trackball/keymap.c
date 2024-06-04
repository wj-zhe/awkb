
#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
#   include "print.h"
#endif

/* #ifdef ENCODER_ENABLE */
/* #   include "encoder_cuz.h" */
/* #endif */

#ifdef TAP_DANCE_ENABLE
#   include "tap_dances.h"
#endif

#ifdef COMBO_ENABLE
#   include "g/keymap_combo.h"
#endif


// A 'transparent' key code (that falls back to the layers below it).
#define ___ KC_TRNS
#define none KC_NO

/* keymaps */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_3x5_3(
            LGUI_T(KC_Q), KC_W, KC_E, KC_R, KC_T,          KC_Y, KC_U, KC_I, KC_O, LGUI_T(KC_P),
            /* KC_A, KC_S, KC_D, LCTL_T(KC_F), KC_G,          KC_H, LCTL_T(KC_J), KC_K, KC_L, KC_SCLN, */
            LCTL_T(KC_A), KC_S, KC_D, KC_F, KC_G,          KC_H, KC_J, KC_K, KC_L, LCTL_T(KC_SCLN),
            LSFT_T(KC_Z), KC_X, KC_C, KC_V, LT(3,KC_B),    LSG_T(KC_N), KC_M, KC_COMM, KC_DOT, LSFT_T(KC_SLSH),
                LT(2,KC_TAB), LALT_T(KC_BSPC), KC_MUTE,    KC_BTN1, LALT_T(KC_SPC), TD(TD_L1)

            ),

    [1] = LAYOUT_split_3x5_3(
            KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
            /* KC_1, KC_2, KC_3, LCTL_T(KC_4), KC_5,       KC_6, LCTL_T(KC_7), KC_8, KC_9, KC_0, */
            LCTL_T(KC_1), KC_2, KC_3, KC_4, KC_5,          KC_6, KC_7, KC_8, KC_9, LCTL_T(KC_0),
            KC_LSFT, KC_GRV, KC_BSLS, KC_LBRC, KC_RBRC,    KC_EQL, KC_MINS, ___, ___, ___,
                                       ___, ___, ___,      KC_BTN2, ___, TG(1)
            ),

    [2] = LAYOUT_split_3x5_3(
            LGUI_T(KC_F9), KC_F10, KC_F11, KC_F12, KC_PSCR,    KC_HOME, KC_PGDN, KC_PGUP, KC_END, LGUI_T(KC_WBAK),
            /* KC_F5, KC_F6, KC_F7, LCTL_T(KC_F8), KC_CAPS,    KC_LEFT, LCTL_T(KC_DOWN), KC_UP, KC_RGHT, KC_CAPS, */
            LCTL_T(KC_F5), KC_F6, KC_F7, KC_F8, KC_INS,        KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, LCTL_T(KC_WFWD),
            LSFT_T(KC_F1), KC_F2, KC_F3, KC_F4, TO(3),         TD(TD_MD_ULT), KC_VOLD, KC_VOLU, KC_MUTE, KC_LSFT,
                                        TG(2), ___, ___,       KC_BTN2, ___, none

            ),

    [3] = LAYOUT_split_3x5_3(
            none, KC_HOME, KC_UP, KC_PGUP, KC_NUM,          KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS,
            KC_END, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,    KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS,
            KC_LSFT, KC_MUTE, KC_VOLD, KC_VOLU, TG(3),      KC_P0, KC_P1, KC_P2, KC_P3, LSFT_T(KC_DOT),
                                         none, ___, ___,    ___, LALT_T(KC_BSPC), KC_ESC

            ),

};

/* Tapping-term per key */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case LCTL_T(KC_A): case LCTL_T(KC_SCLN):
        //     return 175;
        case LALT_T(KC_BSPC): case LALT_T(KC_SPC):
            return 145;
        case LSFT_T(KC_Z): case LSFT_T(KC_F1):
        case LSFT_T(KC_SLSH):
            return 125;
        default:
            return TAPPING_TERM;
    }
};

/* per-key permissive setting */
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Immediately select the hold action when another key is tapped.
        /* case LT(2,KC_TAB): */
        case LSFT_T(KC_Z): case LSFT_T(KC_F1):
        case LSFT_T(KC_SLSH):
            return true;

        // Do not select the hold action when another key is tapped.
        default:
            return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(2,KC_TAB):
        case LALT_T(KC_BSPC): case LALT_T(KC_SPC):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

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

        /* case ENC_TG: { */
        /*     if (record->event.pressed) { */
        /*         // Go to the next encoder mode, looping around to the start. */
        /*         encoder_mode = (encoder_mode + 1) % NUM_ENC_MODES; */
        /*     } */
        /*     return false; */
        /* }; */

    };

    return true;

};

/* lights */
#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)

// Light LEDs 0 when keyboard layer X is active;
// for more color options, see: https://github.com/qmk/qmk_firmware/blob/master/quantum/color.h
const rgblight_segment_t PROGMEM layer_1[] = RGBLIGHT_LAYER_SEGMENTS( {0, 1, HSV_GOLD} );
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

#endif // defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)

#if defined(POINTING_DEVICE_ENABLE)
    static bool scrolling_mode = false;
#endif // defined(POINTING_DEVICE_ENABLE)

layer_state_t layer_state_set_user(layer_state_t state) {

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
    rgblight_set_layer_state(0, layer_state_cmp(state, 1));
    rgblight_set_layer_state(1, layer_state_cmp(state, 2));
    rgblight_set_layer_state(2, layer_state_cmp(state, 3));

#endif // defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)

#if defined(POINTING_DEVICE_ENABLE)
    switch (get_highest_layer(state)) {
        case 1: case 3:  // Enable scrolling mode
            scrolling_mode = true;
            pointing_device_set_cpi(100);
            break;
        default:
            if (scrolling_mode) {  // Disable scrolling mode
                scrolling_mode = false;
            };
            pointing_device_set_cpi(800);
            break;
    }

#endif // defined(POINTING_DEVICE_ENABLE)

    return state;

}

#if defined(POINTING_DEVICE_ENABLE)
int x_sum = 0;
int y_sum = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scrolling_mode) {
        // sum x and y movements
        x_sum += mouse_report.x;
        y_sum += mouse_report.y;

    };

    if (scrolling_mode) {

        // set h/v movements only on consecutive x/y movements
        if (abs(x_sum) >=4 || abs(y_sum) >=4) {

            if ( abs(x_sum) - abs(y_sum) >1 ) {
                mouse_report.h = mouse_report.x;
                mouse_report.v = 0;
            } else if ( abs(y_sum) - abs(x_sum) >1 ) {
                mouse_report.v = mouse_report.y;
                mouse_report.h = 0;
            } else {
                // set h/v to zero to avoid simultaneous scroll movements
                mouse_report.h = 0;
                mouse_report.v = 0;
            };

            // reset x_sum and y_sum
            x_sum = 0;
            y_sum = 0;
        }

        // set x/y to zero to avoid mouse movements
        mouse_report.x = 0;
        mouse_report.y = 0;

    }
    return mouse_report;
}

#endif // defined(POINTING_DEVICE_ENABLE)


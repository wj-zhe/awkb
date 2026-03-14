
#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
#   include "print.h"
#endif // #ifdef CONSOLE_ENABLE

#ifdef POINTING_DEVICE_ENABLE
#   include "trackball.c"
#endif // #ifdef POINTING_DEVICE_ENABLE

#ifdef FSR_ENABLE
#   include "fsr.c"
#endif // #ifdef FSR_ENABLE

#ifdef ENCODER_ENABLE
#   include "encoder_awkb.h"
#endif // #ifdef ENCODER_ENABLE
       //
#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
#   include "rgblight.c"
#endif // defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)

#ifdef TAP_DANCE_ENABLE
#   include "tap_dances.h"
#endif // #ifdef TAP_DANCE_ENABLE

#ifdef COMBO_ENABLE
#   include "combo.h"
#endif // #ifdef COMBO_ENABLE

// Custom keycodes
enum custom_keycodes {

#ifdef ENCODER_ENABLE
    ENC_TG = SAFE_RANGE,
#endif

#ifdef FSR_ENABLE // Key for FSR threshold related actions
    FST_U, 
    FST_D,
    FST_O,
    FST_P
#endif

};

// Aliases
#define ___ KC_TRNS

#ifdef ENCODER_ENABLE
    #define ENC_NO ENC_TG
#else
    #define ENC_NO KC_NO
#endif

/* keymaps */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_36(
            LGUI_T(KC_Q), KC_W, KC_E, KC_R, KC_T,          KC_Y, KC_U, KC_I, KC_O, LGUI_T(KC_P),
            LCTL_T(KC_A), KC_S, KC_D, KC_F, KC_G,          KC_H, KC_J, KC_K, KC_L, LCTL_T(KC_SCLN),
            LSFT_T(KC_Z), KC_X, KC_C, KC_V, LT(3,KC_B),    KC_N, KC_M, KC_COMM, KC_DOT, LSFT_T(KC_SLSH),
                 ENC_TG, LT(2,KC_TAB), LALT_T(KC_BSPC),    LALT_T(KC_SPC), TD(TD_L1), KC_APP

            ),

    [1] = LAYOUT_36(
            KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
            LCTL_T(KC_1), KC_2, KC_3, KC_4, KC_5,           KC_6, KC_7, KC_8, KC_9, LCTL_T(KC_0),
            KC_LSFT, KC_GRV, KC_BSLS, KC_LBRC, KC_RBRC,     KC_EQL, KC_MINS, ___, ___, ___,
                                     ___, KC_LGUI, ___,     ___, TG(1), KC_NO
            ),

    [2] = LAYOUT_36(
            LGUI_T(KC_F9), KC_F10, KC_F11, KC_F12, KC_PSCR,    KC_HOME, KC_PGDN, KC_PGUP, KC_END, LGUI_T(KC_WBAK),
            LCTL_T(KC_F5), KC_F6, KC_F7, KC_F8, KC_INS,        KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, LCTL_T(KC_WFWD),
            LSFT_T(KC_F1), KC_F2, KC_F3, KC_F4, TO(3),         TD(TD_MD), KC_VOLD, KC_VOLU, KC_MUTE, KC_LSFT,
                              KC_NO, KC_NO, LALT_T(KC_DEL),    KC_LALT, KC_DEL, KC_NO

            ),

    [3] = LAYOUT_36(
            KC_NO, KC_HOME, KC_UP, KC_PGUP, KC_NUM,                 KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS,
            LCTL_T(KC_END), KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,    KC_PAST, KC_P4, KC_P5, KC_P6, LCTL_T(KC_PPLS),
            KC_LSFT, KC_MUTE, KC_VOLD, KC_VOLU, TG(3),              KC_P0, KC_P1, KC_P2, KC_P3, LSFT_T(KC_DOT),
                                            KC_NO, KC_NO, KC_NO,    LALT_T(KC_BSPC), KC_ESC, KC_NO

            ),

    [4] = LAYOUT_36(
            KC_LGUI, KC_NO, FST_U, KC_NO, FST_P,      MS_BTN1, MS_BTN2, KC_NO, KC_NO, KC_RGUI,
            KC_LCTL, KC_NO, FST_D, KC_NO, FST_O,      KC_NO, KC_NO, KC_NO, KC_NO, KC_RCTL,
            KC_LSFT, KC_NO, KC_NO, KC_LALT, MO(3),    KC_NO, KC_NO, KC_NO, KC_NO, KC_RSFT,
                          KC_NO, MS_BTN1, MS_BTN2,    KC_RALT, KC_NO, KC_NO

            ),

};

void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    // Customize these values to desired behavior
    debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
#endif

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
  rgblight_layers = awkb_rgb_layers;
#endif

}

// Tapping-term per key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_Q): case LGUI_T(KC_P):
            return 200;
        case LCTL_T(KC_A): case LCTL_T(KC_SCLN):
            return 175;
        // case LALT_T(KC_BSPC): case LALT_T(KC_SPC):
        //     return 150;
        case LSFT_T(KC_Z): // case LSFT_T(KC_F1):
        case LSFT_T(KC_SLSH):
            return 125;

        default:
            return TAPPING_TERM;
    }
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(2,KC_TAB): case TD(TD_L1):
        case LALT_T(KC_BSPC): case LALT_T(KC_SPC):
        case LSFT_T(KC_Z): // case LSFT_T(KC_F1):
        case LSFT_T(KC_SLSH):
            // Immediately select the hold action when another key is tapped
            return true;
        default:
            // Do not select the hold action
            return false;
    }
}

// Layer based functions
static uint8_t active_layer = 0;

layer_state_t layer_state_set_user(layer_state_t state) {

    // Layer light-signal
#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
    rgblight_set_layer_state_user(state);
#endif // defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)

    // Layer-based actions
    active_layer = get_highest_layer(state);

    switch(active_layer) {

        case 3: // Enable scrolling mode
#ifdef POINTING_DEVICE_ENABLE
            scroll_mode = true;
#endif // defined(POINTING_DEVICE_ENABLE)
            break;

        default:
#ifdef POINTING_DEVICE_ENABLE
            if (scroll_mode) { // Disable scrolling mode
                scroll_mode = false;
            };
#endif
            break;
    }

#ifdef POINTING_DEVICE_ENABLE
    pointing_device_task_layer();
#endif

    return state;

}

#ifdef KEY_OVERRIDE_ENABLE
const key_override_t del_key_override = ko_make_basic(MOD_MASK_SHIFT, LALT_T(KC_BSPC), KC_DEL);
const key_override_t grave_esc_override = ko_make_basic(MOD_MASK_SHIFT, LALT_T(KC_ESC), KC_GRV);

const key_override_t *key_overrides[] = {
	&del_key_override,
	&grave_esc_override
};
#endif

static uint8_t keypress_count = 0;
static uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Key press count used to determine how many keys are active
    if (record->event.pressed) {
        keypress_count += 1;
    } else {
        keypress_count -= (keypress_count > 0) ? 1 : 0;
    }

    mod_state = get_mods();

    // Custom key actions and key_overrides
    switch (keycode) {
        case ENC_TG: 
            if (record->event.pressed) {
                // Go to the next encoder mode, looping around to the start.
                encoder_mode = (encoder_mode + 1) % NUM_ENC_MODES;
            }
            return false;

#ifdef FSR_ENABLE
        case FST_O: 
            if (record->event.pressed) {
                // Go to the next fsr thres pre-set, looping around to the start.
                thres_id = (thres_id + 1) % NUM_FSR_THRES;
                thres_actual = fsr_thres_options[thres_id];
            }
            return false;

        case FST_P:
            if (record->event.pressed) {
                char tv[32]; // thres_actual value string
                sprintf(tv, "FSR: thres %u reading %u", thres_actual, fsr_reading);
                SEND_STRING(tv);
            }
            return false;

        case FST_U: // Increase fsr actual threshold.
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    thres_actual += 20;
                    
                    set_mods(mod_state);   
                } else if (mod_state & MOD_MASK_CTRL) {
                    thres_actual += 5;
                } else {
                    thres_actual += 10;
                }
            }
            return false;

        case FST_D: // Decrease fsr actual threshold.
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    thres_actual -= 20;
                    
                    set_mods(mod_state);   
                } else if (mod_state & MOD_MASK_CTRL) {
                    thres_actual -= 5;
                } else {
                    thres_actual -= 10;
                }
            }
            return false;
        
#endif

    };

// #ifdef CONSOLE_ENABLE
//     uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", 
//         keycode, 
//         record->event.key.col, 
//         record->event.key.row, 
//         record->event.pressed, 
//         record->event.time, 
//         record->tap.interrupted, 
//         record->tap.count
//     ); 
// #endif 

    return true;

};

static uint8_t kc_count = 0;
static uint16_t timer = 0xFFFF;
static uint16_t timeElapsed;

void housekeeping_task_user(void) {

#if defined(POINTING_DEVICE_ENABLE) && defined (FSR_ENABLE)

    if (keypress_count > 0) {
        if (kc_count < KEYPRESS_COUNT_THRES) kc_count += 1;
    } else {
        if (kc_count > 0) kc_count -= 1;
    }

    bool sense_return = fsr_sense();
    
    if (active_layer != 4 && active_layer != 3 && fsr_stack >= FSR_STACK_THRES && kc_count ==0 ) {    
        uint32_t keypress_idle = last_matrix_activity_elapsed();
        timeElapsed = timer_elapsed(timer);

#ifdef CONSOLE_ENABLE
        dprintf("x: %u %u \n", thres_actual, fsr_reading);
#endif

        if (keypress_idle >= TAPPING_TERM + 50 && timeElapsed >= LAYER_OFF_TIMING) {
            layer_on(4);
        }
    }       

    if (active_layer == 4) {
        uint32_t mouse_idle = last_pointing_device_activity_elapsed();

        if (!sense_return || mouse_idle >= MOUSE_IDLE_TIMING) {
            timer = timer_read();
            layer_off(4);
        }
    }

#endif

};

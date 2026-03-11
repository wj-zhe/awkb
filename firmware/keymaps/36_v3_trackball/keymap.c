
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

#ifdef FSR_ENABLE // Key for increase or decrease fsr threshold
    FST_U,
    FST_D
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
                 ENC_TG, LT(2,KC_TAB), LALT_T(KC_BSPC),    LALT_T(KC_SPC), TD(TD_L1), MS_BTN1

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
            KC_LGUI, KC_NO, FST_U, KC_NO, MS_BTN3,    KC_NO, KC_NO, KC_NO, KC_NO, KC_RGUI,
            KC_LCTL, KC_NO, FST_D, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_RCTL,
            KC_LSFT, KC_NO, KC_NO, KC_NO, MO(3),      KC_NO, KC_NO, KC_NO, KC_NO, KC_RSFT,
                          KC_NO, MS_BTN1, MS_BTN2,    KC_NO, KC_NO, KC_NO

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Key press count used to determine how many keys are active
    if (record->event.pressed) {
        keypress_count += 1;
    } else {
        keypress_count -= (keypress_count > 0) ? 1 : 0;
    }
    
    // Custom key actions and key_overrides
    switch (keycode) {
        case ENC_TG: 
            if (record->event.pressed) {
                // Go to the next encoder mode, looping around to the start.
                encoder_mode = (encoder_mode + 1) % NUM_ENC_MODES;
            }
            return false;

#ifdef FSR_ENABLE
        case FST_U:
            if (record->event.pressed) thres_actual += 10; // Increase fsr actual threshold.
            return false;

        case FST_D:
            if (record->event.pressed) thres_actual -= 10; // Decrease fsr actual threshold.
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
static uint8_t prev_layer = 0;

void housekeeping_task_user(void) {

#if defined(POINTING_DEVICE_ENABLE) && defined (FSR_ENABLE)

    if (keypress_count > 0) {
        if (kc_count < FSR_INPUT_C) kc_count += 1;
    } else {
        if (kc_count > 0) kc_count -= 1;
    }

    fsr_sense();

    dprintf("x: %d %u %u %d \n", kc_count, fsr_stack, fsr_reading, thres_actual);
    
    if (fsr_stack >= FSR_INPUT_C) {
                
        if (active_layer != 4 && active_layer != 3 && kc_count == 0) {    
            uint32_t keypress_idle = last_matrix_activity_elapsed();
            if (keypress_idle >= FSR_INPUT_C) {
                prev_layer = active_layer;
                layer_move(4);   
            }
        }

        if (active_layer == 4) {
            uint32_t mouse_idle = last_pointing_device_activity_elapsed();
            if (mouse_idle > FSR_INPUT_C * 5) {
                layer_move(prev_layer);
            }
        }

    } else if (fsr_stack < FSR_INPUT_C - 50) {
        if (active_layer == 4 ) layer_move(prev_layer);
    }

#endif

};

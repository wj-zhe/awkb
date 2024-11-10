// 34-monosplit keymap

#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE
#   include "../common/oled_custom.c"
#endif // #ifdef OLED_ENABLE

#ifdef POINTING_DEVICE_ENABLE
#   include "../common/cirque_trackpad.c"
#endif // #ifdef POINTING_DEVICE_ENABLE

#include "../common/keymap_34.c"

// Tapping-term per key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(TD_L1):
            return 255;
        case LCTL_T(KC_A):
            return 165;
        case LCTL_T(KC_SCLN):
            return 155;
        // case LALT_T(KC_BSPC):
        case LALT_T(KC_SPC):
        case LSFT_T(KC_Z): case LSFT_T(KC_SLSH):
            return 145;
        // case LT(2,KC_TAB):
            return 135;
        default:
            return TAPPING_TERM;
    }
};

// bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case LSFT_T(KC_Z): case LSFT_T(KC_SLSH):
//         case LT(2,KC_TAB): case LALT_T(KC_BSPC):
//             // Immediately select the hold action when another key is pressed.
//             return true;
//         default:
//             // Do not select the hold action when another key is pressed.
//             return false;
//     }
// }

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_Z): case LSFT_T(KC_SLSH):
        case LT(2,KC_TAB): case LALT_T(KC_BSPC):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

// Pointing device functions
#ifdef POINTING_DEVICE_ENABLE
#   ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_layer(4); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}
#   endif

#endif

// Layer based functions
layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    switch (get_highest_layer(remove_auto_mouse_layer(state, true))) {
#else
    switch (get_highest_layer(state)) {
#endif

        case 3:  // Enable scrolling mode, diable auto mouse layer
#ifdef POINTING_DEVICE_GESTURES_CUSTOM_SCROLL_ENABLE
            scrolling_mode = true;
#endif

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
            state = remove_auto_mouse_layer(state, false);
            set_auto_mouse_enable(false);
#endif

            break;

        default:

#ifdef POINTING_DEVICE_GESTURES_CUSTOM_SCROLL_ENABLE
            if (scrolling_mode) {  // Disable scrolling mode
                scrolling_mode = false;
            };
#endif

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
            set_auto_mouse_enable(true);
#endif

            break;
    }

    return state;
}

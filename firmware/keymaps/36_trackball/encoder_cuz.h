// Inspired by: https://www.reddit.com/r/olkb/comments/n6hd8v/comment/gx9rg64/?utm_source=share&utm_medium=web2x&context=3

enum custom_keycodes {
    ENC_TG = SAFE_RANGE,
};

#define NUM_ENC_MODES 2
enum encoder_modes {
    VOLUME,
    VOLUME_PRECISE,
    /* MEDIA_CONTROL, */
    /* SCROLL_UD, */
    /* SCROLL_LR, */
    /* ZOOM, */
};

static uint8_t encoder_mode = VOLUME;

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        switch(encoder_mode) {
            case VOLUME:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            break;

            case VOLUME_PRECISE:
                if (clockwise) {
                    tap_code16(LSG(KC_VOLU));
                } else {
                    tap_code16(LSG(KC_VOLD));
                }
            break;

            /* case MEDIA_CONTROL: */
            /*     if (clockwise) { */
            /*         tap_code(KC_MNXT); */
            /*     } else { */
            /*         tap_code(KC_MPRV); */
            /*     } */
            /* break; */

            /* case SCROLL_UD: */
            /*     if (clockwise) { */
            /*         tap_code(KC_WH_D); */
            /*     } else { */
            /*         tap_code(KC_WH_U); */
            /*     } */
            /* break; */

            /* case SCROLL_LR: */
            /*     if (clockwise) { */
            /*         tap_code(KC_WH_R); */
            /*     } else { */
            /*         tap_code(KC_WH_L); */
            /*     } */
            /* break; */

            /* case ZOOM: */
            /*     if (clockwise) { */
            /*         tap_code(LCTRL(KC_PPLUS));  // CTRL+NumpadPlus */
            /*     } else { */
            /*         tap_code(LCTRL(KC_PMNS));   // CTRL+NumpadMinus */
            /*     } */
            /* break; */

        }
    }
    return false;
}

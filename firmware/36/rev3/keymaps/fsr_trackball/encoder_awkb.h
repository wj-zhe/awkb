// Inspired by: https://www.reddit.com/r/olkb/comments/n6hd8v/comment/gx9rg64/?utm_source=share&utm_medium=web2x&context=3

#define NUM_ENC_MODES 2
enum encoder_modes {
    VOLUME,
    SCROLL_UD,
};


static uint8_t encoder_mode = VOLUME;

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // First encoder
        switch(encoder_mode) {
            case VOLUME:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            break;

            case SCROLL_UD:
                if (clockwise) {
                    tap_code(MS_WHLD);
                } else {
                    tap_code(MS_WHLU);
                }
            break;

        }
    }

    return false;
}

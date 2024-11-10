// Light LEDs 0 when keyboard layer X is active;
// for more color options, see: https://github.com/qmk/qmk_firmware/blob/master/quantum/color.h
const rgblight_segment_t PROGMEM layer_1[] = RGBLIGHT_LAYER_SEGMENTS( {0, 1, HSV_GOLD} );
const rgblight_segment_t PROGMEM layer_2[] = RGBLIGHT_LAYER_SEGMENTS( {0, 1, HSV_MAGENTA} );
const rgblight_segment_t PROGMEM layer_3[] = RGBLIGHT_LAYER_SEGMENTS( {0, 1, HSV_CYAN} );

#ifdef POINTING_DEVICE_ENABLE
#   ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
const rgblight_segment_t PROGMEM layer_4[] = RGBLIGHT_LAYER_SEGMENTS( {0, 1, HSV_AZURE} );
#   endif
#endif

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        layer_1,
        layer_2,
#ifdef POINTING_DEVICE_ENABLE
#   ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
        layer_3,
        layer_4
#else
        layer_3
#   endif
#endif
        );

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

void rgblight_set_layer_state_user(layer_state_t state) {
#ifdef POINTING_DEVICE_ENABLE
#   ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    for (uint8_t i=0; i<4; i++) {
#else
    for (uint8_t i=0; i<3; i++) {
#   endif
#endif
        rgblight_set_layer_state(i, layer_state_cmp(state, i+1));
    };
}


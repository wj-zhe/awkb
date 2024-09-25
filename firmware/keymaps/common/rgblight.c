// Light LEDs 0 when keyboard layer X is active;
// for more color options, see: https://github.com/qmk/qmk_firmware/blob/master/quantum/color.h
const rgblight_segment_t PROGMEM layer_1[] = RGBLIGHT_LAYER_SEGMENTS( {0, 1, HSV_GOLD} );
const rgblight_segment_t PROGMEM layer_2[] = RGBLIGHT_LAYER_SEGMENTS( {0, 1, HSV_MAGENTA} );
const rgblight_segment_t PROGMEM layer_3[] = RGBLIGHT_LAYER_SEGMENTS( {0, 1, HSV_CYAN} );

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        layer_1,
        layer_2,
        layer_3
        );

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

void rgblight_set_layer_state_user(layer_state_t state) {
    for (uint8_t i=0; i<3; i++) {
        rgblight_set_layer_state(i, layer_state_cmp(state, i+1));
    };
}


// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD,
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap-Dance declarations
enum {
    TD_L1,  // Layer 1 single-shot tap-dance
    TD_MD,  // Multi media triple-tap control
};

// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) {
            return TD_SINGLE_TAP;
        } else {
            return TD_SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        if (!state->pressed) {
            return TD_DOUBLE_TAP;
        } else {
            return TD_DOUBLE_HOLD;
        }
    } else if (state->count == 3) {
        if (!state->pressed) {
            return TD_TRIPLE_TAP;
        } else {
            return TD_TRIPLE_HOLD;
        }
    } else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void ql_l1_finished(tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            set_oneshot_layer(1, ONESHOT_START);
            break;
        case TD_SINGLE_HOLD: case TD_DOUBLE_TAP:
            layer_on(1);
            break;
        /* case TD_DOUBLE_TAP: */
        /*     // Check to see if the layer is already set */
        /*     if (layer_state_is(1)) { */
        /*         // If already set, then switch it off */
        /*         layer_off(1); */
        /*     } else { */
        /*         // If not already set, then switch the layer on */
        /*         layer_on(1); */
        /*     } */
        /*     break; */
        default:
            break;
    }
}

void ql_l1_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            clear_oneshot_layer_state(ONESHOT_PRESSED);
            break;
        case TD_DOUBLE_TAP:
            break;
        default:
            layer_off(1);
            break;
    }
    ql_tap_state.state = TD_NONE;

}

// Media play/pause, next/previous control all-in-one
void ql_md_ult_finished(tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_MPLY);
            break;
        case TD_DOUBLE_TAP:
            tap_code(KC_MNXT);
            break;
        case TD_TRIPLE_TAP:
            tap_code(KC_MPRV);
            break;
        default:
            break;
    }
}

void ql_md_ult_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    switch (ql_tap_state.state) {
        default:
            break;
    }
    ql_tap_state.state = TD_NONE;

}

// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    // Tap dance control for Layer 1
    [TD_L1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_l1_finished, ql_l1_reset),

    // Media play/pause, next/previous control all-in-one
    [TD_MD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_md_ult_finished, ql_md_ult_reset),

};



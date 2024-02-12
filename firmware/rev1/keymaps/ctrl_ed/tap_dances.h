// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

/* Tap-Dance declarations */
enum {
    /* QUOT_LAYR, // Our custom tap dance key; add any other tap dance keys to this enum */ 
    TD_L1,
    TD_MD_NX_PR,
};

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
/* void ql_finished(tap_dance_state_t *state, void *user_data); */
/* void ql_reset(tap_dance_state_t *state, void *user_data); */


// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
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
        case TD_SINGLE_HOLD:
            layer_on(1);
            break;
        case TD_DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(1)) {
                // If already set, then switch it off
                layer_off(1);
            } else if (layer_state_is(0)) {
                // If not already set, then switch the layer on
                layer_on(1);
            }
            break;
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

// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    // Layer 1 switching mech.
    [TD_L1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_l1_finished, ql_l1_reset),

    // Tap once for next media, twice for previous
    [TD_MD_NX_PR] = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPRV)
};


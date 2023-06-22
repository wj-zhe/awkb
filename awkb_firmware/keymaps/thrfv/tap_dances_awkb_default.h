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
            } else {
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
    [TD_L1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_l1_finished, ql_l1_reset)
};





/* --------------------------------------------------------------------------------------- */

/* typedef struct { */
/*     uint8_t layer_state; */
/* } user_data_t; */

/* /1* Create an instance of 'tap' *1/ */
/* static tap tap_dance_state = { */
/*     .is_press_action = true, */
/*     .state = X_TAPS */
/* }; */

/* /1* determine tap-dance state *1/ */
/* int cur_dance(qk_tap_dance_state_t *state) { */
/*     if (state->count == 1) { */
/*         if (state->interrupted || !state->pressed) return SINGLE_TAP; */
/*         else return SINGLE_HOLD; */
/*     } else if (state->count == 2) { */
/*         if (state->interrupted) return DOUBLE_SINGLE_TAP; */
/*         else if (state->pressed) return DOUBLE_HOLD; */
/*         else return DOUBLE_TAP; */
/*     } */
/*     return X_TAPS; */
/* }; */

/* /1* tap once to activate layer momentarily like oneshot key OSL(); */
/*  * tap twice to toggle layer; */
/*  * hold to activate layer momentarily like MO() */
/*  *1/ */
/* void td_layer_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*     tap_dance_state.state = cur_dance(state); */
/*     uint8_t layer_state = ((user_data_t*)user_data)->layer_state; */
/*     switch (tap_dance_state.state) { */
/*         case SINGLE_TAP: */
/*             set_oneshot_layer(layer_state, ONESHOT_START); */
/*             break; */
/*         case SINGLE_HOLD: */
/*             layer_on(layer_state); */
/*             break; */
/*         case DOUBLE_TAP: */
/*             layer_on(layer_state); */
/*             break; */
/*     } */
/* }; */

/* void td_layer_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*     // If the key was held down and now is released then switch off the layer */
/*     uint8_t layer_state = ((user_data_t*)user_data)->layer_state; */
/*     switch (tap_dance_state.state) { */
/*         case SINGLE_TAP: */
/*             clear_oneshot_layer_state(ONESHOT_PRESSED); */
/*             break; */
/*         case DOUBLE_TAP: */
/*             break; */
/*         default: */
/*             layer_off(layer_state); */
/*             break; */
/*     } */

/*     tap_dance_state.state = X_TAPS; */
/* }; */

/* #define ACTION_TAP_DANCE_FN_ADVANCED_USER(user_fn_on_each_tap, user_fn_on_dance_finished, \ */
/*     user_fn_on_dance_reset, user_user_data) { \ */
/*    .fn = { user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset }, \ */
/*    .user_data = (void*)user_user_data, \ */
/* } */

/* /1* Tap-Dance declarations *1/ */
/* enum { */
/*     TD_L1, */
/* }; */

/* /1* tap dance definitions *1/ */
/* qk_tap_dance_action_t tap_dance_actions[] = { */
/*     /1* [TD_L1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_l1_finished, td_l1_reset), *1/ */
/*     [TD_L1] = ACTION_TAP_DANCE_FN_ADVANCED_USER(NULL, td_layer_finished, td_layer_reset, */
/*         &((user_data_t){1})), */
/* }; */

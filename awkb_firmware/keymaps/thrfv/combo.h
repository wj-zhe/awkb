/*
Copyright 2020 Jz_Wong <@wj-zhe>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

enum combos {
    Q_W,
    W_E,
    I_O,
    O_P,
    W_D,
    E_F,
    R_G,
    U_H,
    I_J,
    O_K,
    S_D,
    D_F,
    J_K,
    J_K_L,
    DOWN_UP_RGHT,
    K_L,
    L_SCLN,
    Z_X,
    X_C,
    X_V,
    M_DOT,
    COMM_DOT,
    DOT_SLSH,
    EINI,
    UP_RGHT,
    TH_FVSX,
    TH_EINI
};

/* combo name by keycode */
/* row 0 */
const uint16_t PROGMEM qw_combo[] = {LGUI_T(KC_Q), KC_W, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
/* const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END}; */
/* const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END}; */
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, LGUI_T(KC_P), COMBO_END};

/* row 0 + 1 */
const uint16_t PROGMEM wd_combo[] = {KC_W, KC_D, COMBO_END};
const uint16_t PROGMEM ef_combo[] = {KC_E, KC_F, COMBO_END};
const uint16_t PROGMEM rg_combo[] = {KC_R, KC_G, COMBO_END};
const uint16_t PROGMEM uh_combo[] = {KC_U, KC_H, COMBO_END};
const uint16_t PROGMEM ij_combo[] = {KC_I, KC_J, COMBO_END};
const uint16_t PROGMEM ok_combo[] = {KC_O, KC_K, COMBO_END};
/* const uint16_t PROGMEM pl_combo[] = {LGUI_T(KC_P), KC_L, COMBO_END}; */

/* row 1 */
/* const uint16_t PROGMEM as_combo[] = {LCTL_T(KC_A), KC_S, COMBO_END}; */
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
/* const uint16_t PROGMEM sf_combo[] = {KC_S, KC_F, COMBO_END}; */
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM jkl_combo[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM down_up_right_combo[] = {KC_DOWN, KC_UP, KC_RIGHT, COMBO_END};
/* const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END}; */
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM lsln_combo[] = {KC_L, LCTL_T(KC_SCLN), COMBO_END};

/* row 1 + 2 */
/* const uint16_t PROGMEM lcm_combo[] = {KC_L, KC_COMM, COMBO_END};

/* row 2 */
const uint16_t PROGMEM zx_combo[] = {LSFT_T(KC_Z), KC_X, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM xv_combo[] = {KC_X, KC_V, COMBO_END};
/* const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END}; */
/* const uint16_t PROGMEM mcm_combo[] = {KC_M, KC_COMM, COMBO_END}; */
const uint16_t PROGMEM mdt_combo[] = {KC_M, KC_DOT, COMBO_END};
const uint16_t PROGMEM cmdt_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM dtsl_combo[] = {KC_DOT, RSFT_T(KC_SLSH), COMBO_END};

/* /1* row 2 + 3 *1/ */
/* const uint16_t PROGMEM mtd1_combo[] = {KC_M, TD(TD_LAYER_1), COMBO_END}; */

/* for layer 1 */
const uint16_t PROGMEM eini_combo[] = {KC_8, KC_9, COMBO_END};

/* for layer 1 */
const uint16_t PROGMEM up_right_combo[] = {KC_UP, KC_RIGHT, COMBO_END};

/* for layer 3 */
const uint16_t PROGMEM th_fvsx_combo[] = {KC_P5, KC_P6, COMBO_END};
const uint16_t PROGMEM th_eini_combo[] = {KC_P8, KC_P9, COMBO_END};

/* assign combo task/function */
combo_t key_combos[] = {
    /* Commands */
    [W_E] = COMBO(we_combo, KC_ESC),
    [S_D] = COMBO(sd_combo, KC_CAPS),
    [K_L] = COMBO(kl_combo, KC_ENT),
    /* Commands on layer 1 */
    [EINI] = COMBO(eini_combo, KC_ENT),
    /* Commands on layer 2 */
    [UP_RGHT] = COMBO(up_right_combo, KC_ENT),
    /* Commands on layer 3 */
    [TH_EINI] = COMBO(th_eini_combo, KC_ESC),
    [TH_FVSX] = COMBO(th_fvsx_combo, KC_ENT),
    /* Symbols */
    [Q_W] = COMBO(qw_combo, KC_EQL),
    [W_D] = COMBO(wd_combo, KC_PLUS),
    [O_P] = COMBO(op_combo, KC_MINS),
    [O_K] = COMBO(ok_combo, KC_UNDS),
    /* COMBO(df_combo, KC_LBRC), */
    /* COMBO(sf_combo, KC_LCBR), */
    /* COMBO(jl_combo, KC_RCBR), */
    /* COMBO(jk_combo, KC_RBRC), */
    [E_F] = COMBO(ef_combo, KC_LBRC),
    [R_G] = COMBO(rg_combo, KC_LCBR),
    [U_H] = COMBO(uh_combo, KC_RCBR),
    [I_J] = COMBO(ij_combo, KC_RBRC),
    /* COMBO(kl_combo, KC_QUOT), */
    [I_O] = COMBO(io_combo, KC_QUOT),
    [L_SCLN] = COMBO(lsln_combo, KC_DQUO),
    [Z_X] = COMBO(zx_combo, KC_TILD),
    [X_C] = COMBO(xc_combo, KC_GRV),
    [X_V] = COMBO(xv_combo, KC_TILD),
    /* COMBO(cv_combo, KC_TILD), */
    /* COMBO(mcm_combo, KC_PIPE), */
    [M_DOT] = COMBO(mdt_combo, KC_PIPE),
    [COMM_DOT] = COMBO(cmdt_combo, KC_BSLS),
    [DOT_SLSH] = COMBO(dtsl_combo, KC_PIPE),
    /* Level change */
    [J_K_L] = COMBO(jkl_combo, TG(2)),
    [DOWN_UP_RGHT] = COMBO(down_up_right_combo, TG(2))
};

uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);

/* configuration */
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    // If you want all combos to be tap-only, just uncomment the next line
    // return true

    // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in its chord, to be
    // tap-only, this is for you:
    uint16_t key;
    uint8_t idx = 0;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP...QK_MOD_TAP_MAX:
            case QK_LAYER_TAP...QK_LAYER_TAP_MAX:
            case QK_MOMENTARY...QK_MOMENTARY_MAX:
                return true;
        }
        idx += 1;
    }
    return false;

}

/* uint16_t get_combo_term(uint16_t index, combo_t *combo) { */
/*     // decide by combo->keycode */
/*     switch (combo->keycode) { */
/*         case KC_ESC: */
/*         case KC_ENT: */
/*         /1* case KC_BSPC: *1/ */
/*             return 50; */
/*     } */
/*     return COMBO_TERM; */
/* } */

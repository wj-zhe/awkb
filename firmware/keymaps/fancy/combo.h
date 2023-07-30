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
const uint16_t PROGMEM lcm_combo[] = {KC_L, KC_COMM, COMBO_END};

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
const uint16_t PROGMEM qk_boot_combo[] = {KC_END, KC_PPLS, COMBO_END};

/* assign combo task/function */
combo_t key_combos[] = {
  /* Commands */
  COMBO(we_combo, KC_ESC),
  COMBO(sd_combo, KC_CAPS),
  COMBO(kl_combo, KC_ENT),

  /* Commands on layer 1 */
  COMBO(eini_combo, KC_ENT),

  /* Commands on layer 2 */
  COMBO(up_right_combo, KC_ENT),

  /* Commands on layer 3 */
  COMBO(th_eini_combo, KC_ESC),
  COMBO(th_fvsx_combo, KC_ENT),
  COMBO(qk_boot_combo, QK_BOOT),

  /* Symbols */
  COMBO(qw_combo, KC_EQL),
  COMBO(wd_combo, KC_PLUS),
  COMBO(op_combo, KC_MINS),
  COMBO(ok_combo, KC_UNDS),

  /* COMBO(df_combo, KC_LBRC), */
  /* COMBO(sf_combo, KC_LCBR), */
  /* COMBO(jl_combo, KC_RCBR), */
  /* COMBO(jk_combo, KC_RBRC), */
  COMBO(ef_combo, KC_LBRC),
  COMBO(rg_combo, KC_LCBR),
  COMBO(uh_combo, KC_RCBR),
  COMBO(ij_combo, KC_RBRC),

  /* COMBO(kl_combo, KC_QUOT), */
  COMBO(io_combo, KC_QUOT),
  COMBO(lsln_combo, KC_DQUO),
  COMBO(zx_combo, KC_TILD),
  COMBO(xc_combo, KC_GRV),
  COMBO(xv_combo, KC_TILD),
  /* COMBO(cv_combo, KC_TILD), */
  /* COMBO(mcm_combo, KC_PIPE), */
  COMBO(mdt_combo, KC_PIPE),
  COMBO(cmdt_combo, KC_BSLS),
  COMBO(dtsl_combo, KC_PIPE),

  /* Level change */
  COMBO(jkl_combo, TG(2)),
  COMBO(down_up_right_combo, TG(2)),

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

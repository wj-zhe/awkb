// Layer 0 //
const uint16_t PROGMEM eql_combo[]       = { LGUI_T(KC_Q), KC_W, COMBO_END};
const uint16_t PROGMEM quot_combo[]      = { KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM mins_combo[]      = { KC_O, LGUI_T(KC_P), COMBO_END};
const uint16_t PROGMEM plus_combo[]      = { KC_W, KC_D, COMBO_END};
const uint16_t PROGMEM lbrc_combo[]      = { KC_E, KC_F, COMBO_END};
const uint16_t PROGMEM lcbr_combo[]      = { KC_R, KC_G, COMBO_END};
const uint16_t PROGMEM rcbr_combo[]      = { KC_U, KC_H, COMBO_END};
const uint16_t PROGMEM rbrc_combo[]      = { KC_I, KC_J, COMBO_END};
const uint16_t PROGMEM unds_combo[]      = { KC_O, KC_K, COMBO_END};
const uint16_t PROGMEM caps_combo[]      = { KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM dquo_combo[]      = { KC_L, LCTL_T(KC_SCLN), COMBO_END};
const uint16_t PROGMEM tild_combo[]      = { LSFT_T(KC_Z), KC_X, COMBO_END};
const uint16_t PROGMEM grv_combo[]       = { KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM bsls_combo[]      = { KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM pipe_combo[]      = { KC_DOT, LSFT_T(KC_SLSH), COMBO_END};
const uint16_t PROGMEM td_md_ult_combo[] = { LALT_T(KC_SPC), TD(TD_L1), COMBO_END};

// Layer 3 //
const uint16_t PROGMEM qk_boot_combo[] = { KC_END, KC_PPLS, COMBO_END};
const uint16_t PROGMEM qk_reboot_combo[] = { KC_PGDN, KC_PAST, COMBO_END}; // Resets the keyboard. Does not load the bootloader

// Layer 0 + 2 //
const uint16_t PROGMEM tg2_combo_l0[] = { KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM tg2_combo_l2[] = { KC_DOWN, KC_UP, KC_RIGHT, COMBO_END};

// Layer 0 + 3 //
const uint16_t PROGMEM tg3_combo_l0[] = { KC_M, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM tg3_combo_l3[] = { KC_P1, KC_P2, KC_P3, COMBO_END};

// Layer 0 + 1 + 2 + 3 //
const uint16_t PROGMEM ent_combo_l0[]   = { KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM ent_combo_l1[]   = { KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM ent_combo_l2[]   = { KC_UP, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM ent_combo_l3[]   = { KC_P5, KC_P6, COMBO_END};
const uint16_t PROGMEM esc_combo_l0[]   = { KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM esc_combo_l1[]   = { KC_AT, KC_HASH, COMBO_END};
const uint16_t PROGMEM esc_combo_l2[]   = { KC_F10, KC_F11, COMBO_END};
const uint16_t PROGMEM esc_combo_l3[]   = { KC_P8, KC_P9, COMBO_END};
const uint16_t PROGMEM esc_combo_l3_2[] = { KC_HOME, KC_UP, COMBO_END};

combo_t key_combos[] = {
    COMBO(eql_combo, KC_EQL),
    COMBO(quot_combo, KC_QUOT),
    COMBO(mins_combo, KC_MINS),
    COMBO(plus_combo, KC_PLUS),
    COMBO(lbrc_combo, KC_LBRC),
    COMBO(lcbr_combo, KC_LCBR),
    COMBO(rcbr_combo, KC_RCBR),
    COMBO(rbrc_combo, KC_RBRC),
    COMBO(unds_combo, KC_UNDS),
    COMBO(caps_combo, KC_CAPS),
    COMBO(dquo_combo, KC_DQUO),
    COMBO(tild_combo, KC_TILD),
    COMBO(grv_combo, KC_GRV),
    COMBO(bsls_combo, KC_BSLS),
    COMBO(pipe_combo, KC_PIPE),
    COMBO(td_md_ult_combo, TD(TD_MD_ULT)),

    COMBO(qk_boot_combo, QK_BOOT),
    COMBO(qk_reboot_combo, QK_RBT),

    COMBO(tg2_combo_l0, TG(2)),
    COMBO(tg2_combo_l2, TG(2)),

    COMBO(tg3_combo_l0, TG(3)),
    COMBO(tg3_combo_l3, TG(3)),

    COMBO(ent_combo_l0, KC_ENT),
    COMBO(ent_combo_l1, KC_ENT),
    COMBO(ent_combo_l2, KC_ENT),
    COMBO(ent_combo_l3, KC_ENT),
    COMBO(esc_combo_l0, KC_ESC),
    COMBO(esc_combo_l1, KC_ESC),
    COMBO(esc_combo_l2, KC_ESC),
    COMBO(esc_combo_l3, KC_ESC),
    COMBO(esc_combo_l3_2, KC_ESC),

};




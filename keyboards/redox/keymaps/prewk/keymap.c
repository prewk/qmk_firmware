#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _NUM 3

#define _SNGLQU KC_NUHS // '
#define _DOBLQU S(KC_2) // "
#define _BCKTIC S(KC_EQL) // `
#define _APOSTR KC_EQL // ´
#define _MULTIP S(KC_NUHS) // *
#define _2_DOTS KC_RBRC // ¨
#define _SV_AU_ KC_LBRC // Å
#define _SV_AE_ KC_QUOT // Ä
#define _SV_OE_ KC_SCLN // Ö
#define _ANGULL KC_GRV  // <
#define _ANGULR S(KC_GRV) // >
#define _SQUARL A(KC_8) // [
#define _SQUARR A(KC_9) // ]
#define _PARENL S(KC_8) // (
#define _PARENR S(KC_9) // )
#define _CURLYL S(A(KC_8)) // {
#define _CURLYR S(A(KC_9)) // }
#define _PLUS__ KC_MINS // +
#define _DASH__ KC_SLSH // -
#define _ATSIGN   A(KC_2) // @
#define _DOLLAR A(KC_4) // $
#define _FSLASH S(KC_7) // /
#define _PIPE__ A(KC_7) // |
#define _BSLASH S(A(KC_7)) // Backslash
#define _WORD_L A(KC_LEFT) // <<
#define _WORD_R A(KC_RIGHT) // >>
#define _TILDE_ A(KC_RBRC) // ~
#define _EQUALS S(KC_0) // =
#define _QUESTI S(KC_MINS) // ?
#define _COLON_ S(KC_DOT) // :
#define _PARAGR KC_NUBS // §

#define _OPTLFT RALT_T(KC_LEFT) // Opt / Left Arrow
#define _OPTDOT LALT_T(KC_DOT) // Opt / .
#define _CTRLRT RCTL_T(KC_RIGHT) // Ctrl / Right Arrow
#define SPC_NAV LT(_NAV, KC_SPC) // Space // NAV layer
#define ENT_SYM LT(_SYMB, KC_ENT) // Enter / SYM layer
#define TAB_NUM LT(_NUM, KC_TAB) // Tab / NUM layer
#define _QUAKE LCMD(KC_NUBS) // Quake terminal
#define _DELLIN LCMD(KC_BSPC) // Delete line

#define _CMD__Z G(KC_Z) // CMD + Z
#define _CMD__X G(KC_X) // CMD + X
#define _CMD__C G(KC_C) // CMD + C
#define _CMD__V G(KC_V) // CMD + V

enum my_keycodes {
    _3BACKT = SAFE_RANGE, // ```
    _1BACKT, // ` + space
    _CHKBOX, // - []
    _INTERP, // ${
    _FATARR, // =>
    _3EQUAL, // ===
    _ENGAGE // engagement
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _SNGLQU ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,_PLUS__ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TAB_NUM ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,_QUAKE  ,                          _QUAKE  ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,_SV_AU_ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_DEL  ,                          KC_BSPC ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,_SV_OE_ ,_SV_AE_ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,_______ ,KC_CAPS ,        _TILDE_ ,_FSLASH ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,_DASH__ ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTRL, _ANGULL, _ANGULR,_OPTDOT ,    KC_LCMD      ,SPC_NAV, ENT_SYM ,        ENT_SYM , SPC_NAV,   KC_RCMD  ,     _OPTLFT ,KC_DOWN ,KC_UP   ,_CTRLRT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _1BACKT ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _3BACKT ,_PARENL ,_CURLYL ,_SQUARL ,_ANGULL ,_______ ,_______ ,                          _______ ,_3EQUAL ,_ANGULR ,_SQUARR ,_CURLYR ,_PARENR ,KC_F12  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _CHKBOX ,_ATSIGN ,_DOLLAR ,_MULTIP ,_TILDE_ ,_COLON_ ,_______ ,                          _DELLIN ,_EQUALS ,_FSLASH ,_PIPE__ ,_BSLASH ,_QUESTI ,_FATARR ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _INTERP ,_CMD__Z ,_CMD__X ,_CMD__C ,_CMD__V ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _PARAGR ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_APOSTR ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_PARENL ,_CURLYL ,_SQUARL ,_ANGULL ,_______ ,_______ ,                          _______ ,_______ ,_WORD_L ,KC_PGDN ,KC_PGUP ,_WORD_R ,_2_DOTS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_ATSIGN ,_DOLLAR ,_MULTIP ,_TILDE_ ,_COLON_ ,_______ ,                          _DELLIN ,_______ ,KC_LEFT ,KC_DOWN   ,KC_UP,KC_RIGHT ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_CMD__Z ,_CMD__X ,_CMD__C ,_CMD__V ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,KC_MPRV ,KC_MNXT ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_ENGAGE ,_______ ,_______ ,KC_VOLU ,                          KC_MUTE ,_______ ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PMNS ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_VOLD ,                          KC_MPLY ,_______ ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______   ,    KC_P0 ,     _______ ,KC_PCMM ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};

const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 14, HSV_WHITE}
);

const rgblight_segment_t PROGMEM symb_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 14, HSV_ORANGE}
);

const rgblight_segment_t PROGMEM nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 14, HSV_GREEN}
);
const rgblight_segment_t PROGMEM num_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 14, HSV_PINK}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    qwerty_layer,
    symb_layer,
    nav_layer,
    num_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 4));

    switch (get_highest_layer(state)) {
        case _QWERTY:
            rgblight_disable();
            break;
        case _SYMB:
            rgblight_enable();
            break;
        case _NAV:
            rgblight_enable();
            break;
        case _NUM:
            rgblight_enable();
            break;
    }

    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _ENGAGE:
            if (record->event.pressed) {
                SEND_STRING("engagement");
            }
            return false;
        case _3BACKT:
            if (record->event.pressed) {
                tap_code16(_BCKTIC);
                tap_code(KC_SPC);
                tap_code16(_BCKTIC);
                tap_code(KC_SPC);
                tap_code16(_BCKTIC);
                tap_code(KC_SPC);
            }
            return false;
        case _1BACKT:
            if (record->event.pressed) {
                tap_code16(_BCKTIC);
                tap_code(KC_SPC);
            }
            return false;
        case _CHKBOX:
            if (record->event.pressed) {
                tap_code(_DASH__);
                tap_code(KC_SPC);
                tap_code16(_SQUARL);
                tap_code(KC_SPC);
                tap_code16(_SQUARR);
                tap_code(KC_SPC);
            }
            return false;
        case _INTERP:
            if (record->event.pressed) {
                tap_code16(_DOLLAR);
                tap_code16(_CURLYL);
            }
            return false;
        case _FATARR:
            if (record->event.pressed) {
                tap_code16(_EQUALS);
                tap_code16(_ANGULR);
                tap_code(KC_SPC);
            }
            return false;
        case _3EQUAL:
            if (record->event.pressed) {
                tap_code16(_EQUALS);
                tap_code16(_EQUALS);
                tap_code16(_EQUALS);
            }
            return false;
    }

    return true;
}

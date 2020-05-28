#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _NUM 3

#define __SQUO KC_NUHS // '
#define __DQUO S(KC_2) // "
#define __BTIC S(KC_EQL) // `
#define __STAR S(KC_NUHS) // *
#define __2DOT KC_RBRC // ¨
#define __AU   KC_LBRC // Å
#define __AE   KC_QUOT // Ä
#define __OE   KC_SCLN // Ö
#define __LABK KC_GRV  // <
#define __RABK S(KC_GRV) // >
#define __LSBK A(KC_8) // [
#define __RSBK A(KC_9) // ]
#define __LPAR S(KC_8) // (
#define __RPAR S(KC_9) // )
#define __LCBK S(A(KC_8)) // {
#define __RCBK S(A(KC_9)) // }
#define __PLUS KC_MINS // +
#define __MINS KC_SLSH // -
#define __AT   A(KC_2) // @
#define __DOLL A(KC_4) // $
#define __FSLA S(KC_7) // /
#define __PIPE A(KC_7) // |
#define __BSLA S(A(KC_7)) // Backslash
#define __ALEFT A(KC_LEFT) // <<
#define __BOT G(KC_DOWN) // vv
#define __TOP G(KC_UP) // ^^
#define __ARIGHT A(KC_RIGHT) // >>
#define __TILDE A(KC_RBRC) // ~

#define SYMB_L MO(_SYMB)
#define __OPTLFT RALT_T(KC_LEFT)
#define ENT_NAV LT(_NAV, KC_ENT)
#define SPC_NAV LT(_NAV, KC_SPC)
#define ENT_SYM LT(_SYMB, KC_ENT)
#define TAB_NUM LT(_NUM, KC_TAB)
#define QUAKE LCMD(KC_NUBS)

#define __CMD LM(_CMD, MOD_LGUI)

enum my_keycodes {
    KC_3BT = SAFE_RANGE,
    KC_BOX,
    _LMOD_,
    _RMOD_,
    _LTOP_,
    _RTOP_,
    _QUOTE,
    DEL_LINE
};

#define WITHOUT_MODS(...) \
  do { \
    const uint8_t _real_mods = get_mods(); \
    clear_mods(); \
    { __VA_ARGS__ } \
    set_mods(_real_mods); \
  } while (0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
      _QUOTE ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,__PLUS  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TAB_NUM ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,_LTOP_  ,                          _RTOP_  ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,__AU    ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,_LMOD_  ,                          _RMOD_  ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,__OE    ,__AE    ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,__AT    ,__STAR  ,        __FSLA   ,__PIPE ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,__MINS  ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTRL ,XXXXXXX ,XXXXXXX ,KC_LALT ,    KC_LCMD     ,SPC_NAV, ENT_SYM ,        ENT_SYM , SPC_NAV,   KC_RCMD  ,     __OPTLFT,KC_DOWN ,KC_UP   ,KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_3BT  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BOX  ,_______ ,_______ ,_______ ,_______ ,_______ ,QUAKE   ,                          DEL_LINE,_______ ,_______ ,_______ ,_______ ,_______ ,KC_F12  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,__DOLL  ,__TILDE ,        __BSLA  ,__BSLA  ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,KC_EQL ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_WH_D ,                          KC_PGUP ,XXXXXXX ,__ALEFT   ,__BOT   ,__TOP,__ARIGHT ,KC_RBRC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_U ,KC_MS_R ,XXXXXXX ,KC_WH_U ,                          KC_PGDN ,XXXXXXX ,KC_LEFT ,KC_DOWN   ,KC_UP,KC_RIGHT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_BTN1 ,KC_BTN2 ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          KC_MUTE ,XXXXXXX ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PMNS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          KC_MPLY ,XXXXXXX ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        XXXXXXX ,KC_P0   ,    KC_PCMM ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
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
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DEL_LINE:
            if (record->event.pressed) {
                tap_code16(G(KC_BSPC));
            }

            return false;
        case _QUOTE:
            if (!record->event.pressed) {
                return false;
            }

            if (get_mods() & MOD_BIT(KC_LSFT) || (get_mods() & MOD_BIT(KC_RSFT))) {
                tap_code(KC_NUHS);
            } else if (get_mods() & MOD_BIT(KC_LGUI)) {
                unregister_code(KC_LGUI);

                register_code(KC_RSFT);
                tap_code(KC_EQL);
                unregister_code(KC_RSFT);
                tap_code(KC_SPC);

                register_code(KC_LGUI);
            } else if (get_mods() & MOD_BIT(KC_RGUI)) {
                unregister_code(KC_RGUI);

                register_code(KC_RSFT);
                tap_code(KC_EQL);
                unregister_code(KC_RSFT);
                tap_code(KC_SPC);

                register_code(KC_RGUI);
            } else {
                WITHOUT_MODS({
                   tap_code(KC_NUHS);
                });
            }

            return false;
        case _LTOP_:
            if (!record->event.pressed) {
                return false;
            }

            if (get_mods() & MOD_BIT(KC_LGUI)) {
                unregister_code(KC_LGUI);
                tap_code(KC_GRV);
                register_code(KC_LGUI);
            } else if (get_mods() & MOD_BIT(KC_RGUI)) {
                unregister_code(KC_RGUI);
                tap_code(KC_GRV);
                register_code(KC_RGUI);
            } else {
                tap_code(KC_DEL);
            }

            return false;
        case _RTOP_:
            if (record->event.pressed && get_mods() & MOD_BIT(KC_LGUI)) {
                unregister_code(KC_LGUI);
                tap_code16(S(KC_GRV));
                register_code(KC_LGUI);
            } else if (record->event.pressed && get_mods() & MOD_BIT(KC_RGUI)) {
                unregister_code(KC_RGUI);
                tap_code16(S(KC_GRV));
                register_code(KC_RGUI);
            } else if (record->event.pressed) {
                register_code(KC_BSPC);
            } else {
                unregister_code(KC_BSPC);
            }

            return false;
        case _LMOD_:
            if (!record->event.pressed) {
                return false;
            }

            if (get_mods() & MOD_BIT(KC_LALT)) {
                tap_code(KC_8);
            } else if (get_mods() & MOD_BIT(KC_RALT)) {
                tap_code(KC_8);
            } else if (get_mods() & MOD_BIT(KC_LGUI)) {
                unregister_code(KC_LGUI);
                tap_code16(S(A(KC_8)));
                register_code(KC_LGUI);
            } else if (get_mods() & MOD_BIT(KC_RGUI)) {
                unregister_code(KC_RGUI);
                tap_code16(S(A(KC_8)));
                register_code(KC_RGUI);
            } else {
                WITHOUT_MODS({
                    tap_code16(S(KC_8));
                });
            }

            return false;
        case _RMOD_:
            if (!record->event.pressed) {
                return false;
            }

            if (get_mods() & MOD_BIT(KC_LALT)) {
                tap_code(KC_9);
            } else if (get_mods() & MOD_BIT(KC_RALT)) {
                tap_code(KC_9);
            } else if (get_mods() & MOD_BIT(KC_LGUI)) {
                unregister_code(KC_LGUI);
                tap_code16(S(A(KC_9)));
                register_code(KC_LGUI);
            } else if (get_mods() & MOD_BIT(KC_RGUI)) {
                unregister_code(KC_RGUI);
                tap_code16(S(A(KC_9)));
                register_code(KC_RGUI);
            } else {
                WITHOUT_MODS({
                     tap_code16(S(KC_9));
                });
            }

            return false;
        case KC_3BT:
            if (record->event.pressed) {
                // ```
                register_code(KC_RSFT);
                register_code(KC_EQL);
                register_code(KC_SPC);
                unregister_code(KC_RSFT);
                unregister_code(KC_EQL);
                unregister_code(KC_SPC);

                register_code(KC_RSFT);
                register_code(KC_EQL);
                register_code(KC_SPC);
                unregister_code(KC_RSFT);
                unregister_code(KC_EQL);
                unregister_code(KC_SPC);

                register_code(KC_RSFT);
                register_code(KC_EQL);
                register_code(KC_SPC);
                unregister_code(KC_RSFT);
                unregister_code(KC_EQL);
                unregister_code(KC_SPC);
            }
            return false;
        case KC_BOX:
            if (record->event.pressed) {
                register_code(KC_SLSH); // -
                unregister_code(KC_SLSH);
                register_code(KC_SPC); // space
                unregister_code(KC_SPC);
                register_code(KC_LALT);
                register_code(KC_8); // [
                unregister_code(KC_8);
                register_code(KC_LALT);
                register_code(KC_SPC); // space
                unregister_code(KC_SPC);
                register_code(KC_LALT);
                register_code(KC_9); // ]
                unregister_code(KC_9);
                unregister_code(KC_LALT);
            }
            return false;
    }

    return true;
}

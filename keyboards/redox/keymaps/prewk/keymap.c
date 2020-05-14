#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
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
#define __BOT C(KC_DOWN) // vv
#define __TOP C(KC_UP) // ^^
#define __ARIGHT A(KC_RIGHT) // >>

#define SYMB_L MO(_SYMB)
#define __OPTLFT RALT_T(KC_LEFT)
#define ENT_NAV LT(_NAV, KC_ENT)
#define SPC_NAV LT(_NAV, KC_SPC)
#define TAB_NUM LT(_NAV, KC_TAB)

enum my_keycodes {
    KC_3BT = SAFE_RANGE,
    KC_BOX
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NUHS ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,__PLUS  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TAB_NUM ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,XXXXXXX ,                          XXXXXXX ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,__AU    ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,SYMB_L  ,                          SYMB_L  ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,__OE    ,__AE    ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,XXXXXXX ,XXXXXXX ,        KC_PGDN ,KC_PGUP ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,__MINS  ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTRL ,XXXXXXX ,XXXXXXX ,KC_LALT ,     KC_LCMD    ,KC_BSPC ,SPC_NAV ,        ENT_NAV , KC_DEL ,    KC_RCMD ,     __OPTLFT,KC_DOWN ,KC_UP   ,KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_3BT  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BOX  ,_______ ,__AT    ,__BSLA  ,__PIPE  ,__FSLA  ,_______ ,                          _______ ,__DQUO  ,__SQUO  ,__BTIC  ,__STAR  ,_______ ,KC_F12  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,__LABK  ,__LSBK  ,__RSBK  ,__RABK  ,_______ ,                          _______ ,__LCBK  ,__LPAR  ,__RPAR  ,__RCBK  ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,__DOLL  ,_______ ,_______ ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_MUTE ,KC_VOLD ,KC_VOLU ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MPLY ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_WH_U ,                          KC_WH_U ,__ALEFT ,__BOT   ,__TOP   ,__ARIGHT,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_MS_L ,KC_MS_D ,KC_MS_U ,KC_MS_R ,_______ ,KC_WH_D ,                          KC_WH_D ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     KC_BTN1 ,    KC_BTN2 ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,RESET   ,RGB_M_P ,RGB_TOG ,RGB_MOD ,RGB_HUD ,RGB_HUI ,                          XXXXXXX ,XXXXXXX ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PMNS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        XXXXXXX ,KC_P0   ,    KC_PCMM ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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

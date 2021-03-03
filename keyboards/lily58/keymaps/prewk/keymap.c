#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern uint8_t is_master;

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
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   '  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  +   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  Å   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ö  |  Ä   |
 * |------+------+------+------+------+------|   (   |    |    )  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCtl | LOpt | LCMD | /Space  /       \Enter \  | Bksp | Left | Right|
 *                   |      |      |      |/ _NAV  /         \ _SYM \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
  _SNGLQU,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _PLUS__, \
  TAB_NUM,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _SV_AU_, \
  KC_ESC,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    _SV_OE_, _SV_AE_, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, _PARENL,  _PARENR,  KC_N,    KC_M,    KC_COMM, KC_DOT,  _DASH__,  KC_RSFT, \
                          KC_LCTRL,KC_LALT,KC_LGUI, SPC_NAV,    ENT_SYM, KC_BSPC, KC_LEFT, KC_RIGHT \
),
/* SYM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |  ``` |      |      |      |      |                    |      |      |      |      |      |  ´   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   @  |   $  |   *  |   ~  |  :   |-------.    ,-------|   =  |   /  |   |  |   \  |   ?  |  ¨   |
 * |------+------+------+------+------+------|   {   |    |    }  |------+------+------+------+------+------|
 * |      |   <  |   >  |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |  Del | Down |  Up  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SYMB] = LAYOUT( \
  _1BACKT, _3BACKT, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,\
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, _ATSIGN, _DOLLAR, _MULTIP, _TILDE_, _COLON_,                   _EQUALS, _FSLASH, _PIPE__, _BSLASH, _QUESTI, _2_DOTS, \
  _______, _ANGULL, _ANGULR, _______, _______, _______, _CURLYL, _CURLYR, _______, _______, _______, _______, _______, _______, \
                             _______, _______, _______, _______, _______, KC_DEL,  KC_DOWN, KC_UP\
),
/* NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Term |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |WrdLft|PgDown| PgUp |WrdRgt|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_NAV] = LAYOUT( \
  _QUAKE,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                     _______, _WORD_L, KC_PGUP, KC_PGDN, _WORD_R, _______, \
  _______, _______, _______, _______, _______, _______,                     _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, \
  _______, _______, _______, _______, _______, _______,  _SQUARL, _SQUARR,  _______, _______, _______, _______, _______, _______, \
                             _______, _______, _______,  _______, _______,  _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |   7  |  8   |  9   |   -  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |   4  |  5   |  6   |   +  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   1  |  2   |  3   | Enter|      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |   0  |   ,  |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_NUM] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, KC_7   , KC_8   , KC_9, KC_PMNS, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, KC_4   , KC_5   , KC_6, KC_PPLS, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_MPLY, _______, KC_1   , KC_2   , KC_3, KC_PENT, _______,\
                             _______, _______, _______, _______, _______,  KC_0  , KC_PCMM, _______ \
  )
};

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
/*
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}
*/

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    //matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  //if (record->event.pressed) {
    // set_timelog();
  //}

  switch (keycode) {
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
  }

  return true;
}

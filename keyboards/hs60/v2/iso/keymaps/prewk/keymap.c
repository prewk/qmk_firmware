/* Copyright 2018 Yiancar
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include <keymap_swedish.h>
#include <keyboards/wilba_tech/wt_rgb_backlight_api.h>
#include <keyboards/wilba_tech/wt_rgb_backlight.h>

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

#define _OPTDWN RALT_T(KC_DOWN) // Opt / Down Arrow
#define _CMDLFT RGUI_T(KC_LEFT) // Opt / Left Arrow
#define _OPTDOT LALT_T(KC_DOT) // Opt / .
#define _CTRLRT RCTL_T(KC_RIGHT) // Ctrl / Right Arrow
#define SPC_SYM LT(_SYMB, KC_SPC) // Space // SYMB layer
#define ESC_NAV LT(_NAV, KC_ESC) // ESC / NAV layer
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
[_QWERTY] = LAYOUT_60_iso( /* Base */
    _SNGLQU,  KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,  KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,\
    TAB_NUM,  KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,  KC_O,     KC_P,     KC_LBRC,  KC_RBRC,         \
    ESC_NAV,  KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,  KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS, KC_ENT, \
    KC_LSFT,  KC_GRV,  KC_Z,     KC_X,  KC_C,  KC_V,  KC_B,    KC_N,  KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,           KC_RSFT,\
    KC_LCTL,  KC_LALT,  KC_LGUI,                       SPC_SYM,                         _CMDLFT,  _OPTDWN,  KC_UP,   _CTRLRT),

[_SYMB] = LAYOUT_60_iso( /* FN */
    _1BACKT,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL ,\
    _3BACKT,  _PARENL, _CURLYL,   _SQUARL,  _ANGULL,  KC_TRNS,  KC_TRNS,  _ANGULR,  _SQUARR,  _CURLYR,  _PARENR,  KC_TRNS,  KC_TRNS  ,          \
    _CHKBOX,  _ATSIGN,  _DOLLAR,  _MULTIP,  _TILDE_,  _EQUALS,  _FSLASH,   _PIPE__, _BSLASH,  _QUESTI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,\
    _INTERP,  KC_NUBS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,             KC_TRNS,\
    KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[_NAV] = LAYOUT_60_iso( /* Empty for dynamic keymaps */
    _QUAKE,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,\
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  _WORD_L,  KC_PGDN,  KC_PGUP,  _WORD_R,  KC_TRNS,  KC_TRNS,          \
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_TRNS,  KC_TRNS,  KC_TRNS,\
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,\
    KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[_NUM] = LAYOUT_60_iso( /* Empty for dynamic keymaps */
    _QUAKE,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,\
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_P7,    KC_P8,    KC_P9,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,          \
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_P4,    KC_P5,    KC_P6,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,\
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_P1,    KC_P2,    KC_P3,    KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,\
    KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_P0,                                  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),
};

void matrix_init_user(void) {
  //user initialization
}

void matrix_scan_user(void) {
  //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
    }

    return true;
}

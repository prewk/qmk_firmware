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

#define KC_OPTL A(KC_LEFT)
#define KC_OPTR A(KC_RIGHT)

//This is the ISO version of the PCB

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_60_iso( /* Qwerty layer */
    TG(_NAV), SE_1,     SE_2,     SE_3,     SE_4,     SE_5,     SE_6,     SE_7,     SE_8,     SE_9,     SE_0,     SE_PLUS,    SE_EQL,  KC_BSPC,\
    KC_TAB,   SE_Q,     SE_W,     SE_E,     SE_R,     SE_T,     SE_Y,     SE_U,     SE_I,     SE_O,     SE_P,     SE_ARNG,    SE_DIAE,         \
    KC_GESC,  SE_A,     SE_S,     SE_D,     SE_F,     SE_G,     SE_H,     SE_J,     SE_K,     SE_L,     SE_ODIA,  SE_ADIA,    SE_QUOT, KC_ENT, \
    KC_LSPO,  SE_LABK,  SE_Z,     SE_X,     SE_C,     SE_V,     SE_B,     SE_N,     SE_M,     SE_COMM,  SE_DOT,   SE_MINS,    KC_RSPC,\
    KC_LCTL, KC_LOPT,  KC_LCMD,                      LT(_NAV, KC_SPC),                       MO(_SYMB),  KC_ROPT,  TG(_SYMB), KC_RCTL),

[_SYMB] = LAYOUT_60_iso( /* Symbol layer */
    KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL ,\
    KC_TRNS,  SE_GRV,  SE_DIAE,  SE_DQUO,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  A(S(KC_8)),  A(S(KC_9)),          \
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  A(KC_8),  A(KC_9),  KC_TRNS,\
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  SE_SECT,  S(SE_SECT),         KC_TRNS,\
    KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[_NAV] = LAYOUT_60_iso( /* Nav layer */
    KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,      KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,      KC_F11,   KC_F12,   KC_DEL ,\
    KC_TRNS,  KC_TRNS,  KC_MS_U,  KC_TRNS,  KC_WH_D,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,          \
    KC_BTN1,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_U,  A(KC_LEFT), KC_LEFT,  KC_UP,    KC_DOWN,  KC_RIGHT, A(KC_RIGHT), KC_TRNS,  KC_TRNS,  KC_TRNS,\
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,            KC_TRNS,\
    KC_TRNS,  KC_TRNS,  KC_TRNS,                                  KC_BTN2,                      KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS),
};

void matrix_init_user(void) {
    uint8_t data[2];
    data[0] = id_effect;
    data[1] = 3;
    backlight_config_set_value(data);
}

void matrix_scan_user(void) {
  //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t data[2];
    data[0] = id_effect;

    switch (get_highest_layer(state)) {
        case _SYMB:
            data[1] = 1;
            break;
        case _NAV:
            data[1] = 2;
            break;
        default:
            data[1] = 3;
            break;
    }
    backlight_config_set_value(data);

    return state;
}
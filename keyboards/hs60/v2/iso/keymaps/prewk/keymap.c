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

enum my_keycodes {
    KC_3BT = SAFE_RANGE,
    KC_BOX
};

enum td_keycodes {
    Q_DANCE
};

void qdance_finished (qk_tap_dance_state_t *state, void *user_data);
void qdance_reset (qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_60_iso( /* Base layer */
    TD(Q_DANCE),KC_1,   KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,  KC_9,     KC_0,               KC_MINS,         KC_EQL,  KC_BSPC,\
LT(_NUM, KC_TAB),KC_Q,  KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,  KC_O,     KC_P,               KC_LBRC,         KC_RBRC,         \
    KC_GESC,  KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,  KC_L,     KC_SCLN,            KC_QUOT,         KC_NUHS, KC_ENT, \
    KC_LSPO,  KC_GRV,   KC_Z,     KC_X,  KC_C,  KC_V,  KC_B,    KC_N,  KC_M,  KC_COMM,  KC_DOT,             KC_SLSH,                  KC_RSPC,\
    KC_LCTL,  KC_LALT,   KC_LCMD,                      LT(_NAV, KC_SPC),                LT(_SYMB, KC_LEFT), RALT_T(KC_DOWN), KC_UP, RCTL_T(KC_RIGHT)),

[_SYMB] = LAYOUT_60_iso( /* Symbol layer */
    KC_NUBS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL ,\
    KC_TRNS,  KC_TRNS,  KC_UP,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  A(S(KC_8)),  A(S(KC_9))    ,\
    KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  S1_DEC,   S1_INC,   S2_DEC,   S2_INC,   KC_TRNS,  A(KC_4),  A(KC_2),  A(KC_8),  A(KC_9),  KC_TRNS,\
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  S(KC_7),  A(KC_7),  S(A(KC_7)),         KC_TRNS,\
    KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[_NAV] = LAYOUT_60_iso( /* Nav layer */
   G(KC_NUBS),KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,      KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,      KC_F11,   KC_F12,   KC_DEL ,\
    KC_TRNS,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_WH_D,  KC_TRNS,    KC_TRNS,  KC_PGUP,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,          \
    KC_TRNS,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_U,  A(KC_LEFT), KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, A(KC_RIGHT), KC_TRNS,  KC_TRNS,  KC_TRNS,\
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_PGDOWN,KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,            KC_TRNS,\
    KC_TRNS,  KC_TRNS,  KC_TRNS,                                  KC_TRNS,                      KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS),

[_NUM] = LAYOUT_60_iso( /* Nav layer */
    KC_3BT,   KC_BOX,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_PEQL,  KC_PSLS,KC_PAST,  KC_TRNS,     KC_VOLD,  KC_VOLU,  KC_MUTE ,\
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_P7,    KC_P8,    KC_P9,  KC_PMNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,          \
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_P4,    KC_P5,    KC_P6,  KC_PPLS,  KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_MPLY,\
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_P1,    KC_P2,  KC_P3,  KC_TRNS,     KC_TRNS,            KC_TRNS,\
    KC_TRNS,  KC_TRNS,  KC_TRNS,                                  KC_P0,                      KC_PCMM,  KC_TRNS,     KC_TRNS,  KC_TRNS),
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

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t color_data[2];
    uint8_t color_data_hs[2];
    uint8_t effect_data[2];

    switch (get_highest_layer(state)) {
        case _SYMB:
            color_data_hs[0] = 0;
            color_data_hs[1] = 255;
            color_data[0] = id_color_1;
            color_data[1] = *color_data_hs;
            effect_data[0] = id_effect;
            effect_data[1] = 5;
            backlight_config_set_value(effect_data);
            backlight_config_set_value(color_data);
            break;
        case _NAV:
            color_data_hs[0] = 127;
            color_data_hs[1] = 255;
            color_data[0] = id_color_1;
            color_data[1] = *color_data_hs;
            effect_data[0] = id_effect;
            effect_data[1] = 1;
            backlight_config_set_value(effect_data);
            backlight_config_set_value(color_data);
            break;
        case _NUM:
            color_data_hs[0] = 255;
            color_data_hs[1] = 64;
            color_data[0] = id_color_1;
            color_data[1] = *color_data_hs;
            effect_data[0] = id_effect;
            effect_data[1] = 4;
            backlight_config_set_value(effect_data);
            backlight_config_set_value(color_data);
            break;         
        default:
            effect_data[0] = id_effect;
            effect_data[1] = 6;
            backlight_config_set_value(effect_data);
            break;
    }

    return state;
}

void qdance_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_NUHS);
    } else if (state->count == 2) {
        register_code(KC_RSFT);
        register_code(KC_2);
    } else if (state->count == 3) {
        register_code(KC_RSFT);
        register_code(KC_EQL);
        register_code(KC_SPC);
    }
}

void qdance_reset (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_NUHS);
    } else if (state->count == 2) {
        unregister_code(KC_RSFT);
        unregister_code(KC_2);
    } else if (state->count == 3) {
        unregister_code(KC_RSFT);
        unregister_code(KC_EQL);
        unregister_code(KC_SPC);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [Q_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, qdance_finished, qdance_reset)
};

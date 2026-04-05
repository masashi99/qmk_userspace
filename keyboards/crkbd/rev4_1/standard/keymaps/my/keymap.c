/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------+--------.  ,--------+-------------------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_BRIU,    KC_VOLU,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
   LALT_T(KC_ESC), KC_A,   KC_S,    KC_D,    KC_F,    KC_G, KC_BRID,    KC_VOLD,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT, LSG_T(KC_Z), LGUI_T(KC_X), LCTL_T(KC_C), LALT_T(KC_V), LCS_T(KC_B),          RCS_T(KC_N), RALT_T(KC_M), RCTL_T(KC_COMM), RGUI_T(KC_DOT), RSG_T(KC_SLSH), KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+-----------------|  |-----------------+--------+--------+--------+--------+--------+--------|
                                     LGUI_T(KC_LNG2), LSFT_T(KC_ESC), LCTL_T(KC_BSPC), LT(3, KC_ENT), LT(1, KC_SPC), LT(2, KC_LNG1)
  //                                 `------------------------------------'  `------------------------------------'

  ),

    [1] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------+--------.  ,--------+-------------------------------------------------------------.
      _______, S(KC_1), KC_LBRC, KC_LCBR, KC_LPRN, S(KC_COMM), _______,    _______, S(KC_DOT), KC_RPRN, KC_RCBR, KC_RBRC, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
      _______,  KC_GRV, S(KC_6),  S(KC_4), KC_EQL, S(KC_MINS), _______,    _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, KC_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, S(KC_GRV), S(KC_2), S(KC_3), S(KC_7), S(KC_BSLS),                   S(KC_SLSH), S(KC_EQL), KC_MINS, S(KC_8), S(KC_5), _______,
  //|--------+--------+--------+--------+--------+--------+-----------------|  |-----------------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  KC_DEL,     _______, _______, _______
  //                                      `------------------------------------'  `------------------------------------'
  ),

    [2] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------+--------.  ,--------+-------------------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______,    _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______,    _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                          KC_F11,  KC_F12, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+-----------------|  |-----------------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     _______, _______, _______
  //                                      `------------------------------------'  `------------------------------------'
  ),

    [3] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------+--------.  ,--------+-------------------------------------------------------------.
      QK_BOOT, KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE, _______,    _______, MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
      RM_TOGG, _______, MS_BTN3, MS_BTN2, MS_BTN1, _______, _______,    _______, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, QK_MACRO_0, _______,                    _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+-----------------|  |-----------------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     _______, _______, _______
  //                                      `------------------------------------'  `------------------------------------'
  )
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    // サムクラスタはHOLD_ON_OTHER_KEY_PRESSを有効化
    switch (keycode) {
        case LGUI_T(KC_LNG2):
        case LSFT_T(KC_ESC):
        case LCTL_T(KC_BSPC):
        case LT(3, KC_ENT):
        case LT(1, KC_SPC):
        case LT(2, KC_LNG1):
            return true;
        default:
            return false;
    }
}

// const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
//     LAYOUT_split_3x6_3_ex2(
//         'L', 'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 'R',
//         'L', 'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 'R',
//         'L', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', 'R',
//                        '*', '*', '*',  '*', '*', '*'
//     );

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = {
      ENCODER_CCW_CW(KC_BRID, KC_BRIU),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_BRID, KC_BRIU),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
  },
  [1] = {
 c>ENCODER_CCW_CW(_______, _______),
      ENCODER_CCW_CW(_______, _______),
      ENCODER_CCW_CW(_______, _______),
      ENCODER_CCW_CW(_______, _______),
  },
  [2] = {
      ENCODER_CCW_CW(_______, _______),
      ENCODER_CCW_CW(_______, _______),
      ENCODER_CCW_CW(_______, _______),
      ENCODER_CCW_CW(_______, _______),
  },
  [3] = {
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_WH_D, KC_WH_U),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_WH_D, KC_WH_U),
  },
};
#endif


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
   LCTL_T(KC_ESC), KC_A,   KC_S,    KC_D,    KC_F,    KC_G, KC_BRID,    KC_VOLD,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT, LSG_T(KC_Z), LGUI_T(KC_X), LCTL_T(KC_C), LALT_T(KC_V), KC_B,          KC_N, RALT_T(KC_M), RCTL_T(KC_COMM), RGUI_T(KC_DOT), RSG_T(KC_SLSH), KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+-----------------|  |-----------------+--------+--------+--------+--------+--------+--------|
                                     LGUI_T(KC_LNG2), LSFT_T(KC_TAB), LALT_T(KC_BSPC), LT(3, KC_ENT), LT(1, KC_SPC), LT(2, KC_LNG1)
  //                                 `------------------------------------'  `------------------------------------'

  ),

    [1] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------+--------.  ,--------+-------------------------------------------------------------.
      XXXXXXX, S(KC_1), KC_LBRC, KC_LCBR, KC_LPRN, S(KC_COMM), XXXXXXX,    XXXXXXX, S(KC_DOT), KC_RPRN, KC_RCBR, KC_RBRC, KC_BSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_GRV, S(KC_6),  S(KC_4), KC_EQL, S(KC_MINS), XXXXXXX,    XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, KC_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, S(KC_GRV), S(KC_2), S(KC_3), S(KC_7), S(KC_BSLS),                   S(KC_SLSH), S(KC_EQL), KC_MINS, S(KC_8), S(KC_5), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+-----------------|  |-----------------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,  KC_DEL,     XXXXXXX, XXXXXXX, XXXXXXX
  //                                      `------------------------------------'  `------------------------------------'
  ),

    [2] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------+--------.  ,--------+-------------------------------------------------------------.
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, XXXXXXX,    XXXXXXX,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, XXXXXXX,    XXXXXXX,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+-----------------|  |-----------------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
  //                                      `------------------------------------'  `------------------------------------'
  ),

    [3] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------+--------.  ,--------+-------------------------------------------------------------.
      QK_BOOT, KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX,    XXXXXXX, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, MS_BTN3, MS_BTN2, MS_BTN1, XXXXXXX, XXXXXXX,    XXXXXXX, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_MACRO_0, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+-----------------|  |-----------------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
  //                                      `------------------------------------'  `------------------------------------'
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = {
      ENCODER_CCW_CW(KC_BRID, KC_BRIU),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_BRID, KC_BRIU),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
  },
  [1] = {
      ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
      ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
      ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
      ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
  },
  [2] = {
      ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
      ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
      ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
      ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
  },
  [3] = {
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_WH_D, KC_WH_U),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_WH_D, KC_WH_U),
  },
};
#endif

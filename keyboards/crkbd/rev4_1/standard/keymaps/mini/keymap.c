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

#include "custom_keycodes.h"
#include "layer1_tab.h"
#include "private.h"
#include "shifted_modtap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------------------------------+--------.  ,--------+-------------------------------------------------------------------------------------------------.
        XXXXXXX, KC_Q,        KC_W,          KC_E,          KC_R,          KC_T,          KC_BRIU,                  KC_VOLU,      KC_Y,          KC_U,          KC_I,           KC_O,          KC_P,           XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+-------+--------+--------+--------+------|  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
        XXXXXXX, KC_A,        KC_S,          KC_D,          KC_F,          KC_G,          KC_BRID,                  KC_VOLD,      KC_H,          KC_J,          KC_K,           KC_L,          KC_MINS,        XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+-------+--------+--------+--------+------|  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
        XXXXXXX, LSFT_T(KC_Z), LGUI_T(KC_X),  LCTL_T(KC_C),  LALT_T(KC_V),  LCS_T(KC_B),                                          RCS_T(KC_N),  RALT_T(KC_M), RCTL_T(KC_COMM), RGUI_T(KC_DOT), RSFT_T(KC_TAB), XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+-------+--------+--------+--------+------|  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
                                              LGUI_T(KC_LNG2), LSFT_T(KC_ESC), LCTL_T(KC_BSPC),                          LT(3, KC_ENT),   LT(1, KC_SPC), LT(2, KC_LNG1)
        //                              `-----------------------------------------------------------------'  `-----------------------------------------------------------------'
    ),

    [1] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------------------------------+--------.  ,--------+-------------------------------------------------------------------------------------------------.
        XXXXXXX, S(KC_6),     S(KC_2),       S(KC_3),       S(KC_7),       KC_BSLS,       _______,                  _______,      KC_SLSH,       S(KC_EQL),     S(KC_8),        S(KC_5),       S(KC_4),        XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+-------+--------+--------+--------+------|  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
        XXXXXXX, KC_GRV,      KC_QUOT,       S(KC_QUOT),    KC_EQL,        S(KC_BSLS),    _______,                  _______,      KC_LEFT,       KC_DOWN,       KC_UP,          KC_RIGHT,      KC_SCLN,        XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+-------+--------+--------+--------+------|  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
        XXXXXXX, LSFT_T(KC_GRV), LGUI_T(KC_LBRC), LCTL_T(KC_LBRC), LALT_T(KC_9), LCS_T(KC_COMM),                                  RCS_T(KC_DOT), RALT_T(KC_0),RCTL_T(KC_RBRC),RGUI_T(KC_RBRC),RSFT_T(KC_SCLN), XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+-------+--------+--------+--------+------|  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
                                              CTRL_TAB,    CMD_TAB,   KC_DEL,                                       _______,       _______,       _______
        //                              `-----------------------------------------------------------------'  `-----------------------------------------------------------------'
    ),

    [2] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------------------------------+--------.  ,--------+-------------------------------------------------------------------------------------------------.
        XXXXXXX, XXXXXXX,      KC_F1,         KC_F2,         KC_F3,         KC_F4,         XXXXXXX,                  XXXXXXX,      KC_MINUS,      KC_1,          KC_2,           KC_3,          KC_PSLS,        XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+-------+--------+--------+--------+------|  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
        XXXXXXX, XXXXXXX,      KC_F5,         KC_F6,         KC_F7,         KC_F8,         XXXXXXX,                  XXXXXXX,      KC_PPLS,       KC_4,          KC_5,           KC_6,          KC_0,           XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+-------+--------+--------+--------+------|  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
        XXXXXXX, XXXXXXX,      KC_F9,         KC_F10,        KC_F11,        KC_F12,                                                KC_PAST,       KC_7,          KC_8,           KC_9,          S(KC_5),        XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+-------+--------+--------+--------+------|  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
                                              _______,       _______,      _______,                                       _______,       _______,       _______
        //                              `-----------------------------------------------------------------'  `-----------------------------------------------------------------'
    ),

    [3] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------------------------------+--------.  ,--------+-------------------------------------------------------------------------------------------------.
        QK_BOOT, KC_BRID,     KC_BRIU,       KC_VOLD,       KC_VOLU,       KC_MUTE,       XXXXXXX,                  XXXXXXX,      MS_WHLL,       MS_WHLD,       MS_WHLU,        MS_WHLR,       QK_BOOT,        XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+-------+--------+--------+--------+------|  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
        XXXXXXX, LSG(KC_4),   LCSG(KC_4),    MS_BTN2,       MS_BTN1,       MS_BTN3,       XXXXXXX,                  XXXXXXX,      MS_LEFT,       MS_DOWN,       MS_UP,          MS_RGHT,       XXXXXXX,        XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+-------+--------+--------+--------+------|  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
        XXXXXXX, MAIL1_MACRO,  MAIL2_MACRO,  KC_F13,        KC_F14,        KC_F15,                                                KC_F16,        KC_F17,        KC_F18,         KC_F19,        KC_F20,         XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+-------+--------+--------+--------+------|  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
                                              _______,       _______,      _______,                                       _______,       _______,       _______
        //                              `-----------------------------------------------------------------'  `-----------------------------------------------------------------'
    )
};

const key_override_t comm_key_override = ko_make_basic(MOD_MASK_SHIFT, RCTL_T(KC_COMM), S(KC_1));
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, RGUI_T(KC_DOT), S(KC_SLSH));

const key_override_t *key_overrides[] = {
    &comm_key_override,
    &dot_key_override
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_layer1_tab_keys(keycode, record)) {
        return false;
    }

    if (!process_shifted_modtap_keys(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case MAIL1_MACRO:
            if (record->event.pressed) {
                SEND_STRING(EMAIL_ADDRESS1);
            }
            return false;
        case MAIL2_MACRO:
            if (record->event.pressed) {
                SEND_STRING(EMAIL_ADDRESS2);
            }
            return false;
        default:
            break;
    }

    return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    // サムクラスタはHOLD_ON_OTHER_KEY_PRESSを有効化
    switch (keycode) {
        case LGUI_T(KC_LNG2):
        case LSFT_T(KC_ESC):
        case LALT_T(KC_BSPC):
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
      ENCODER_CCW_CW(_______, _______),
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

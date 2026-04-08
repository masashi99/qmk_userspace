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

enum custom_keycodes {
    CMD_TAB = SAFE_RANGE,
    CTRL_TAB,
};

static bool cmd_tab_lgui_held = false;
static bool ctrl_tab_lctl_held = false;

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
        XXXXXXX, KC_F13,      KC_F14,        KC_F15,        KC_F16,        KC_F17,                                                KC_F18,        KC_F19,        KC_F20,         KC_F21,        KC_F22,         XXXXXXX,
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

enum shifted_modtap_key {
    SMT_LSFT_GRV = 0,
    SMT_LCTL_LCBR,
    SMT_LALT_LPRN,
    SMT_LCS_LABK,
    SMT_RCS_RABK,
    SMT_RALT_RPRN,
    SMT_RCTL_RCBR,
    SMT_RSFT_COLN,
    SMT_COUNT,
};

static uint8_t shifted_modtap_saved_mods[SMT_COUNT];

static int8_t get_shifted_modtap_index(uint16_t keycode) {
    switch (keycode) {
        case LSFT_T(KC_GRV):
            return SMT_LSFT_GRV;
        case LCTL_T(KC_LBRC):
            return SMT_LCTL_LCBR;
        case LALT_T(KC_9):
            return SMT_LALT_LPRN;
        case LCS_T(KC_COMM):
            return SMT_LCS_LABK;
        case RCS_T(KC_DOT):
            return SMT_RCS_RABK;
        case RALT_T(KC_0):
            return SMT_RALT_RPRN;
        case RCTL_T(KC_RBRC):
            return SMT_RCTL_RCBR;
        case RSFT_T(KC_SCLN):
            return SMT_RSFT_COLN;
        default:
            return -1;
    }
}

static uint16_t get_shifted_modtap_tap_keycode(uint16_t keycode) {
    switch (keycode) {
        case LSFT_T(KC_GRV):
            return S(KC_GRV);
        case LCTL_T(KC_LBRC):
            return S(KC_LBRC);
        case LALT_T(KC_9):
            return S(KC_9);
        case LCS_T(KC_COMM):
            return S(KC_COMM);
        case RCS_T(KC_DOT):
            return S(KC_DOT);
        case RALT_T(KC_0):
            return S(KC_0);
        case RCTL_T(KC_RBRC):
            return S(KC_RBRC);
        case RSFT_T(KC_SCLN):
            return S(KC_SCLN);
        default:
            return KC_NO;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // layer 1 を維持している間だけ Ctrl を握り、Tab を複数回送れるようにする。
        case CTRL_TAB:
            if (record->event.pressed) {
                if (!ctrl_tab_lctl_held) {
                    register_code(KC_LCTL);
                    ctrl_tab_lctl_held = true;
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;
        // layer 1 を維持している間だけ GUI を握り、Cmd+Tab を継続できるようにする。
        case CMD_TAB:
            if (record->event.pressed) {
                if (!cmd_tab_lgui_held) {
                    register_code(KC_LGUI);
                    cmd_tab_lgui_held = true;
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;
        // レイヤーキーを離したら、CTRL_TAB / CMD_TAB が掴んだ modifier を解放する。
        case LT(1, KC_SPC):
            if (!record->event.pressed) {
                if (ctrl_tab_lctl_held) {
                    unregister_code(KC_LCTL);
                    ctrl_tab_lctl_held = false;
                }
                if (cmd_tab_lgui_held) {
                    unregister_code(KC_LGUI);
                    cmd_tab_lgui_held = false;
                }
            }
            break;
    }

    const int8_t shifted_modtap_index = get_shifted_modtap_index(keycode);

    if (shifted_modtap_index >= 0) {
        const uint16_t shifted_tap_keycode = get_shifted_modtap_tap_keycode(keycode);

        // ホールド候補の押下イベント。
        // retro tap 時に既存の modifier 状態を壊さず記号を送れるよう、
        // キー押下前の mod 状態を退避しておく。
        if (record->event.pressed && record->tap.count == 0) {
            shifted_modtap_saved_mods[shifted_modtap_index] = get_mods();
            return true;
        }

        // 通常タップ経路。
        // QMK は tap.count > 0 の場合でも press/release の両イベントを流すので、
        // press 側で shifted 記号を送り、release 側は握りつぶして
        // デフォルトの基本キーコードが漏れないようにする。
        if (record->tap.count > 0) {
            if (record->event.pressed) {
                tap_code16(shifted_tap_keycode);
            }
            return false;
        }

        // retro tap のリリース経路。
        // 「TAPPING_TERM を超えて保持し、他キーで割り込まれずに離した」ケースでは
        // tap.count が 0 のままなので、ここで shifted 側のタップキーコードを手動送信する。
        if (!record->event.pressed && !record->tap.interrupted) {
            set_mods(shifted_modtap_saved_mods[shifted_modtap_index]);
            send_keyboard_report();
            tap_code16(shifted_tap_keycode);
            return false;
        }
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

#include "shifted_modtap.h"

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

static uint8_t shifted_modtap_saved_mods[SMT_COUNT];

bool process_shifted_modtap_keys(uint16_t keycode, keyrecord_t *record) {
    const int8_t shifted_modtap_index = get_shifted_modtap_index(keycode);

    if (shifted_modtap_index < 0) {
        return true;
    }

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

    return true;
}

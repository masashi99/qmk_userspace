#include "custom_tab.h"
#include "custom_keycodes.h"

static bool cmd_tab_lgui_held = false;
static bool ctrl_tab_lctl_held = false;

static void release_layer1_tab_modifiers(void) {
    if (ctrl_tab_lctl_held) {
        unregister_code(KC_LCTL);
        ctrl_tab_lctl_held = false;
    }

    if (cmd_tab_lgui_held) {
        unregister_code(KC_LGUI);
        cmd_tab_lgui_held = false;
    }
}

bool custom_tab_keys(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // layer 3 を維持している間だけ Ctrl を握り、Tab を複数回送れるようにする。
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
        // layer 3 を維持している間だけ GUI を握り、Cmd+Tab を継続できるようにする。
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
        case LT(3, KC_ENT):
            if (!record->event.pressed) {
                release_layer1_tab_modifiers();
            }
            break;
        default:
            break;
    }

    return true;
}

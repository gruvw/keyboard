#include QMK_KEYBOARD_H

// === special keys ===

#define NU_LAY LT(1, KC_ENT)
#define SP_LAY LT(2, KC_TAB)
#define MO_LAY LT(3, MOD_LCTL) // LT(3, OSM(MOD_LCTL))
#define MA_LAY LT(4, MOD_LSFT) // LT(4, OSM(MOD_LSFT))

#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)

// === custom keys ===

enum custom_keycodes {
    MA_WEB = SAFE_RANGE, // https://
    MA_MAIL, // gruvw.dev@gmail.com
    MA_SIGN, // Lucas Jung (@gruvw)\nhttps://gruvw.com
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MO_LAY:
            if (record->event.pressed && record->tap.count > 0) {
                add_oneshot_mods(MOD_LCTL);
            }
            break;
        case MA_LAY:
            if (record->event.pressed && record->tap.count > 0) {
                add_oneshot_mods(MOD_LSFT);
            }
            break;
        case MA_WEB:
            if (record->event.pressed) {
                SEND_STRING("https://");
            }
            break;
        case MA_MAIL:
            if (record->event.pressed) {
                SEND_STRING("gruvw.dev@gmail.com");
            }
            break;
        case MA_SIGN:
            if (record->event.pressed) {
                SEND_STRING("Lucas Jung (@gruvw)\nhttps://gruvw.com");
            }
            break;
    }
    return true;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

// === unicode keys ===

#define UC_DEG UC(0x00B0) // °
#define UC_MID UC(0x00B7) // ·

// === keymap - 36 keys ===

// TODO set bootloader name `gruvw-keyboard`
// TODO Fast typing lay(osm) with key (within typing term), needs study of common chains
// - ctrl+tap
// - ctrl+shift+tab
// - gui+ctrl+h/j/k/l

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // layer 0: letters, spacing, modifiers
    [0] = LAYOUT_split_3x6_3(
        KC_NO,   OS_LALT, OS_LGUI, KC_DOT,  KC_P,    KC_Y,                          KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_NO,
        KC_NO,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                          KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_NO,
        KC_NO,   KC_ESC,  KC_Q,    KC_J,    KC_K,    KC_X,                          KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_NO,
                                            MO_LAY,  KC_SPC,  SP_LAY,      NU_LAY,  KC_BSPC, MA_LAY
    ),

    // layer 1: numbers, special character
    [1] = LAYOUT_split_3x6_3(
        KC_NO,   KC_GRV,  KC_TILD, KC_DLR,  KC_HASH, KC_AT,                         KC_PERC, KC_EXLM, KC_QUES, KC_AMPR, KC_CIRC, KC_NO,
        KC_NO,   KC_0,    KC_1,    KC_2,    KC_3,    KC_4,                          KC_SLSH, KC_COMM, KC_COLN, KC_PLUS, KC_DQUO, KC_NO,
        KC_NO,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,                          KC_BSLS, KC_ASTR, KC_UNDS, KC_MINS, KC_QUOT, KC_NO,
                                            KC_RALT, KC_EQL,  KC_SCLN,     _______, KC_NO,   KC_NO
    ),

    // layer 2: special characters, function keys, caps word
    [2] = LAYOUT_split_3x6_3(
        KC_NO,   KC_PSCR, XXXXXXX, KC_F10,  KC_F11,  KC_F12,                        UC_NEXT, UC_DEG,  UC_MID,  XXXXXXX, XXXXXXX, KC_NO,
        KC_NO,   XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,                         KC_PIPE, KC_LPRN, KC_LBRC, KC_LCBR, KC_LABK, KC_NO,
        KC_NO,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,                         XXXXXXX, KC_RPRN, KC_RBRC, KC_RCBR, KC_RABK, KC_NO,
                                            KC_NO,   KC_NO,   _______,     KC_NO,   KC_NO,   CW_TOGG
    ),

    // layer 3: mouse, cursor control, sound, brightness, media control
    [3] = LAYOUT_split_3x6_3(
        KC_NO,   KC_VOLU, KC_HOME, MS_UP,   KC_END,  KC_BRIU,                       KC_INS,  XXXXXXX, MS_WHLU, XXXXXXX, KC_PGUP, KC_NO,
        KC_NO,   KC_VOLD, MS_LEFT, MS_DOWN, MS_RGHT, KC_BRID,                       KC_DEL,  MS_WHLL, MS_WHLD, MS_WHLR, KC_PGDN, KC_NO,
        KC_NO,   KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
                                            _______, KC_NO,   KC_NO,       MS_BTN3, MS_BTN1, MS_BTN2
    ),

    // layer 4: macros, predefined macros, keyboard boot
    [4] = LAYOUT_split_3x6_3(
        KC_NO,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, DM_REC1, DM_REC2, XXXXXXX, XXXXXXX, KC_NO,
        KC_NO,   XXXXXXX, MA_SIGN, MA_MAIL, MA_WEB,  XXXXXXX,                       XXXXXXX, DM_PLY1, DM_PLY2, XXXXXXX, XXXXXXX, KC_NO,
        KC_NO,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, KC_NO,
                                            KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   _______
    ),
};

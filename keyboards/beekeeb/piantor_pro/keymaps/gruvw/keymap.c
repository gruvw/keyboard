#include QMK_KEYBOARD_H

// === special keys ===

#define TY_LAY DF(0) // typing layer
#define NU_LAY LT(1, KC_ENT) // numbers layer
#define SP_LAY LT(2, KC_TAB) // special layer
#define MO_LAY LT(3, MOD_LCTL) // mouse layer - LT(3, OSM(MOD_LCTL))
#define MA_LAY LT(4, MOD_LSFT) // macros layer - LT(4, OSM(MOD_LSFT))
#define GM_LAY DF(5) // gaming (movement) layer
#define GO_LAY LT(6, KC_F) // gaming (movement) layer

#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)

// === custom keys ===

enum custom_keycodes {
    MA_WEB = SAFE_RANGE, // https://
    MA_MAIG, // gruvw.dev@gmail.com
    MA_MAII, // luclecool@icloud.com
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
        case MA_MAIG:
            if (record->event.pressed) {
                SEND_STRING("gruvw.dev@gmail.com");
            }
            break;
        case MA_MAII:
            if (record->event.pressed) {
                SEND_STRING("luclecool@icloud.com");
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
        case KC_MINS:
        case KC_BSPC:
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

// TODO midi layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // layer 0 (sticky): letters, spacing, modifiers
    [0] = LAYOUT_split_3x6_3(
        KC_NO,   OS_LALT, OS_LGUI, KC_DOT,  KC_P,    KC_Y,                          KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_NO,
        KC_NO,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                          KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_NO,
        KC_NO,   KC_ESC,  KC_Q,    KC_J,    KC_K,    KC_X,                          KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_NO,
                                            MO_LAY,  KC_SPC,  SP_LAY,      NU_LAY,  KC_BSPC, MA_LAY
    ),

    // layer 1: numbers, special character
    [1] = LAYOUT_split_3x6_3(
        KC_NO,   KC_GRV,  KC_TILD, KC_DLR,  KC_HASH, KC_AT,                         KC_PERC, KC_EXLM, KC_QUES, KC_AMPR, KC_CIRC, KC_NO,
        KC_NO,   KC_0,    KC_1,    KC_2,    KC_3,    KC_4,                          KC_SLSH, KC_COMM, KC_COLN, KC_QUOT, KC_DQUO, KC_NO,
        KC_NO,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,                          KC_BSLS, KC_ASTR, KC_UNDS, KC_MINS, KC_PLUS, KC_NO,
                                            KC_RALT, KC_SCLN,  KC_EQL,     _______, KC_NO,   GM_LAY
    ),

    // layer 2: special characters, function keys, caps word, input control
    [2] = LAYOUT_split_3x6_3(
        KC_NO,   KC_PSCR, XXXXXXX, KC_F10,  KC_F11,  KC_F12,                        UC_NEXT, UC_DEG,  UC_MID,  XXXXXXX, XXXXXXX, KC_NO,
        KC_NO,   XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,                         KC_PIPE, KC_LPRN, KC_LBRC, KC_LCBR, KC_LABK, KC_NO,
        KC_NO,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,                         XXXXXXX, KC_RPRN, KC_RBRC, KC_RCBR, KC_RABK, KC_NO,
                                            KC_NO,   KC_NO,   _______,     KC_INS,  KC_DEL,  CW_TOGG
    ),

    // layer 3: mouse, modifiers, sound, brightness
    [3] = LAYOUT_split_3x6_3(
        KC_NO,   XXXXXXX, XXXXXXX, MS_UP,   XXXXXXX, KC_VOLU,                       KC_BRIU, XXXXXXX, MS_WHLU, XXXXXXX, XXXXXXX, KC_NO,
        KC_NO,   XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, KC_VOLD,                       KC_BRID, MS_WHLL, MS_WHLD, MS_WHLR, XXXXXXX, KC_NO,
        KC_NO,   KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_MUTE,                       XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_NO,
                                            _______, KC_NO,   KC_NO,       MS_BTN3, MS_BTN1, MS_BTN2
    ),

    // layer 4: custom macros, predefined macros, cursor control, media control, keyboard boot
    [4] = LAYOUT_split_3x6_3(
        KC_NO,   XXXXXXX, XXXXXXX, KC_UP,   DM_PLY1, DM_REC1,                       KC_PGUP, MA_WEB,  MA_MAII, MA_MAIG, MA_SIGN, KC_NO,
        KC_NO,   KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,                        KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,
        KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT, DM_PLY2, DM_REC2,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,
                                            KC_NO,   KC_NO,   KC_NO,       QK_BOOT, KC_NO,   _______
    ),

    // layer 5 (sticky): gaming (movement)
    [5] = LAYOUT_split_3x6_3(
        KC_NO,   KC_ESC,  KC_R,    KC_W,    KC_E,    KC_G,                          KC_U,    KC_K,    KC_N,    KC_P,    KC_J,    KC_NO,
        KC_NO,   KC_LSFT, KC_A,    KC_S,    KC_D,    KC_T,                          KC_L,    KC_I,    KC_M,    KC_H,    KC_O,    KC_NO,
        KC_NO,   KC_LCTL, KC_LALT, KC_B,    KC_X,    KC_C,                          KC_P3,   KC_P4,   KC_P5,   KC_P6,   KC_P7,   KC_NO,
                                            KC_TAB,  KC_SPC,  GO_LAY,      KC_P0,   KC_P1,   KC_P2
    ),

    // layer 6: gaming (others)
    [6] = LAYOUT_split_3x6_3(
        KC_NO,   KC_ENT,  KC_Q,    KC_Y,    KC_V,    KC_Z,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,
        KC_NO,   KC_0,    KC_1,    KC_2,    KC_3,    KC_4,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,
        KC_NO,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,
                                            TY_LAY,  KC_NO,   _______,     XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

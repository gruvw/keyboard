#include QMK_KEYBOARD_H

// === settings ===

#define ONESHOT_TIMEOUT 5000

// === custom keys ===

enum custom_keycodes {
    TT_LAY = SAFE_RANGE, // LT(3, OSM(MOD_LSFT))
};

static uint16_t os_lsft_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TT_LAY:
            if (record->event.pressed) {
                os_lsft_timer = timer_read();
                layer_on(3);
            } else {
                layer_off(3);
                if (timer_elapsed(os_lsft_timer) < TAPPING_TERM) {
                    set_oneshot_mods(MOD_LSFT);
                }
            }
            return false;
    }
    return true;
}

// === special keys ===

#define NU_LAY LT(1, KC_TAB)
#define SP_LAY LT(2, KC_SCLN)

// === keymap ===

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
        KC_NO, KC_RALT, KC_LGUI, KC_LALT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,   KC_NO,
        KC_NO,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S,   KC_NO,
        KC_NO,  KC_ESC,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,   KC_NO,
                                           TT_LAY,  KC_SPC, NU_LAY,      KC_ENT, KC_BSPC, KC_LCTL
    ),

    [1] = LAYOUT_split_3x6_3(
        KC_NO,  KC_GRV, KC_TILD,  KC_DLR, KC_HASH,   KC_AT,                      KC_PERC, KC_EXLM, KC_QUES, KC_AMPR, KC_CIRC,   KC_NO,
        KC_NO,    KC_0,    KC_1,    KC_2,    KC_3,    KC_4,                      KC_SLSH, KC_COMM, KC_COLN, KC_PLUS, KC_DQUO,   KC_NO,
        KC_NO,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,                      KC_BSLS, KC_UNDS, KC_ASTR, KC_MINS, KC_QUOT,   KC_NO,
                                            KC_NO,   KC_NO, _______,     SP_LAY,  KC_DOT,  KC_EQL
    ),

    [2] = LAYOUT_split_3x6_3(
        KC_NO, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_PIPE, KC_PIPE, KC_ASTR, KC_LPRN, KC_RPRN,   KC_NO,
        KC_NO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,   KC_NO,
        KC_NO, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,   KC_NO,
                                            KC_NO,   KC_NO, _______,    _______,   KC_NO,   KC_NO
    ),

    [3] = LAYOUT_split_3x6_3(
        KC_NO, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,
        KC_NO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,
        KC_NO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
    )
};

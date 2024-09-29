#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
        KC_NO,  KC_ESC,    KC_A,    KC_A,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,   KC_NO,
        KC_NO,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S,   KC_NO,
        KC_NO, QK_BOOT,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,   KC_NO,
                                           KC_TAB,  KC_SPC,  KC_ENT,    KC_LSFT, KC_BSPC, KC_LCTL
  ),

    [1] = LAYOUT_split_3x6_3(
        KC_NO,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_NO,
        KC_NO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX,   KC_NO,
        KC_NO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RALT
  ),

    [2] = LAYOUT_split_3x6_3(
        KC_NO, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,   KC_NO,
        KC_NO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,   KC_NO,
        KC_NO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,   KC_NO,
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
  ),

    [3] = LAYOUT_split_3x6_3(
        KC_NO, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,
        KC_NO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,
        KC_NO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_NO,
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
  )
};

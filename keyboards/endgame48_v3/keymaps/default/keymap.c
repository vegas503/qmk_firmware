// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "taphold.h"
#include "smoothled.h"

#define _MAIN 0
#define ALPHA 1
#define BETA 2

#define ________ KC_TRNS

enum custom_keycodes {
    KC_MAIN = SAFE_RANGE,
    KC_ALPHA,
    KC_BETA,
};

uint16_t  taphold_config_size = 3;
taphold_t taphold_config[]    = {
    {.key = KC_ALPHA, .mode = TAPHOLD_LAYER, .shortAction = KC_ESC, .longAction = ALPHA},
    {.key = KC_BETA, .mode = TAPHOLD_LAYER, .shortAction = KC_EQL, .longAction = BETA},
    /* {.key=KC_SIGMA, .mode=TAPHOLD_LAYER, .shortAction=KC_MUTE, .longAction=SIGMA}, */
    {.key = KC_LCTL, .mode = TAPHOLD_MOD, .shortAction = KC_MINS, .longAction = KC_LCTL},
    /*{.key=KC_V, .mode=TAPHOLD_MOD, .shortAction=KC_V, .longAction=KC_LALT},*/
    /*{.key=KC_B, .mode=TAPHOLD_MOD, .shortAction=KC_B, .longAction=KC_LGUI}*/
};
uint32_t taphold_timeout = 100;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Main layer
       ┏━━━━━┳━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┓┏┳━┳┓┏━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┳━━━━━┓
       ┃ TAB ┃  Q  │  W  │  E  │  R  │  T  ┃┃┃ ┃┃┃  Y  │  U  │  I  │  O  │  P  ┃ BSP ┃
       ┣━━━━━╉─────┼─────┼─────┼─────┼─────┨┃┃ ┃┃┣─────┼─────┼─────┼─────┼─────╊━━━━━┫
       ┃𝛼/ESC┃  A  │  S  │  D  │  F  │  G  ┃┃┃ ┃┃┃  H  │  J  │  K  │  L  │  ;  ┃ RET ┃
       ┣━━━━━╉─────┼─────┼─────┼─────┼─────┨┗┻━┻┛┣─────┼─────┼─────┼─────┼─────╊━━━━━┫
       ┃SHIFT┃  Z  │  X  │  C  │  V  │  B  ┃     ┃  N  │  M  │  ,  │  .  │  /  ┃LCTRL┃
       ┣━━━━━╉─────┼─────┼─────┼─────┼─────┨     ┣─────┼─────┼─────┼─────┼─────╊━━━━━┫
       ┃CTRL ┃     │     │ ALT │ GUI │SPACE┃ (o) ┃SPACE│ 𝛽/= │  '  │     │     ┃     ┃
       ┗━━━━━┻━━━━━┷━━━━━┷━━━━━┷━━━━━┷━━━━━┛     ┗━━━━━┷━━━━━┷━━━━━┷━━━━━┷━━━━━┻━━━━━┛
       */
    [_MAIN] = LAYOUT_ortho_4x12( \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
        KC_ALPHA,KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LCTL, \
        KC_LCTL, ________,________,KC_LALT, KC_LGUI, KC_SPC,  KC_SPC,  KC_BETA, KC_QUOT, ________,________,________\
    ),

    /* 𝛼 layer
       ┏━━━━━┳━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┓┏┳━┳┓┏━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┳━━━━━┓
       ┃     ┃PREV │PLAY │NEXT │     │     ┃┃┃ ┃┃┃  -  │ ^^^ │  ^  │ vvv │  ~  ┃ DEL ┃
       ┣━━━━━╉─────┼─────┼─────┼─────┼─────┨┃┃ ┃┃┣─────┼─────┼─────┼─────┼─────╊━━━━━┫
       ┃     ┃     │VOL -│VOL +│     │     ┃┃┃ ┃┃┃HOME │ <-- │  v  │ --> │  `  ┃  \  ┃
       ┣━━━━━╉─────┼─────┼─────┼─────┼─────┨┗┻━┻┛┣─────┼─────┼─────┼─────┼─────╊━━━━━┫
       ┃     ┃     │     │     │     │     ┃     ┃ END │  =  │  [  │  ]  │  (  ┃  )  ┃
       ┣━━━━━╉─────┼─────┼─────┼─────┼─────┨     ┣─────┼─────┼─────┼─────┼─────╊━━━━━┫
       ┃     ┃     │     │     │     │     ┃ (o) ┃     │     │     │     │     ┃     ┃
       ┗━━━━━┻━━━━━┷━━━━━┷━━━━━┷━━━━━┷━━━━━┛     ┗━━━━━┷━━━━━┷━━━━━┷━━━━━┷━━━━━┻━━━━━┛
       */
    [ALPHA] = LAYOUT_ortho_4x12( \
        ________,KC_MPRV, KC_MPLY, KC_MNXT, ________,________,KC_MINS, KC_PGUP, KC_UP,   KC_PGDN, KC_TILD, KC_DEL,  \
        ________,________,KC_VOLD, KC_VOLU, ________,________,KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT,KC_GRV,  KC_BSLS, \
        ________,________,________,________,________,________,KC_END,  KC_EQL,  KC_LBRC, KC_RBRC, LSFT(KC_9),LSFT(KC_0),\
        ________,________,________,________,________,________,________,________,________,________,________,________\
    ),

    /* 𝛽 layer
       ┏━━━━━┳━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┓┏┳━┳┓┏━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┳━━━━━┓
       ┃ RGB ┃  1  │  2  │  3  │  4  │  5  ┃┃┃ ┃┃┃  6  │  7  │  8  │  9  │  0  ┃ F12 ┃
       ┣━━━━━╉─────┼─────┼─────┼─────┼─────┨┃┃ ┃┃┣─────┼─────┼─────┼─────┼─────╊━━━━━┫
       ┃     ┃ F1  │ F2  │ F3  │ F4  │ F5  ┃┃┃ ┃┃┃ F6  │ F7  │ F8  │ F9  │ F10 ┃ F11 ┃
       ┣━━━━━╉─────┼─────┼─────┼─────┼─────┨┗┻━┻┛┣─────┼─────┼─────┼─────┼─────╊━━━━━┫
       ┃     ┃RESET│     │SLEEP│WAKE │EGMNU┃     ┃     │     │  {  │  }  │     ┃     ┃
       ┣━━━━━╉─────┼─────┼─────┼─────┼─────┨     ┣─────┼─────┼─────┼─────┼─────╊━━━━━┫
       ┃     ┃     │     │     │     │     ┃ (o) ┃PTSCR│     │     │     │     ┃     ┃
       ┗━━━━━┻━━━━━┷━━━━━┷━━━━━┷━━━━━┷━━━━━┛     ┗━━━━━┷━━━━━┷━━━━━┷━━━━━┷━━━━━┻━━━━━┛
       */
    [BETA] = LAYOUT_ortho_4x12( \
        RGB_TOG, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,  \
        ________,KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
        ________,QK_RBT,  ________,KC_PWR,  KC_WAKE, ________,________,________,KC_LCBR, KC_RCBR, ________,________,\
        ________,________,________,________,________,KC_MUTE, KC_PSCR, ________,________,________,________,________\
    ),
};
// clang-format on

uint32_t layer_colors[4] = {0x4020FF, 0xFF0010, 0x20FF00, 0x40FFFF};

void keyboard_post_init_user(void) {
    smoothled_set(layer_colors[0], 1500);
}

void matrix_scan_user(void) {
    smoothled_process();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return taphold_process(keycode, record);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = biton32(state);
    smoothled_set(layer_colors[layer], 150);
    return state;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t current_layer = get_highest_layer(layer_state);

    if (index == 0) {
        if (current_layer == ALPHA) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        } else if (current_layer == BETA) {
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        } else {
            if (clockwise) {
                tap_code(KC_MS_WH_DOWN);
            } else {
                tap_code(KC_MS_WH_UP);
            }
        }
    }
    return false;
}

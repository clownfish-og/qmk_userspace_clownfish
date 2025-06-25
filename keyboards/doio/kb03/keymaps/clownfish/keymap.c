// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE
#include "rgb_keys.h"

bool rgb_matrix_indicators_user() {
    hsv_t hsv = {0, 255, 200};

    uint8_t active_layer = get_highest_layer(layer_state);

    switch (active_layer) {
        case 0:
            hsv = (hsv_t){HSV_WHITE}; // Layer 0: WHITE
            break;
        case 1:
            hsv = (hsv_t){HSV_GREEN}; // Layer 1: GREEN
            break;
        case 2:
            hsv = (hsv_t){HSV_BLUE}; // Layer 2: BLUE
            break;
        case 3:
            hsv = (hsv_t){HSV_GOLD}; // Layer 3: YELLOW
            break;
        default:
            hsv = (hsv_t){HSV_RED}; // err: RED
            break;
    }
    hsv.v     = (rgb_matrix_get_val() * 70 / 200) + 30; //set indicator brightness range 30-100, vary based on RGB Matrix brightness
    rgb_t rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(9, rgb.r, rgb.g, rgb.b);
    return false;
}

#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        TO(1),   UG_HUEU,  SIMPLGT,  UG_SATU,   KC_RSFT
    ),
    [1] = LAYOUT(
        TO(2),   KC_ENT,   C(KC_C), C(S(KC_V)), C(KC_Z)
    ),
    [2] = LAYOUT(
        TO(3),   CHROME,   UG_TOGG,  G(KC_D),   EXTEND
    ),
    [3] = LAYOUT(
        TO(0),   KC_WBAK,  KC_WHOM,  KC_WFWD,   KC_MPLY
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(UG_VALD, UG_VALU),  ENCODER_CCW_CW(UG_PREV, UG_NEXT) },
    [1] = { ENCODER_CCW_CW(KC_WH_L, KC_WH_R),  ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
    [2] = { ENCODER_CCW_CW(KC_BRID, KC_BRIU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [3] = { ENCODER_CCW_CW(KC_MRWD, KC_MFFD),  ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif

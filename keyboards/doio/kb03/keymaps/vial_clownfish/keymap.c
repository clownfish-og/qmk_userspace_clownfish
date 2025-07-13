// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "rgb_keys.h"

enum my_layers {
    SYSTEM,
    COPY,
    TWITCH,
    LIGHTS
};

enum custom_keycodes {
    LFISH = MY_SAFE_RANGE,
    BUP,
    LOVE,
    DRAGON,
    CFOG,
    KEK,
    SWAG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [SYSTEM] = LAYOUT(
            TO(COPY),
        CHROME,   RM_TOGG, G(KC_D),
                      EXTEND
    ),
    [COPY] = LAYOUT(
            TO(TWITCH),
        KC_ENT,   C(KC_C), C(S(KC_V)),
                      C(KC_Z)
    ),
    [TWITCH] = LAYOUT(
            TO(LIGHTS),
        KC_ENT,   SPAM,    LFISH,
                      BUP
    ),
    [LIGHTS] = LAYOUT(
            TO(SYSTEM),
        RM_HUEU,  SIMPLGT, RM_SATU,
                      KC_LSFT
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [SYSTEM] = { ENCODER_CCW_CW(KC_BRID, KC_BRIU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [COPY]   = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [TWITCH] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(G(KC_LEFT), G(KC_RGHT)) },
    [LIGHTS] = { ENCODER_CCW_CW(RM_VALD, RM_VALU),  ENCODER_CCW_CW(RM_PREV, RM_NEXT) }
};
#endif

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LFISH:
                if (record->event.pressed) {
                    if (host_keyboard_led_state().caps_lock) {
                        tap_code(KC_CAPS);
                    }
                    SEND_STRING("tacosa13Lubs wertyo2Clownfish tacosa13Lubs ");
                }
            return false;
        case BUP:
            if (record->event.pressed) {
                if (host_keyboard_led_state().caps_lock) {
                    tap_code(KC_CAPS);
                }
                SEND_STRING("bupBup ");
            }
            return false;
        case LOVE:
            if (record->event.pressed) {
                if (host_keyboard_led_state().caps_lock) {
                    tap_code(KC_CAPS);
                }
                SEND_STRING("bupLOVE ");
            }
            return false;
        case DRAGON:
            if (record->event.pressed) {
                if (host_keyboard_led_state().caps_lock) {
                    tap_code(KC_CAPS);
                }
                SEND_STRING("bupDragon ");
            }
            return false;
        case CFOG:
            if (record->event.pressed) {
                if (host_keyboard_led_state().caps_lock) {
                    tap_code(KC_CAPS);
                }
                SEND_STRING("koby36Clownfishog ");
            }
            return false;
        case KEK:
            if (record->event.pressed) {
                if (host_keyboard_led_state().caps_lock) {
                    tap_code(KC_CAPS);
                }
                SEND_STRING("bupKekw ");
            }
            return false;
        case SWAG:
            if (record->event.pressed) {
                if (host_keyboard_led_state().caps_lock) {
                    tap_code(KC_CAPS);
                }
                SEND_STRING("gopros2Cfswag ");
            }
            return false;
        }
    return true; // Process all other keycodes normally
}

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_user(void) {
    hsv_t hsv = {0, 255, 200};

    uint8_t active_layer = get_highest_layer(layer_state);

    switch (active_layer) {
        case SYSTEM:
            hsv = (hsv_t){HSV_BLUE};
            break;
        case COPY:
            hsv = (hsv_t){HSV_GREEN};
            break;
        case TWITCH:
            hsv = (hsv_t){HSV_PURPLE};
            break;
        case LIGHTS:
            hsv = (hsv_t){HSV_GOLD};
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

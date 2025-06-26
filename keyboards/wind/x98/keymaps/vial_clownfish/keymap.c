/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H
#include "rgb_keys.h"
#include <lib/lib8tion/lib8tion.h>

enum custom_keycodes {
    LFISH = MY_SAFE_RANGE,
    BUP,
    LOVE,
    DRAGON,
    CFOG,
    KEK,
    SWAG,
    CAPSLKD,
    CAPSLKU,
    NUMLKOD,
    NUMLKOU,
    COMBLKD,
    COMBLKU
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
    KC_ESC,           KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,           KC_F12,  MO(1),   KC_HOME, KC_END,  KC_MUTE,  KC_EQL,
	KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC, KC_DEL,  KC_NUM,  KC_PSLS, KC_PAST,  KC_PMNS,
	KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS, KC_PGUP, KC_P7,   KC_P8,   KC_P9,    KC_PPLS,
	KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,  KC_PGDN, KC_P4,   KC_P5,   KC_P6,
	KC_LSFT, KC_BSLS, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,            KC_P1,   KC_P2,   KC_P3,     KC_PENT,
	KC_LCTL, KC_LGUI, KC_LALT,                           KC_SPC,                             KC_RALT, KC_RALT, KC_LEFT,          KC_DOWN, KC_RGHT, KC_P0,            KC_PDOT
    ),

	[1] = LAYOUT(
	EXTEND,           KC_BRID, KC_BRIU, CAPSLKD, CAPSLKU, COMBLKD, COMBLKU, NUMLKOD, NUMLKOU, _______, _______, _______,          SPAM,  _______, _______, _______, _______, CHROME,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, UG_SATU, UG_VALU, UG_SPDU, UG_NEXT,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, UG_HUED, _______, UG_HUEU,
	_______, _______, _______, _______, CLANGD,  VENV,    _______, _______, KC_MAKE, _______, _______, _______, _______,          _______,          UG_SATD, UG_VALD, UG_SPDD, UG_PREV,
	MO(2),   _______, _______,                            _______,                            _______, _______, _______,          _______, _______, UG_TOGG,          RM_M_PL
    ),

	[2] = LAYOUT(
	EE_CLR,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, QK_BOOT,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, _______, _______, _______,
	_______, _______, _______,                            _______,                            _______, _______, _______,          _______, _______, _______,          _______
    ),

	[3] = LAYOUT(
	_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, _______, _______, _______,
	_______, _______, _______,                            _______,                            _______, _______, _______,          _______, _______, _______,          _______
    ),
};
// clang-format on
// Single Indicator memory layout
typedef struct indicator_t {
        uint8_t cap_h;
        uint8_t num_h;
        uint8_t com_h;
        uint8_t cap_s;
        uint8_t num_s;
        uint8_t com_s;
    } indicator;

indicator indi;

// Check if the size of the reserved persistent memory is the same as the size of struct indicator
_Static_assert(sizeof(indicator) == EECONFIG_USER_DATA_SIZE, "Mismatch in keyboard EECONFIG stored data");

void eeconfig_init_user(void) {
    // Default values
    indi.cap_h = 168;
    indi.num_h = 0;
    indi.com_h = 184;
    indi.cap_s = 255;
    indi.num_s = 0;
    indi.com_s = 255;
    eeconfig_update_user_datablock(&indi);
}

// Initialize the EEPROM values
void keyboard_post_init_user(void) {
eeconfig_read_user_datablock(&indi);
}

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) {
        return false;
        }
    hsv_t hsv;
    if (host_keyboard_led_state().caps_lock && !host_keyboard_led_state().num_lock) {
        hsv.h = indi.com_h;
        hsv.s = indi.com_s;
        hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
    } else if (!host_keyboard_led_state().num_lock) {
        hsv.h = indi.num_h;
        hsv.s = indi.num_s;
        hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
    } else if (host_keyboard_led_state().caps_lock) {
        hsv.h = indi.cap_h;
        hsv.s = indi.cap_s;
        hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
    } else if (!rgb_matrix_get_flags()) {
        hsv.h = 0;
        hsv.s = 0;
        hsv.v = 0;
    } else {
        return false;
    }

    rgb_t rgb = hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x08)) { // 0x08 == LED_FLAG_INDICATOR
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
    return true;
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    bool shifted = get_mods() & MOD_MASK_SHIFT;
    uint8_t sat_step = RGB_MATRIX_SAT_STEP;
    uint8_t hue_step = RGB_MATRIX_HUE_STEP;

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
                case CAPSLKU:
            if (record->event.pressed) {
                if (shifted) {
                    indi.cap_s = qadd8(indi.cap_s, sat_step);
                } else {
                    if (indi.cap_s == 0) {
                        indi.cap_s = 255;
                    }
                    indi.cap_h = (indi.cap_h + hue_step);
                }
                eeconfig_update_user_datablock(&indi);
            }
            return false;
        case CAPSLKD:
            if (record->event.pressed) {
                if (shifted) {
                    indi.cap_s = qsub8(indi.cap_s, sat_step);
                } else {
                    if (indi.cap_s == 0) {
                        indi.cap_s = 255;
                    }
                    indi.cap_h = (indi.cap_h - hue_step);
                }
                eeconfig_update_user_datablock(&indi);
            }
            return false;
        case NUMLKOU:
            if (record->event.pressed) {
                if (shifted) {
                    indi.num_s = qadd8(indi.num_s, sat_step);
                } else {
                    if (indi.num_s == 0) {
                        indi.num_s = 255;
                    }
                    indi.num_h = (indi.num_h + hue_step);
                }
                eeconfig_update_user_datablock(&indi);
            }
            return false;
        case NUMLKOD:
            if (record->event.pressed) {
                if (shifted) {
                    indi.num_s = qsub8(indi.num_s, sat_step);
                } else {
                    if (indi.num_s == 0) {
                        indi.num_s = 255;
                    }
                    indi.num_h = (indi.num_h - hue_step);
                }
                eeconfig_update_user_datablock(&indi);
            }
            return false;
        case COMBLKU:
            if (record->event.pressed) {
                if (shifted) {
                    indi.com_s = qadd8(indi.com_s, sat_step);
                } else {
                    if (indi.com_s == 0) {
                        indi.com_s = 255;
                    }
                    indi.com_h = (indi.com_h + hue_step);
                }
                eeconfig_update_user_datablock(&indi);
            }
            return false;
        case COMBLKD:
            if (record->event.pressed) {
                if (shifted) {
                    indi.com_s = qsub8(indi.com_s, sat_step);
                } else {
                    if (indi.com_s == 0) {
                        indi.com_s = 255;
                    }
                    indi.com_h = (indi.com_h - hue_step);
                }
                eeconfig_update_user_datablock(&indi);
            }
            return false;
    }
    return true;
}

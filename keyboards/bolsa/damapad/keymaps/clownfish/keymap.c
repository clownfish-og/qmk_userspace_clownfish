/*
Copyright 2021 Matthew Dias

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "keycodes.h"
#include "quantum.h"
#include QMK_KEYBOARD_H

enum my_keycodes {
    NUL = MY_SAFE_RANGE,
    INDEX,
    DESC,
    AVS,
    BOM,
    QTY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_bar(
        NUL,     KC_C,    KC_V,    KC_COLN, KC_DEL,  KC_MUTE,
        INDEX,   DESC,    AVS,     BOM,     QTY,     MO(1),
                 KC_ENT,           KC_LCTL,          KC_ENT
    ),
    [1] = LAYOUT_bar(
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
                 _______,          _______,          _______
    ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLD)},
    [1] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLU)}
};
#endif

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NUL:
            if (record->event.pressed) {
                SEND_STRING("null");
            }
            return false;
        case INDEX:
            if (record->event.pressed) {
                SEND_STRING("INDEX");
            }
            return false;
        case DESC:
            if (record->event.pressed) {
                SEND_STRING("DESC");
            }
            return false;
        case AVS:
            if (record->event.pressed) {
                SEND_STRING("AVS");
            }
            return false;
        case BOM:
            if (record->event.pressed) {
                SEND_STRING("BOM");
            }
            return false;
        case QTY:
            if (record->event.pressed) {
                SEND_STRING("QTY");
            }
            return false;
    }
    return true;
}

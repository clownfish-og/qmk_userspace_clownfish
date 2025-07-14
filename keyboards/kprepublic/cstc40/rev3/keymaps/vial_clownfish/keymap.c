/* Copyright 2023
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "rgb_keys.h"
#include "elpekenin/ledmap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Grv  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  \   |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Menu | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[0] = LAYOUT_planck_mit(
    KC_GRV,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,    KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,     KC_BSPC,
    KC_BSLS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,    KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,    KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_ENT ,
    KC_LCTL,  KC_MENU,  KC_LGUI,  KC_LALT,  TL_LOWR,       KC_SPC,       TL_UPPR,  KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      | Home | End  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[1] = LAYOUT_planck_mit(
    KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
    KC_TAB,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE,
    _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  KC_HOME,  KC_END,   _______,  _______,
    _______,  _______,  _______,  _______,  _______,       _______,       _______,  _______,  KC_VOLD,  KC_VOLU,  KC_MUTE
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |ISO # |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |Pg Up |Pg Dn |ISO / |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[2] = LAYOUT_planck_mit(
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    KC_NUHS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS,
    _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  KC_PGUP,  KC_PGDN,  KC_NUBS,  _______,
    _______,  _______,  _______,  _______,  _______,       _______,       _______,  _______,  _______,  _______,  _______
),

/* Adjust (Lower + Raise)
 *  v--------------RGB CONTROL--------------v
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RGB  | Next | Val+ | Hue+ | Sat+ | Spd+ |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Prev | Val- | Hue- | Sat- | Spd- |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[3] = LAYOUT_planck_mit(
    KC_MAKE,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,
    RM_M_PL,  RM_M_AM,  RM_M_RB,  RM_M_CN,  SIMPLGT,       _______,       _______,  _______,  _______,  _______,  _______
)

};

const ledmap_color_t PROGMEM ledmap[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_planck_mit(
    CYAN,     CYAN,     CYAN,     CYAN,     CYAN,     RED,      ORANGE,   YELLOW,   VIOLET,   VIOLET,   VIOLET,   VIOLET,
    CYAN,     CYAN,     CYAN,     CYAN,     RED,      ORANGE,   YELLOW,   VIOLET,   VIOLET,   VIOLET,   VIOLET,   VIOLET,
    CYAN,     CYAN,     CYAN,     RED,      ORANGE,   YELLOW,   VIOLET,   VIOLET,   VIOLET,   VIOLET,   VIOLET,   VIOLET,
    CYAN,     CYAN,     RED,      ORANGE,   YELLOW,         VIOLET,       VIOLET,   VIOLET,   VIOLET,   VIOLET,   VIOLET
),

[1] = LAYOUT_planck_mit(
    TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,
    TRNS,     GREEN,    GREEN,    GREEN,    GREEN,    GREEN,    GREEN,    TRNS,     TRNS,     TRNS,     TRNS,     TRNS,
    BLACK,    GREEN,    GREEN,    GREEN,    GREEN,    GREEN,    GREEN,    BLACK,    TRNS,     TRNS,     BLACK,    BLACK,
    WHITE,    WHITE,    WHITE,    WHITE,    WHITE,        TRNS,           TRNS,     TRNS,     TRNS,     TRNS,     TRNS
),

[2] = LAYOUT_planck_mit(
    TRNS,     BLUE,     BLUE,     BLUE,     BLUE,     BLUE,     BLUE,     BLUE,     BLUE,     BLUE,     BLUE,     TRNS,
    TRNS,     GREEN,    GREEN,    GREEN,    GREEN,    GREEN,    GREEN,    TRNS,     TRNS,     TRNS,     TRNS,     TRNS,
    BLACK,    GREEN,    GREEN,    GREEN,    GREEN,    GREEN,    GREEN,    TRNS,     TRNS,     TRNS,     TRNS,     TRNS,
    TRNS,     TRNS,     TRNS,     TRNS,     TRNS,           TRNS,         WHITE,    WHITE,    WHITE,    WHITE,    WHITE
),

[3] = LAYOUT_planck_mit(
    RED,      TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,
    TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,
    TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,     TRNS,
    TRNS,     TRNS,     TRNS,     TRNS,     TRNS,           TRNS,         TRNS,     TRNS,     TRNS,     TRNS,     TRNS
)

};

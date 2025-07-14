/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0x8A, 0x52, 0x5A, 0xBE, 0x1D, 0x82, 0x69, 0x72}
#define VIAL_UNLOCK_COMBO_ROWS { 1, 2 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 11 }

#ifdef WEAR_LEVELING_BACKING_SIZE
    #undef WEAR_LEVELING_BACKING_SIZE
#endif
#define WEAR_LEVELING_BACKING_SIZE	2*1024*16 // 32kB for 16kB of logical data
#define DYNAMIC_KEYMAP_LAYER_COUNT 10
#define VIAL_TAP_DANCE_ENTRIES 32
#define VIAL_COMBO_ENTRIES 32

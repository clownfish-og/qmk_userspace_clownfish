/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#ifdef WEAR_LEVELING_BACKING_SIZE
    #undef WEAR_LEVELING_BACKING_SIZE
#endif
#define WEAR_LEVELING_BACKING_SIZE	2*1024*8 // 16kB for 8kB of logical data
#define DYNAMIC_KEYMAP_LAYER_COUNT 10

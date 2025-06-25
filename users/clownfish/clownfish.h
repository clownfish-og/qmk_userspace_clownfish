// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "quantum.h"
#include "action.h"
#include "quantum_keycodes.h"
#include "version.h"

enum clownfish_keycodes {
    KC_MAKE = SAFE_RANGE,
    ALT_TAB,
    EXTEND,
    CHROME,
    SPAM,
    VENV,
    DBL_0,
    CLOWNFISH_RANGE
};

#ifndef RGB_MATRIX_ENABLE
    #define MY_SAFE_RANGE CLOWNFISH_RANGE
#endif
#ifdef RGB_MATRIX_ENABLE
    #include "rgb_keys.h"
#endif

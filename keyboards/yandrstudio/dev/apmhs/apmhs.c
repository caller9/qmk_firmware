// Copyright 2018-2022 Nick Brassel (@tzarc)
// SPDX-License-Identifier: GPL-3.0-or-later
#include "quantum.h"

void keyboard_post_init_kb(void) {
    keyboard_post_init_user();
#ifdef CONSOLE_ENABLE
    debug_enable = true;
#endif
}

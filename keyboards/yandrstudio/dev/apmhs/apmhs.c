// Copyright 2018-2022 Nick Brassel (@tzarc)
// SPDX-License-Identifier: GPL-3.0-or-later
#include "quantum.h"

#include "apmhs.h"

// globol
kb_cstm_config_t kb_cstm_config;

void eeconfig_init_kb(void) {
    eeconfig_init_user();
}

void keyboard_post_init_kb(void) {
    keyboard_post_init_user();
#ifdef CONSOLE_ENABLE
    debug_enable = true;
#endif
}

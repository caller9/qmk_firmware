// Copyright 2018-2022 Nick Brassel (@tzarc)
// SPDX-License-Identifier: GPL-3.0-or-later
#include "quantum.h"

void keyboard_post_init_kb(void) {
    keyboard_post_init_user();
#ifdef CONSOLE_ENABLE
    debug_enable = true;
#endif
    // chThdCreateStatic(TxThread1, sizeof(TxThread1), NORMALPRIO+1, Thread2, NULL);
    // chThdCreateStatic(RxThread1, sizeof(RxThread1), NORMALPRIO+1, Thread1, NULL);
}

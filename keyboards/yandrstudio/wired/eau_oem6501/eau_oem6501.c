// Copyright 2023 Y&R-Biu (@jiaxin96)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "eau_oem6501.h"

#ifdef RGB_MATRIX_ENABLE

#define SKIP_IND_N 0

led_config_t g_led_config = {
    {
        {52+SKIP_IND_N,  53+SKIP_IND_N,  54+SKIP_IND_N,  55+SKIP_IND_N,  56+SKIP_IND_N,  57+SKIP_IND_N,  58+SKIP_IND_N,  59+SKIP_IND_N,  60+SKIP_IND_N,  61+SKIP_IND_N,  62+SKIP_IND_N,  63+SKIP_IND_N,  64+SKIP_IND_N,  65+SKIP_IND_N,  66+SKIP_IND_N},
        {51+SKIP_IND_N,  50+SKIP_IND_N,  49+SKIP_IND_N,  48+SKIP_IND_N,  47+SKIP_IND_N,  46+SKIP_IND_N,  45+SKIP_IND_N,  44+SKIP_IND_N,  43+SKIP_IND_N,  42+SKIP_IND_N,  41+SKIP_IND_N,  40+SKIP_IND_N,  39+SKIP_IND_N,  38+SKIP_IND_N,  37+SKIP_IND_N},
        {23+SKIP_IND_N,  24+SKIP_IND_N,  25+SKIP_IND_N,  26+SKIP_IND_N,  27+SKIP_IND_N,  28+SKIP_IND_N,  29+SKIP_IND_N,  30+SKIP_IND_N,  31+SKIP_IND_N,  32+SKIP_IND_N,  33+SKIP_IND_N,  34+SKIP_IND_N,   NO_LED,  35+SKIP_IND_N,  36+SKIP_IND_N},
        {22+SKIP_IND_N,  21+SKIP_IND_N,  20+SKIP_IND_N,  19+SKIP_IND_N,  18+SKIP_IND_N,  17+SKIP_IND_N,  16+SKIP_IND_N,  15+SKIP_IND_N,  14+SKIP_IND_N,  13+SKIP_IND_N,  12+SKIP_IND_N,   NO_LED,  11+SKIP_IND_N,  10+SKIP_IND_N,  9+SKIP_IND_N},
        {0,  1,  2,   NO_LED,   NO_LED,  3,   NO_LED,   NO_LED,   NO_LED,  4,  5,   NO_LED,  6+SKIP_IND_N,  7+SKIP_IND_N,  8+SKIP_IND_N}
    },
    {
        // LED Index to Physical Position
        {0,64},{16,64},{32,64},              {80,64},                     {144,64},{160,64},
        #if SKIP_IND_N > 0
        {175,64},{175,64},{175,64},{175,64},{175,64},
        #endif
        {192,64},{208,64},{224,64},
        {224,48},{208,48},{192,48},       {160,48},{144,48},{128,48},{112,48},{96,48},{80,48},{64,48},{48,48},{32,48},{16,48},{0,48},
        {0,32},{16,32},{32,32},{48,32},{64,32},{80,32},{96,32},{112,32},{128,32},{144,32},{160,32},{176,32},       {208,32},{224,32},
        {224,16},{208,16},{192,16},{176,16},{160,16},{144,16},{128,16},{112,16},{96,16},{80,16},{64,16},{48,16},{32,16},{16,16},{0,16},
        {0,0},{16,0},{32,0},{48,0},{64,0},{80,0},{96,0},{112,0},{128,0},{144,0},{160,0},{176,0},{192,0},{208,0},{224,0},

        {224, 0}, {224, 12}, {224, 24}, {224, 36}, {224, 48},
        {0, 48}, {0, 36}, {0, 24}, {0, 12}, {0, 0},

        {0,0}, {10,0}, {20,0}, {30,0}, {40,0}, {50,0}, {60,0}, {70,0}, {80,0}, {90,0},
        {100,0}, {110,0}, {120,0}, {130,0}, {140,0}, {150,0}, {160,0}, {170,0}, {180,0}, {190,0},
    },
    {
      // LED Index to Flag
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4,
    #if SKIP_IND_N > 0
    4, 4, 4, 4, 4,
    #endif
      4, 4
    }
};

void keyboard_post_init_kb(void) {
    rgb_matrix_reload_from_eeprom();
}

#endif

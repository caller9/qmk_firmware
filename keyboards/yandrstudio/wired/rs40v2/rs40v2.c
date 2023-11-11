// Copyright 2023 Y&R-studio (@superYoungMonk)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "rs40v2.h"

#ifdef RGB_MATRIX_ENABLE

#include "rgb_matrix_layer.h"

extern rgb_task_states rgb_task_state;

led_config_t g_led_config = {
    {
        {41,  40,  39,  38,  37,  36,  35,  34,  33,  32,  31,  30},
        {19,  20,  21,  22,  23,  24,  25,  26,  27,  28,   NO_LED,  29},
        {18,  17,  16,  15,  14,  13,  12,  11,  10,  9,  8,   NO_LED},
        {0,  1,  2,   NO_LED,  3,  4,   NO_LED,  5,   NO_LED,  6,  7,   NO_LED}
    },
    {
        // LED Index to Physical Position
        {0,64},{20,64},{41,64},       {81,64},{102,64},       {143,64},       {183,64},{204,64},
            {204,43},{183,43},{163,43},{143,43},{122,43},{102,43},{81,43},{61,43},{41,43},{20,43},{0,43},
        {0,21},{20,21},{41,21},{61,21},{81,21},{102,21},{122,21},{143,21},{163,21},{183,21},       {224,21},
        {224,0},{204,0},{183,0},{163,0},{143,0},{122,0},{102,0},{81,0},{61,0},{41,0},{20,0},{0,0}
    },
    {
      // LED Index to Flag
      4,4,4,4,4, 4,4,4,4,4, // 0
      4,4,4,4,4, 4,4,4,4,4, // 1
      4,4,4,4,4, 4,4,4,4,4, // 2
      4,4,4,4,4, 4,4,4,4,4, // 3
      4,4                   // 4
    }
};


const rgb_matrix_adv_layer_segment_t PROGMEM my_capslock_layer[] = RGB_MATRIX_LAYER_SEGMENTS(
    {19, 1, HSV_RED}
);

const rgb_matrix_adv_layer_segment_t* const PROGMEM my_rgb_matrix_layers[] = RGB_MATRIX_LAYERS_LIST(
    my_capslock_layer
);

extern LED_TYPE rgb_matrix_ws2812_array[RGB_MATRIX_LED_COUNT];

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) {
        return false;
    }
    rgb_matrix_adv_blink_layer_repeat_helper();
    rgb_matrix_adv_set_layer_state(0, host_keyboard_led_state().caps_lock);

    // If not enabled, then nothing else will actually set the LEDs...
    if (!rgb_matrix_is_enabled()) {
        rgb_task_state = FLUSHING;
    }
    return true;
}


void keyboard_post_init_kb(void) {
    rgb_matrix_reload_from_eeprom();
    rgb_matrix_layers = my_rgb_matrix_layers;
}

#endif


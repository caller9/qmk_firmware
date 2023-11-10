// Copyright 2023 Y&R-studio (@superYoungMonk)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "rs40v2.h"

#ifdef RGB_MATRIX_ENABLE

#include "rgb_matrix_layer.h"

extern rgb_task_states rgb_task_state;

led_config_t g_led_config = {
    {
        {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11}, 
        {22,  21,  20,  19,  18,  17,  16,  15,  14,  13,  12,   NO_LED}, 
        {23,  24,  25,  26,  27,  28,  29,  30,  31,  32,  33,   NO_LED}, 
        {41,  40,  39,  38,   NO_LED,  37,  36,   NO_LED,  35,   NO_LED,  34,   NO_LED}
    },
    {
        // LED Index to Physical Position
        {0,0},{20,0},{41,0},{61,0},{81,0},{102,0},{122,0},{143,0},{163,0},{183,0},{204,0},{224,0},
        {204,21},{183,21},{163,21},{143,21},{122,21},{102,21},{81,21},{61,21},{41,21},{20,21},{0,21},
        {0,43},{20,43},{41,43},{61,43},{81,43},{102,43},{122,43},{143,43},{163,43},{183,43},{204,43},       
        {204,64},       {163,64},       {122,64},{102,64},       {61,64},{41,64},{20,64},{0,64}
    },
    {
      // LED Index to Flag
      4,4,4,4,4, 4,4,4,4,4, // 0
      4,4,4,4,4, 4,4,4,4,4, // 1
      4,4,4,4,4, 4,4,4,4,4, // 2
      4,4,4,4,4, 4,4,4,4,4, // 3
      4,                    // 4
    }
};


const rgb_matrix_adv_layer_segment_t PROGMEM my_capslock_layer[] = RGB_MATRIX_LAYER_SEGMENTS(
    {63, 1, HSV_RED}
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
#ifdef LAYOUT_RGB_87
    uint8_t cent_num = 85;
#else
    uint8_t cent_num = 86;
#endif
    rgb_matrix_ws2812_array[cent_num-1].r = rgb_matrix_ws2812_array[cent_num].r;
    rgb_matrix_ws2812_array[cent_num-1].g = rgb_matrix_ws2812_array[cent_num].g;
    rgb_matrix_ws2812_array[cent_num-1].b = rgb_matrix_ws2812_array[cent_num].b;
    rgb_matrix_ws2812_array[cent_num-2].r = rgb_matrix_ws2812_array[cent_num].r;
    rgb_matrix_ws2812_array[cent_num-2].g = rgb_matrix_ws2812_array[cent_num].g;
    rgb_matrix_ws2812_array[cent_num-2].b = rgb_matrix_ws2812_array[cent_num].b;
    rgb_matrix_ws2812_array[cent_num+1].r = rgb_matrix_ws2812_array[cent_num].r;
    rgb_matrix_ws2812_array[cent_num+1].g = rgb_matrix_ws2812_array[cent_num].g;
    rgb_matrix_ws2812_array[cent_num+1].b = rgb_matrix_ws2812_array[cent_num].b;
    rgb_matrix_ws2812_array[cent_num+2].r = rgb_matrix_ws2812_array[cent_num].r;
    rgb_matrix_ws2812_array[cent_num+2].g = rgb_matrix_ws2812_array[cent_num].g;
    rgb_matrix_ws2812_array[cent_num+2].b = rgb_matrix_ws2812_array[cent_num].b;
    return true;
}


void keyboard_post_init_kb(void) {
    rgb_matrix_reload_from_eeprom();
    rgb_matrix_layers = my_rgb_matrix_layers;
#ifdef CONSOLE_ENABLE
    debug_enable = true;
    debug_matrix = true;
#endif
}

// void board_init(void) {
//     AFIO->MAPR |= AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1;
// }

#endif


// Copyright 2023 Y&R-Biu (@jiaxin96)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* RGN Matrix */

#    define RGB_MATRIX_LED_COUNT 117
#    define RGB_MATRIX_LAYERS
#    define RGB_MATRIX_LAYER_BLINK
#    define RGB_MATRIX_LAYERS_OVERRIDE_RGB_OFF
#    define RGB_MATRIX_LAYERS_RETAIN_VAL
#    define RGB_MATRIX_MAX_LAYERS 1



#    define WS2812_PWM_DRIVER PWMD2  // default: PWMD2
#    define WS2812_PWM_CHANNEL 4  // default: 2
#    define WS2812_DMA_STREAM STM32_DMA1_STREAM2
#    define WS2812_DMA_CHANNEL 2

#define EECONFIG_KB_DATA_SIZE 1

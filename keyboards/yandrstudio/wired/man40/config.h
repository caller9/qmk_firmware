// Copyright 2023 Y&R-Biu (@jiaxin96)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xAA96
#define PRODUCT_ID      0xAAD6
#define DEVICE_VER      0x0001
#define MANUFACTURER    "Y&R"
#define PRODUCT         "MAN40"

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 8

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

//                        0   1   2   3   4   5   6   7
#define MATRIX_COL_PINS { B3, B4, B5, B6, B7, B8, B9, A3 }
#define MATRIX_ROW_PINS { A8, A9, A0, A1, A2 }

#define TAP_HOLD_CAPS_DELAY 250

#define LED_SCROLL_LOCK_PIN  B14
#define LED_CAPS_LOCK_PIN A15
#define LED_PIN_ON_STATE  1

// Copyright 2024 Y&R-Biu (@jiaxin96)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "quantum.h"

#define LAYOUT( \
    K000,       K002, K003, K004, K005, K006, K007, K008, K009,       K011, K012, K013, K014, K015, K016, K017, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116, K117, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212,       K214, K215, K216, K217, \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K313, \
    K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411,       K413, K414,       K416,\
    K500, K501,       K503,                   K507,                   K511, K512,       K514, K515, K516, K517 \
    )\
    { \
    { K000,  KC_NO, K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  KC_NO, K011,  K012,  K013,  K014,  K015,  K016,  K017}, \
    { K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113,  K114,  K115,  K116,  K117}, \
    { K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  KC_NO, K214,  K215,  K216,  K217}, \
    { K300,  K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  KC_NO, K313,  KC_NO, KC_NO, KC_NO, KC_NO}, \
    { K400,  K401,  K402,  K403,  K404,  K405,  K406,  K407,  K408,  K409,  K410,  K411,  KC_NO, K413,  K414,  KC_NO, K416,  KC_NO}, \
    { K500,  K501,  KC_NO, K503,  KC_NO, KC_NO, KC_NO, K507,  KC_NO, KC_NO, KC_NO, K511,  K512,  KC_NO, K514,  K515,  K516,  K517}  \
}

enum keyboard_keycodes {
    LOCK_GUI = QK_KB,
    TOG_MACOS_KEYMAP,
    KC_MISSION_CONTROL_MAC,
    KC_LAUNCHPAD_MAC
};

#define MKC_LG    LOCK_GUI
#define MKC_MACOS TOG_MACOS_KEYMAP
#define MKC_MCTL  KC_MISSION_CONTROL_MAC
#define MKC_LPAD  KC_LAUNCHPAD_MAC

extern bool yr_factory_test;

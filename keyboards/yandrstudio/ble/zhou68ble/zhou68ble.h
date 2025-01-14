/* Copyright 2021 JasonRen(biu)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"

#define LAYOUT( \
      K000, K001, K002, K003, K004, K005, K006, K007,  K008,  K009, K010, K011,  K012,  K013, K014, K015, \
      K100, K101, K102, K103, K104, K105, K106, K107,  K108,  K109, K110, K111,  K112,  K113, K114, K115, \
      K200, K201, K202, K203, K204, K205, K206, K207,  K208,  K209, K210, K211,  K212,                    \
      K300, K301, K302, K303, K304, K305, K306,        K308,  K309, K310, K311,  K312,        K314,       \
      K400, K401,                         K406, K407,  K408,  K409,              K412,  K413, K414, K415  \
) { \
    { K000, K001, K002,  K003,  K004,  K005,  K006, K007,  K008, K009, K010,  K011,  K012,  K013,  K014,  K015  }, \
    { K100, K101, K102,  K103,  K104,  K105,  K106, K107,  K108, K109, K110,  K111,  K112,  K113,  K114,  K115  }, \
    { K200, K201, K202,  K203,  K204,  K205,  K206, K207,  K208, K209, K210,  K211,  K212,  KC_NO, KC_NO, KC_NO }, \
    { K300, K301, K302,  K303,  K304,  K305,  K306, KC_NO, K308, K309, K310,  K311,  K312,  KC_NO, K314,  KC_NO }, \
    { K400, K401, KC_NO, KC_NO, KC_NO, KC_NO, K406, K407,  K408, K409, KC_NO, KC_NO, K412,  K413,  K414,  K415  }  \
}

#ifdef RGB_MATRIX_ENABLE

void rgb_matrix_adv_unblink_all_batlayer_but_one_layer(uint8_t l);

#endif

enum keyboard_keycodes {
    LOCK_GUI = QK_KB,
#ifdef RGB_MATRIX_ENABLE
    BAT_SHOW,
#endif
    TOG_MACOS_KEYMAP_MAC,
    KC_MISSION_CONTROL_MAC,
    KC_LAUNCHPAD_MAC,
    TOG_TFT_SCREEN,
    BT_1,BT_2,BT_3,
    BT_4,BT_5,BT_6,BT_7,
    BT_8,BT_9,BT_10
};

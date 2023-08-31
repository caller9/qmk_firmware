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
#include "tmagnetic.h"

#include "analog.h"

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_Q:
            if (record->event.pressed) {
                dprintf("X read value:%d \n", analogReadPin(JOYSTICK_X_PIN));
                dprintf("Y read value:%d \n", analogReadPin(JOYSTICK_Y_PIN));
            }
            return false;
        default:
            return true;
    }
    return true;
}


void keyboard_post_init_kb(void) {
    debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
}

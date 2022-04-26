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
#include "tjoystick.h"

#ifdef JOYSTICK_ENABLE
#   include "joystick.h"
#   include "analog.h"
#endif

#ifdef JOYSTICK_ENABLE
/* Joystick axes settings */
joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
    [0] = JOYSTICK_AXIS_VIRTUAL,
    [1] = JOYSTICK_AXIS_VIRTUAL,
    [2] = JOYSTICK_AXIS_VIRTUAL
};
// joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
//     [0] = JOYSTICK_AXIS_IN(JOYSTICK_X_PIN, 50, 515, 1000),
//     [1] = JOYSTICK_AXIS_IN(JOYSTICK_Y_PIN, 50, 515, 1000),
//     [2] = JOYSTICK_AXIS_VIRTUAL
// };
void matrix_scan_kb() {
    #   ifdef VIA_ENABLE
    uint16_t keycode = 0;
    #   endif
    if (readPin(JOYSTICK_Z_PIN) == 1) {
    #   ifdef VIA_ENABLE
        keycode = dynamic_keymap_get_keycode(biton32(layer_state), 0, 2);
        if (keycode >= MACRO00 && keycode <= MACRO15) {
            dynamic_keymap_macro_send(keycode - MACRO00);
        } else {
            tap_code16(keycode);
        }
    #   else
        tap_code16(KC_MUTE);
    #   endif
    }
    if (analogReadPin(JOYSTICK_X_PIN) > 768) {
    #   ifdef VIA_ENABLE
        keycode = dynamic_keymap_get_keycode(biton32(layer_state), 1, 2);
        if (keycode >= MACRO00 && keycode <= MACRO15) {
            dynamic_keymap_macro_send(keycode - MACRO00);
        } else {
            tap_code16(keycode);
        }
    #   else
        tap_code16(KC_LEFT);
    #   endif

    } else if (analogReadPin(JOYSTICK_X_PIN) < 256) {
    #   ifdef VIA_ENABLE
        keycode = dynamic_keymap_get_keycode(biton32(layer_state), 1, 0);
        if (keycode >= MACRO00 && keycode <= MACRO15) {
            dynamic_keymap_macro_send(keycode - MACRO00);
        } else {
            tap_code16(keycode);
        }
    #   else
        tap_code16(KC_RIGHT);
    #   endif
    }
    if (analogReadPin(JOYSTICK_Y_PIN) < 256) {
    #   ifdef VIA_ENABLE
        keycode = dynamic_keymap_get_keycode(biton32(layer_state), 0, 1);
        if (keycode >= MACRO00 && keycode <= MACRO15) {
            dynamic_keymap_macro_send(keycode - MACRO00);
        } else {
            tap_code16(keycode);
        }
    #   else
        tap_code16(KC_UP);
    #   endif
    } else if (analogReadPin(JOYSTICK_Y_PIN) > 768) {
    #   ifdef VIA_ENABLEs
        keycode = dynamic_keymap_get_keycode(biton32(layer_state), 1, 1);
        if (keycode >= MACRO00 && keycode <= MACRO15) {
            dynamic_keymap_macro_send(keycode - MACRO00);
        } else {
            tap_code16(keycode);
        }
    #   else
        tap_code16(KC_DOWN);
    #   endif
    }
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_A:
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

#endif


void keyboard_post_init_kb(void) {
    debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
}

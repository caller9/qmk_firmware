// Copyright 2018-2022 Nick Brassel (@tzarc)
// SPDX-License-Identifier: GPL-3.0-or-later
#include QMK_KEYBOARD_H

enum { _QWERTY, _LOWER, _RAISE, _ADJUST };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

#define SFT_ESC LSFT_T(KC_ESC)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_Q
    )
};
// clang-format on
static void dummy_vt_callback(virtual_timer_t *vtp, void *p) {}
void matrix_init_user(void) {
    // Start a virtual timer so we'll still get periodic wakeups, now that USB SOF doesn't wake up the main loop
    static virtual_timer_t vt;
    chVTObjectInit(&vt);
    chVTSetContinuous(&vt, TIME_MS2I(10), dummy_vt_callback, NULL);
}
void keyboard_post_init_user(void) {
    setPinOutput(A8);
    writePinHigh(A8);
    setPinOutput(C9);
    writePinLow(C9);
    setPinOutput(C8);
    writePinLow(C8);

    analogReadPin(C0);
    analogReadPin(C1);
    analogReadPin(C2);
    analogReadPin(C3);
    analogReadPin(A0);
    analogReadPin(A1);
    analogReadPin(A2);
    analogReadPin(A4);
    analogReadPin(A5);
    analogReadPin(A6);

    analogReadPin(B0);
    analogReadPin(B1);

}

void housekeeping_task_user(void) {
    // // Draw the display */
    /* rgblight_setrgb(100,0,0); */
    // if (analogReadPin(A4) > 430) {
    //     rgblight_setrgb_at(0,0,100,0);
    // } else {
    //     rgblight_setrgb_at(0,100,0,0);
    // }
    // if (analogReadPin(A5) > 430) {
    //     rgblight_setrgb_at(0,0,100, 1);
    // } else {
    //     rgblight_setrgb_at(0,100,0, 1);
    // }
    // if (analogReadPin(A6) > 430) {
    //     rgblight_setrgb_at(0,0,100,2);
    // } else {
    //     rgblight_setrgb_at(0,100,0,2);
    // }
    // if (analogReadPin(C0) > 430) {
    //     rgblight_setrgb_at(0,0,100,3);
    // } else {
    //     rgblight_setrgb_at(0,100,0,3);
    // }
    // if (analogReadPin(C1) > 430) {
    //     rgblight_setrgb_at(0,0,100,4);
    // } else {
    //     rgblight_setrgb_at(0,100,0,4);
    // }
    // if (analogReadPin(C2) > 430) {
    //     rgblight_setrgb_at(0,0,100,5);
    // } else {
    //     rgblight_setrgb_at(0,100,0,5);
    // }
    // if (analogReadPin(C3) > 430) {
    //     rgblight_setrgb_at(0,0,100,6);
    // } else {
    //     rgblight_setrgb_at(0,100,0,6);
    // }
    // if (analogReadPin(A0) > 430) {
    //     rgblight_setrgb_at(0,0,100,7);
    // } else {
    //     rgblight_setrgb_at(0,100,0,7);
    // }
    if (analogReadPin(A1) > 430) {
        rgblight_setrgb_at(0,0,100,8);
    } else {
        // unregister_code(KC_A);
        rgblight_setrgb_at(0,100,0,8);
    }
    if (analogReadPin(A2) > 430) {
        rgblight_setrgb_at(0,0,100,9);
    } else {
        // tap_code(KC_A);
        // tap_code_delay(KC_A, 10);
        wait_ms(19);
        // register_code(KC_A);
        // dprintf("fffff%d\n", analogReadPin(A2));
        rgblight_setrgb_at(0,100,0,9);
    }
    // if (analogReadPin(B0) > 430) {
    //     rgblight_setrgb_at(0,0,100,10);
    // } else {
    //     rgblight_setrgb_at(0,100,0,10);
    // }
    // if (analogReadPin(B1) > 430) {
    //     rgblight_setrgb_at(0,0,100,11);
    // } else {
    //     rgblight_setrgb_at(0,100,0,11);
    // }
    if (USB_DRIVER.state == USB_UNINIT) {
        rgblight_setrgb_at(0,0,100,12);
    } else {
        rgblight_setrgb_at(0,100,0,12);
    }
    if (USB_DRIVER.state == USB_STOP) {
        rgblight_setrgb_at(0,0,100,13);
    } else {
        rgblight_setrgb_at(0,100,0,13);
    }
    if (USB_DRIVER.state == USB_READY) {
        rgblight_setrgb_at(0,0,100,14);
    } else {
        rgblight_setrgb_at(0,100,0,14);
    }
    if (USB_DRIVER.state == USB_SELECTED) {
        rgblight_setrgb_at(0,0,100,15);
    } else {
        rgblight_setrgb_at(0,100,0,15);
    }
    if (USB_DRIVER.state == USB_ACTIVE) {
        rgblight_setrgb_at(0,0,100,16);
    } else {
        rgblight_setrgb_at(0,100,0,16);
    }
    if (USB_DRIVER.state == USB_SUSPENDED) {
        rgblight_setrgb_at(0,0,100,17);
    } else {
        rgblight_setrgb_at(0,100,0,17);
    }

}


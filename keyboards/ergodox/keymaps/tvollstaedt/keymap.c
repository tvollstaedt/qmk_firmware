#include "config.h"
#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "led.h"
#include "keymap_extras/keymap_neo2.h"

/* Layers */
enum {
	BASE = 0,
	MDIA,
	SHRT
};

/* Macros */
enum {
  NONE = 0
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Basic layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   ^    |   1  |   2  |   3  |   4  |   5  | Play |           | Next |   6  |   7  |   8  |   9  |   0  |   ß    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |    Ä   |   Q  |   W  |   E  |   R  |   T  |      |           |  L1  |   Z  |   U  |   I  |   O  |   P  |   Ü    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | CpsLck |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  | CpsLck |
     * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
     * |   L2   |   Y  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |-/Ctrl| RShift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | Ctrl |      |      |      |  M4  |                                       |  M4  |      |      |      | Ctrl |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | App  | LGui |       | Alt  | Esc  |
     *                                 ,------+------+------|       |------+--------+------.
     *                                 |      |      |      |       | PgUp |        |      |
     *                                 | Shift| BckSp|------|       |------| Enter  |Space |
     *                                 |      |      | Tab  |       | PgDn |        |      |
     *                                 `--------------------'       `----------------------'
     */
    // If it accepts an argument (i.e, is a function), it doesn't need KC_.
    // Otherwise, it needs KC_*
    [BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_CIRC,       KC_1,           KC_2,     KC_3,     KC_4,     KC_5,   KC_MPLY,
        DE_AE,         KC_Q,           KC_W,     KC_E,     KC_R,     KC_T,   XXXXXXX,
        KC_CAPS,       KC_A,           KC_S,     KC_D,     KC_F,     KC_G,
        MO(2),         DE_Y,           KC_X,     KC_C,     KC_V,     KC_B,   ALL_T(XXXXXXX),
        KC_LCTRL,      XXXXXXX,        XXXXXXX,  XXXXXXX,    NEO_L2_L,
                                                ALT_T(KC_APP),KC_LGUI,
                                                              XXXXXXX,
                                              KC_LSFT,KC_BSPC,KC_TAB,
        // right hand
        KC_MNXT,       KC_6,   KC_7,    KC_8,    KC_9,   KC_0,             KC_MINS,
        TG(1),         DE_Z,   KC_U,    KC_I,    KC_O,   KC_P,             DE_UE,
                       KC_H,   KC_J,    KC_K,    KC_L,   DE_OE,            KC_CAPS,
        MEH_T(XXXXXXX),KC_N,   KC_M,    KC_COMM, KC_DOT, CTL_T(DE_MINS),   KC_RSFT,
                       NEO_L2_R, XXXXXXX,  XXXXXXX,   XXXXXXX,        KC_RCTRL,
        KC_LALT, KC_ESC,
        KC_PGUP,
        KC_PGDN,KC_ENT, KC_SPC
    ),
    /* Keymap 1: Media and mouse keys
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |   F1 |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |Brwser|
     *                                 |      |      |------|       |------|      |Back  |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */
    // MEDIA AND MOUSE
    [MDIA] = KEYMAP(
       _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
       _______, _______, _______, KC_MS_U, _______, _______, _______,
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_BTN1, KC_BTN2,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
        // right hand
       KC_F7,  KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, KC_MPLY,
       _______,  _______, _______, KC_MPRV, KC_MNXT, _______, _______,
                          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
       _______, _______,
       _______,
       _______, _______, KC_WBAK
    ),

    /* Keymap 2: Shortcuts and handy functions
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |      |      | Cut  |Break |      |           |      |  F12 |  F7  |  F8  |  F9  |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      | Copy |PrtScr|------|           |------|  F10 |  F4  |  F5  |  F6  |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |Paste |      |      |           |      |  F11 |  F1  |  F2  |  F3  |      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       |      |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */
    [SHRT] = KEYMAP(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______,   M(1),  KC_BRK,  _______,
       _______, _______, _______, _______,   M(0),  KC_PSCR,
       _______, _______, _______, _______,   M(2),  _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
       // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  KC_F12, KC_F7,   KC_F8,   KC_F9,   _______, _______,
                 KC_F10, KC_F4,   KC_F5,   KC_F6,   _______, _______,
       _______,  KC_F11, KC_F1,   KC_F2,   KC_F3,   _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
    )
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    // MACRODOWN only works in this function
    switch(id) {
        // Cut
        case 0:
            if (record->event.pressed) {
                return MACRO( D(LCTL), T(B), U(LCTL), END ); // PUQ - X
            }
            break;
        // Copy
        case 1:
            if (record->event.pressed) {
                return MACRO( D(LCTL), T(U), U(LCTL), END ); // PUQ - C
            }
            break;
        // Paste
        case 2:
            if (record->event.pressed) {
                return MACRO( D(LCTL), T(M), U(LCTL), END ); // PUQ - V
            }
            break;
    }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  ergodox_led_all_on();
  for (int i = LED_BRIGHTNESS_HI; i > LED_BRIGHTNESS_LO; i--) {
    ergodox_led_all_set (i);
    wait_ms (5);
  }
  wait_ms(1000);
  for (int i = LED_BRIGHTNESS_LO; i > 0; i--) {
    ergodox_led_all_set (i);
    wait_ms (10);
  }
  ergodox_led_all_off();
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
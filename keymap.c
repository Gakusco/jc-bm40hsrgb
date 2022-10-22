#include QMK_KEYBOARD_H

// Gives the layers nicer names. 

#define _BASE 0
#define _SYMBOLS 1
#define _NUMBERS 2
#define _ADJUST 3
#define _CALCULATE 4
#define _MOV 5

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

// KEYMAPS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT_planck_mit(

		KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
    KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
    KC_LCTL, KC_CAPS, KC_LGUI, KC_LALT, MO(1), KC_SPC, MO(2), RALT_T(KC_LEFT), KC_DOWN, KC_UP, KC_RGHT
    
		),


	[_SYMBOLS] = LAYOUT_planck_mit(

		KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, 
    KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    TO(5), KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, LSFT(KC_QUOT), KC_QUOT, KC_DEL, KC_END, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_PSCR, KC_VOLD, KC_VOLU, KC_INS
		),


	[_NUMBERS] = LAYOUT_planck_mit(

		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
    KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
    KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NUHS, KC_NUBS, KC_DEL, KC_PGDN, TO(4),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_PSCR, KC_VOLD, KC_VOLU, KC_INS
		
		),


	[_ADJUST] = LAYOUT_planck_mit(

		KC_TRNS, RESET, DEBUG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, LCTL(KC_LEFT), KC_UP, LCTL(KC_RGHT), RGB_VAD, KC_DEL,
    KC_LSFT, KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

  ),


  [_CALCULATE] = LAYOUT_planck_mit(

    KC_ESC, LCTL(KC_LEFT), KC_UP, LCTL(KC_RGHT), LSFT(KC_1), KC_LPRN, KC_RPRN, KC_7, KC_8, KC_9, KC_PPLS, KC_BSPC,
    KC_TAB, KC_LEFT, KC_DOWN, KC_RGHT, TO(0), KC_LCBR, KC_RCBR, KC_4, KC_5, KC_6, KC_PMNS, KC_ENT,
    KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_1, KC_2, KC_3, KC_PAST, TO(0), KC_LCTL,
    KC_NO, KC_LGUI, KC_LALT, KC_NO, KC_SPC, KC_COMM, KC_0, KC_DOT, KC_PSLS, KC_EQL

  ),

  [_MOV] = LAYOUT_planck_mit(

    KC_ESC, KC_INS, LCTL(KC_BSPC), LCTL(KC_DEL), KC_DEL, KC_LSFT, LCTL(KC_Z), LCTL(KC_LEFT), KC_UP, LCTL(KC_RGHT), LALT(KC_TAB), KC_BSPC,
    KC_TAB, LCTL(LGUI(KC_LEFT)), KC_ENT, KC_BSPC, TO(0), LCTL(LGUI(KC_RIGHT)), KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_ENT,
    KC_LSFT, LCTL(KC_SLSH), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_MINS), LCTL(KC_PLUS), KC_NO, KC_NO, KC_NO, LGUI(KC_TAB), LALT(KC_F4),
    KC_LCTL, KC_NO, KC_LGUI, KC_LALT, KC_LGUI, KC_SPC, KC_PSCR, LGUI(KC_E), KC_VOLD, KC_VOLU, KC_MYCM

  )

};

void rgb_matrix_indicators_user(void) {
    uint8_t red[3] = {50, 5, 0};
    uint8_t yellow[3] = {50, 50, 0};
    uint8_t blue[3] = {0, 15, 50};
    uint8_t green[3] = {15, 33, 1};
    uint8_t white[3] = {255, 255, 255};

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            break;
        case _SYMBOLS:
            rgb_matrix_set_color_all(green[0], green[1], green[2]);
            break;
        case _NUMBERS:
            rgb_matrix_set_color_all(blue[0], blue[1], blue[2]);
            break;
        case _ADJUST:
            break;
        case _CALCULATE:
            rgb_matrix_set_color_all(white[0], white[1], white[2]);
            break;
        case _MOV:
            rgb_matrix_set_color_all(red[0], red[1], red[2]);
            break;
    }

    led_t led_state = host_keyboard_led_state();

    //Capslock led
    if (led_state.caps_lock) {
        rgb_matrix_set_color(37, yellow[0], yellow[1], yellow[2]);
        rgb_matrix_set_color(5, yellow[0], yellow[1], yellow[2]);
        rgb_matrix_set_color(6, yellow[0], yellow[1], yellow[2]);
    }

}
#include QMK_KEYBOARD_H

// Gives the layers nicer names. 

#define _BASE 0
#define _SYMBOLS 1
#define _NUMBERS 2
#define _ADJUST 3
#define _CALCULATE 4
#define _MOV 5

// Sets the default values for the RGB LEDs.

uint8_t prev = _BASE;
uint32_t desiredmode = 31;
uint16_t hue = 120;
uint16_t sat = 255;
uint16_t val = 250;

// Does something to grab the RGB LED values to retain when switching layers.

void get_hsv(void) {
   hue = rgblight_get_hue();
   sat = rgblight_get_sat();
   val = rgblight_get_val();
}

void reset_hsv(void) {
   rgblight_sethsv(hue, sat, val);
}

void matrix_init_user() {
    rgblight_mode(desiredmode);
   rgblight_enable();
   reset_hsv();
}

enum custom_keycodes {
 MACRO_OO,
};


// Macro section


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
           case MACRO_OO:
      if (record->event.pressed)
      {
        SEND_STRING("0_0");
      }
      return false;
      break;
        
return false;
    break;
  }
    return true;
};


// KEYMAPS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_planck_mit(

		KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
    KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
    KC_LCTL, KC_CAPS, KC_LGUI, KC_LALT, MO(1), KC_SPC, MO(2), RALT_T(KC_LEFT), KC_DOWN, KC_UP, KC_RGHT
    
		),


	[1] = LAYOUT_planck_mit(

		KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, 
    KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    TO(5), KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, LSFT(KC_QUOT), KC_QUOT, KC_DEL, KC_END, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_PSCR, KC_VOLD, KC_VOLU, KC_INS
		),


	[2] = LAYOUT_planck_mit(

		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
    KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
    KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NUHS, KC_NUBS, KC_DEL, KC_PGDN, TO(4),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_PSCR, KC_VOLD, KC_VOLU, KC_INS
		
		),


	[3] = LAYOUT_planck_mit(

		KC_TRNS, RESET, DEBUG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, LCTL(KC_LEFT), KC_UP, LCTL(KC_RGHT), RGB_VAD, KC_DEL,
    KC_LSFT, KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

  ),


  [4] = LAYOUT_planck_mit(

    KC_ESC, LCTL(KC_LEFT), KC_UP, LCTL(KC_RGHT), LSFT(KC_1), KC_LPRN, KC_RPRN, KC_7, KC_8, KC_9, KC_PPLS, KC_BSPC,
    KC_TAB, KC_LEFT, KC_DOWN, KC_RGHT, TO(0), KC_LCBR, KC_RCBR, KC_4, KC_5, KC_6, KC_PMNS, KC_ENT,
    KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_1, KC_2, KC_3, KC_PAST, TO(0), KC_LCTL,
    KC_NO, KC_LGUI, KC_LALT, KC_NO, KC_SPC, KC_COMM, KC_0, KC_DOT, KC_PSLS, KC_EQL

  ),

  [5] = LAYOUT_planck_mit(

    KC_ESC, KC_INS, LCTL(KC_BSPC), LCTL(KC_DEL), KC_DEL, KC_LSFT, LCTL(KC_Z), LCTL(KC_LEFT), KC_UP, LCTL(KC_RGHT), LALT(KC_TAB), KC_BSPC,
    KC_TAB, LCTL(LGUI(KC_LEFT)), KC_ENT, KC_BSPC, TO(0), LCTL(LGUI(KC_RIGHT)), KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_ENT,
    KC_LSFT, LCTL(KC_SLSH), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_MINS), LCTL(KC_PLUS), KC_NO, KC_NO, KC_NO, LGUI(KC_TAB), LALT(KC_F4),
    KC_LCTL, KC_NO, KC_LGUI, KC_LALT, KC_LGUI, KC_SPC, KC_PSCR, LGUI(KC_E), KC_VOLD, KC_VOLU, KC_MYCM

  )

};


// Section to change RGB LED colours and animation when activating layer 1 and 2, and then go back to the default, which I can change on the fly.

layer_state_t layer_state_set_user(layer_state_t state) 
{
  uint8_t layer = get_highest_layer(state);
  if (prev!=_ADJUST) {
      switch (layer) {
        case _BASE:
          rgblight_mode(desiredmode);
          reset_hsv();
          break;
        case _NUMBERS:
          rgblight_mode(0);
          rgblight_sethsv(HSV_CYAN);
          break;
        case _SYMBOLS:
          rgblight_mode(0);
          rgblight_sethsv(HSV_GREEN);
          break;  
        case _ADJUST:
          rgblight_mode(desiredmode);
          reset_hsv();
          break;
        case _CALCULATE:
          rgblight_mode(0);
          rgblight_sethsv(HSV_WHITE);
          break;
        case _MOV:
          rgblight_mode(0);
          rgblight_sethsv(HSV_RED);
          break;
      }
  } else {
      desiredmode = rgblight_get_mode();
      get_hsv();
  }
  prev = layer;
  return state;
}
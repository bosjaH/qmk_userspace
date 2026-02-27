
#include QMK_KEYBOARD_H
#include "bosjah.h"

#define WRAPPER_60_ansi(...) LAYOUT_60_ansi(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = WRAPPER_60_ansi(
    __BASE_60_ROW2______________________,
    __BASE_60_ROW3______________________,
    __BASE_60_ROW4______________________,
    __BASE_60_ROW5______________________,
    __BASE_60_ROW6______________________
  ),
  [L_MOD_ISO] = WRAPPER_60_ansi(
    __TRNS_60_ROW2______________________,
    __MOD_ISO_60_ROW3___________________,
    __TRNS_60_ROW4______________________,
    __TRNS_60_ROW5______________________,
    __TRNS_60_ROW6______________________
  ),
  [L_MOD_EURKEY] = WRAPPER_60_ansi(
    __TRNS_60_ROW2______________________,
    __TRNS_60_ROW3______________________,
    __TRNS_60_ROW4______________________,
    __TRNS_60_ROW5______________________,
    __MOD_EURKEY_60_ROW6________________
  ),
  [L_GAME] = WRAPPER_60_ansi(
    __TRNS_60_ROW2______________________,
    __TRNS_60_ROW3______________________,
    __TRNS_60_ROW4______________________,
    __TRNS_60_ROW5______________________,
    __GAME_60_ROW6______________________
  ),
  [L_LOWER] = WRAPPER_60_ansi(
    __LOWER_60_ROW2_____________________,
    __LOWER_60_ROW3_____________________,
    __LOWER_60_ROW4_____________________,
    __LOWER_60_ROW5_____________________,
    __LOWER_60_ROW6_____________________
  ),
  [L_RAISE] = WRAPPER_60_ansi(
    __RAISE_60_ROW2_____________________,
    __RAISE_60_ROW3_____________________,
    __RAISE_60_ROW4_____________________,
    __RAISE_60_ROW5_____________________,
    __RAISE_60_ROW6_____________________
  ),
  [L_EURKEY_ALTGR] = WRAPPER_60_ansi(
    __EURKEY_60_ROW2____________________,
    __EURKEY_60_ROW3____________________,
    __EURKEY_60_ROW4____________________,
    __EURKEY_60_ROW5____________________,
    __EURKEY_60_ROW6____________________
  ),
  [L_ADJUST] = WRAPPER_60_ansi(
    __ADJUST_60_ROW2____________________,
    __ADJUST_60_ROW3____________________,
    __ADJUST_60_ROW4____________________,
    __ADJUST_60_ROW5____________________,
    __ADJUST_60_ROW6____________________
  )
};

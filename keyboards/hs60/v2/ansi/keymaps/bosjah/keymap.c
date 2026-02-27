/* Copyright 2025 Joren Paps
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
// Minimal includes for userspace wrappers
#include QMK_KEYBOARD_H
#include "bosjah.h"

#ifdef COMBO_ENABLE
enum combo_events {
    COMBO_LSFT_DF,
    COMBO_RSFT_JK,
    COMBO_LALT_SD,
    COMBO_RALT_KL,
    COMBO_LSFT_LALT_SDF,
    COMBO_RSFT_LALT_JKL
};

// Combo key sequences (must be in keymap for introspection)
const uint16_t PROGMEM combo_lsft_df[] = { KC_D, KC_F, COMBO_END };
const uint16_t PROGMEM combo_rsft_jk[] = { KC_J, KC_K, COMBO_END };
const uint16_t PROGMEM combo_lalt_sd[] = { KC_S, KC_D, COMBO_END };
const uint16_t PROGMEM combo_ralt_kl[] = { KC_K, KC_L, COMBO_END };
const uint16_t PROGMEM combo_lsft_lalt_sdf[] = { KC_S, KC_D, KC_F, COMBO_END };
const uint16_t PROGMEM combo_rsft_lalt_jkl[] = { KC_J, KC_K, KC_L, COMBO_END };

combo_t key_combos[] = {
    [COMBO_LSFT_DF] = COMBO(combo_lsft_df, KC_LSFT), \
    [COMBO_RSFT_JK] = COMBO(combo_rsft_jk, KC_RSFT), \
    [COMBO_LALT_SD] = COMBO(combo_lalt_sd, KC_LALT), \
    [COMBO_RALT_KL] = COMBO(combo_ralt_kl, KC_RALT), \
    [COMBO_LSFT_LALT_SDF] = COMBO(combo_lsft_lalt_sdf, KC_LSFT), \
    [COMBO_RSFT_LALT_JKL] = COMBO(combo_rsft_lalt_jkl, KC_RSFT)
};
#endif

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

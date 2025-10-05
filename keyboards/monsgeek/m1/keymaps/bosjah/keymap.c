/* Copyright (C) 2025 Joren Paps
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

#include QMK_KEYBOARD_H
#include "bosjah.h"

#define WRAPPER_ansi(...) LAYOUT_ansi(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [L_BASE] = WRAPPER_ansi( /* Base */
        __BASE_75_ROW1______________________,
        __BASE_75_ROW2______________________,
        __BASE_75_ROW3_ISO__________________,
        __BASE_75_ROW4______________________,
        __BASE_75_ROW5______________________,
        __BASE_75_ROW6______________________),

    [L_BASE_ANSI] = WRAPPER_ansi( /* Base */
        __BASE_75_ROW1______________________,
        __BASE_75_ROW2______________________,
        __BASE_75_ROW3_ANSI_________________,
        __BASE_75_ROW4______________________,
        __BASE_75_ROW5______________________,
        __BASE_75_ROW6______________________),

    [L_BASE_EURKEY] = WRAPPER_ansi( /* Eurkey Base */
        __BASE_75_ROW1_EURKEY_______________,
        __BASE_75_ROW2______________________,
        __BASE_75_ROW3_ANSI_________________,
        __BASE_75_ROW4______________________,
        __BASE_75_ROW5______________________,
        __BASE_75_ROW6______________________),

    [L_GAME] = WRAPPER_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        __TRNS_60_ROW2______________________,          _______,
        __TRNS_60_ROW3______________________,          _______,
        __TRNS_60_ROW4______________________,          _______,
        __TRNS_60_ROW5______________________, _______, _______,
        __GAME_75_ROW6______________________),

    [L_LOWER] = WRAPPER_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          RM_TOGG,
        __LOWER_60_ROW2_____________________,                 RM_HUEU,
        __LOWER_60_ROW3_____________________,                 RM_HUED,
        __LOWER_60_ROW4_____________________,                 RM_SATU,
        __LOWER_60_ROW5_____________________,        RM_VALU, RM_SATD,
        _______, _______, _______,                   _______,                            _______, _______, _______,          RM_SPDD, RM_VALD, RM_SPDU),

    [L_RAISE] = WRAPPER_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,           _______,
        __RAISE_60_ROW2_____________________,                 _______,
        __RAISE_60_ROW3_____________________,                 _______,
        __RAISE_60_ROW4_____________________,                 _______,
        __RAISE_60_ROW5_____________________,        _______, _______,
        _______, _______, _______,                   _______,                            _______, _______, _______,          _______, _______, _______),

    [L_EURKEY_ALTGR] = WRAPPER_ansi( /* Eurkey AltGr Layer */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        __EURKEY_60_ROW2____________________,                 _______,
        __EURKEY_60_ROW3____________________,                 _______,
        __EURKEY_60_ROW4____________________,                 _______,
        __EURKEY_60_ROW5____________________,        _______, _______,
        _______, _______, _______,                   _______,                            _______, _______, _______,          _______, _______, _______),

    [L_ADJUST] = WRAPPER_ansi(
        __ADJUST_60_ROW2____________________,                 XXXXXXX,
        __ADJUST_60_ROW2____________________,                 XXXXXXX,
        __ADJUST_60_ROW3____________________,                 XXXXXXX,
        __ADJUST_60_ROW4____________________,                 XXXXXXX,
        __ADJUST_60_ROW5____________________,        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [L_BASE] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [L_BASE_ANSI] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [L_BASE_EURKEY] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [L_GAME] = { ENCODER_CCW_CW(_______, _______) },
    [L_LOWER] = { ENCODER_CCW_CW(_______, _______) },
    [L_RAISE] = { ENCODER_CCW_CW(_______, _______) },
    [L_EURKEY_ALTGR] = { ENCODER_CCW_CW(_______, _______) },
    [L_ADJUST] = { ENCODER_CCW_CW(RM_PREV, RM_NEXT) },
};
#endif

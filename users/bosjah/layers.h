#pragma once
#include "eurkey.h"

// The 60% core is defined once, then extended for larger keyboards

// Base building blocks
#define __F_KEYS_L__________________________    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6
#define __NUMBERS_L_________________________    KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define __QWERTY_L1_________________________    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#ifdef HOME_ROW_MODS_ENABLE
    #define __QWERTY_L2_________________________    HRM_A,   HRM_S,   HRM_D,   HRM_F,   KC_G
#else
    #define __QWERTY_L2_________________________    KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#endif
#define __QWERTY_L3_________________________    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define __F_KEYS_R__________________________    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12
#define __NUMBERS_R_________________________    KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define __QWERTY_R1_________________________    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#ifdef HOME_ROW_MODS_ENABLE
    #define __QWERTY_R2_________________________    KC_H,    HRM_J,   HRM_K,   HRM_L,   HRM_SCLN
#else
    #define __QWERTY_R2_________________________    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#endif
#define __QWERTY_R3_________________________    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define __BLANK_5___________________________    _______,  _______,  _______,  _______,  _______


// Transparent layer rows (60%)
#define __TRNS_60_ROW2______________________    _______,  __BLANK_5___________________________,  __BLANK_5___________________________,  _______,  _______,  _______
#define __TRNS_60_ROW3______________________    _______,  __BLANK_5___________________________,  __BLANK_5___________________________,  _______,  _______,  _______
#define __TRNS_60_ROW4______________________    _______,  __BLANK_5___________________________,  __BLANK_5___________________________,  _______,  _______
#define __TRNS_60_ROW5______________________    _______,  __BLANK_5___________________________,  __BLANK_5___________________________,  _______
#define __TRNS_60_ROW6______________________    _______,  _______,  _______,                     _______,                               _______,  _______,  _______,  _______

// Base layer rows (60%)
#define __BASE_60_ROW2______________________    KC_GRV,    __NUMBERS_L_________________________, __NUMBERS_R_________________________, KC_MINS, KC_EQL, KC_BSPC
#define __BASE_60_ROW3______________________    KC_ESC,    __QWERTY_L1_________________________, __QWERTY_R1_________________________, KC_LBRC, KC_RBRC, KC_BSLS
#define __BASE_60_ROW4______________________    FN_LW_TAB, __QWERTY_L2_________________________, __QWERTY_R2_________________________, KC_QUOT, KC_ENT
#define __BASE_60_ROW5______________________    KC_LSFT,   __QWERTY_L3_________________________, __QWERTY_R3_________________________, KC_RSFT
#define __BASE_60_ROW6______________________    KC_LCTL,   KC_LGUI,   KC_LALT,                   FN_RS_SPC,                            KC_RALT, KC_RGUI, KC_APP, KC_RCTL

// Modifier layer: ISO overlay (60%) — only overrides BSLS → NUBS
#define __MOD_ISO_60_ROW3___________________    _______,   _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_NUBS

// Modifier layer: EURKEY overlay (60%) — replaces RALT with EU_ALTGR, APP with F13
#define __MOD_EURKEY_60_ROW6________________    _______,   _______,   _______,                   _______,                        FN_EU_ALTGR, _______, KC_F13, _______

// Base layer rows (75%)
#define __BASE_75_ROW1______________________    KC_ESC,    __F_KEYS_L__________________________, __F_KEYS_R__________________________, KC_INS,  KC_MUTE
#define __BASE_75_ROW2______________________    __BASE_60_ROW2______________________,                                                           KC_DEL
#define __BASE_75_ROW3______________________    __BASE_60_ROW3______________________,                                                           KC_PGUP
#define __BASE_75_ROW4______________________    __BASE_60_ROW4______________________,                                                           KC_PGDN
#define __BASE_75_ROW5______________________    __BASE_60_ROW5______________________,                                                  KC_UP,   KC_END
#define __BASE_75_ROW6______________________    KC_LCTL,   KC_LGUI,   KC_LALT,     FN_RS_SPC,      KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT

// Modifier layer: ISO overlay (75%)
#define __MOD_ISO_75_ROW3___________________    __MOD_ISO_60_ROW3___________________,                                                            _______

// Modifier layer: EURKEY overlay (75%)
#define __MOD_EURKEY_75_ROW1________________    _______,   _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_F13,  _______
#define __MOD_EURKEY_75_ROW6________________    _______,   _______,   _______,     _______,    FN_EU_ALTGR, _______, _______, _______, _______, _______

// Base layer rows (6x4)
#define __BASE_6x4_L1_______________________    KC_GRV,    __NUMBERS_L_________________________
#define __BASE_6x4_L2_______________________    KC_ESC,    __QWERTY_L1_________________________
#define __BASE_6x4_L3_______________________    KC_TAB,    __QWERTY_L2_________________________
#define __BASE_6x4_L4_______________________    KC_LSFT,   __QWERTY_L3_________________________

#define __BASE_6x4_R1_______________________    __NUMBERS_R_________________________, KC_DEL
#define __BASE_6x4_R2_______________________    __QWERTY_R1_________________________, KC_BSPC
#define __BASE_6x4_R3_______________________    __QWERTY_R2_________________________, KC_QUOT
#define __BASE_6x4_R4_______________________    __QWERTY_R3_________________________, KC_RSFT

// Game lockout
#define __GAME_60_ROW6______________________    _______,  XXXXXXX,  _______,                   KC_SPACE,                             _______,  _______,  _______,  _______
#define __GAME_75_ROW6______________________    _______,  XXXXXXX,  _______,                   KC_SPACE,                             _______,  _______,  _______,          _______, _______, _______

// Home row mods training layer
#ifdef HOME_ROW_MODS_ENABLE
#define __BASE_60_ROW5_DM___________________    XXXXXXX,   __BLANK_5___________________________, __BLANK_5___________________________, XXXXXXX
#define __BASE_60_ROW6_DM___________________    XXXXXXX,   XXXXXXX,   XXXXXXX,         _______,             _______, XXXXXXX, _______, XXXXXXX
#define __BASE_75_ROW6_DM___________________    XXXXXXX,   XXXXXXX,   XXXXXXX,         _______,             _______, XXXXXXX, XXXXXXX, _______, _______, _______
#endif

// Lower = Extended
// Raise = SpaceFN
// Adjust = Config

// Lower layer wrappers
#define __LOWER_60_ROW2_____________________    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL
#define __LOWER_60_ROW3_____________________    _______, _______, _______, _______, _______, M_TM,    KC_CALC, KC_HOME, KC_UP,   KC_END,  _______, _______, _______, _______
#define __LOWER_60_ROW4_____________________    _______, _______, _______, _______, _______, _______, KC_PGUP, KC_LEFT, KC_DOWN, KC_RIGHT,_______, KC_NUHS,          FN_ADJUST
#define __LOWER_60_ROW5_____________________    _______,          _______, _______, _______, _______, _______, KC_PGDN, M_WRDL,  M_WRDR,  _______, _______,          _______
#define __LOWER_60_ROW6_____________________    _______, _______, _______,                   _______,                                     _______, _______, _______, _______

#define __LOWER_6x4_L1______________________    __F_KEYS_L__________________________

// Raise layer wrappers
#define __RAISE_60_ROW2_____________________    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL
#define __RAISE_60_ROW3_____________________    _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP,   KC_END,  _______, _______, _______, _______
#define __RAISE_60_ROW4_____________________    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT,KC_PGUP, KC_NUHS,          FN_ADJUST
#define __RAISE_60_ROW5_____________________    _______,          _______, _______, _______, _______, _______, _______, M_WRDL,  M_WRDR,  _______, KC_PGDN,          _______
#define __RAISE_60_ROW6_____________________    _______, _______, _______,                   _______,                                     _______, _______, _______, _______

// Adjust layer wrappers
#define __ADJUST_60_ROW2____________________    FN_GAME,  FN_ISO,   XXXXXXX, FN_EURKEY,XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  QK_BOOT
#define __ADJUST_60_ROW3____________________    XXXXXXX,  XXXXXXX,  UC_WINC, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
#ifdef HOME_ROW_MODS_ENABLE
#define __ADJUST_60_ROW4____________________    _______,  XXXXXXX,  DB_TOGG, XXXXXXX,  XXXXXXX,  XXXXXXX,  TG(L_HRM_TRAINING),  XXXXXXX,  XXXXXXX,  UC_LINX,  XXXXXXX,  XXXXXXX,          FN_ADJUST
#else
#define __ADJUST_60_ROW4____________________    _______,  XXXXXXX,  DB_TOGG, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  UC_LINX,  XXXXXXX,  XXXXXXX,          FN_ADJUST
#endif
#define __ADJUST_60_ROW5____________________    XXXXXXX,            XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX
#define __ADJUST_60_ROW6____________________    XXXXXXX,  XXXXXXX,  XXXXXXX,                               XXXXXXX,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX

// Eurkey AltGr layer using Unicode Map
#define __EURKEY_60_ROW2____________________    _______, EU_1,    EU_2,    EU_3,    EU_4,    EU_5,    _______, _______, EU_8,    EU_9,    EU_0,    EU_MINS, EU_EQL,   _______
#define __EURKEY_60_ROW3____________________    _______, EU_Q,    EU_W,    EU_E,    EU_R,    EU_T,    EU_Y,    EU_U,    EU_I,    EU_O,    EU_P,    EU_LBRC, EU_RBRC,  EU_BSLS
#define __EURKEY_60_ROW4____________________    _______, EU_A,    EU_S,    EU_D,    EU_F,    EU_G,    EU_H,    EU_J,    EU_K,    EU_L,    EU_SCLN, _______,           _______
#define __EURKEY_60_ROW5____________________    _______,          EU_Z,    EU_X,    EU_C,    EU_V,    EU_B,    EU_N,    EU_M,    EU_COMM, EU_DOT,  EU_SLSH,           _______
#define __EURKEY_60_ROW6____________________    __TRNS_60_ROW6______________________

// Eurkey layer rows (6x4)
#define __EURKEY_6x4_L1_____________________    _______, EU_1,    EU_2,    EU_3,    EU_4,    EU_5
#define __EURKEY_6x4_L2_____________________    _______, EU_Q,    EU_W,    EU_E,    EU_R,    EU_T
#define __EURKEY_6x4_L3_____________________    _______, EU_A,    EU_S,    EU_D,    EU_F,    EU_G
#define __EURKEY_6x4_L4_____________________    _______, EU_Z,    EU_X,    EU_C,    EU_V,    EU_B

#define __EURKEY_6x4_R1_____________________    _______, _______, EU_8,    EU_9,    EU_0,    _______
#define __EURKEY_6x4_R2_____________________    EU_Y,    EU_U,    EU_I,    EU_O,    EU_P,    EU_LBRC
#define __EURKEY_6x4_R3_____________________    EU_H,    EU_J,    EU_K,    EU_L,    EU_SCLN, EU_RBRC
#define __EURKEY_6x4_R4_____________________    EU_N,    EU_M,    EU_COMM, EU_DOT,  EU_SLSH, EU_BSLS

#pragma once

#include <quantum.h>
#include <action_code.h>
#include <action_layer.h>

// Include wrapper definitions
#include "eurkey.h"
#include "layers.h"

enum custom_keycodes {
    CK_DEV = QK_USER,
    CK_EURO
};

// Layers
enum layer_id {
    L_BASE,
    L_BASE_ANSI,
    L_BASE_EURKEY,
    L_GAME,
    L_LOWER,
    L_RAISE,
    L_EURKEY_ALTGR,
    L_ADJUST,
};

// Macros
#define M_WRDL  LCTL(KC_LEFT)        // Word left
#define M_WRDR  LCTL(KC_RIGHT)       // Word right
#define M_VDL   LCTL(LGUI(KC_LEFT))  // Previous virtual desktop
#define M_VDR   LCTL(LGUI(KC_RIGHT)) // Next virtual desktop
#define M_TM    LCTL(LSFT(KC_ESC))   // Task manager

// Common layer switching macros
#define FN_LW_ESC   LT(L_LOWER, KC_ESC)
#define FN_RS_SPC   LT(L_RAISE, KC_SPC)
#define FN_ADJUST   MO(L_ADJUST)
#define FN_EU_ALTGR MO(L_EURKEY_ALTGR)
#define FN_GAME     TG(L_GAME)
#define DL_ISO      PDF(L_BASE)
#define DL_ANSI     PDF(L_BASE_ANSI)
#define DL_EURKEY   PDF(L_BASE_EURKEY)

// Function declarations
void keyboard_post_init_user(void);
bool process_record_user(uint16_t keycode, keyrecord_t *record);

#ifdef ENCODE_ENABLE
void encoder_update_user(uint8_t index, bool clockwise);
#endif

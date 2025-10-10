#pragma once

#include <quantum.h>
#include <action_code.h>
#include <action_layer.h>

// Include wrapper definitions
#include "eurkey.h"
#include "layers.h"
#ifdef RGB_MATRIX_ENABLE
#include "rgb_indicators.h"
#endif

enum custom_keycodes {
    CK_DEV = QK_USER,
    CK_EURO
};

// Layers
enum layer_id {
    L_BASE,
    L_BASE_ANSI,
    L_BASE_EURKEY,
#ifdef HOME_ROW_MODS_ENABLE
    L_HRM_TRAINING,
#endif
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

// Home row mods
#define HRM_A    LGUI_T(KC_A)
#define HRM_S    LALT_T(KC_S)
#define HRM_D    LSFT_T(KC_D)
#define HRM_F    LCTL_T(KC_F)

#define HRM_J    RCTL_T(KC_J)
#define HRM_K    RSFT_T(KC_K)
#define HRM_L    LALT_T(KC_L)
#define HRM_SCLN RGUI_T(KC_SCLN)

// Function declarations
void keyboard_post_init_user(void);
bool process_record_user(uint16_t keycode, keyrecord_t *record);

#ifdef ENCODE_ENABLE
void encoder_update_user(uint8_t index, bool clockwise);
#endif

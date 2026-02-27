// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "bosjah.h"

// Macros for layer-tap keys matching Vial export
#define LT_LOW_ENT  LT(L_LOWER, KC_ENT)   // LT2(KC_ENTER) in Vial
#define LT_RSE_SPC  LT(L_RAISE, KC_SPC)   // LT1(KC_SPACE) in Vial
#define MO_ADJUST   MO(L_ADJUST)

// Word navigation macros
#define M_WRDL  LCTL(KC_LEFT)   // Word left
#define M_WRDR  LCTL(KC_RIGHT)  // Word right

#define WRAPPER(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY (Layer 0)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    | CALC  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LT/Ent| / Bspc  /       \Enter \  |LT/Spc| RAlt |   -  |   =  |
 *            |      |      |      |LOWER |/       /         \      \ |RAISE |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[L_BASE] = WRAPPER(
    __BASE_6x4_L1_______________________,                        __BASE_6x4_R1_______________________,
    __BASE_6x4_L2_______________________,                        __BASE_6x4_R2_______________________,
    __BASE_6x4_L3_______________________,                        __BASE_6x4_R3_______________________,
    __BASE_6x4_L4_______________________, KC_MUTE,      KC_CALC, __BASE_6x4_R4_______________________,
        KC_LGUI, KC_LALT, KC_LCTL, LT_LOW_ENT, KC_BSPC, KC_ENT, LT_RSE_SPC, KC_RALT, KC_MINS, KC_EQL
),

/*
 * Eurkey Modifier - Overlay that adds FN_EU_ALTGR to thumb cluster
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      |  /      /       \      \  |      |EuAltG|      |      |
 *            |      |      |      |      | /      /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[L_MOD_EURKEY] = WRAPPER(
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,       _______, _______, FN_EU_ALTGR, _______, _______
),

/*
 * LOWER (Layer 1) - Numbers & Symbols
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ~   |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |  \   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |   {  |   [  |   (  |-------|    |-------|   )  |   ]  |   }  |   |  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      |  /      /       \      \  |ADJUST|      |      |      |
 *            |      |      |      |      | /      /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[L_LOWER] = WRAPPER(
    __F_KEYS_L__________________________,                                         __F_KEYS_R__________________________,
    KC_GRV,  __NUMBERS_L_________________________,                                __NUMBERS_R_________________________, KC_DEL,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
    _______, _______, _______, KC_LCBR, KC_LBRC, KC_LPRN, _______,       _______, KC_RPRN, KC_RBRC, KC_RCBR, KC_PIPE, _______, _______,
                      _______, _______, _______, _______, _______,       _______, MO_ADJUST, _______, _______, _______
),

/*
 * RAISE (Layer 2) - Navigation & F-keys
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      | Home |  Up  | End  |      |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | GUI  | Alt  | Ctrl |Shift |      |-------.    ,-------|      | Left | Down | Right| PgUp |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |WrdLft|WrdRgt|      | PgDn |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |ADJUST|  /      /       \      \  |      |      |      |      |
 *            |      |      |      |      | /      /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[L_RAISE] = WRAPPER(
    __F_KEYS_L__________________________,                                                             __F_KEYS_R__________________________,
    _______, _______,      _______,      _______,      _______,      _______,                         _______, KC_HOME, KC_UP,   KC_END,  _______, KC_DEL,
    _______, OSM(MOD_LGUI),OSM(MOD_LALT),OSM(MOD_LCTL),OSM(MOD_LSFT),_______,                         _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, _______,
    _______, KC_UNDO,      KC_CUT,       KC_COPY,      KC_PASTE,     _______,   _______,     _______, _______, M_WRDL,  M_WRDR, _______,  KC_PGDN, _______,
                           _______,      _______,      _______,      MO_ADJUST, _______,     _______, _______, _______, _______, _______
),

/*
 * EURKEY ALTGR - Unicode Characters
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  ¡   |  ª   |  º   |  £   |  €   |                    |      |      |  „   |  "   |  "   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  æ   |  å   |  ë   |  ý   |  þ   |                    |  ÿ   |  ü   |  ï   |  ö   |  œ   |  «   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  ä   |  ß   |  đ   |  è   |  é   |-------.    ,-------|  ù   |  ú   |  ĳ   |  ø   |  °   |  »   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  à   |  á   |  ç   |  ì   |  í   |-------|    |-------|  ñ   |  μ   |  ò   |  ó   |  ¿   |  ¬   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      |  /      /       \      \  |      |      |      |      |
 *            |      |      |      |      | /      /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[L_EURKEY_ALTGR] = WRAPPER(
    __EURKEY_6x4_L1_____________________,                         __EURKEY_6x4_R1_____________________,
    __EURKEY_6x4_L2_____________________,                         __EURKEY_6x4_R2_____________________,
    __EURKEY_6x4_L3_____________________,                         __EURKEY_6x4_R3_____________________,
    __EURKEY_6x4_L4_____________________, _______,       _______, __EURKEY_6x4_R4_____________________,
      _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),

/*
 * ADJUST (Layer 3) - System
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      | ISO  |      |Eurkey|      |      |                    |      |      |      |      |      | BOOT |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      |  /      /       \      \  |      |      |      |      |
 *            |      |      |      |      | /      /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[L_ADJUST] = WRAPPER(
    XXXXXXX, XXXXXXX, XXXXXXX, FN_EURKEY, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
    XXXXXXX, XXXXXXX, UC_WINC, XXXXXXX, RM_TOGG, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, DB_TOGG, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, UC_LINX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,       XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
)
};



#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    // Left encoder: Volume control
    // Right encoder: Scroll wheel
    [L_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [L_MOD_EURKEY] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [L_LOWER]  = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [L_RAISE]  = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [L_EURKEY_ALTGR] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [L_ADJUST] = { ENCODER_CCW_CW(RM_PREV, RM_NEXT), ENCODER_CCW_CW(RM_HUEU, RM_HUED) },
};
#endif

// #ifdef RGB_MATRIX_ENABLE
// // Indicator LEDs (flags: 8) are index 0 (left) and 36 (right)
// #define INDICATOR_LED_LEFT  0
// #define INDICATOR_LED_RIGHT 36

// bool rgb_matrix_indicators_user(void) {
//     switch (get_highest_layer(layer_state)) {
//         case L_LOWER:
//             // Blue for Lower (symbols/numbers)
//             rgb_matrix_set_color(INDICATOR_LED_LEFT,  RGB_BLUE);
//             rgb_matrix_set_color(INDICATOR_LED_RIGHT, RGB_BLUE);
//             break;
//         case L_RAISE:
//             // Green for Raise (navigation)
//             rgb_matrix_set_color(INDICATOR_LED_LEFT,  RGB_GREEN);
//             rgb_matrix_set_color(INDICATOR_LED_RIGHT, RGB_GREEN);
//             break;
//         case L_EURKEY_ALTGR:
//             // Yellow for EurKey AltGr
//             rgb_matrix_set_color(INDICATOR_LED_LEFT,  RGB_YELLOW);
//             rgb_matrix_set_color(INDICATOR_LED_RIGHT, RGB_YELLOW);
//             break;
//         case L_ADJUST:
//             // Red for Adjust (system)
//             rgb_matrix_set_color(INDICATOR_LED_LEFT,  RGB_RED);
//             rgb_matrix_set_color(INDICATOR_LED_RIGHT, RGB_RED);
//             break;
//         default:
//             break;
//     }
//     return false;
// }
// #endif

#ifdef OLED_ENABLE
#include "oled_bitmaps.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

static void render_icon(uint8_t col, uint8_t line, const char *data, uint8_t width, uint8_t pages) {
    for (uint8_t p = 0; p < pages; p++) {
        oled_set_cursor(col, line + p);
        oled_write_raw_P(data + p * width, width);
    }
}

// Render a modifier letter: shown when active, blank when inactive
static void render_mod_letter(uint8_t page, const char *data, bool active) {
    static const char PROGMEM blank[MOD_LETTER_W] = {0};
    for (uint8_t p = 0; p < MOD_LETTER_PAGES; p++) {
        oled_set_cursor(0, page + p);
        if (active) {
            oled_write_raw_P(data + p * MOD_LETTER_W, MOD_LETTER_W);
        } else {
            oled_write_raw_P(blank, MOD_LETTER_W);
        }
    }
}

// Left OLED (master, 32x128 vertical): modifier letters or adjust info
static void render_left(void) {
    static bool was_adjust = false;
    uint8_t layer = get_highest_layer(layer_state);
    bool is_adjust = (layer == L_ADJUST);

    if (is_adjust != was_adjust) {
        oled_clear();
        was_adjust = is_adjust;
    }

    if (is_adjust) {
        // Adjust screen: show base layer info
        oled_set_cursor(0, 0);
        oled_write_ln_P(PSTR(""), false);
        oled_set_cursor(0, 3);
        oled_write_ln_P(PSTR("Base:"), false);
        oled_set_cursor(0, 5);
        switch (get_highest_layer(default_layer_state)) {
            case L_BASE:
                oled_write_ln_P(PSTR("QWRTY"), false);
                break;
            default:
                oled_write_ln_P(PSTR("?"), false);
        }
        oled_set_cursor(0, 8);
        oled_write_ln_P(PSTR("ADJST"), false);
        return;
    }

    // Default: 4 modifier letters stacked (C, A, S, G), 32x32 each = 128px
    uint8_t mods = get_mods() | get_oneshot_mods();

    static const struct {
        uint8_t      mask;
        const char  *icon;
    } mod_letters[] = {
        { MOD_MASK_CTRL,  mod_letter_c },
        { MOD_MASK_ALT,   mod_letter_a },
        { MOD_MASK_SHIFT, mod_letter_s },
        { MOD_MASK_GUI,   mod_letter_g },
    };

    for (uint8_t i = 0; i < 4; i++) {
        render_mod_letter(i * MOD_LETTER_PAGES, mod_letters[i].icon,
                          (mods & mod_letters[i].mask) != 0);
    }
}

// Right OLED (slave, 32x128 vertical): big layer indicator
static void render_right(void) {
    static uint8_t prev_layer = 255;
    uint8_t layer = get_highest_layer(layer_state);

    if (layer != prev_layer) {
        oled_clear();
        prev_layer = layer;
    }

    const char *glyph = NULL;
    const char *label = NULL;

    switch (layer) {
        case L_LOWER:
            glyph = big_layer_L;
            label = PSTR("Lower");
            break;
        case L_RAISE:
            glyph = big_layer_R;
            label = PSTR("Raise");
            break;
        case L_ADJUST:
            glyph = big_layer_A;
            label = PSTR("Adjst");
            break;
        case L_GAME:
            glyph = big_layer_G;
            label = PSTR(" Game");
            break;
        case L_EURKEY_ALTGR:
            glyph = big_layer_E;
            label = PSTR("EurKy");
            break;
#ifdef HOME_ROW_MODS_ENABLE
        case L_HRM_TRAINING:
            glyph = big_layer_H;
            label = PSTR(" HRM ");
            break;
#endif
        default:
            return; // Base layers: stay blank
    }

    // Big glyph centered vertically (pages 5-10 of 0-15, 48px = 6 pages)
    render_icon(0, 5, glyph, BIG_LAYER_W, BIG_LAYER_H / 8);

    // Text label near top
    oled_set_cursor(0, 12);
    oled_write_P(label, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_left();
    } else {
        render_right();
    }
    return false;
}
#endif

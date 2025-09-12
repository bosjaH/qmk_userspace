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

// Unicode Map
enum unicode_names {
    // Row 1 (numbers) - AltGr and Shift+AltGr
    EXCL, SUP1,  // ¡ and ¹
    ORDF, SUP2,  // ª and ²
    ORDM, SUP3,  // º and ³
    POUN, YEN,   // £ and ¥
    EURO, CENT,  // € and ¢
    LDQU, LSQU,  // „ and ‚
    LDQU2, LSQU2, // " and '
    RDQU, RSQU,  // " and '
    CHKM, CHKX,  // ✓ and ✗
    MULT, DIVI,  // × and ÷

    // Row 2 (QWERTY) - AltGr and Shift+AltGr
    AE, CAE,     // æ and Æ
    ARING, CARING, // å and Å
    EDIA, CEDIA, // ë and Ë
    YACU, CYACU, // ý and Ý
    THRN, CTHRN, // þ and Þ
    YDIA, CYDIA, // ÿ and Ÿ
    UDIA, CUDIA, // ü and Ü
    IDIA, CIDIA, // ï and Ï
    ODIA, CODIA, // ö and Ö
    OE, COE,     // œ and Œ
    LAQUO, LSAQUO, // « and ‹
    RAQUO, RSAQUO, // » and ›
    NOT, PIPE2,  // ¬ and ¦

    // Row 3 (ASDF) - AltGr and Shift+AltGr
    ADIA, CADIA, // ä and Ä
    SSHP, CSSHP, // ß and ẞ
    DSTR, CDSTR, // đ and Đ
    EGRA, CEGRA, // è and È
    EACU, CEACU, // é and É
    UGRA, CUGRA, // ù and Ù
    UACU, CUACU, // ú and Ú
    FIKR, CFIKR, // ĳ and Ĳ
    OSTR, COSTR, // ø and Ø
    DEG, MIDDOT, // ° and ·

    // Row 4 (ZXCV) - AltGr and Shift+AltGr
    AGRA, CAGRA, // à and À
    AACU, CAACU, // á and Á
    CCED, CCCED, // ç and Ç
    IGRA, CIGRA, // ì and Ì
    IACU, CIACU, // í and Í
    NTIL, CNTIL, // ñ and Ñ
    MU, INFIN,   // μ and ∞
    OGRA, COGRA, // ò and Ò
    OACU, COACU, // ó and Ó
    IQUE, ELLIP, // ¿ and …
};

const uint32_t unicode_map[] PROGMEM = {
    // Row 1 (numbers)
    [EXCL] = 0x00A1,  [SUP1] = 0x00B9,   // ¡ ¹
    [ORDF] = 0x00AA,  [SUP2] = 0x00B2,   // ª ²
    [ORDM] = 0x00BA,  [SUP3] = 0x00B3,   // º ³
    [POUN] = 0x00A3,  [YEN] = 0x00A5,    // £ ¥
    [EURO] = 0x20AC,  [CENT] = 0x00A2,   // € ¢
    [LDQU] = 0x201E,  [LSQU] = 0x201A,   // „ ‚
    [LDQU2] = 0x201C, [LSQU2] = 0x2018,  // " '
    [RDQU] = 0x201D,  [RSQU] = 0x2019,   // " '
    [CHKM] = 0x2713,  [CHKX] = 0x2717,   // ✓ ✗
    [MULT] = 0x00D7,  [DIVI] = 0x00F7,   // × ÷

    // Row 2 (QWERTY)
    [AE] = 0x00E6,    [CAE] = 0x00C6,    // æ Æ
    [ARING] = 0x00E5, [CARING] = 0x00C5, // å Å
    [EDIA] = 0x00EB,  [CEDIA] = 0x00CB,  // ë Ë
    [YACU] = 0x00FD,  [CYACU] = 0x00DD,  // ý Ý
    [THRN] = 0x00FE,  [CTHRN] = 0x00DE,  // þ Þ
    [YDIA] = 0x00FF,  [CYDIA] = 0x0178,  // ÿ Ÿ
    [UDIA] = 0x00FC,  [CUDIA] = 0x00DC,  // ü Ü
    [IDIA] = 0x00EF,  [CIDIA] = 0x00CF,  // ï Ï
    [ODIA] = 0x00F6,  [CODIA] = 0x00D6,  // ö Ö
    [OE] = 0x0153,    [COE] = 0x0152,    // œ Œ
    [LAQUO] = 0x00AB, [LSAQUO] = 0x2039, // « ‹
    [RAQUO] = 0x00BB, [RSAQUO] = 0x203A, // » ›
    [NOT] = 0x00AC,   [PIPE2] = 0x00A6,  // ¬ ¦

    // Row 3 (ASDF)
    [ADIA] = 0x00E4,  [CADIA] = 0x00C4,  // ä Ä
    [SSHP] = 0x00DF,  [CSSHP] = 0x1E9E,  // ß ẞ
    [DSTR] = 0x0111,  [CDSTR] = 0x0110,  // đ Đ
    [EGRA] = 0x00E8,  [CEGRA] = 0x00C8,  // è È
    [EACU] = 0x00E9,  [CEACU] = 0x00C9,  // é É
    [UGRA] = 0x00F9,  [CUGRA] = 0x00D9,  // ù Ù
    [UACU] = 0x00FA,  [CUACU] = 0x00DA,  // ú Ú
    [FIKR] = 0x0133,  [CFIKR] = 0x0132,  // ĳ Ĳ
    [OSTR] = 0x00F8,  [COSTR] = 0x00D8,  // ø Ø
    [DEG] = 0x00B0,   [MIDDOT] = 0x00B7, // ° ·

    // Row 4 (ZXCV)
    [AGRA] = 0x00E0,  [CAGRA] = 0x00C0,  // à À
    [AACU] = 0x00E1,  [CAACU] = 0x00C1,  // á Á
    [CCED] = 0x00E7,  [CCCED] = 0x00C7,  // ç Ç
    [IGRA] = 0x00EC,  [CIGRA] = 0x00CC,  // ì Ì
    [IACU] = 0x00ED,  [CIACU] = 0x00CD,  // í Í
    [NTIL] = 0x00F1,  [CNTIL] = 0x00D1,  // ñ Ñ
    [MU] = 0x03BC,    [INFIN] = 0x221E,  // μ ∞
    [OGRA] = 0x00F2,  [COGRA] = 0x00D2,  // ò Ò
    [OACU] = 0x00F3,  [COACU] = 0x00D3,  // ó Ó
    [IQUE] = 0x00BF,  [ELLIP] = 0x2026,  // ¿ …
};

// Layers
enum __layers {
    L_DEFAULT,
    L_DEFAULT_ANSI,
    L_DEFAULT_EURKEY,
    L_GAME,
    L_EURKEY_ALTGR,
    L_SPACE_FN,
    L_EXTENDED,
    L_EXTENDED_LOCK,
    L_CONFIG
};// Keycodes
enum __custom_keycodes {
    C_LCKEXT = SAFE_RANGE,
    C_CLSEXT,
    C_AACUTE,
    C_AGRAVE,
    C_TILDE,
    C_M_DEV,
    C_EURO
};

// Initialize keyboard with better Unicode input mode for Windows
// void keyboard_post_init_user(void) {
//     // Set Unicode input mode to Windows Unicode
//     // Mode 1 = UC_WIN (Windows Alt+U method)
//     set_unicode_input_mode(1);
// }

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define XXXXXXX KC_NO

// Macros
#define M_PIPE  RALT(KC_1)           // |
#define M_AT    RALT(KC_2)           // @
#define M_HASH  RALT(KC_3)           // #
#define M_LCBR  RALT(KC_9)           // {
#define M_RCBR  RALT(KC_0)           // }
#define M_BSLS  RALT(KC_NUBS)        // Backslash
#define M_LBRC  RALT(KC_LBRC)        // [
#define M_RBRC  RALT(KC_RBRC)        // ]
#define M_LT    KC_NUBS              // <
#define M_GT    LSFT(KC_NUBS)        // >
#define M_WRDL  LCTL(KC_LEFT)        // Word left
#define M_WRDR  LCTL(KC_RIGHT)       // Word right
#define M_VDL   LCTL(LGUI(KC_LEFT))  // Previous virtual desktop
#define M_VDR   LCTL(LGUI(KC_RIGHT)) // Next virtual desktop
#define M_TM    LCTL(LSFT(KC_ESC))   // Task manager

// Layer switching
#define FN_SPACE_FN LT(L_SPACE_FN, KC_SPC)
#define FN_EXT      LT(L_EXTENDED, KC_BSPC)
#define FN_GAME     TG(L_GAME)
#define FN_CONFIG   MO(L_CONFIG)
#define DL_ISO      DF(L_DEFAULT)
#define DL_ANSI     DF(L_DEFAULT_ANSI)
#define DL_EURKEY   DF(L_DEFAULT_EURKEY)
#define FN_EURKEY_ALTGR MO(L_EURKEY_ALTGR)

// Unicode characters for Eurkey AltGr layer using Unicode Map
// Row 1 (numbers)
#define EU_EXCL UP(EXCL, SUP1)      // ¡ on 1, ¹ on shift
#define EU_ORDF UP(ORDF, SUP2)      // ª on 2, ² on shift
#define EU_ORDM UP(ORDM, SUP3)      // º on 3, ³ on shift
#define EU_POUN UP(POUN, YEN)       // £ on 4, ¥ on shift
#define EU_EURO UP(EURO, CENT)      // € on 5, ¢ on shift
// 6 and 7 are dead keys - skipping for now
#define EU_LDQU UP(LDQU, LSQU)      // „ on 8, ‚ on shift
#define EU_LDQU2 UP(LDQU2, LSQU2)   // " on 9, ' on shift
#define EU_RDQU UP(RDQU, RSQU)      // " on 0, ' on shift
#define EU_CHKM UP(CHKM, CHKX)      // ✓ on -, ✗ on shift
#define EU_MULT UP(MULT, DIVI)      // × on =, ÷ on shift

// Row 2 (QWERTY)
#define EU_AE   UP(AE, CAE)         // æ on Q, Æ on shift
#define EU_ARING UP(ARING, CARING)  // å on W, Å on shift
#define EU_EDIA UP(EDIA, CEDIA)     // ë on E, Ë on shift
#define EU_YACU UP(YACU, CYACU)     // ý on R, Ý on shift
#define EU_THRN UP(THRN, CTHRN)     // þ on T, Þ on shift
#define EU_YDIA UP(YDIA, CYDIA)     // ÿ on Y, Ÿ on shift
#define EU_UDIA UP(UDIA, CUDIA)     // ü on U, Ü on shift
#define EU_IDIA UP(IDIA, CIDIA)     // ï on I, Ï on shift
#define EU_ODIA UP(ODIA, CODIA)     // ö on O, Ö on shift
#define EU_OE   UP(OE, COE)         // œ on P, Œ on shift
#define EU_LAQUO UP(LAQUO, LSAQUO)  // « on [, ‹ on shift
#define EU_RAQUO UP(RAQUO, RSAQUO)  // » on ], › on shift
#define EU_NOT  UP(NOT, PIPE2)      // ¬ on backslash, ¦ on shift

// Row 3 (ASDF)
#define EU_ADIA UP(ADIA, CADIA)     // ä on A, Ä on shift
#define EU_SSHP UP(SSHP, CSSHP)     // ß on S, ẞ on shift
#define EU_DSTR UP(DSTR, CDSTR)     // đ on D, Đ on shift
#define EU_EGRA UP(EGRA, CEGRA)     // è on F, È on shift
#define EU_EACU UP(EACU, CEACU)     // é on G, É on shift
#define EU_UGRA UP(UGRA, CUGRA)     // ù on H, Ù on shift
#define EU_UACU UP(UACU, CUACU)     // ú on J, Ú on shift
#define EU_FIKR UP(FIKR, CFIKR)     // ĳ on K, Ĳ on shift
#define EU_OSTR UP(OSTR, COSTR)     // ø on L, Ø on shift
#define EU_DEG  UP(DEG, MIDDOT)     // ° on ;, · on shift
// ' is a dead key - skipping for now

// Row 4 (ZXCV)
#define EU_AGRA UP(AGRA, CAGRA)     // à on Z, À on shift
#define EU_AACU UP(AACU, CAACU)     // á on X, Á on shift
#define EU_CCED UP(CCED, CCCED)     // ç on C, Ç on shift
#define EU_IGRA UP(IGRA, CIGRA)     // ì on V, Ì on shift
#define EU_IACU UP(IACU, CIACU)     // í on B, Í on shift
#define EU_NTIL UP(NTIL, CNTIL)     // ñ on N, Ñ on shift
#define EU_MU   UP(MU, INFIN)       // μ on M, ∞ on shift
#define EU_OGRA UP(OGRA, COGRA)     // ò on comma, Ò on shift
#define EU_OACU UP(OACU, COACU)     // ó on period, Ó on shift
#define EU_IQUE UP(IQUE, ELLIP)     // ¿ on slash, … on shift

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [L_DEFAULT_ANSI] = LAYOUT_ansi( /* Base */
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_INS,           KC_MUTE,
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS,          KC_PGUP,
        FN_EXT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,           KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                   FN_SPACE_FN,                        KC_RALT, KC_RGUI, KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT),

    [L_DEFAULT] = LAYOUT_ansi( /* Base */
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_INS,           KC_MUTE,
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_NUBS,          KC_PGUP,
        FN_EXT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,           KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                   FN_SPACE_FN,                        KC_RALT, KC_RGUI, KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT),

    [L_DEFAULT_EURKEY] = LAYOUT_ansi( /* Eurkey Base */
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_F13,           KC_MUTE,
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_NUBS,          KC_PGUP,
        FN_EXT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,           KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                   FN_SPACE_FN,                        FN_EURKEY_ALTGR, KC_RGUI, KC_RCTL,   KC_LEFT, KC_DOWN, KC_RGHT),

    [L_GAME] = LAYOUT_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, XXXXXXX, _______,                   KC_SPC,                             _______, _______, _______,          _______, _______, _______),

    [L_SPACE_FN] = LAYOUT_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,           _______,
        _______, M_PIPE,  M_AT,    M_HASH,  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,           _______,
        _______, _______, _______, C_EURO,  _______, KC_BTN4, KC_BTN5, KC_HOME, KC_UP,   KC_END,  _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, C_AACUTE, C_AGRAVE,        _______,          _______,
        _______,          _______, _______, KC_SPC,  KC_SPC,  KC_SPC,  KC_PGDN, M_WRDL,  M_WRDR,  _______, C_TILDE,          _______, _______, _______,
        _______, _______, _______,                   _______,                            _______, _______, _______,          _______, _______, _______),

    [L_EXTENDED] = LAYOUT_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, C_M_DEV,          RM_TOGG,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          RM_HUEU,
        C_LCKEXT,KC_BTN4, KC_WH_U, KC_BTN5, _______, M_TM,    KC_CALC, KC_HOME, KC_UP,   KC_END,  _______, _______, _______, _______,          RM_HUED,
        _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______, KC_PGUP, KC_LEFT, KC_DOWN, KC_RIGHT,_______, KC_NUHS,          FN_CONFIG,        RM_SATU,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, RM_VALU, RM_SATD,
        _______, _______, _______,                   _______,                            _______, _______, _______,          RM_SPDD, RM_VALD, RM_SPDU),

    [L_EXTENDED_LOCK] = LAYOUT_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        KC_TAB,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        C_CLSEXT,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_ENT,           _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                   _______,                            _______, _______, _______,          _______, _______, _______),

    [L_CONFIG] = LAYOUT_ansi(
        FN_GAME, DL_ISO,  DL_ANSI, DL_EURKEY,_______,_______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, UC_WINC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, DB_TOGG, _______, _______, _______, _______, _______, _______, UC_LINX, _______, _______,          FN_CONFIG,        _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                   _______,                            _______, _______, _______,          _______, _______, _______),

    [L_EURKEY_ALTGR] = LAYOUT_ansi( /* Eurkey AltGr Layer */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, EU_EXCL, EU_ORDF, EU_ORDM, EU_POUN, EU_EURO, _______, _______, EU_LDQU, EU_LDQU2,EU_RDQU, EU_CHKM, EU_MULT, _______,          _______,
        _______, EU_AE,   EU_ARING,EU_EDIA, EU_YACU, EU_THRN, EU_YDIA, EU_UDIA, EU_IDIA, EU_ODIA, EU_OE,   EU_LAQUO,EU_RAQUO, EU_NOT,          _______,
        _______, EU_ADIA, EU_SSHP, EU_DSTR, EU_EGRA, EU_EACU, EU_UGRA, EU_UACU, EU_FIKR, EU_OSTR, EU_DEG,  _______,          _______,          _______,
        _______,          EU_AGRA, EU_AACU, EU_CCED, EU_IGRA, EU_IACU, EU_NTIL, EU_MU,   EU_OGRA, EU_OACU, EU_IQUE,          _______, _______, _______,
        _______, _______, _______,                   _______,                            _______, _______, _______,          _______, _______, _______),
};


// clang-format off
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [L_DEFAULT_ANSI] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [L_DEFAULT] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [L_GAME] = { ENCODER_CCW_CW(_______, _______) },
    [L_SPACE_FN] = { ENCODER_CCW_CW(_______, _______) },
    [L_EXTENDED] = { ENCODER_CCW_CW(RM_PREV, RM_NEXT) },
    [L_EXTENDED_LOCK] = { ENCODER_CCW_CW(_______, _______) },
    [L_CONFIG] = { ENCODER_CCW_CW(_______, _______) },
    [L_DEFAULT_EURKEY] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [L_EURKEY_ALTGR] = { ENCODER_CCW_CW(_______, _______) },
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case C_LCKEXT:
      if (record->event.pressed) {
        layer_on(L_EXTENDED_LOCK);
      }
      return false;
    case C_CLSEXT:
      if (record->event.pressed) {
        layer_off(L_EXTENDED_LOCK);
        layer_off(L_EXTENDED);
      }
      return false;
    case C_AACUTE:
      if (record->event.pressed) {
        // Check which base layer is active and send appropriate sequence
        if (IS_LAYER_ON(L_DEFAULT)) {
          // Belgian AZERTY layout - use dead key combination
          SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_QUOTE))));
          SEND_STRING(SS_TAP(X_SPACE));
        } else {
          // US QWERTY or Eurkey - send Unicode directly
          register_unicode(unicode_map[AACU]);
        }
      }
      return false;
    case C_AGRAVE:
      if (record->event.pressed) {
        // Check which base layer is active and send appropriate sequence
        if (IS_LAYER_ON(L_DEFAULT)) {
          // Belgian AZERTY layout - use dead key combination
          SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_BACKSLASH))));
          SEND_STRING(SS_TAP(X_SPACE));
        } else {
          // US QWERTY or Eurkey - send Unicode directly
          register_unicode(unicode_map[AGRA]);
        }
      }
      return false;
    case C_TILDE:
      if (record->event.pressed) {
        // Check which base layer is active and send appropriate sequence
        if (IS_LAYER_ON(L_DEFAULT)) {
          // Belgian AZERTY layout - use dead key combination
          SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_SLASH))));
          SEND_STRING(SS_TAP(X_SPACE));
        } else {
          // US QWERTY or Eurkey - send tilde directly
          SEND_STRING("~");
        }
      }
      return false;
    case C_EURO:
      if (record->event.pressed) {
        // Check which base layer is active and send appropriate sequence
        if (IS_LAYER_ON(L_DEFAULT)) {
          // Belgian AZERTY layout - use AltGr+E
          SEND_STRING(SS_RALT("e"));
        } else {
          // US QWERTY or Eurkey - send Unicode directly
          register_unicode(unicode_map[EURO]);
        }
      }
      return false;
    case C_M_DEV:
        if (record->event.pressed) {
            SEND_STRING_DELAY("Npiuk", 50);
            // SEND_STRING_DELAY(SS_LSFT(X_2), 50);
            SEND_STRING_DELAY("USirpazoieurpoghmglhqgfmb\n", 50);

            SEND_STRING_DELAY("Npiuk", 0);
            // SEND_STRING_DELAY(SS_LSFT(X_2), 0);
            SEND_STRING_DELAY("USirpazoieurpoghmglhqgfmb\n", 0);
        }
        return false;
    default:
      return true;
  }
}

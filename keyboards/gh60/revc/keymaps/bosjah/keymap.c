#include QMK_KEYBOARD_H
#include "action_code.h"
#include "action_layer.h"

// Layers
enum layer_id {
    L_DEFAULT,
    L_DEFAULT_ANSI,
    L_GAME,
    L_SPACE_FN,
    L_EXTENDED,
    L_EXTENDED_LOCK,
    L_CONFIG
};

// Keycodes
enum custom_keycodes {
    C_LCKEXT = SAFE_RANGE,
    C_CLSEXT,
    C_AACUTE,
    C_AGRAVE,
    C_TILDE
};

// Fillers to make layering clearer
#define ______ KC_TRNS
#define XXXXXX KC_NO

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
#define M_EUR   RALT(KC_E)           // Euro sign

// Layer switching
#define FN_SPACE_FN LT(L_SPACE_FN, KC_SPC)
#define FN_EXT      LT(L_EXTENDED, KC_GRV)
#define FN_GAME     TG(L_GAME)
#define FN_CONFIG   MO(L_CONFIG)
#define DL_ISO      DF(L_DEFAULT)
#define DL_ANSI     DF(L_DEFAULT_ANSI)


// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Default Layer (using ISO backslash)
     * Keymap 1: Default Layer (using ANSI backslash)
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backspc|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
     * |-----------------------------------------------------------|
     * |ExtFN |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return|
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|     Shift|
     * |-----------------------------------------------------------|
     * |Ctrl|Gui |Alt |        SpaceFN         |Alt |Gui |App |Ctrl|
     * `-----------------------------------------------------------'
     */
   /* Qwerty
    * ,-----------------------------------------------------------------------------------------.
    * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
    * |-----------------------------------------------------------------------------------------|
    * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  Bksp  |
    * |-----------------------------------------------------------------------------------------|
    * | Caps/FN1|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
    * |-----------------------------------------------------------------------------------------|
    * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |     Up    | FN2 |
    * |-----------------------------------------------------------------------------------------|
    * | Ctrl  | Gui   | Alt   |               Space             | AltGr | Left  | Down  | Right |
    * `-----------------------------------------------------------------------------------------'
    */
  [L_DEFAULT] = LAYOUT_60_ansi(
        KC_ESC,   KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,     KC_7,    KC_8,  KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  \
        KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,    KC_I,  KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_NUBS,  \
        FN_EXT,   KC_A,     KC_S,     KC_D,    KC_F,     KC_G,     KC_H,     KC_J,    KC_K,  KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   \
        KC_LSFT,  KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,     KC_N,     KC_M,  KC_COMM, KC_DOT,   KC_SLSH,                      KC_RSFT,  \
        KC_LCTL,  KC_LGUI,  KC_LALT,                            FN_SPACE_FN,                           KC_RALT,  KC_RGUI,  KC_APP,   KC_RCTL   \
    ),
  [L_DEFAULT_ANSI] = LAYOUT_60_ansi(
        KC_ESC,   KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,     KC_7,    KC_8,  KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  \
        KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,    KC_I,  KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  \
        FN_EXT,   KC_A,     KC_S,     KC_D,    KC_F,     KC_G,     KC_H,     KC_J,    KC_K,  KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   \
        KC_LSFT,  KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,     KC_N,     KC_M,  KC_COMM, KC_DOT,   KC_SLSH,                      KC_RSFT,  \
        KC_LCTL,  KC_LGUI,  KC_LALT,                            FN_SPACE_FN,                           KC_RALT,  KC_RGUI,  KC_APP,   KC_RCTL   \
    ),

	/* Overlay: Game Layer (disable left win and SpaceFN)
     * ,-----------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |Backspc|
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |          |
     * |-----------------------------------------------------------|
     * |    | NO |    |         Space          |    |    |NpFN|    |
     * `-----------------------------------------------------------'
     */
  [L_GAME] = LAYOUT_60_ansi(
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   KC_BSPC, \
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,  \
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,  \
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,                       ______,  \
        ______,   XXXXXX,   ______,                       KC_SPC,                                           ______,   ______,   ______,   ______   \
    ),

    /* Overlay: SpaceFN Layer
     * ,-----------------------------------------------------------.
     * |   |  ||  @|  #|   |   |   |   |   |  {|  }|   |   | Delete|
     * |-----------------------------------------------------------|
     * |     |   |   | € |   |Mb4|Mb5|Hom|Up |End|   |  [|  ]|    \|
     * |-----------------------------------------------------------|
     * |CAPS  |   |   |VDL|VDR|   |PgU|Lef|Dow|Rig|  ´|  `|        |
     * |-----------------------------------------------------------|
     * |        |   |   |Spc|Spc|Spc|PgD|WLe|WRi|   |  ~|          |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |    |    |    |
     * `-----------------------------------------------------------'
     * Br: Browser (forward/back)
     */
  [L_SPACE_FN] = LAYOUT_60_ansi(
        ______,   M_PIPE,   M_AT,     M_HASH,   ______,   ______,   ______,   ______,   ______,   M_LCBR,   M_RCBR,   ______,   ______,   KC_DEL, \
        ______,   ______,   ______,   M_EUR,    ______,   KC_BTN4,  KC_BTN5,  KC_HOME,  KC_UP,    KC_END,   ______,   M_LBRC,   M_RBRC,   M_BSLS, \
        KC_CAPS,  ______,   ______,   M_VDL,    M_VDR,    ______,   KC_PGUP,  KC_LEFT,  KC_DOWN,  KC_RIGHT, C_AACUTE, C_AGRAVE,           ______, \
        ______,   ______,   ______,   KC_SPC,   KC_SPC,   KC_SPC,   KC_PGDN,  M_WRDL,   M_WRDR,   ______,   C_TILDE,                      ______, \
        ______,   ______,   ______,                       ______,                                           ______,   ______,   ______,   ______ \
    ),

    /* Overlay: Extended Function Layer
     * ,-----------------------------------------------------------.
     * |  `| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12| Delete|
     * |-----------------------------------------------------------|
     * |Lock |Mb4|WhU|Mb5|   | Tm|Clc|Hom|Up |End|   |Psc|Pau|  Ins|
     * |-----------------------------------------------------------|
     * |      |WhL|WhD|WhR|   |   |PgU|Lef|Dow|Rig|  '|  \|ConfigFN|
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |PgD|   |VDn|VUp|VMt|          |
     * |-----------------------------------------------------------|
     * |    |    |    |         Space          |    |    |NpFN|    |
     * `-----------------------------------------------------------'
     * Mb: Mouse Button
     * Wh: Mouse Wheel
     * Clc: Calculator
     * Tm: Task Manager
     */
  [L_EXTENDED] = LAYOUT_60_ansi(
        KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL, \
        C_LCKEXT, KC_BTN4,  KC_WH_U,  KC_BTN5,  ______,   M_TM,     KC_CALC,  KC_HOME,  KC_UP,    KC_END,   ______,   KC_PSCR,  KC_PAUSE, KC_INS, \
        ______,   KC_WH_L,  KC_WH_D,  KC_WH_R,  ______,   ______,   KC_PGUP,  KC_LEFT,  KC_DOWN,  KC_RIGHT, ______,   KC_NUHS,         FN_CONFIG, \
        ______,   ______,   ______,   ______,   ______,   ______,   KC_PGDN,  ______,   KC_VOLD,  KC_VOLU,  KC_MUTE,                      ______, \
        ______,   ______,   ______,                       ______,                                           ______,   ______,   ______,   ______  \
  ),

    /* Overlay: Extended Locking Layer
     * ,-----------------------------------------------------------.
     * |Esc|   |   |   |   |   |   |   |   |   |   |   |   |       |
     * |-----------------------------------------------------------|
     * |Tab  |   |   |   |   |   |   |   |   |   |   |   |   |     |
     * |-----------------------------------------------------------|
     * |Unlock|   |   |   |   |   |   |   |   |   |   |   |   Enter|
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |          |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |Gui |App |    |
     * `-----------------------------------------------------------'
     */
  [L_EXTENDED_LOCK] = LAYOUT_60_ansi(
        KC_ESC,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______, \
        KC_TAB,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______, \
        C_CLSEXT, ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,             KC_ENT, \
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,                       ______, \
        ______,   ______,   ______,                       ______,                                           ______,   KC_RGUI,  ______,   ______  \
  ),

    /* Overlay: Layout selection layer
     * ,-----------------------------------------------------------.
     * |   |ISO|ANS|   |   |   |   |   |   |   |   |   |   |BootLdr|
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |Gm |   |   |   |   |   |   |ConfigFN|
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |          |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |    |    |    |
     * `-----------------------------------------------------------'
     * Gm: Game
     */
  [L_CONFIG] = LAYOUT_60_ansi(
        ______,   DL_ISO,   DL_ANSI,  ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,  QK_BOOT,  \
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______, \
        ______,   ______,   ______,   ______,   ______,   FN_GAME,  ______,   ______,   ______,   ______,   ______,   ______,          FN_CONFIG, \
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,                       ______, \
        ______,   ______,   ______,                       ______,                                           ______,   ______,   ______,   ______ \
  )
};

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
        SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_QUOTE))));
        SEND_STRING(SS_TAP(X_SPACE));
      }
      return false;
    case C_AGRAVE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_BACKSLASH))));
        SEND_STRING(SS_TAP(X_SPACE));
      }
      return false;
    case C_TILDE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_SLASH))));
        SEND_STRING(SS_TAP(X_SPACE));
      }
      return false;
    default:
      return true;
  }
}

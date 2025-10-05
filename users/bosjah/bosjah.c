#include "bosjah.h"

// Initialize keyboard with better Unicode input mode for Windows
void keyboard_post_init_user(void) {
    // Set Unicode input mode to Windows Unicode
    set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case C_LCKEXT:
    //   if (record->event.pressed) {
    //     layer_on(L_EXTENDED_LOCK);
    //   }
    //   return false;
    // case C_CLSEXT:
    //   if (record->event.pressed) {
    //     layer_off(L_EXTENDED_LOCK);
    //     layer_off(L_EXTENDED);
    //   }
    //   return false;
    // case C_AACUTE:
    //   if (record->event.pressed) {
    //     SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_QUOTE))));
    //     SEND_STRING(SS_TAP(X_SPACE));
    //   }
    //   return false;
    // case C_AGRAVE:
    //   if (record->event.pressed) {
    //     SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_BACKSLASH))));
    //     SEND_STRING(SS_TAP(X_SPACE));
    //   }
    //   return false;
    // case C_TILDE:
    //   if (record->event.pressed) {
    //     SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_SLASH))));
    //     SEND_STRING(SS_TAP(X_SPACE));
    //   }
    //   return false;
    default:
      return true;
  }
}


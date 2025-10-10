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
    // case C_AACUTE:`
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

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGB_MATRIX_ENABLE
    // Static variable to track previous layer state
    static layer_state_t prev_state = 0;

    // Check if we're leaving the adjust layer
    bool was_adjust_active = (prev_state & (1UL << L_ADJUST)) != 0;
    bool is_adjust_active = (state & (1UL << L_ADJUST)) != 0;

    if (was_adjust_active && !is_adjust_active) {
        // We just left the adjust layer, trigger full RGB refresh like on startup
        rgb_matrix_init(); // This does the full initialization like on power-up
    }

    prev_state = state;
#endif
    return state;
}

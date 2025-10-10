#include <quantum.h>
#include <color.h>
#include "bosjah.h"

// Define base layer mask for efficient checking
#define BASE_LAYERS_MASK ((1UL << L_BASE) | (1UL << L_BASE_ANSI) | (1UL << L_BASE_EURKEY))

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
#ifdef RGB_MATRIX_ENABLE
    // Check if we're only on base layers (no other layers active)
    if ((layer_state & ~BASE_LAYERS_MASK) == 0) {
        return false;  // Only base layers active, no indicators needed
    }

    // Handle adjust layer with specific colors
    if (layer_state_is(L_ADJUST)) {
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED) {
                    // Get keycode from adjust layer first, then resolve transparency manually
                    keypos_t key = {col, row};
                    uint16_t keycode = keymap_key_to_keycode(L_ADJUST, key);

                    // If transparent on adjust layer, check lower layers
                    if (keycode == KC_TRNS) {
                        // Check each active layer from highest to lowest
                        for (int8_t layer = L_ADJUST; layer >= 0; layer--) {
                            if (layer_state_is(layer)) {
                                keycode = keymap_key_to_keycode(layer, key);
                                if (keycode != KC_TRNS) {
                                    break;
                                }
                            }
                        }
                    }

                    switch (keycode) {
                        case QK_BOOT:
                            rgb_matrix_set_color(index, RGB_RED);
                            break;
                        case DL_ISO:
                        case DL_ANSI:
                        case DL_EURKEY:
                            rgb_matrix_set_color(index, RGB_CYAN);
                            break;
                        case KC_NO:
                        case KC_TRNS:
                            rgb_matrix_set_color(index, RGB_OFF);
                            break;
                        default:
                            rgb_matrix_set_color(index, RGB_SPRINGGREEN);
                            break;
                    }
                }
            }
        }
    } else {
        // For other non-base layers: turn off KC_NO keys
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED) {
                    // Resolve keycode through all active layers manually
                    keypos_t key = {col, row};
                    uint16_t keycode = KC_TRNS;

                    // Check each active layer from highest to lowest
                    for (int8_t layer = L_ADJUST; layer >= 0; layer--) {
                        if (layer_state_is(layer)) {
                            keycode = keymap_key_to_keycode(layer, key);
                            if (keycode != KC_TRNS) {
                                break;
                            }
                        }
                    }

                    if (keycode == KC_NO) {
                        rgb_matrix_set_color(index, RGB_OFF);
                    }
                }
            }
        }
    }
#endif
    return false;  // Let other RGB indicators run
}

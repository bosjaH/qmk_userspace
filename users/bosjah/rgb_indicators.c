#include <quantum.h>
#include <color.h>
#include <string.h>
#include "bosjah.h"

#ifdef RGB_MATRIX_ENABLE

// Access the WS2812 LED buffer directly for reading current LED colors.
// This allows saving the animation state before overriding with indicators.
#ifdef RGB_MATRIX_WS2812
#include "ws2812.h"
extern ws2812_led_t ws2812_leds[];
#endif

// Define base layer mask for efficient checking
#define BASE_LAYERS_MASK ((1UL << L_BASE) | (1UL << L_BASE_ANSI) | (1UL << L_BASE_EURKEY))

//
// LED state save/restore for effects like jellybean raindrops that only
// update a few LEDs per frame. Without this, indicator colors linger
// after the layer is deactivated because the effect hasn't randomly
// picked those specific LEDs to update yet.
//
// How it works:
// - Before overriding an LED with an indicator color, save its current
//   animation color from the driver buffer.
// - Each frame, track which LEDs are actively overridden.
// - At the end of each frame (last chunk), restore any LEDs that were
//   previously overridden but are no longer needed (due to layer changes).
//
static rgb_t saved_led_state[RGB_MATRIX_LED_COUNT];
static bool  key_has_save[RGB_MATRIX_LED_COUNT];
static bool  key_active_this_frame[RGB_MATRIX_LED_COUNT];

// Save the current LED color and override it with an indicator color.
// Only saves on the first override; subsequent frames keep the original save.
static inline void save_and_set_color(uint8_t index, uint8_t r, uint8_t g, uint8_t b) {
    if (!key_has_save[index]) {
#ifdef RGB_MATRIX_WS2812
        // Read the actual animation color from the WS2812 LED buffer
        saved_led_state[index].r = ws2812_leds[index].r;
        saved_led_state[index].g = ws2812_leds[index].g;
        saved_led_state[index].b = ws2812_leds[index].b;
#else
        // Fallback for non-WS2812 drivers: generate a jellybean-style random
        // color to use when restoring, since we can't read the LED buffer.
        hsv_t hsv = {random8(), random8_min_max(127, 255), rgb_matrix_config.hsv.v};
        saved_led_state[index] = rgb_matrix_hsv_to_rgb(hsv);
#endif
        key_has_save[index] = true;
    }
    key_active_this_frame[index] = true;
    rgb_matrix_set_color(index, r, g, b);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Start of frame (first chunk): clear per-frame override tracking
    if (led_min == 0) {
        memset(key_active_this_frame, 0, sizeof(key_active_this_frame));
    }

    // Apply indicators if any non-base layer is active
    if ((layer_state & ~BASE_LAYERS_MASK) != 0) {
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
                                save_and_set_color(index, RGB_RED);
                                break;
                            case DL_ISO:
                            case DL_ANSI:
                            case DL_EURKEY:
                                save_and_set_color(index, RGB_CYAN);
                                break;
                            case KC_NO:
                            case KC_TRNS:
                                save_and_set_color(index, RGB_OFF);
                                break;
                            default:
                                save_and_set_color(index, RGB_SPRINGGREEN);
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

                        for (int8_t layer = L_ADJUST; layer >= 0; layer--) {
                            if (layer_state_is(layer)) {
                                keycode = keymap_key_to_keycode(layer, key);
                                if (keycode != KC_TRNS) {
                                    break;
                                }
                            }
                        }

                        if (keycode == KC_NO) {
                            save_and_set_color(index, RGB_OFF);
                        }
                    }
                }
            }
        }
    }

    // End of frame (last chunk): restore LEDs that are no longer overridden.
    // This handles both returning to base layer and switching between
    // indicator layers (e.g. L_ADJUST -> L_LOWER where different keys
    // are overridden).
    if (led_max >= RGB_MATRIX_LED_COUNT) {
        for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
            if (key_has_save[i] && !key_active_this_frame[i]) {
                rgb_matrix_set_color(i, saved_led_state[i].r, saved_led_state[i].g, saved_led_state[i].b);
                key_has_save[i] = false;
            }
        }
    }

    return false;
}

#endif // RGB_MATRIX_ENABLE

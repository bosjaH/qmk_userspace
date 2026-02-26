#include "bosjah.h"
#include "persistent_layers.h"

void persistent_layers_init(void) {
    uint32_t persistent_state = eeconfig_read_user();
    for (uint8_t i = 0; i < 32; i++) {
        if (persistent_state & ((uint32_t)1 << i)) {
            layer_on(i);
        }
    }
}

bool persistent_layers_process(uint16_t keycode, keyrecord_t *record) {
    if (keycode < CK_PTG || keycode > CK_PTG_MAX) {
        return true;
    }

    if (record->event.pressed) {
        uint8_t layer = keycode - CK_PTG;
        layer_invert(layer);

        uint32_t persistent_state = eeconfig_read_user();
        persistent_state ^= ((uint32_t)1 << layer);
        eeconfig_update_user(persistent_state);
    }

    return false;
}

void persistent_layers_eeconfig_init(void) {
    eeconfig_update_user(0);
}

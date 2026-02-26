#pragma once

#include <quantum.h>

enum persistent_layer_keycodes {
    CK_PTG = QK_USER,
    CK_PTG_MAX = CK_PTG + 31,
};

// PTG(layer) — Persistent Toggle Layer
// Toggles a layer on/off and persists the state to EEPROM.
// Works like TG() but survives power cycles.
// The layer state is stored as a uint32_t bitmask via eeconfig_update_user().
#define PTG(layer) (CK_PTG + (layer))

// Call from keyboard_post_init_user() to restore persisted layer state
void persistent_layers_init(void);

// Call from process_record_user(); returns false if the keycode was handled
bool persistent_layers_process(uint16_t keycode, keyrecord_t *record);

// Call from eeconfig_init_user() to reset persisted state on EEPROM clear
void persistent_layers_eeconfig_init(void);

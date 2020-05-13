#pragma once

#include QMK_KEYBOARD_H

#define USERSPACE

// Dvorak keymappings
#include <keymap_dvorak.h>

#ifdef STENO_ENABLE
  // Steno keymappings
  #include <keymap_steno.h>
#endif

#ifdef AUDIO_ENABLE
  float planck_song[][2]    = SONG(PLANCK_SOUND);
  float dvorak_song[][2]    = SONG(DVORAK_SOUND);
  float plover_song[][2]    = SONG(PLOVER_SOUND);
  float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

void eeconfig_init_user(void) {
  #ifdef UNICODE_ENABLE
    // Default to Linux unicode mode
    set_unicode_input_mode(UC_LNX);
  #endif
}

void matrix_init_user(void) {
  steno_set_mode(STENO_MODE_GEMINI);
}

void suspend_power_down_user(void) {
  #ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_suspend_state(true);
  #endif
}

void suspend_wakeup_init_user(void) {
  #ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_suspend_state(false);
  #endif
}

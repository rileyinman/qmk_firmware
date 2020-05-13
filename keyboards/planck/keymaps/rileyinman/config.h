#pragma once

#ifdef AUDIO_ENABLE
  #define STARTUP_SONG SONG(ZELDA_PUZZLE)
#endif

// Allows MT() modifiers pressed quickly to still work as modifiers
#define PERMISSIVE_HOLD

// Disable mechanical locking keys
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// Only require a double tap to toggle hold layers
#define TAPPING_TOGGLE 2

#ifdef RGB_MATRIX_ENABLE
  // Disable individual matrix animations
  #define DISABLE_RGB_MATRIX_ALPHAS_MODS
  #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
  #define DISABLE_RGB_MATRIX_BREATHING
  #define DISABLE_RGB_MATRIX_BAND_SAT
  #define DISABLE_RGB_MATRIX_BAND_VAL
  #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
  #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
  #define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
  #define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
  #define DISABLE_RGB_MATRIX_RAINDROPS
  #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#endif

#ifdef ENCODER_ENABLE
  // Fix keycodes such as volume, brightness, etc.
  #define TAP_CODE_DELAY 10

  // Most tactile encoders have detents every 4 stages
  #define ENCODER_RESOLUTION 4
#endif

// MIDI options

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

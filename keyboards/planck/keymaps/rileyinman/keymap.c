/* Copyright 2015-2017 Jack Humbert
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

// Userspace config
#include "rileyinman.h"

// NOTE: Common codes
// DF - Set default layer
// MO - Momentarily switch to layer on hold
// TG - Toggle layer on/off
// TT - Tap toggle (MO on hold, TG on double-tap)
#define SYMBOLS MO(_SYMBOLS)
#define DSYMBOLS MO(_DSYMBOLS)
#define MOVEMENT TT(_MOVEMENT)
#define NUMPAD TT(_NUMPAD)
#define UNICODE OSL(_UNICODE)
#define SETTINGS MO(_SETTINGS)
#define DSETTINGS MO(_DSETTINGS)

#define CTL_ESC LCTL_T(KC_ESC)

extern keymap_config_t keymap_config;

enum planck_layers {
  _DVORAK,
  _SDVORAK,
  _SYMBOLS,
  _DSYMBOLS,
  _MOVEMENT,
  _NUMPAD,
  _GAMES,
  _DGAMES,
  _UNICODE,
  _SETTINGS,
  _DSETTINGS,
  _PLOVER
};

enum planck_keycodes {
  GAMES = SAFE_RANGE,
  DGAMES,
  PLOVER,
  EXT_PLV
};

/* Layer Template
 * ,-----------------------------------------------++-----------------------------------------------.
 * |       |       |       |       |       |       ||       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       ||       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       ||       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |                |       |       |       |       |       |
 * `------------------------------------------------------------------------------------------------'
 */
/* [_LAYER] = LAYOUT_planck_grid( */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ */
/* ), */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------++-----------------------------------------------.
 * |  Tab  |  " '  |  < ,  |  > .  |  P p  |  Y y  ||  F f  |  G g  |  C c  |  R r  |  L l  |  ? /  |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * | Ct/Es |  A a  |  O o  |  E e  |  U u  |  I i  ||  D d  |  H h  |  T t  |  N n  |  S s  | Enter |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * | Move  |  : ;  |  Q q  |  J j  |  K k  |  X x  ||  B b  |  M m  |  W w  |  V v  |  Z z  | Lock  |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * | Mute  | Npad  |  GUI  | Shift | Bksp  |     Space      | Symbs |  Alt  |Unicode| Print |Setting|
 * `------------------------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
  KC_TAB,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,   KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
  CTL_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,   KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
  MOVEMENT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,   KC_M,    KC_W,    KC_V,    KC_Z,    KC_LOCK,
  KC_MUTE,  NUMPAD,  KC_LGUI, KC_LSFT, KC_BSPC, KC_SPC,  KC_SPC, SYMBOLS, KC_LALT, UNICODE, KC_PSCR, SETTINGS
),

// Software Dvorak - Same as above, but works if the host computer is set to Dvorak
[_SDVORAK] = LAYOUT_planck_grid(
  KC_TAB,   DV_QUOT, DV_COMM, DV_DOT,  DV_P,    DV_Y,    DV_F,   DV_G,     DV_C,    DV_R,    DV_L,    DV_SLSH,
  CTL_ESC,  DV_A,    DV_O,    DV_E,    DV_U,    DV_I,    DV_D,   DV_H,     DV_T,    DV_N,    DV_S,    KC_ENT,
  MOVEMENT, DV_SCLN, DV_Q,    DV_J,    DV_K,    DV_X,    DV_B,   DV_M,     DV_W,    DV_V,    DV_Z,    KC_LOCK,
  KC_MUTE,  NUMPAD,  KC_LGUI, KC_LSFT, KC_BSPC, KC_SPC,  KC_SPC, DSYMBOLS, KC_LALT, UNICODE, KC_PSCR, DSETTINGS
),

/* Symbols
 * ,-----------------------------------------------++-----------------------------------------------.
 * |   ~   |   !   |   @   |   #   |   $   |   %   ||   ^   |   &   |   *   |   (   |   )   |   |   |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * |   `   |   1   |   2   |   3   |   4   |   5   ||   6   |   7   |   8   |   9   |   0   |   \   |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * |   .   |   -   |   _   |   +   |   =   |       ||       |   {   |   [   |   ]   |   }   |       |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * | Music |       |       |       |  Del  |                |       |       |       |       |       |
 * `------------------------------------------------------------------------------------------------'
 */
[_SYMBOLS] = LAYOUT_planck_grid(
  KC_TILD,        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  LCTL_T(KC_GRV), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
  KC_DOT,         KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS, _______, _______, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, _______,
  KC_MPLY,        _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______, _______
),
[_DSYMBOLS] = LAYOUT_planck_grid(
  DV_TILD,        DV_EXLM, DV_AT,   DV_HASH, DV_DLR,  DV_PERC, DV_CIRC, DV_AMPR, DV_ASTR, DV_LPRN, DV_RPRN, DV_PIPE,
  LCTL_T(DV_GRV), DV_1,    DV_2,    DV_3,    DV_4,    DV_5,    DV_6,    DV_7,    DV_8,    DV_9,    DV_0,    DV_BSLS,
  DV_DOT,         DV_MINS, DV_UNDS, DV_EQL,  DV_PLUS, _______, _______, DV_LCBR, DV_LBRC, DV_RBRC, DV_RCBR, _______,
  KC_MPLY,        _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______, _______
),

/* Movement
 * ,-----------------------------------------------++-----------------------------------------------.
 * |       |       |       |       |       |       ||       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       ||       | Left  | Down  |  Up   | Right |       |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       ||       | Home  | Pg Dn | Pg Up |  End  |       |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * | Scrl  |       |       |       |       |                |       |       |       |       |       |
 * `------------------------------------------------------------------------------------------------'
 */
[_MOVEMENT] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
  XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Numpad
 * ,-----------------------------------------------++-----------------------------------------------.
 * |       |       |       |       |       |       ||       |   7   |   8   |   9   |   /   | Back  |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       ||       |   4   |   5   |   6   |   *   | Enter |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       ||       |   1   |   2   |   3   |   -   |NumLock|
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |                |       |   0   |   .   |   +   |       |
 * `------------------------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8, KC_P9,   KC_PSLS, KC_BSPC,
  _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5, KC_P6,   KC_PAST, KC_PENT,
  _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2, KC_P3,   KC_PMNS, KC_NLCK,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P0, KC_PDOT, KC_PPLS, _______
),

/* Games layer
 * ,-----------------------------------------------++-----------------------------------------------.
 * |  Tab  |  Q q  |  W w  |  E e  |  R r  |  T t  ||  Y y  |   7   |   8   |   9   |  P p  |  / ?  |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * | Ct/Es |  A a  |  S s  |  D d  |  F f  |  G g  ||  H h  |   4   |   5   |   6   |  : ;  | Enter |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * | Exit  |  Z z  |  X x  |  C c  |  V v  |  B b  ||  N n  |   1   |   2   |   3   |   ^   | Lock  |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * | Scrl  |  Alt  |  GUI  | Shift | Bksp  |     Space      | Symbs |   0   |   <   |   v   |   >   |
 * `------------------------------------------------------------------------------------------------'
 */
[_GAMES] = LAYOUT_planck_grid(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_P7,   KC_P8, KC_P9,   KC_P,    KC_SLSH,
  CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_P4,   KC_P5, KC_P6,   KC_SCLN, KC_ENT,
  GAMES,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,   KC_P1,   KC_P2, KC_P3,   KC_UP,   KC_LOCK,
  _______, KC_LALT, KC_LGUI, KC_LSFT, KC_BSPC, KC_SPC, KC_SPC, SYMBOLS, KC_P0, KC_LEFT, KC_DOWN, KC_RGHT
),
[_DGAMES] = LAYOUT_planck_grid(
  KC_TAB,  DV_Q,    DV_W,    DV_E,    DV_R,    DV_T,   DV_Y,   KC_P7,    KC_P8, KC_P9,   DV_P,    DV_SLSH,
  CTL_ESC, DV_A,    DV_S,    DV_D,    DV_F,    DV_G,   DV_H,   KC_P4,    KC_P5, KC_P6,   DV_SCLN, KC_ENT,
  DGAMES,  DV_Z,    DV_X,    DV_C,    DV_V,    DV_B,   DV_N,   KC_P1,    KC_P2, KC_P3,   KC_UP,   KC_LOCK,
  _______, KC_LALT, KC_LGUI, KC_LSFT, KC_BSPC, KC_SPC, KC_SPC, DSYMBOLS, KC_P0, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Unicode
 * ,-----------------------------------------------++-----------------------------------------------.
 * |       |       |       |       |       |       ||       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       ||       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       ||       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |                |       |       |       |       |       |
 * `------------------------------------------------------------------------------------------------'
 */
[_UNICODE] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Settings layer
 * ,-----------------------------------------------++-----------------------------------------------.
 * | Reset | MOD - | MOD + | HUE - | HUE + | SAT - || SAT + | BRI - | BRI + |       |       |       |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * |       |  F1   |  F2   |  F3   |  F4   |  F5   ||  F6   | Games |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * |       |  F7   |  F8   |  F9   |  F10  |  F11  ||  F12  |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * | Brite |       |       |       |       |                |       |       |       |       |       |
 * `------------------------------------------------------------------------------------------------'
 */
[_SETTINGS] = LAYOUT_planck_grid(
  RESET,   RGB_RMOD, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, _______,
  _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   GAMES,   _______, _______, _______, _______,
  _______, KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______,
  XXXXXXX, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[_DSETTINGS] = LAYOUT_planck_grid(
  RESET,   RGB_RMOD, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, _______,
  _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   DGAMES,  _______, _______, _______, _______,
  _______, KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______,
  XXXXXXX, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Plover layer (http://opensteno.org)
 * ,------------------------------------------------------------------------------------------------.
 * | Exit  |   S   |   T   |   P   |   H   |   *        *   |   F   |   P   |   L   |   T   |   D   |
 * |-------+-------+-------+-------+-------+                +-------+-------+-------+-------+-------|
 * | Funct |   S   |   K   |   W   |   R   |   *        *   |   R   |   B   |   G   |   S   |   Z   |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * |   #       #       #       #       #       #        #       #       #       #       #       #   |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * |                       |   A   |   O   |                |   E   |   U   |  Pwr  |  RE1  |  RE2  |
 * `------------------------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
  EXT_PLV, STN_S1,  STN_TL,  STN_PL, STN_HL, STN_ST1, STN_ST3, STN_FR, STN_PR, STN_LR,  STN_TR,  STN_DR,
  STN_FN,  STN_S2,  STN_KL,  STN_WL, STN_RL, STN_ST2, STN_ST4, STN_RR, STN_BR, STN_GR,  STN_SR,  STN_ZR,
  STN_N1,  STN_N2,  STN_N3,  STN_N4, STN_N5, STN_N6,  STN_N7,  STN_N8, STN_N9, STN_NA,  STN_NB,  STN_NC,
  XXXXXXX, XXXXXXX, XXXXXXX, STN_A,  STN_O,  XXXXXXX, XXXXXXX, STN_E,  STN_U,  STN_PWR, STN_RE1, STN_RE2
)

};

uint8_t base_layer_mode;

void keyboard_post_init_user(void) {
  #ifdef RGB_MATRIX_ENABLE
    base_layer_mode = rgb_matrix_get_mode();
    rgb_matrix_sethsv_noeeprom(HSV_RED);
  #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t current_layer = biton32(layer_state);

  switch (keycode) {
    case RGB_MOD:
    case RGB_RMOD:
      base_layer_mode = rgb_matrix_get_mode();
      return true;
      break;
    case GAMES:
      if (record->event.pressed) {
        if (current_layer == _GAMES) {
          stop_all_notes();
          PLAY_SONG(planck_song);
          layer_off(_GAMES);
        } else {
          stop_all_notes();
          // TODO: Define this song
          // PLAY_SONG(games_song);
          layer_on(_GAMES);
        }
      }
      return false;
      break;
    case DGAMES:
      if (record->event.pressed) {
        if (current_layer == _DGAMES) {
          stop_all_notes();
          PLAY_SONG(planck_song);
          layer_off(_DGAMES);
        } else {
          stop_all_notes();
          // TODO: Define this song
          // PLAY_SONG(games_song);
          layer_on(_DGAMES);
        }
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_SYMBOLS);
        layer_off(_DSYMBOLS);
        layer_off(_MOVEMENT);
        layer_off(_NUMPAD);
        layer_off(_SETTINGS);
        layer_off(_DSETTINGS);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}

bool numlock_modified = false;

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
  case _NUMPAD:
  case _GAMES:
  case _DGAMES:
    if (!IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {
      numlock_modified = true;
      tap_code(KC_NLCK);
    }
    break;
  default:
    if (numlock_modified) {
      numlock_modified = false;
      tap_code(KC_NLCK);
    }
    break;
  }

  #ifdef RGB_MATRIX_ENABLE
    switch (get_highest_layer(state)) {
    case _SYMBOLS:
    case _DSYMBOLS:
      rgb_matrix_sethsv_noeeprom(HSV_TEAL);
      rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
      break;
    case _MOVEMENT:
      rgb_matrix_sethsv_noeeprom(HSV_GREEN);
      rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
      break;
    case _NUMPAD:
      rgb_matrix_sethsv_noeeprom(HSV_ORANGE);
      rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
      break;
    case _SETTINGS:
    case _DSETTINGS:
      rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
      rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
      break;
    case _GAMES:
    case _DGAMES:
      rgb_matrix_sethsv_noeeprom(HSV_PURPLE);
      rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    case _PLOVER:
      break;
    default:
      rgb_matrix_sethsv_noeeprom(HSV_RED);
      rgb_matrix_mode_noeeprom(base_layer_mode);
      break;
    }
  #endif
  return state;
}

#ifdef ENCODER_ENABLE
void encoder_update(bool clockwise) {
  if (IS_LAYER_ON(_MOVEMENT)) {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGDN);
      #endif
    }
  } else if (IS_LAYER_ON(_SYMBOLS) || IS_LAYER_ON(_DSYMBOLS)) {
    if (clockwise) {
      #ifdef EXTRAKEY_ENABLE
        tap_code(KC_MNXT);
      #endif
    } else {
      #ifdef EXTRAKEY_ENABLE
        tap_code(KC_MPRV);
      #endif
    }
  }
  else if (IS_LAYER_ON(_SETTINGS) || IS_LAYER_ON(_DSETTINGS)) {
    #ifdef EXTRAKEY_ENABLE
      if (clockwise) {
        tap_code(KC_BRIU);
      } else {
        tap_code(KC_BRID);
      }
    #endif
  } else {
    #ifdef EXTRAKEY_ENABLE
      if (clockwise) {
        tap_code(KC_VOLU);
      } else {
        tap_code(KC_VOLD);
      }
    #endif
  }
}
#endif

void dip_switch_update_user(uint8_t index, bool active) {
  switch (index) {
    case 0: {
      static bool play_sound = false;
      if (active) {
        #ifdef AUDIO_ENABLE
          if (play_sound) { PLAY_SONG(planck_song); }
        #endif
        default_layer_set(1 << _SDVORAK);
      } else {
        #ifdef AUDIO_ENABLE
          if (play_sound) { PLAY_SONG(dvorak_song); }
        #endif
        default_layer_set(1 << _DVORAK);
      }
      play_sound = true;
      break;
    }
    case 3: {
      if (active) {
        #ifdef RGB_MATRIX_ENABLE
          rgb_matrix_enable_noeeprom();
        #endif
      } else {
        #ifdef RGB_MATRIX_ENABLE
          rgb_matrix_disable_noeeprom();
        #endif
      }
    }
  }
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case SYMBOLS:
    case DSYMBOLS:
    case MOVEMENT:
    case NUMPAD:
    case SETTINGS:
    case DSETTINGS:
      return false;
    default:
      return true;
  }
}

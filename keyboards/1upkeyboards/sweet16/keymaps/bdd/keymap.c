#include QMK_KEYBOARD_H
#include "config.h"

enum layers {
  L_FB,		// (Default) Facebook Messenger, Workplace, Rooms.
  L_BJ,		// BlueJeans
  L_ZOOM,	// Zoom
  L_SUPER	// Alternate keycodes. Momentarily (MO) toggled layer.
};

enum combos {
  VOLUPDOWN
};

const uint16_t PROGMEM volupdown_combo[] = {KC_VOLU, KC_VOLD, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  // Chord Volume Up & Down for Mute.
  [VOLUPDOWN] = COMBO(volupdown_combo, KC_MUTE)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * [mute audio]  [mute video]  [fullscreen]  [volume up]
   *                             \   'F'   / <---{ super }
   *
   * [  rwd 5s  ]  [play/pause]   [ fwd 5s  ]  [volume down]
   * \ rwd 10s /                  \ fwd 5s / <---{ super }
   *
   * [no func]     [no func]     [no func]     [no func]
   *
   * [TO: FB]      [TO: BJ]      [TO: ZOOM]    [MO: super]
   */
	[L_FB] = LAYOUT_ortho_4x4(
	    LALT(KC_M),	LALT(KC_V),	LALT(KC_F),	KC_VOLU,
	    KC_LEFT,	KC_SPC,		KC_RGHT,	KC_VOLD,
	    KC_NO,	KC_NO,		KC_NO,		KC_NO,
	    TO(L_FB),	TO(L_BJ),	TO(L_ZOOM),	MO(L_SUPER)
	),
	[L_BJ] = LAYOUT_ortho_4x4(
	    KC_M,	KC_V,		KC_NO,/* ! */	KC_TRNS,
	    KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
	    KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
	    KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
	),
	[L_ZOOM] = LAYOUT_ortho_4x4(
	    SGUI(KC_A),	SGUI(KC_V),	SGUI(KC_F),	KC_TRNS,
	    KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
	    KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
	    KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
	),
	[L_SUPER] = LAYOUT_ortho_4x4(
	    KC_TRNS,	KC_TRNS,	KC_F,		KC_TRNS,
	    KC_J,	KC_TRNS,	KC_L,		KC_TRNS,
	    KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
	    KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
	)
};

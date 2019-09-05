#include QMK_KEYBOARD_H

enum custom_layers {
  _QWERTY,
  _MOD1,
  _EXT,
  _CMD,
  _ADJUST,
  _MOV,
  _MOU,
  _QC,
  _QP
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  EXT,
  CMD,
  MOV,
  MOU,
  UNWIND,
  DLC_1,
  DLC_2,
  PX_SPACE,
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

#define x KC_NO

#define DM1_R DYN_REC_START1
#define DM2_R DYN_REC_START2
#define DM1_P DYN_MACRO_PLAY1
#define DM2_P DYN_MACRO_PLAY2
#define DM_STOP DYN_REC_STOP

#define _C(kc) LT(_QC, kc)
#define _P(kc) LT(_QP, kc)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Shift|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Tab  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Bspc |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | CMD  | EXT  |    Space    | EXT  | CMD  | GUI  |  Alt | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit( \
  KC_LSFT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RSFT, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_TAB,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSPC, \
  KC_LCTL, KC_LALT, KC_LGUI, CMD,     EXT,         KC_SPACE,     EXT,     CMD,     KC_RGUI, KC_RALT, KC_RCTL \
),

/* Mod1
 * ,-----------------------------------------------------------------------------------.
 * | Shift|   Q  |   W  |   D  |   F  |      |      |   M  |   I  |   O  |   P  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   E  |   R  |   G  |   H  |   J  |   K  |   L  |   T  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Tab  |   Z  |   Y  |   U  |   C  |   V  |   B  |   N  |   ,  |   .  |   X  | Bspc |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | CMD  | EXT  |    Space    | EXT  | CMD  | GUI  |  Alt | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_MOD1] = LAYOUT_planck_mit( \
  KC_LSFT, KC_Q,    KC_W,    KC_D,    KC_F,    KC_NO,   KC_NO,   KC_M,    KC_I,    KC_O,    KC_P,    KC_RSFT, \
  KC_ESC,  KC_A,    KC_S,    KC_E,    _C(KC_R),KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_T,    KC_ENT, \
  KC_TAB,  KC_Z,    KC_Y,    KC_U,    _P(KC_C),KC_V,    KC_B,    KC_N,    KC_COMM, KC_DOT,  KC_X,    KC_BSPC, \
  KC_LCTL, KC_LALT, KC_LGUI, CMD,     EXT,        KC_SPACE,      EXT,     CMD,     KC_RGUI, KC_RALT, KC_RCTL \
),

/* Extended keys
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |      |      |   "  |   [  |   ]  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   5  |   6  |   7  |   8  |   0  |   ;  |   _  |   (  |   )  |   :  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   .  |   9  |   -  |   +  |   0  |  --  |   `  |   -  |   =  |   '  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_EXT] = LAYOUT_planck_mit( \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    x,       x,       KC_DQUO, KC_LBRC, KC_RBRC, KC_BSLS, _______, \
  _______, KC_5,    KC_6,    KC_7,    KC_8,    KC_0,    KC_SCLN, KC_UNDS, KC_LPRN, KC_RPRN, KC_COLN, _______, \
  KC_DOT,  KC_9,    KC_PMNS, KC_PPLS, KC_0,    x,       KC_GRV,  KC_MINS, KC_EQL,  KC_QUOT, KC_SLSH, _______, \
  _______, _______, _______, _______, CMD,        PX_SPACE,      CMD,     _______, _______, _______, _______ \
),

/* Command keys
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F13 |  --  |  --  | Bksp | Del  | Pause|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |  F14 | Left | Down |  Up  | Right| Caps |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |  F15 | Home | PgDn | PgUp | End  | App  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_CMD] = LAYOUT_planck_mit( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F13,  x,       DM1_P,   DM2_P,   KC_DEL,  KC_PAUS, _______, \
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F14,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, _______, \
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F15,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_APP,  _______, \
  _______, _______, _______, _______, _______,       x,          _______, _______, _______, _______, _______ \
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |      |  MOV |  MOU |  --  |  --  |  --  |  --  | DLC_1| DLC_2|  --  |  --  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Btn1 | Btn2 | Btn3 | Btn4 | Btn5 |  MsL | MsD  | MsU  | MsR  |  --  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  --  |  --  | Mute | VolU | VolD |  --  |  WhL | WhD  | WhU  | WhR  |  --  |SysRq |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    -----    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit( \
  _______, DM1_R,   DM2_R,   x,       DM_STOP, x,       x,       x,       x,       x,       x,       _______, \
  _______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, x,       _______, \
  x,       x,       KC_MUTE, KC_VOLD, KC_VOLU, x,       KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, x,       KC_SYSREQ, \
  _______, _______, _______, _______, _______,       x,          _______, _______, _______, _______, _______ \
),

/* Movement control
 * ,-----------------------------------------------------------------------------------.
 * |      |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Btn1 |  MsL |  MsU |  MsD |  MsR | Left | Down |  Up  | Right|  --  |  --  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  --  |  --  |  --  |  --  |  --  | Home | PgDn | PgUp | End  |  --  |  --  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  --  |  --  |    UNWIND   |  --  |  --  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOV] = LAYOUT_planck_mit( \
  _______, x,       x,       x,       x,       x,       x,       x,       x,       x,       x,       _______, \
  _______, x,       x,       x,       x,       x,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, x,       _______, \
  x,       x,       x,       x,       x,       x,       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  x,       x, \
  _______, _______, _______, x,       x,          UNWIND,        x,       x,       _______, _______, _______ \
),

/* Mouse control
 * ,-----------------------------------------------------------------------------------.
 * |      |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Btn1 | Btn2 | Btn3 | Btn4 | Btn5 |  MsL | MsD  | MsU  | MsR  |  --  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  --  |  --  |  --  |  --  |  --  |  --  |  WhL | WhD  | WhU  | WhR  |  --  |  --  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  --  |  --  |    UNWIND   |  --  |  --  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOU] = LAYOUT_planck_mit( \
  _______, x,       x,       x,       x,       x,       x,       x,       x,       x,       x,       _______, \
  _______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, _______, \
  x,       x,       x,       x,       x,       x,       KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, x,       x, \
  _______, _______, _______, x,       x,           UNWIND,       x,       x,       _______, _______, _______ \
),

/* Quick control
 * ,-----------------------------------------------------------------------------------.
 * |      |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  --  |  --  |  --  |  --  |  --  | Left | Down |  Up  | Right|  --  |  --  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  --  |  --  |  --  |  --  |  --  | Home | PgDn | PgUp | End  |  --  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  --  |  --  |             |  --  |  --  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QC] = LAYOUT_planck_mit( \
  _______, x,       x,       x,       x,       x,       x,       x,       x,       x,       x,       _______, \
  _______, x,       x,       x,       _______, x,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, _______, \
  x,       x,       x,       x,       x,       x,       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  x,       KC_DEL, \
  _______, _______, _______, x,       x,           MOV,          x,       x,       _______, _______, _______ \
),

/* Quick mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Btn1 | Btn2 | Btn3 | Btn4 | Btn5 |  MsL | MsD  | MsU  | MsR  | Btn1 |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  --  |  --  |  --  |  --  |  --  |  --  |  WhL | WhD  | WhU  | WhR  |  --  |  --  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  --  |  --  |             |  --  |  --  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QP] = LAYOUT_planck_mit( \
  _______, x,       x,       x,       x,       x,       x,       x,       x,       x,       x,       _______, \
  _______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, _______, \
  x,       x,       x,       x,       x,       x,       KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, x,       x, \
  _______, _______, _______, x,       x,           MOU,          x,       x,       _______, _______, _______ \
)

};

#define NO_CONTROL 0

int control_layer = NO_CONTROL;
int default_layer = _MOD1;
bool is_ext_on = false;
bool is_ext_pristine = false;
bool is_px_on = false;

void keyboard_post_init_user(void) {
  default_layer_set(1UL << default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }
  switch (keycode) {
  case PX_SPACE:
    if (record->event.pressed) {
      if (is_ext_on && is_ext_pristine) {
        SEND_STRING(SS_DOWN(X_LCTRL));
        SEND_STRING(SS_TAP(X_SPACE));
        is_px_on = true;
      } else {
        SEND_STRING(SS_TAP(X_SPACE));
      }
      is_ext_pristine = false;
    } else {
      if (is_px_on) {
        SEND_STRING(SS_UP(X_LCTRL));
        is_px_on = false;
      }
    }
    return false;
  case EXT:
    if (record->event.pressed) {
      layer_on(_EXT);
      update_tri_layer(_EXT, _CMD, _ADJUST);
      is_ext_on = true;
      is_ext_pristine = true;
    } else {
      layer_off(_EXT);
      update_tri_layer(_EXT, _CMD, _ADJUST);
      is_ext_on = false;
      is_ext_pristine = false;
    }
    return false;
  case CMD:
    if (record->event.pressed) {
      layer_on(_CMD);
      update_tri_layer(_EXT, _CMD, _ADJUST);
    } else {
      layer_off(_CMD);
      update_tri_layer(_EXT, _CMD, _ADJUST);
    }
    return false;
  case MOV:
    if (record->event.pressed) {
      if (control_layer != MOV) {
        layer_off(_QWERTY);
        layer_off(_ADJUST);
        layer_off(_EXT);
        layer_off(_CMD);
        layer_off(_MOU);
        layer_on(_MOV);
        control_layer = MOV;
      }
    }
    return false;
  case MOU:
    if (record->event.pressed) {
      if (control_layer != MOU) {
        layer_off(_QWERTY);
        layer_off(_ADJUST);
        layer_off(_EXT);
        layer_off(_CMD);
        layer_off(_MOV);
        layer_on(_MOU);
        control_layer = MOU;
      }
    }
    return false;
  case UNWIND:
    if (record->event.pressed) {
      layer_off(_MOV);
      layer_off(_MOU);
      control_layer = NO_CONTROL;
      layer_off(_ADJUST);
      layer_off(_EXT);
      layer_off(_CMD);
      layer_on(_QWERTY);
    }
    return false;
  case DLC_1:
    if (record->event.pressed) {
      default_layer = _QWERTY;
      default_layer_set(1UL << default_layer);
    }
    return false;
  case DLC_2:
    if (record->event.pressed) {
      default_layer = _MOD1;
      default_layer_set(1UL << default_layer);
    }
    return false;
  default:
    if (is_ext_on)
      is_ext_pristine = false;
  }
  return true;
}

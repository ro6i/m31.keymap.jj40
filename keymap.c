#include QMK_KEYBOARD_H

enum custom_layers {
  _QWERTY,
  _MOD1,
  _EXT,
  _CMD,
  _ADJUST,
  _MOV,
  _MOU,
  _QUICK_CONTROL,
  _QUICK_GO,
  _QUICK_MOVE,
  _QUICK_POINT
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

#define QC_F LT(_QUICK_MOVE, KC_F)
#define QC_R LT(_QUICK_CONTROL, KC_R)
#define QC_G LT(_QUICK_GO, KC_G)
#define QC_C LT(_QUICK_POINT, KC_C)

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
  KC_LCTL, KC_LALT, KC_LGUI, CMD,     EXT,        KC_SPACE,      EXT,  CMD,     KC_RGUI, KC_RALT, KC_RCTL \
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
  KC_LSFT, KC_Q,    KC_W,    KC_D,    QC_F,    KC_NO,   KC_NO,   KC_M,    KC_I,    KC_O,    KC_P,    KC_RSFT, \
  KC_ESC,  KC_A,    KC_S,    KC_E,    QC_R,    QC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_T,    KC_ENT, \
  KC_TAB,  KC_Z,    KC_Y,    KC_U,    QC_C,    KC_V,    KC_B,    KC_N,    KC_COMM, KC_DOT,  KC_X,    KC_BSPC, \
  KC_LCTL, KC_LALT, KC_LGUI, CMD,     EXT,   LCTL_T(KC_SPACE),   EXT,     CMD,     KC_RGUI, KC_RALT, KC_RCTL \
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
 * |      |  Alt |  Cmd |  --  |  --  |  --  | Left | Down |  Up  | Right|  --  |  --  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  --  |  --  |  --  |  --  |  --  | Home | PgDn | PgUp | End  |  --  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  --  |  --  |             |  --  |  --  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QUICK_CONTROL] = LAYOUT_planck_mit( \
  _______, x,       x,       x,       x,       x,       x,       x,       x,       x,       x,       _______, \
  _______, KC_LALT, KC_LGUI, x,       _______, x,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, _______, \
  x,       x,       x,       x,       x,       x,       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,  _______, \
  _______, _______, _______, x,       KC_LCTL,     MOV,          x,       x,       _______, _______, _______ \
),

[_QUICK_GO] = LAYOUT_planck_mit( \
  _______, x,       x,       x,       x,       x,       x,       x,       x,       x,       x,       _______, \
  _______, x,       x,       x,       x,       _______, S(KC_TAB),KC_GRV, S(KC_GRV),KC_TAB, KC_ESC,  _______, \
  x,       x,       x,       x,       x,       x,       x,       x,       x,       x,       x,       _______, \
  _______, _______, _______, x,       x,            x,           x,       x,       _______, _______, _______ \
),

[_QUICK_MOVE] = LAYOUT_planck_mit( \
  _______, x,       x,       x,       _______, x,       x,       x,       x,       x,       x,       _______, \
  _______, x,       x,       x,       x,       x,   C(S(KC_TAB)),C(KC_TAB),C(S(KC_TAB)),C(KC_TAB),   _______, _______, \
  x,       x,       x,       x,       x,       x,       x,       x,       x,       x,       x,       _______, \
  _______, _______, _______, x,       x,            x,           x,       x,       _______, _______, _______ \
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
[_QUICK_POINT] = LAYOUT_planck_mit( \
  _______, x,       x,       x,       x,       x,       x,       x,       x,       x,       x,       _______, \
  _______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, _______, \
  x,       x,       x,       x,       x,       x,       KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, x,       x, \
  _______, _______, _______, x,       x,           MOU,          x,       x,       _______, _______, _______ \
)

};

#define NO_CONTROL 0

int control_layer = NO_CONTROL;
int default_layer = _MOD1;
bool is_ext_layer_on = false;
bool is_ext_layer_pristine = false;
bool is_px_key_on = false;
bool is_gui_on = false;

#define LAYER_ON(l_on, l_off_1, l_off_2, l_off_3, l_off_4, l_off_5) layer_off(l_off_1); layer_off(l_off_2); layer_off(l_off_3); layer_off(l_off_4); layer_off(l_off_5); layer_on(l_on); control_layer = l_on == _QWERTY ? NO_CONTROL : l_on;

void keyboard_post_init_user(void) {
  default_layer_set(1UL << default_layer);
}


uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
  case _QUICK_GO:
    register_code(KC_LGUI);
    is_gui_on = true;
    break;
  default:
    /* if (keyboard_report->mods & MOD_BIT(KC_LGUI)) { */
    if (is_gui_on) {
      unregister_code(KC_LGUI);
      is_gui_on = false;
    }
    break;
  }
  return state;
}

/* uint16_t get_tapping_term(uint16_t keycode) { */
/*   switch (keycode) { */
/*     case LCTL_T(KC_SPACE): */
/*       return TAPPING_TERM << 1; */
/*     default: */
/*       return TAPPING_TERM; */
/*   } */
/* } */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }
  switch (keycode) {
  case PX_SPACE:
    if (record->event.pressed) {
      if (is_ext_layer_on && is_ext_layer_pristine) {
        register_code(KC_LCTRL);
        tap_code(KC_SPACE);
        is_px_key_on = true;
      } else {
        tap_code(KC_SPACE);
      }
      is_ext_layer_pristine = false;
    } else {
      if (is_px_key_on) {
        unregister_code(KC_LCTRL);
        is_px_key_on = false;
      }
    }
    return false;
  case EXT:
    if (record->event.pressed) {
      layer_on(_EXT);
      is_ext_layer_pristine = is_ext_layer_on = true;
    } else {
      layer_off(_EXT);
      is_ext_layer_pristine = is_ext_layer_on = false;
    }
    update_tri_layer(_EXT, _CMD, _ADJUST);
    return false;
  case CMD:
    if (record->event.pressed) {
      layer_on(_CMD);
    } else {
      layer_off(_CMD);
    }
    update_tri_layer(_EXT, _CMD, _ADJUST);
    return false;
  case MOV:
    if (record->event.pressed && control_layer != MOV) {
      LAYER_ON(_MOV, _EXT, _CMD, _ADJUST, _MOU, _QWERTY);
    }
    return false;
  case MOU:
    if (record->event.pressed && control_layer != MOU) {
      LAYER_ON(_MOU, _EXT, _CMD, _ADJUST, _MOV, _QWERTY);
    }
    return false;
  case UNWIND:
    if (record->event.pressed) {
      LAYER_ON(_QWERTY, _EXT, _CMD, _ADJUST, _MOV, _MOV);
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
    if (is_ext_layer_on)
      is_ext_layer_pristine = false;
  }
  return true;
}

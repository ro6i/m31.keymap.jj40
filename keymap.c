#include "jj40.h"

#define RGBLIGHT_ANIMATIONS

extern keymap_config_t keymap_config;

enum custom_layers {
  _QWERTY,
  _EXT,
  _CMD,
  _ADJUST,
  _MOV,
  _MOU
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  EXT,
  CMD,
  ADJUST,
  MOV,
  MOU,
  UNWIND
};

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

/* Extended/QWERTY keys
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |      |   `  |   '  |   [  |   ]  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   5  |   6  |   7  |   8  |   9  |   "  |   _  |   (  |   )  |   :  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   .  |   0  |   -  |   +  |   *  |   /  |   ~  |   -  |   <  |   >  |   =  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_EXT] = LAYOUT_planck_mit( \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_NO,   KC_GRV,  KC_QUOT, KC_LBRC, KC_RBRC, KC_BSLS, _______, \
  _______, KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_DQUO, KC_UNDS, KC_LPRN, KC_RPRN, KC_COLN, _______, \
  KC_DOT,  KC_0,    KC_PMNS, KC_PPLS, KC_PAST, KC_PSLS, KC_TILD, KC_MINS, KC_LT,   KC_GT,   KC_EQL,  _______, \
  _______, _______, _______, _______, CMD,          _______,     CMD,     _______, _______, _______, _______ \
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
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F13,  KC_NO,   KC_NO,   KC_BSPC, KC_DEL,  KC_PAUS, _______, \
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F14,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, _______, \
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F15,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_APP,  _______, \
  _______, _______, _______, _______, _______,       KC_NO,      _______, _______, _______, _______, _______ \
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |      |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Btn1 | Btn2 | Btn3 | Btn4 | Btn5 |  MsL | MsD  | MsU  | MsR  |  --  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  --  |  --  | Mute | VolU | VolD |  --  |  WhL | WhD  | WhU  | WhR  |  --  |SysRq |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    -----    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit( \
  _______, MOV,     MOU,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   MOU,     MOV,    _______, \
  _______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,   _______, \
  KC_NO,   KC_NO,   KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,   KC_SYSREQ, \
  _______, _______, _______, _______, _______,       KC_NO,      _______, _______, _______, _______, _______ \
),

/* Movement control
 * ,-----------------------------------------------------------------------------------.
 * |UNWIND|  MOV |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |UNWIND|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Btn1 |  MsL |  MsU |  MsD |  MsR | Left | Down |  Up  | Right|  --  |  --  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  --  |  --  |  --  |  --  |  --  | Home | PgDn | PgUp | End  |  --  |  --  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  --  |  --  |    UNWIND   |  --  |  --  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOV] = LAYOUT_planck_mit( \
  UNWIND,  KC_NO,   MOU,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   MOU,     KC_NO,   UNWIND, \
  _______, KC_BTN1, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO, \
  _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,   KC_NO, \
  _______, _______, _______, KC_NO,   KC_NO,       UNWIND,       KC_NO,   KC_NO,   _______, _______, _______ \
),

/* Mouse control
 * ,-----------------------------------------------------------------------------------.
 * |UNWIND|  MOV |  MOU |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |UNWIND|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Btn1 |  MsL |  MsU |  MsD |  MsR | Left | Down |  Up  | Right|  --  |  --  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  --  |  --  |  --  |  --  |  --  | Home | PgDn | PgUp | End  |  --  |  --  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  --  |  --  |    UNWIND   |  --  |  --  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOU] = LAYOUT_planck_mit( \
  UNWIND,  MOV,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   MOV,     UNWIND, \
  _______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,   _______, \
  KC_NO,   KC_NO,   KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,   KC_NO, \
  _______, _______, _______, KC_NO,   KC_NO,       UNWIND,       KC_NO,   KC_NO,   _______, _______, _______ \
),
};

#define NO_CONTROL 0

int control_layer = NO_CONTROL;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case EXT:
    if (record->event.pressed) {
      layer_on(_EXT);
      update_tri_layer(_EXT, _CMD, _ADJUST);
    } else {
      layer_off(_EXT);
      update_tri_layer(_EXT, _CMD, _ADJUST);
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
      /* } else { */
      /*   layer_off(_MOV); */
      /*   is_mov_on = false; */
      /*   layer_on(_QWERTY); */
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
      /* } else { */
      /*   layer_off(_MOV); */
      /*   is_mov_on = false; */
      /*   layer_on(_QWERTY); */
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
  }
  return true;
}

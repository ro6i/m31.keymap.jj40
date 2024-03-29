#include QMK_KEYBOARD_H

enum custom_layers {
  _MODE1
  , _EXTL
  , _EXTR
  , _CMD
  , _ADJUST
  , _MOVE
  , _POINT
  , _QUICK_CONTROL
  , _QUICK_POINT
};

enum custom_keycodes {
  MODE1 = SAFE_RANGE
  , EXTL
  , EXTR
  , CMDL
  , CMDR
  , MOVE
  , POINT
  , UNWIND
  , PF_L
  , PF_R
};

#define x KC_NO

/* #define DM1_R DYN_REC_START1 */
/* #define DM2_R DYN_REC_START2 */
/* #define DM1_P DYN_MACRO_PLAY1 */
/* #define DM2_P DYN_MACRO_PLAY2 */
/* #define DM_STOP DYN_REC_STOP */

#define QC_R LT(_QUICK_CONTROL, KC_R)
#define QC_C LT(_QUICK_POINT, KC_C)
#define _Q_R _QUICK_CONTROL
#define _Q_P _QUICK_POINT

#define SPCTL LCTL_T(KC_SPACE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Mode 1
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   D  |   F  |   Z  |   X  |   M  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   E  |   R  |   G  |   H  |   J  |   K  |   L  |   T  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Tab  | Shift|   Y  |   U  |   C  |   V  |   B  |   N  |   ,  |   .  | Shift| Rsft |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | CMD  | EXT  | Space/Ctrl  | EXT  | CMD  | GUI  |  Alt | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_MODE1] = LAYOUT_planck_grid( \
  KC_TAB,  KC_Q,    KC_W,    KC_D,    KC_F,    KC_Z,    KC_X,    KC_M,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_E,    KC_R,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_T,    KC_ENT, \
  KC_LSFT, KC_LSFT, KC_Y,    KC_U,    KC_C,    KC_V,    KC_B,    KC_N,    KC_COMM, KC_DOT,  KC_RSFT, KC_RSFT, \
  KC_LCTL, KC_LALT, KC_LGUI, CMDL,    EXTL,    SPCTL,   SPCTL,   EXTR,    CMDR,    KC_RGUI, KC_RALT, KC_RCTL \
),

/* Extended keys
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |      |      |   "  |   [  |   ]  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   5  |   6  |   7  |   8  |   0  |   ;  |   _  |   (  |   )  |   :  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   .  |   9  |   -  |   +  |   0  |  --  |   `  |   -  |   =  |   '  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_EXTL] = LAYOUT_planck_grid( \
  _______, x,       x,       x,       x,       x,       x,       KC_DQUO, KC_LBRC, KC_RBRC, KC_BSLS, KC_SCLN, \
  _______, x,       x,       MO(_Q_P),MO(_Q_R),x,       x,       KC_UNDS, KC_LPRN, KC_RPRN, KC_COLN, _______, \
  _______, _______, x,       x,       x,       x,       KC_GRV,  KC_MINS, KC_EQL,  KC_QUOT, KC_SLSH, _______, \
  _______, _______, _______, _______, _______, _______, _______, PF_R,    _______, _______, _______, _______  \
),

[_EXTR] = LAYOUT_planck_grid( \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    x,       x,       KC_DQUO, KC_LBRC, KC_RBRC, KC_BSLS, _______, \
  _______, KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    x,       KC_UNDS, KC_LPRN, KC_RPRN, KC_COLN, _______, \
  _______, _______, KC_PMNS, KC_PPLS, KC_DOT,  x,       KC_GRV,  KC_MINS, KC_EQL,  KC_QUOT, _______, _______, \
  _______, _______, _______, _______, PF_L,    KC_0,    _______, _______, _______, _______, _______, _______  \
),

/* Command keys
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F13 |  --  |  --  | Bksp | Del  | Pause|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |  F14 | Left | Down |  Up  | Right| Caps |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |  F15 | Home | PgDn | PgUp | End  | App  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  F16 | F16  |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
//_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F13,  x,       DM1_P,   DM2_P,   KC_DEL,  KC_PAUS, _______,
[_CMD] = LAYOUT_planck_grid( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F13,  x,       x,       x,       KC_DEL,  KC_PAUS, _______, \
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F14,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, _______, \
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F15,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_APP,  _______, \
  _______, _______, _______, _______, _______, KC_F16,  KC_F16,  _______, _______, _______, _______, _______ \
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |      | REC 1| REC 2|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | MOVE |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  --  |  --  | Mute | VolU | VolD |  --  | POINT|      |      |      |      |SysRq |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
//_______, DM1_R,   DM2_R,   x,       DM_STOP, x,       x,       x,       x,       x,       x,       _______,
[_ADJUST] = LAYOUT_planck_grid( \
  _______, x,       x,       x,       x,       x,       x,       x,       x,       x,       x,       _______, \
  _______, x,       x,       x,       x,       x,       x,       MOVE,    x,       x,       x,       _______, \
  x,       x,       KC_MUTE, KC_VOLD, KC_VOLU, x,       x,       POINT,   x,       x,       x,       KC_SYRQ, \
  _______, _______, _______, _______, _______, x,       x,        _______, _______, _______, _______, _______ \
),

/* Movement control
 * ,-----------------------------------------------------------------------------------.
 * |      |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |UNWIND| Btn1 |  MsL |  MsU |  MsD |  MsR | Left | Down |  Up  | Right|  --  |  --  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  --  |  --  |  --  |  --  |  --  | Home | PgDn | PgUp | End  |  --  |  --  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  --  |  --  |    POINT    |  --  |  --  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOVE] = LAYOUT_planck_grid( \
  _______, x,       x,       x,       x,       x,       x,       x,       x,       x,       x,       _______, \
  UNWIND,  x,       x,       x,       x,       x,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, x,       _______, \
  x,       x,       x,       x,       x,       x,       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  x,       x, \
  _______, _______, _______, x,       x,       POINT,   POINT,   x,       x,       _______, _______, _______ \
),

/* Mouse control
 * ,-----------------------------------------------------------------------------------.
 * |      |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |UNWIND| Btn1 | Btn2 | Btn3 | Btn4 | Btn5 |  MsL | MsD  | MsU  | MsR  |  --  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  --  |  --  |  --  |  --  |  --  |  --  |  WhL | WhD  | WhU  | WhR  |  --  |  --  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  --  |  --  |     MOVE    |  --  |  --  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_POINT] = LAYOUT_planck_grid( \
  _______, x,       x,       x,       x,       x,       x,       x,       x,       x,       x,       _______, \
  UNWIND,  KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, _______, \
  x,       x,       x,       x,       x,       x,       KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, x,       x, \
  _______, _______, _______, x,       x,       MOVE,    MOVE,    x,       x,       _______, _______, _______ \
),

/* Quick control
 * ,-----------------------------------------------------------------------------------.
 * |      |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  Alt |  Cmd |  --  |  --  |  --  | Left | Down |  Up  | Right|  --  |  --  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  --  |  --  |  --  |  --  |  --  | Home | PgDn | PgUp | End  | Caps |  --  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  --  |  --  |      |      |  --  |  --  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QUICK_CONTROL] = LAYOUT_planck_grid( \
  _______, x,       x,       x,       x,       x,       x,       x,       x,       x,       x,       KC_DEL, \
  _______, KC_LALT, KC_LGUI, MO(_Q_P),_______, x,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
  _______, _______, x,       x,       x,       x,       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_CAPS, _______, \
  _______, _______, _______, x,       x,       _______, _______, x,       x,       _______, _______, _______ \
),

/* Quick mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Btn1 | Btn2 | Btn3 | Btn4 | Btn5 |  MsL | MsD  | MsU  | MsR  | Btn1 |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  --  |  --  |  --  |  --  |  --  |  --  |  WhL | WhD  | WhU  | WhR  |  --  |  --  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  --  |  --  |      |      |  --  |  --  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QUICK_POINT] = LAYOUT_planck_grid( \
  _______, x,       x,       x,       x,       x,       x,       x,       x,       x,       x,       _______, \
  _______, KC_BTN1, KC_BTN2, _______, MO(_Q_R),x,       KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, _______, \
  _______, _______, x,       x,       x,       x,       KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______, \
  _______, _______, _______, x,       KC_BTN1, KC_BTN3, KC_BTN3, KC_BTN2, x,       _______, _______, _______ \
)

};

#define NO_CONTROL 0

int control_layer = NO_CONTROL;
int default_layer = _MODE1;
int pfxl_pressed = 0;
int pfxr_pressed = 0;
int synthetic_layer_l_on = 0;
int synthetic_layer_r_on = 0;

int layer_ids[] = {
  _MODE1
  , _EXTL
  , _EXTR
  , _CMD
  , _ADJUST
  , _MOVE
  , _POINT
  , _QUICK_CONTROL
  , _QUICK_POINT
};

void
keyboard_post_init_user(void) {
  default_layer_set(1UL << default_layer);
}

void
stall_layer(int layer_id_to_turn_on) {
  unsigned int index, a;
  for (index = 0; index < sizeof layer_ids / sizeof *layer_ids; index++) {
    a = layer_ids[index];
    layer_off(a);
  }
  layer_on(layer_id_to_turn_on);
  control_layer = layer_id_to_turn_on == _MODE1 ? NO_CONTROL : layer_id_to_turn_on;
}

bool
process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case PF_L:
    if (record->event.pressed) {
      pfxl_pressed = 1;
      register_code(KC_LCTL);
      register_code(KC_SPACE);
      unregister_code(KC_SPACE);
    } else {
      pfxl_pressed = 0;
      /* unregister_code(KC_SPACE); */
      unregister_code(KC_LCTL);
      if (synthetic_layer_l_on) {
        synthetic_layer_l_on = 0;
        layer_off(_EXTL);
      }
    }
    return false;
  case PF_R:
    if (record->event.pressed) {
      pfxr_pressed = 1;
      register_code(KC_LCTL);
      register_code(KC_SPACE);
      unregister_code(KC_SPACE);
    } else {
      pfxr_pressed = 0;
      /* unregister_code(KC_SPACE); */
      unregister_code(KC_LCTL);
      if (synthetic_layer_r_on) {
        synthetic_layer_r_on = 0;
        layer_off(_EXTR);
      }
    }
    return false;
  case EXTL:
    if (record->event.pressed) {
      layer_on(_EXTL);
    } else {
      layer_off(_EXTL);
      if (pfxr_pressed) {
        /* unregister_code(KC_SPACE); */
        unregister_code(KC_LCTL);
        synthetic_layer_r_on = 1;
        layer_on(_EXTR);
      }
    }
    update_tri_layer(_EXTL, _CMD, _ADJUST);
    return false;
  case EXTR:
    if (record->event.pressed) {
      layer_on(_EXTR);
    } else {
      layer_off(_EXTR);
      if (pfxl_pressed) {
        /* unregister_code(KC_SPACE); */
        unregister_code(KC_LCTL);
        synthetic_layer_l_on = 1;
        layer_on(_EXTL);
      }
    }
    update_tri_layer(_EXTR, _CMD, _ADJUST);
    return false;
  case CMDL:
    if (record->event.pressed) {
      layer_on(_CMD);
    } else {
      layer_off(_CMD);
    }
    update_tri_layer(_EXTL, _CMD, _ADJUST);
    return false;
  case CMDR:
    if (record->event.pressed) {
      layer_on(_CMD);
    } else {
      layer_off(_CMD);
    }
    update_tri_layer(_EXTR, _CMD, _ADJUST);
    return false;
  case MOVE:
    if (record->event.pressed && control_layer != _MOVE) {
      stall_layer(_MOVE);
    }
    return false;
  case POINT:
    if (record->event.pressed && control_layer != _POINT) {
      stall_layer(_POINT);
    }
    return false;
  case UNWIND:
    if (record->event.pressed) {
      stall_layer(_MODE1);
    }
    return false;
  }
  return true;
}

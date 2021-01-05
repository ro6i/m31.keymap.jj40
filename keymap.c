#include QMK_KEYBOARD_H

enum custom_layers {
  _MODE1
  , _EXT
  , _CMD
  , _ADJUST
  , _MOVE
  , _POINT
  , _QUICK_CONTROL
  , _QUICK_POINT
};

enum custom_keycodes {
  MODE1 = SAFE_RANGE
  , EXT
  , CMD
  , MOVE
  , POINT
  , UNWIND
  , PX_SPACE
};

#define x KC_NO

#define DM1_R DYN_REC_START1
#define DM2_R DYN_REC_START2
#define DM1_P DYN_MACRO_PLAY1
#define DM2_P DYN_MACRO_PLAY2
#define DM_STOP DYN_REC_STOP

#define QC_R LT(_QUICK_CONTROL, KC_R)
#define QC_C LT(_QUICK_POINT, KC_C)

#define MC_PRFX LCTL(KC_SPACE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Mode 1
 * ,-----------------------------------------------------------------------------------.
 * | Shift|   Q  |   W  |   D  |   F  |      |      |   M  |   I  |   O  |   P  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   E  |   R  |   G  |   H  |   J  |   K  |   L  |   T  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Tab  |   Z  |   Y  |   U  |   C  |   V  |   B  |   N  |   ,  |   .  |   X  | Bspc |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | CMD  | EXT  | Space /Ctrl | EXT  | CMD  | GUI  |  Alt | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_MODE1] = LAYOUT_planck_mit( \
  KC_LSFT, KC_Q,    KC_W,    KC_D,    KC_F,    KC_NO,   KC_NO,   KC_M,    KC_I,    KC_O,    KC_P,    KC_RSFT, \
  KC_ESC,  KC_A,    KC_S,    KC_E,    QC_R,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_T,    KC_ENT, \
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
  _______, _______, _______, _______, MC_PRFX,    PX_SPACE,      MC_PRFX, _______, _______, _______, _______ \
),

/* Command keys
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F13 |  --  |  --  | Bksp | Del  | Pause|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |  F14 | Left | Down |  Up  | Right| Caps |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |  F15 | Home | PgDn | PgUp | End  | App  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    -----    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_CMD] = LAYOUT_planck_mit( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F13,  x,       DM1_P,   DM2_P,   KC_DEL,  KC_PAUS, _______, \
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F14,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, _______, \
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F15,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_APP,  _______, \
  _______, _______, _______, _______, _______,        x,         _______, _______, _______, _______, _______ \
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |      | REC 1| REC 2|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | MOVE |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  --  |  --  | Mute | VolU | VolD |  --  | POINT|      |      |      |      |SysRq |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    -----    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit( \
  _______, DM1_R,   DM2_R,   x,       DM_STOP, x,       x,       x,       x,       x,       x,       _______, \
  _______, x,       x,       x,       x,       x,       x,       MOVE,    x,       x,       x,       _______, \
  x,       x,       KC_MUTE, KC_VOLD, KC_VOLU, x,       x,       POINT,   x,       x,       x,       KC_SYSREQ, \
  _______, _______, _______, _______, _______,        x,         _______, _______, _______, _______, _______ \
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
[_MOVE] = LAYOUT_planck_mit( \
  _______, x,       x,       x,       x,       x,       x,       x,       x,       x,       x,       _______, \
  UNWIND,  x,       x,       x,       x,       x,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, x,       _______, \
  x,       x,       x,       x,       x,       x,       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  x,       x, \
  _______, _______, _______, x,       x,         POINT,          x,       x,       _______, _______, _______ \
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
[_POINT] = LAYOUT_planck_mit( \
  _______, x,       x,       x,       x,       x,       x,       x,       x,       x,       x,       _______, \
  UNWIND,  KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, _______, \
  x,       x,       x,       x,       x,       x,       KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, x,       x, \
  _______, _______, _______, x,       x,           MOVE,         x,       x,       _______, _______, _______ \
),

/* Quick control
 * ,-----------------------------------------------------------------------------------.
 * |      |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |  --  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  Alt |  Cmd |  --  |  --  |  --  | Left | Down |  Up  | Right|  --  |  --  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  --  |  --  |  --  |  --  |  --  | Home | PgDn | PgUp | End  |  --  |  --  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  --  |  --  |             |  --  |  --  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QUICK_CONTROL] = LAYOUT_planck_mit( \
  _______, x,       x,       x,       x,       x,       x,       x,       x,       x,       x,       _______, \
  _______, KC_LALT, KC_LGUI, x,       _______, x,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, _______, \
  x,       x,       x,       x,       x,       x,       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,  _______, \
  _______, _______, _______, x,       KC_LCTL,   _______,        x,       x,       _______, _______, _______ \
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
  _______, _______, _______, x,       x,           x,            x,       x,       _______, _______, _______ \
)

};

#define NO_CONTROL 0

int control_layer = NO_CONTROL;
int default_layer = _MODE1;
bool is_ext_layer_on = false;
bool is_ext_layer_pristine = false;
bool is_px_key_on = false;

int layer_ids[] = {
  _MODE1
  , _EXT
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
  case PX_SPACE:
    if (record->event.pressed) {
      if (is_ext_layer_on && is_ext_layer_pristine) {
        // emit tmux prefix key CTRL+SPACE
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
  default:
    if (is_ext_layer_on)
      is_ext_layer_pristine = false;
  }
  return true;
}

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

// #include "../../config.h"

#define PREVENT_STUCK_MODIFIERS

// magic mode not used
/* #pragma push_macro("IS_COMMAND") */
/* #undef IS_COMMAND */
/* #define IS_COMMAND() false */

/* #define PERMISSIVE_HOLD */
/* #define TAPPING_TERM_PER_KEY */
/* #define IGNORE_MOD_TAP_INTERRUPT */
#define TAPPING_TERM 200

/* TAP_HOLD_CAPS_DELAY 200 */

#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_MAX_SPEED 5
#define MOUSEKEY_MOVE_DELTA 4
#define MOUSEKEY_TIME_TO_MAX 50
#define MOUSEKEY_WHEEL_MAX_SPEED 0
#define MOUSEKEY_WHEEL_TIME_TO_MAX 255

#endif

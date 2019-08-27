#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#define PREVENT_STUCK_MODIFIERS

#pragma push_macro("IS_COMMAND")
#undef IS_COMMAND
#define IS_COMMAND() false

/* #define TAPPING_TERM 80 */

#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_MAX_SPEED 4
#define MOUSEKEY_TIME_TO_MAX 16
#define MOUSEKEY_WHEEL_MAX_SPEED 0
#define MOUSEKEY_WHEEL_TIME_TO_MAX 255

#endif

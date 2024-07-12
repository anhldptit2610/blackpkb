#include "profile.h"

int whichProfile;

key_profile_t profileList[][KEYMATRIX_ROW][KEYMATRIX_COL] = {
    [kiCAD_PROFILE] = {
        [0][0] = {.modifier = KEY_NONE, .key = KEY_0},
        [0][1] = {.modifier = KEY_NONE, .key = KEY_1},
        [0][2] = {.modifier = KEY_NONE, .key = KEY_2},
        [1][0] = {.modifier = KEY_NONE, .key = KEY_3},
        [1][1] = {.modifier = KEY_NONE, .key = KEY_4},
        [1][2] = {.modifier = KEY_NONE, .key = KEY_5},
    },
    [BROWSER_PROFILE] = {
        [0][0] = {.modifier = KEY_MOD_LCTRL, .key = KEY_C},
        [0][1] = {.modifier = KEY_MOD_LCTRL, .key = KEY_V},
        [0][2] = {.modifier = KEY_MOD_LCTRL | KEY_MOD_LSHIFT, .key = KEY_N},
        [1][0] = {.modifier = KEY_NONE, .key = KEY_D},
        [1][1] = {.modifier = KEY_NONE, .key = KEY_E},
        [1][2] = {.modifier = KEY_NONE, .key = KEY_F},
    },
    {}
};

int get_profile_number(void)
{
    return sizeof(profileList) / sizeof(profileList[0]);
}

void profile_select(int profile)
{
    whichProfile = profile;
}
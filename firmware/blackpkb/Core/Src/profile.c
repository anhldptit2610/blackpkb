#include "profile.h"

int whichProfile;

key_profile_t soundProfile[] = {
    [VOL_UP] = {KEY_MOD_RCTRL, KEY_9},
    [VOL_DOWN] = {KEY_MOD_RCTRL, KEY_0},
};

key_profile_t profileList[][KEYMATRIX_ROW][KEYMATRIX_COL] = {
    [kiCAD_PROFILE] = {
        [0][0] = {.modifier = KEY_NONE, .key = KEY_0},
        [0][1] = {.modifier = KEY_NONE, .key = KEY_1},
        [0][2] = {.modifier = KEY_NONE, .key = KEY_2},
        [1][0] = {.modifier = KEY_NONE, .key = KEY_3},
        [1][1] = {.modifier = KEY_NONE, .key = KEY_4},
        [1][2] = {.modifier = KEY_NONE, .key = KEY_5},
    },
    [CHROME_PROFILE] = {
        [0][0] = {.modifier = KEY_MOD_LCTRL, .key = KEY_C},
        [1][0] = {.modifier = KEY_MOD_LCTRL, .key = KEY_V},
        [0][1] = {.modifier = KEY_NONE, .key = KEY_F5},
        [1][1] = {.modifier = KEY_MOD_LCTRL | KEY_MOD_LSHIFT, .key = KEY_N},
        [0][2] = {.modifier = KEY_MOD_LCTRL, .key = KEY_W},
        [1][2] = {.modifier = KEY_MOD_LCTRL, .key = KEY_T},
    },
    {}
};

void set_mode_led(int mode0, int mode1, int mode2)
{
    HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, mode0);
    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, mode1);
    HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, mode2);
}

int get_profile_number(void)
{
    return sizeof(profileList) / sizeof(profileList[0]);
}

void profile_switch(void)
{
    static int i = 0;
    i = (i + 1) % (get_profile_number() - 1);
    profile_select(i);
}

void profile_select(int profile)
{
    whichProfile = profile;
    if (profile == 0)
        set_mode_led(0, 1, 1);
    else if (profile == 1)
        set_mode_led(1, 0, 1);
    else if (profile == 2)
        set_mode_led(1, 1, 0);
}
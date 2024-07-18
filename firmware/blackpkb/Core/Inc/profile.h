#ifndef PROFILE_H
#define PROFILE_H

#include "keymatrix.h"
#include "keycode.h"

typedef enum {
    kiCAD_PROFILE,
    BROWSER_PROFILE
} matrix_profile_t;

int get_profile_number(void);
void profile_switch(void);
void profile_select(int profile);

#endif
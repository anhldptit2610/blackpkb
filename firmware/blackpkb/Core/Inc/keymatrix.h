#ifndef KEYMATRIX_H
#define KEYMATRIX_H

#define KEYMATRIX_ROW       2
#define KEYMATRIX_COL       3

#include <stdbool.h>
#include "main.h"

typedef union {
    uint8_t instance[8];
    struct {
        uint8_t reportID;
        uint8_t modifier;
        uint8_t reserved;
        uint8_t key1;
        uint8_t key2;
        uint8_t key3;
        uint8_t key4;
        uint8_t key5;
    };
} key_report_t;

void keymatrix_scan(bool matrix[KEYMATRIX_ROW][KEYMATRIX_COL]);
void keymatrix_send_key(uint8_t modifier, uint8_t key);
void keymatrix_init(void);

#endif
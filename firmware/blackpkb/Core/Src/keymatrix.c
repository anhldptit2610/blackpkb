#include "keymatrix.h"
#include "usb_device.h"
#include "usbd_hid.h"
#include "main.h"

typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
    bool oldState;
    bool newState;
} macropad_key_t;

#define UP      1
#define DOWN    0

macropad_key_t keymatrix[KEYMATRIX_ROW][KEYMATRIX_COL];
key_report_t report;
extern USBD_HandleTypeDef hUsbDeviceFS;

static void keymatrix_pull_col(int col, bool upDown)
{
    switch (col) {
    case 1:
        HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, upDown); 
        break;
    case 2:
        HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, upDown); 
        break;
    case 3:
        HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, upDown); 
        break;
    default:
        break;
    }
}

static bool keymatrix_is_key_pressed(int row, int col)
{
    keymatrix[row][col].oldState = keymatrix[row][col].newState; 
    keymatrix[row][col].newState = HAL_GPIO_ReadPin(keymatrix[row][col].port, keymatrix[row][col].pin);
    return (!keymatrix[row][col].oldState && keymatrix[row][col].newState);
}

void keymatrix_send_key(uint8_t modifier, uint8_t key)
{
    report.modifier = modifier;
    report.key1 = key;
    USBD_HID_SendReport(&hUsbDeviceFS, report.instance, 8);
    HAL_Delay(20);
    report.modifier = 0x00;
    report.key1 = 0x00;
    USBD_HID_SendReport(&hUsbDeviceFS, report.instance, 8);
}

void keymatrix_scan(bool keymatrix[KEYMATRIX_ROW][KEYMATRIX_COL])
{
    keymatrix_pull_col(1, UP);
    keymatrix[0][0] = keymatrix_is_key_pressed(0, 0);
    keymatrix[1][0] = keymatrix_is_key_pressed(1, 0);
    keymatrix_pull_col(1, DOWN);
    keymatrix_pull_col(2, UP);
    keymatrix[0][1] = keymatrix_is_key_pressed(0, 1);
    keymatrix[1][1] = keymatrix_is_key_pressed(1, 1);
    keymatrix_pull_col(2, DOWN);
    keymatrix_pull_col(3, UP);
    keymatrix[0][2] = keymatrix_is_key_pressed(0, 2);
    keymatrix[1][2] = keymatrix_is_key_pressed(1, 2);
    keymatrix_pull_col(3, DOWN);
}

void keymatrix_init(void)
{
    keymatrix[0][0].port = keymatrix[0][1].port = keymatrix[0][2].port = ROW_1_GPIO_Port;
    keymatrix[1][0].port = keymatrix[1][1].port = keymatrix[1][2].port = ROW_2_GPIO_Port;
    keymatrix[0][0].pin = keymatrix[0][1].pin = keymatrix[0][2].pin = ROW_1_Pin;
    keymatrix[1][0].pin = keymatrix[1][1].pin = keymatrix[1][2].pin = ROW_2_Pin;

    for (int i = 0; i < KEYMATRIX_ROW; i++)
        for (int j = 0; j < KEYMATRIX_COL; j++)
            keymatrix[i][j].newState = keymatrix[i][j].oldState = 0;

    report.reportID = 1;  // report ID
    report.modifier = 0;  // modifier
    report.reserved = 0;  // reserved
    report.key1 = 0;
    report.key2 = 0;
    report.key3 = 0;
    report.key4 = 0;
    report.key5 = 0;
}
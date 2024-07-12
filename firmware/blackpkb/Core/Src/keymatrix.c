#include "keymatrix.h"
#include "usb_device.h"
#include "profile.h"
#include "usbd_hid.h"
#include "main.h"

typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
    bool oldState;
    bool newState;
} macropad_key_t;

extern key_profile_t profileList[][KEYMATRIX_ROW][KEYMATRIX_COL];
extern int whichProfile;

#define UP      1
#define DOWN    0

macropad_key_t keyMatrix[KEYMATRIX_ROW][KEYMATRIX_COL];
key_profile_t keyProfile[KEYMATRIX_ROW][KEYMATRIX_COL];
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
    keyMatrix[row][col].oldState = keyMatrix[row][col].newState; 
    keyMatrix[row][col].newState = HAL_GPIO_ReadPin(keyMatrix[row][col].port, keyMatrix[row][col].pin);
    return (!keyMatrix[row][col].oldState && keyMatrix[row][col].newState);
}

void keymatrix_send_key(uint8_t row, uint8_t col)
{
    report.modifier = profileList[whichProfile][row][col].modifier;
    report.key1 = profileList[whichProfile][row][col].key;
    USBD_HID_SendReport(&hUsbDeviceFS, report.instance, 8);
    HAL_Delay(20);
    report.modifier = 0x00;
    report.key1 = 0x00;
    USBD_HID_SendReport(&hUsbDeviceFS, report.instance, 8);
}

void keymatrix_scan(bool keyMatrix[KEYMATRIX_ROW][KEYMATRIX_COL])
{
    keymatrix_pull_col(1, UP);
    keyMatrix[0][0] = keymatrix_is_key_pressed(0, 0);
    keyMatrix[1][0] = keymatrix_is_key_pressed(1, 0);
    keymatrix_pull_col(1, DOWN);
    keymatrix_pull_col(2, UP);
    keyMatrix[0][1] = keymatrix_is_key_pressed(0, 1);
    keyMatrix[1][1] = keymatrix_is_key_pressed(1, 1);
    keymatrix_pull_col(2, DOWN);
    keymatrix_pull_col(3, UP);
    keyMatrix[0][2] = keymatrix_is_key_pressed(0, 2);
    keyMatrix[1][2] = keymatrix_is_key_pressed(1, 2);
    keymatrix_pull_col(3, DOWN);
}

void keymatrix_init(void)
{
    keyMatrix[0][0].port = keyMatrix[0][1].port = keyMatrix[0][2].port = ROW_1_GPIO_Port;
    keyMatrix[1][0].port = keyMatrix[1][1].port = keyMatrix[1][2].port = ROW_2_GPIO_Port;
    keyMatrix[0][0].pin = keyMatrix[0][1].pin = keyMatrix[0][2].pin = ROW_1_Pin;
    keyMatrix[1][0].pin = keyMatrix[1][1].pin = keyMatrix[1][2].pin = ROW_2_Pin;

    profile_select(BROWSER_PROFILE);

    for (int i = 0; i < KEYMATRIX_ROW; i++)
        for (int j = 0; j < KEYMATRIX_COL; j++)
            keyMatrix[i][j].newState = keyMatrix[i][j].oldState = 0;

    report.reportID = 1;  // report ID
    report.modifier = 0;  // modifier
    report.reserved = 0;  // reserved
    report.key1 = 0;
    report.key2 = 0;
    report.key3 = 0;
    report.key4 = 0;
    report.key5 = 0;
}
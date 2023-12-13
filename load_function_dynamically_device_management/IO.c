/******************************************************************************
 * INCLUDES
******************************************************************************/
#include <stdio.h>
#include "IO.h"
/******************************************************************************
 * VARIABLES
******************************************************************************/
static uint8_t* message[] = {
    "Command Successfully",
    "Allocation failed",
    "Device list is current empty",
    "Cannot find the device",
    "The position is invalid",
    "---EXIT---",
    "INVALID COMMAND",
    "INVALID ADDRESS"
};
/******************************************************************************
 * PROTOTYPES
******************************************************************************/
Device_Data_t* Device_Create_Information(Device_Data_t* data) {
    printf("Enter the name of device: ");
    fflush(stdin);
    scanf("%s", &(data->name));
    printf("Enter the power of device: ");
    fflush(stdin);
    scanf("%f", &(data->power));
    printf("Enter the price of device: ");
    fflush(stdin);
    scanf("%d", &(data->price));
}

Device_Manage_Error_Code_t Device_Display_All(void) {
    Device_Manage_Error_Code_t error_code = DEVICE_LIST_EMPTY;
    uint16_t len = Device_Get_List_Length();
    system("cls");
    if(len > 0) {
        uint16_t index = 0;
        Device_Data_t data;
        printf("ORD    |Device Name         |Power     |Price\n");
        for(index; index < len; ++ index) {
            printf("-------|--------------------|----------|-----\n");
            error_code = Device_Get_Information(&data, index);
            printf("%-7d|%-20s|%-10f|%d\n", index, data.name, data.power, data.price);
        }
    }
    return error_code;
}

uint8_t* IO_Message(Device_Manage_Error_Code_t error_code) {
    return message[error_code];
}
/******************************************************************************
 * END OF FILE
******************************************************************************/
/******************************************************************************
 * INCLUDES
******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include "Device_Manage.h"
#include "IO.h"
/******************************************************************************
 * DEFINITIONS
******************************************************************************/
void main() {
    Device_Data_t device_information;
    Device_Manage_Error_Code_t error_code;
    uint16_t option = 0;
    uint16_t position;

    do {
        printf("\n___________________________________________________________________\n");
        printf("Program to manage electric device\n"
        "- 'a' to add a new device.\n"
        "- 'd' to delete a device.\n"
        "- 's' to show all device.\n"
        "- 'e' to exit the program.\n");
        printf("___________________________________________________________________");
        printf("\nPlease enter a key to select action\n");
        /*Get the option*/
        fflush(stdin);
        scanf("%s", &option);
        /*option handling*/
        switch (option) {
            case 'a':
                Device_Create_Information(&device_information);
                printf("Enter the position to add: ");
                fflush(stdin);
                scanf("%d", &position);
                error_code = Device_Add(position, &device_information);
                break;
            
            case 'd':
                printf("Enter the position to delete: ");
                fflush(stdin);
                scanf("%d", &position);
                error_code = Device_Delete(position);
                break;

            case 's':
                error_code = Device_Display_All();
                break;

            case 'e':
                error_code = EXIT;
                break;
            
            default:
                error_code = INVALID_COMMAND;
                break;
        }

        printf("\n%s\n", IO_Message(error_code));
    } while (option != 'e');
}
/******************************************************************************
 * END OF FILE
******************************************************************************/
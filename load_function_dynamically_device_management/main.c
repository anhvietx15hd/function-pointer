/******************************************************************************
 * INCLUDES
******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include "Device_Manage.h"
#include "IO.h"
/******************************************************************************
 * TYPEDEFS
******************************************************************************/
typedef enum {
    ADD             = 0,
    DELETE          = 1,
    SHOW            = 2,
    NO_COMMAND      = 3
} Device_Command_t;
/*Define the function pointer prototype*/
typedef Device_Manage_Error_Code_t (*device_command)(void);

/******************************************************************************
 *PROTOTYPES
******************************************************************************/
Device_Manage_Error_Code_t Add(void);
Device_Manage_Error_Code_t Delete(void);
Device_Manage_Error_Code_t Show(void);
/******************************************************************************
 * VARIABLES
******************************************************************************/
device_command command[] = {Add, Delete, Show};
/******************************************************************************
 * DEFINITIONS
******************************************************************************/
void main() {
    /*Show the address of functions*/
    printf("%x %x %x\n", command[ADD], command[DELETE], command[SHOW]);
    
    Device_Data_t device_information;
    Device_Manage_Error_Code_t error_code;
    uint16_t option = 0;
    Device_Command_t cmd_option = NO_COMMAND;

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
                /*Assign the index of function pointer in function pointer array*/
                cmd_option = ADD;
                break;
            
            case 'd':
                cmd_option = DELETE;
                break;

            case 's':
                cmd_option = SHOW;
                break;

            case 'e':
                error_code = EXIT;
                break;
            
            default:
                error_code = INVALID_COMMAND;
                break;
        }
        if(cmd_option != NO_COMMAND) {
            /*Call function*/
            error_code = command[cmd_option]();
        }
        /*Show the message after the action is done*/
        printf("\n%s\n", IO_Message(error_code));
    } while (option != 'e');
}

Device_Manage_Error_Code_t Add(void) {
    Device_Manage_Error_Code_t error_code;
    uint16_t position;
    Device_Data_t device_information;

    Device_Create_Information(&device_information);
    printf("Enter the position to add: ");
    fflush(stdin);
    scanf("%d", &position);
    error_code = Device_Add(position, &device_information);

    return error_code;
}

Device_Manage_Error_Code_t Delete(void) {
    Device_Manage_Error_Code_t error_code;
    uint16_t position;

    printf("Enter the position to delete: ");
    fflush(stdin);
    scanf("%d", &position);
    error_code = Device_Delete(position);

    return error_code;
}

Device_Manage_Error_Code_t Show(void) {
    return Device_Display_All();
}
/******************************************************************************
 * END OF FILE
******************************************************************************/

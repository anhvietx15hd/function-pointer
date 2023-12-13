/******************************************************************************
 * INCLUDES
******************************************************************************/
#include <stdlib.h>
#include "Device_Manage.h"
/******************************************************************************
 * VARIABLES
******************************************************************************/
static Device_List_t device_list = {NULL, NULL, 0};
/******************************************************************************
 * PROTOTYPES
******************************************************************************/
static Device_Manage_Error_Code_t Device_Add_First_Device(Device_Data_t* device_data);
static Device_Manage_Error_Code_t Device_Add_To_Head(Device_Data_t* device_data);
static Device_Manage_Error_Code_t Device_Add_To_Normal_Position(uint16_t position, Device_Data_t* device_data);
static void Device_Delete_At_Head();
static void Device_Delete_At_Normal_Position(uint16_t position);
/******************************************************************************
 * DEFINITIONS
******************************************************************************/
Device_Manage_Error_Code_t Device_Add(uint16_t position, Device_Data_t* device_data) {
    Device_Manage_Error_Code_t error_code = INVALID_POSITION;
    if(device_list.number_of_device <= 0) {
        /*Add the first device for list*/
        error_code = Device_Add_First_Device(device_data);
    } else if(position == 0) {
        error_code = Device_Add_To_Head(device_data);
    } else {
        error_code = Device_Add_To_Normal_Position(position, device_data);
    }
    return error_code;

}

static Device_Manage_Error_Code_t Device_Add_First_Device(Device_Data_t* device_data) {
    Device_Manage_Error_Code_t error_code = ALLOCATION_FAILED;
    Device_Node_t* new_node;
    /*Memory Allocation for new node*/
    new_node = (Device_Node_t*)malloc(sizeof(Device_Node_t));
    if(new_node != NULL) {
        new_node->data = *device_data;
        new_node->next = NULL;

        device_list.head = new_node;
        device_list.tail = device_list.head;
        ++ device_list.number_of_device;

        error_code = SUCCESSFULLY;
    }
    return error_code;
}

static Device_Manage_Error_Code_t Device_Add_To_Head(Device_Data_t* device_data) {
    Device_Manage_Error_Code_t error_code = ALLOCATION_FAILED;
    Device_Node_t* new_node;
    /*Memory Allocation for new node*/
    new_node = (Device_Node_t*)malloc(sizeof(Device_Node_t));
    if(new_node != NULL) {
        new_node->data = *device_data;
        new_node->next = device_list.head;
        /*Update the new head*/
        device_list.head = new_node;
        ++ device_list.number_of_device;

        error_code = SUCCESSFULLY;
    }
    return error_code;
}

static Device_Manage_Error_Code_t Device_Add_To_Normal_Position(uint16_t position, Device_Data_t* device_data) {
    Device_Manage_Error_Code_t error_code = INVALID_POSITION;

    if(position <= device_list.number_of_device) {
        Device_Node_t* new_node;
        error_code = ALLOCATION_FAILED;
        /*Memory Allocation for new node*/
        new_node = (Device_Node_t*)malloc(sizeof(Device_Node_t));

        if(new_node != NULL) {
            uint16_t index = 0;
            Device_Node_t* tmp_node = device_list.head;

            new_node->data = *device_data;
            /*Trave to the device position*/
            for(index; index < position - 1; ++index) {
                tmp_node = tmp_node->next;
            }

            if(position == device_list.number_of_device) {
                /*Add to the tail*/
                new_node->next = NULL;
                tmp_node->next = new_node;
                /*Update the new tail*/
                device_list.tail = new_node;
            } else {
                /*Add to others position*/
                new_node->next = tmp_node->next;
                tmp_node->next = new_node;
            }

            ++ device_list.number_of_device;
            error_code = SUCCESSFULLY;
        }
    }
    return error_code;
}

Device_Manage_Error_Code_t Device_Get_Information(Device_Data_t* output_data, uint16_t position) {
    Device_Manage_Error_Code_t error_code = INVALID_POSITION;
    if(device_list.number_of_device <=0) {
        error_code = DEVICE_LIST_EMPTY;
    }
    /*Check if the position is valid*/
    if((error_code != DEVICE_LIST_EMPTY) && (position < device_list.number_of_device)) {
        error_code = INVALID_ADDRESS;
        if(output_data != NULL){
            Device_Node_t* tmp_node = device_list.head;
            uint16_t index = 0;

            for(index; index < position; ++ index){
                tmp_node = tmp_node->next;
            }
            /*Assign to the output*/
            *output_data = tmp_node->data;
            error_code = SUCCESSFULLY;
        }  
    }

    return error_code;

}

uint16_t Device_Get_List_Length(void) {
    return device_list.number_of_device;
}


Device_Manage_Error_Code_t Device_Delete(uint8_t position) {
    Device_Manage_Error_Code_t error_code = INVALID_POSITION;
    if(device_list.number_of_device <=0) {
        error_code = DEVICE_LIST_EMPTY;
    }
    /*Check if the position is valid*/
    if((error_code != DEVICE_LIST_EMPTY) && (position < device_list.number_of_device)) {
        if(position == 0) {
            Device_Delete_At_Head();
        } else {
            Device_Delete_At_Normal_Position(position);
        }

        -- device_list.number_of_device;
        error_code = SUCCESSFULLY;
    }
    return error_code;
}

static void Device_Delete_At_Head() {
    Device_Node_t* tmp_node = device_list.head;
    /*Update the new head*/
    device_list.head = device_list.head->next;

    free(tmp_node);
}

static void Device_Delete_At_Normal_Position(uint16_t position) {
    Device_Node_t* tmp = device_list.head;
    Device_Node_t* delete_node;
    uint16_t index = 0;

    for(index; index < (position - 1); ++ index) {
        tmp = tmp->next;
    }
    delete_node = tmp->next;
    tmp->next = delete_node->next;
    /*Update the new tail*/
    if(position == (device_list.number_of_device - 1)) {
        device_list.tail = tmp;
    }
    free(delete_node);
}
/******************************************************************************
 * END OF FILE
******************************************************************************/

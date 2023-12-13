/**
 * \file            Device_Manage.h
 * \author          Le Hung VIET (anhvietx15hd@gmail.com)
 * \brief           Device manage using struct and dynamic linked-list
 * \version         0.1
 * \date            2023-12-05
 */
#ifndef _DEVICE_MANAGE_H_
#define _DEVICE_MANAGE_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/******************************************************************************
 * INCLUDES
******************************************************************************/
#include <stdint.h>
#include <stdio.h>
/******************************************************************************
 * DEFINITIONS
******************************************************************************/
#define DEVICE_NAME_MAX_LENGTH          20U
/******************************************************************************
 * PROTOTYPES
******************************************************************************/
typedef struct {
    uint8_t         name[DEVICE_NAME_MAX_LENGTH];
    float           power;
    uint32_t        price;
}Device_Data_t;

typedef struct Node {
    Device_Data_t          data;
    struct Node*           next;
} Device_Node_t;

typedef struct {
    Device_Node_t*  head;
    Device_Node_t*  tail;
    uint16_t        number_of_device;         
} Device_List_t;

typedef enum {
    SUCCESSFULLY,                       /*Action done successfully*/
    ALLOCATION_FAILED,                   /*Fail to allocate memory for new device*/
    DEVICE_LIST_EMPTY,
    DEVICE_CANNOT_FOUND,
    INVALID_POSITION,
    EXIT,
    INVALID_COMMAND,
    INVALID_ADDRESS
} Device_Manage_Error_Code_t;
/******************************************************************************
 * APIs
******************************************************************************/

/**
 * \brief           Add a new device to list
 * \param[in]       position: The position need to add device
 * \param[in]       device_data: The information about device
 * \return          Error Code
 */
Device_Manage_Error_Code_t Device_Add(uint16_t position, Device_Data_t* device_data);

/**
 * \brief           Get all information about the device
 * \param[in]       output_data: The address of output data
 * \param[in]       position: Position of device need to get information
 * \return          Error Code
 */

Device_Manage_Error_Code_t Device_Delete(uint8_t position);

/**
 * \brief           Get all information about device
 * \param[in]       output_data: output data address
 * \param[in]       position: The position of device in list
 * \return          Device_Manage_Error_Code_t 
 */
Device_Manage_Error_Code_t Device_Get_Information(Device_Data_t* output_data, uint16_t position);

uint16_t Device_Get_List_Length(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DEVICE_MANAGE_H_ */
/******************************************************************************
 * END OF FILE
******************************************************************************/
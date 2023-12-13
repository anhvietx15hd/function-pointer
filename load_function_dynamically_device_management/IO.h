/**
 * \file            IO.h
 * \author          Le Hung VIET (anhvietx15hd@gmail.com)
 * \version         0.1 
 */

#ifndef _IO_H_
#define _IO_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/******************************************************************************
 * INCLUDES
******************************************************************************/
#include <stdint.h>
#include "Device_Manage.h"
/******************************************************************************
 * APIs
******************************************************************************/
Device_Data_t* Device_Create_Information(Device_Data_t* data);

Device_Manage_Error_Code_t Device_Display_All(void);

uint8_t* IO_Message(Device_Manage_Error_Code_t error_code);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _IO_H_ */
/******************************************************************************
 * END OF FILE
******************************************************************************/
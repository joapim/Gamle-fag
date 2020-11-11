/**
* @file
* @brief Library for doing light operations
*/
#include "elev.h"
#include "state.h"
#include <stdio.h>
#include "channels.h"


/**
* @brief Reset all lights on @p floor
*
* @param[in] floor Specified floor
*/
void reset_floor_lights(int floor);


/**
* @brief Reset all lights on every floor except emergency STOP
*
*/
void reset_all_lights_except_stop();

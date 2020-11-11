/**
* @file
* @brief Implementation file for light functions.
*/

#include "lights.h"


void reset_floor_lights(int floor){
    if (floor != 3){
        elev_set_button_lamp(BUTTON_CALL_UP, floor, 0);
    }
    if (floor != 0){
        elev_set_button_lamp(BUTTON_CALL_DOWN, floor, 0);
    }
    elev_set_button_lamp(BUTTON_COMMAND, floor,0);
}


void reset_all_lights_except_stop(){
    for (int floor = 0; floor < 4; floor++){
        reset_floor_lights(floor);
    }
}

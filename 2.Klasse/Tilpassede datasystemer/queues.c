/**
* @file
* @brief Implementation file for queue functions.
*/

#include "queues.h"

void update_queue_and_lights(elevator_t * elev){
    for (int floor = 0; floor < 3; floor++){
        if (elev_get_button_signal(BUTTON_CALL_UP, floor)){
            elev_set_button_lamp(BUTTON_CALL_UP, floor, 1);
            elev->UP_queue[floor] = 1;
        }
    }
    for (int floor = 1; floor < 4; floor++){
        if (elev_get_button_signal(BUTTON_CALL_DOWN, floor)){
            elev_set_button_lamp(BUTTON_CALL_DOWN, floor, 1);
            elev->DOWN_queue[floor] = 1;
        }
    }
    for (int floor = 0; floor < 4; floor++){
        if (elev_get_button_signal(BUTTON_COMMAND, floor)){
            elev_set_button_lamp(BUTTON_COMMAND, floor, 1);
            elev->panel_queue[floor] = 1;
        }
    }
}


void clear_floor_queue(elevator_t *elev, int floor){
    elev->UP_queue[floor] = 0;
    elev->DOWN_queue[floor] = 0;
    elev->panel_queue[floor] = 0;
}


void clear_all_queues(elevator_t *elev){
    for (int i = 0; i < 4 ; i++){
        elev->UP_queue[i] = 0;
        elev->DOWN_queue[i] = 0;
        elev->panel_queue[i] = 0;
    }
}


int queues_at_floor(elevator_t *elev){
    int i = elev->current_floor;
    if(elev->current_floor == -1){
        return 0;
    }
    if( elev->UP_queue[i] == 1 ||  elev->DOWN_queue[i] == 1 || elev->panel_queue[i] == 1){
        return 1;
    }
    return 0;
}


int queues_at_prev_floor(elevator_t *elev){
    int i = elev->prev_floor;
    if( elev->UP_queue[i] == 1 ||  elev->DOWN_queue[i] == 1 || elev->panel_queue[i] == 1){
        return 1;
    }
    return 0;
}


int if_queues_ABOVE(elevator_t * elev){
    int current_floor = elev->prev_floor+1;
    for (int floor = current_floor; floor < 3; floor++){
        if (elev->UP_queue[floor]){
            return 1;
        }
    }
    for (int floor = current_floor; floor < 4; floor++){
        if (elev->DOWN_queue[floor]){
            return 1;
        }
    }
    for (int floor = current_floor; floor < 4; floor++){
        if (elev->panel_queue[floor]){
            return 1;
        }
    }
    return 0;
}


int if_queues_BELOW(elevator_t * elev){
    int current_floor = elev->prev_floor;
    for (int floor = 0; floor < current_floor; floor++){
        if (elev->UP_queue[floor]){
            return 1;
        }
    }
    for (int floor = 0; floor < current_floor; floor++){
        if (elev->DOWN_queue[floor]){
            return 1;
        }
    }
    for (int floor = 0; floor < current_floor; floor++){
        if (elev->panel_queue[floor]){
            return 1;
        }
    }
    return 0;
}


bool is_queue_empty(elevator_t * elev){
    for (int i = 0; i < 4; i++){
        if (elev->UP_queue[i] || elev->DOWN_queue[i] || elev->panel_queue[i]){
            return false;
        }
    }
    return true;
}

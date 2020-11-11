/**
* @file
* @brief Implementation file for state functions.
*/

#include "state.h"
#include "queues.h"
#include <stdlib.h>


void start_elev(){
    // Initialize hardware
    if (!elev_init()) {
        printf("Unable to initialize elevator hardware!\n");
        exit(1); //terminate
    }

    while(elev_get_floor_sensor_signal() == -1){
        elev_set_motor_direction(DIRN_DOWN);
    }
    elev_set_motor_direction(DIRN_STOP);
    elev_set_floor_indicator(elev_get_floor_sensor_signal());
}


void initialize_elevator_t(elevator_t * elev){
    elev->current_floor = elev_get_floor_sensor_signal();
    elev->prev_floor = elev_get_floor_sensor_signal();
    elev->state = IDLESTATE;
    elev->motor = DIRN_STOP;
    elev->prev_dir = DIRN_DOWN;

    for (int i = 0; i < 4 ; i++){
        elev->UP_queue[i] = 0;
        elev->DOWN_queue[i] = 0;
        elev->panel_queue[i] = 0;
    }

}


void update_floor_indicator(elevator_t *elev){
    int floor = elev_get_floor_sensor_signal();
    if (floor != -1){
        elev->current_floor = floor;
        elev->prev_floor = floor;
        elev_set_floor_indicator(floor);
    }
}


void open_door(){
    if (elev_get_floor_sensor_signal() != -1){
        elev_set_door_open_lamp(1);
    }
}

void check_stop_button(elevator_t *elev){
    if (elev_get_stop_signal()){
        elev->state = STOPSTATE;
    }
}


void stop_elevator(elevator_t* elev){
    clear_all_queues(elev);
    elev_set_motor_direction(DIRN_STOP);
    elev->motor = DIRN_STOP;
    reset_all_lights_except_stop();


    elev_set_stop_lamp(1);
    open_door();
    while (elev_get_stop_signal());
    elev_set_stop_lamp(0);
    restart_timer();
}


void wait_floor(elevator_t * elev){
    elev->motor = DIRN_STOP;
    elev_set_motor_direction(DIRN_STOP);
    open_door();
    elev->state = DOOR_OPEN;

    if(isTimerDone() == 1){
        elev_set_door_open_lamp(0);
        elev->state = IDLESTATE;
    }
}



void shall_i_stop(elevator_t *elev){
    elev->current_floor = elev_get_floor_sensor_signal();
    elev->prev_dir = elev->motor;
    if (elev->current_floor != -1){

        if(elev->motor == DIRN_UP){

            if ((elev->UP_queue[elev->current_floor] || elev->panel_queue[elev->current_floor]) || (if_queues_ABOVE(elev)==0)){
                elev->motor = DIRN_STOP;
                elev_set_motor_direction(DIRN_STOP);
                elev->state = DOOR_OPEN;
                clear_floor_queue(elev, elev->current_floor);
                reset_floor_lights(elev->current_floor);
                restart_timer();
                }
            }
        if(elev->motor == DIRN_DOWN){
            if ((elev->DOWN_queue[elev->current_floor] || elev->panel_queue[elev->current_floor]) || (if_queues_BELOW(elev)==0)){
                elev->motor = DIRN_STOP;
                elev_set_motor_direction(DIRN_STOP);
                elev->state = DOOR_OPEN;
                clear_floor_queue(elev, elev->current_floor);
                reset_floor_lights(elev->current_floor);
                restart_timer();
                }
            }
        }
    }


int continue_after_pause(elevator_t * elev){
    if (elev->prev_dir == DIRN_UP && if_queues_ABOVE(elev)){
        elev->motor = DIRN_UP;

        elev_set_motor_direction(DIRN_UP);

        elev->state = MOVESTATE;
        return 1;
    }

    if (elev->prev_dir == DIRN_DOWN && if_queues_BELOW(elev)){
        elev->motor = DIRN_DOWN;

        elev_set_motor_direction(DIRN_DOWN);

        elev->state = MOVESTATE;
        return 1;
    }
    return 0;
}


void decide_direction(elevator_t * elev){
    if (is_queue_empty(elev)) {
        elev->motor = DIRN_STOP;
        elev->state = IDLESTATE;
        return;
    }

    if(queues_at_floor(elev)){
        elev->motor = DIRN_STOP;
        elev->state = DOOR_OPEN;
        elev_set_motor_direction(DIRN_STOP);
        return;
    }

    if (continue_after_pause(elev)){
        return;
    }

    if (if_queues_BELOW(elev)){
        elev->motor = DIRN_DOWN;
        elev->state = MOVESTATE;
        elev_set_motor_direction(DIRN_DOWN);
        return;
    }

    if (if_queues_ABOVE(elev)){
        elev->motor = DIRN_UP;
        elev->state = MOVESTATE;
        elev_set_motor_direction(DIRN_UP);
        return;
    }

}

void decide_direction_after_stop(elevator_t * elev){
    if (is_queue_empty(elev)) {
        elev->motor = DIRN_STOP;
        elev->state = BETWEEN_FLOOR;
        return;
    }

    if(queues_at_floor(elev)){
        elev->motor = DIRN_STOP;
        elev->state = DOOR_OPEN;
        elev_set_motor_direction(DIRN_STOP);
        return;
    }

    if (continue_after_pause(elev)){
        return;
    }

    if (if_queues_BELOW(elev)){
        elev->motor = DIRN_DOWN;
        elev->state = MOVESTATE;
        elev_set_motor_direction(DIRN_DOWN);
        return;
    }

    if (if_queues_ABOVE(elev)){
        elev->motor = DIRN_UP;
        elev->state = MOVESTATE;
        elev_set_motor_direction(DIRN_UP);
        return;
    }



    if (!(is_queue_empty(elev))) {
        if (queues_at_prev_floor(elev)){
            if (elev->isAbove == 1){
                elev->motor = DIRN_DOWN;
                elev->state = MOVESTATE;
                elev_set_motor_direction(DIRN_DOWN);
            }
            else {
                elev->motor = DIRN_UP;
                elev->state = MOVESTATE;
                elev_set_motor_direction(DIRN_UP);
            }
        }
    }
}

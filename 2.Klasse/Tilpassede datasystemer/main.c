/**
* @file
* @brief Main file. Shows state logic.
*/

#include "elev.h"
#include "state.h"
#include "queues.h"
#include "timer.h"
#include <stdio.h>


int main() {
    start_elev();

    elevator_t elev;
    initialize_elevator_t(&elev);


    while (1) {
        check_stop_button(&elev);
        update_floor_indicator(&elev);
        update_queue_and_lights(&elev);

        switch(elev.state){
            case IDLESTATE:
                decide_direction(&elev);
                if(queues_at_floor(&elev)){
                    shall_i_stop(&elev);
                }
                if (elev.motor == DIRN_UP){
                    elev.isAbove = 1;
                } else if (elev.motor == DIRN_DOWN){
                    elev.isAbove = 0;
                }

                break;
            case STOPSTATE:
                stop_elevator(&elev);
                if (elev.current_floor == -1){
                    elev.state = BETWEEN_FLOOR;
                } else{
                    elev.state = DOOR_OPEN;
                }
                break;

            case BETWEEN_FLOOR:
                decide_direction_after_stop(&elev);
                break;


            case DOOR_OPEN:
                if(queues_at_floor(&elev)==1){
                    restart_timer();
                    clear_floor_queue(&elev, elev.current_floor);
                    reset_floor_lights(elev.current_floor);
                }
                wait_floor(&elev);
                break;
            case MOVESTATE:
                shall_i_stop(&elev);
                break;
        }
    }

    return 0;
}

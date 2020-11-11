/**
* @file
* @brief Library of state related functions, i.e initialize and elevator logic.
*/

#pragma once
#include "elev.h"
#include "lights.h"
#include "timer.h"
#include <stdio.h>
#include <stdbool.h>

/**
* @brief The different states of the elevator.
*/
typedef enum tag_states {   IDLESTATE,
                            DOOR_OPEN,
                            STOPSTATE,
                            MOVESTATE,
                            BETWEEN_FLOOR } state_t;

/**
* @brief  Struct containing variables related to the elevator
*/
typedef struct tag_elevator {
    int current_floor;
    unsigned int prev_floor;
    int isAbove;
    elev_motor_direction_t motor;
    elev_motor_direction_t prev_dir;
    state_t state;
    int UP_queue[4];
    int DOWN_queue[4];
    int panel_queue[4];
} elevator_t;


/**
* @brief Initializing elevator's hardware and putting it in a defined state.
*
* @warning If hardware initialization fails, the program terminates
* with exit code 1.
*/
void start_elev();

/**
* @brief Initializes elevator struct; defining its variables.
*
* @param[in, out] elev Elevator struct
*/
void initialize_elevator_t(elevator_t * elev);


/**
* @brief Updates floor light indicator.
*
* @param[in, out] elev Elevator struct, updating current_floor and prev_floor.
*/
void update_floor_indicator(elevator_t * elev);


/**
* @brief Sets door open light given it is in a defined floor.
*/
void open_door();


/**
* @brief Polls the STOP button, setting the elevator to STOPSTATE if triggered.
*
* @param[in, out] elev Elevator struct
*/
void check_stop_button(elevator_t *elev);


/**
* @brief Executes series of tasks if elevator is in STOPSTATE.
* Clears all queues and lights, sets STOP light and door light depending on
* the elevators position.
*
* @param[in, out] elev Elevator struct
*/
void stop_elevator(elevator_t *elev);


/**
* @brief The elevator pause at a floor, opening its door for 3 seconds.
*
* @param[in, out] elev Elevator struct
*/
void wait_floor(elevator_t *elev);

/**
* @brief Stops the elevator if the floor it reaches has a queue.
* Clears all queues and lights on floor if it stops,
* as well as restarting timer.
*
* @param[in, out] elev Elevator struct
*/
void shall_i_stop(elevator_t * elev);


/**
* @brief Continues elevator if there are unfinished orders in the
* same direction.
*
* @param[in, out] elev Elevator struct
*
* @return 1 if it should continue, 0 if it should stop.
*/
int continue_after_pause(elevator_t * elev);



/**
* @brief Decides direction based on queues and the previous direction.
*
* @param[in, out] elev Elevator struct
*/
void decide_direction(elevator_t * elev);


/**
* @brief Decides the direction if emergency stop has been activated
*  and the elevator is in the BETWEEN_FLOOR state.
*
* @param[in, out] elev Elevator struct
*/
void decide_direction_after_stop(elevator_t * elev);

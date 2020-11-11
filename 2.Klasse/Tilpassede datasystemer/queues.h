/**
* @file
* @brief Library containing functions related to queue logic.
*/

#pragma once
#include "state.h"
#include <stdio.h>


/**
* @brief Polling all the buttons, setting the light and adding them to queue
* whenever pressed.
*
* @param[in, out] elev Elevator struct.
*/
void update_queue_and_lights(elevator_t * elev);


/**
* @brief Clears all queues (UP, DOWN, PANEL) on specific @p floor.
*
* @param[in, out] elev Elevator struct.
* @param [in] floor Specifies which floor to reset queues.
*/
void clear_floor_queue(elevator_t *elev, int floor);


/**
* @brief Clears all queues on all floors.
*
* @param[in, out] elev Elevator struct
*/
void clear_all_queues(elevator_t *elev);

/**
* @brief Checks if there are any queues on current floor.
*
* @param[in, out] elev Elevator struct.
*
* @return 1 if there are any queues on current floor, 0 otherwise.
*/
int queues_at_floor(elevator_t * elev);


/**
* @brief Checks if there are any queues on previously passed floor.
*
* @param[in, out] elev Elevator struct.
*
* @return 1 if there are any queues on previous floor. Returns 0 if
* there are no queues or the elevator is between floors.
*/
int queues_at_prev_floor(elevator_t * elev);

/**
* @brief Checks if there are any queues on the floors above the current floor.
*
* @param[in, out] elev Elevator struct.
*
* @return 1 if found any queues above, 0 otherwise.
*/
int if_queues_ABOVE(elevator_t * elev);


/**
* @brief Checks if there are any queues on the floors below the current floor.
*
* @param[in, out] elev Elevator struct.
*
* @return 1 if found any queues below, 0 otherwise.
*/
int if_queues_BELOW(elevator_t * elev);

/**
* @brief Checks if there are any active queues on any of the floors.
*
* @param[in, out] elev Elevator struct.
*
* @return @c true if no queues were found, @c false otherwise.
*/
bool is_queue_empty(elevator_t * elev);

/**
* @file
* @brief Implementation file for timer functions.
*/

#include "timer.h"


clock_t before;


void restart_timer(){
     before = clock();
}


int isTimerDone(){
    clock_t difference = clock() - before;
    int msec = difference * 1000 / CLOCKS_PER_SEC;
    if(msec > 3000){
        return 1;
    }else{
        return 0;
    }
}

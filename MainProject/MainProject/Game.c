#include "Game.h"

#include <time.h>

Bool game_over;

int initGame(void){
    srand((unsigned int)time(NULL));

    initMap();
    spreadFood();
    spreadPoint();

    return 0;
}

int updateGame(time_t ElapsedTime){
    static time_t timer=0;
    timer+=ElapsedTime;
    if( timer > 2000){
        updateMap();
        timer -= 2000;
    }

    return 0;
}

int deleteGame(void){
    return 0;
}

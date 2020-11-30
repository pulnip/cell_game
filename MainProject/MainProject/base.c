#include "base.h"

#include <time.h>
#include <stdio.h>

int main(void){
    if( OnStart() )game_over=True;

    time_t t1, t2;
    t1=t2=clock();

    while( !game_over ){
        t2=clock();
        time_t _ElapsedTime=t2-t1;

        t1=t2;
        if( OnUpdate(_ElapsedTime) )game_over=True;
    }

    OnDestroy();
    return 0;
}

int OnStart(){
    if( (
        initInfra()    ||
        initGame()     ||
        initUserCell() ||
        initCPUCell()
        // add ...
    ) ) return 1;
    return 0;
}

int OnUpdate(time_t ElapsedTime){
    if( (
        updateInfra1()          ||
        updateGame(ElapsedTime) ||
        updateUserCell()        ||
        updateCPUCell()         ||
        updateInfra2()
        // add ...
    ) ) return 1;
    return 0;
}

int OnDestroy(){
    deleteUserCell();
    deleteCPUCell();
    deleteGame();
    deleteInfra();
    waitUntilKeyInput();
    // add ...

    return 0;
}

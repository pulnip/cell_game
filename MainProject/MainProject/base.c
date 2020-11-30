#include "base.h"

#include <time.h>
#include <stdio.h>

// <OnStart()>
#ifndef __INC_INFRA 
int initInfra(void)     _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_GAME
int initGame(void)     _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_USER_CELL
int initUserCell(void) _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_CPU_MAIN
int initCPUCell(void)  _INT_FUNC_NOT_IMPLEMENT
#endif
// </OnStart()>

// <OnUpdate()>
#ifndef __INC_INFRA
int FastEscape(void)     _INT_FUNC_NOT_IMPLEMENT
int updateInfra1(void)   _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_GAME
int updateGame(void)     _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_USER_CELL
int updateUserCell(time_t ElapsedTime) _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_CPU_MAIN
int updateCPUCell(void)  _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_INFRA
int updateInfra2(void)   _INT_FUNC_NOT_IMPLEMENT
#endif
// </OnUpdate>


// <OnDestroy()>
#ifndef __INC_USER_CELL
int deleteUserCell(void)     _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_CPU_MAIN
int deleteCPUCell(void)      _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_GAME
int deleteGame(void)         _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_INFRA
int deleteInfra(void)        _INT_FUNC_NOT_IMPLEMENT
void waitUntilKeyInput(void) _INT_FUNC_NOT_IMPLEMENT
#endif
// </OnDestroy()>

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
        updateInfra1()              ||
        updateGame(ElapsedTime)     ||
        updateUserCell(ElapsedTime) ||
        updateCPUCell(ElapsedTime)  ||
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

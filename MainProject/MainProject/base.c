#include "base.h"

#include <time.h>

// <OnStart()>

#ifndef __INC_INFRA 
int initInfra(void)     _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_GAME
int initGame(void)     _INT_FUNC_NOT_IMPLEMENT
#endif
int initUser(void)     _INT_FUNC_NOT_IMPLEMENT
int initComputer(void) _INT_FUNC_NOT_IMPLEMENT

// </OnStart()>

// <OnUpdate()>

#ifndef __INC_INFRA
int FastEscape(void)     _INT_FUNC_NOT_IMPLEMENT
int updateInfra1(void)   _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_GAME
int updateGame(void)     _INT_FUNC_NOT_IMPLEMENT
#endif
int updateUser(void)     _INT_FUNC_NOT_IMPLEMENT
int updateComputer(void) _INT_FUNC_NOT_IMPLEMENT
#ifndef __INC_INFRA
int updateInfra2(void)   _INT_FUNC_NOT_IMPLEMENT
#endif

// </OnUpdate>


// <OnDestroy()>

#ifndef __INC_GAME
int deleteGame(void)         _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_INFRA
int deleteInfra(void)        _INT_FUNC_NOT_IMPLEMENT
void waitUntilKeyInput(void) _INT_FUNC_NOT_IMPLEMENT
#endif

// </OnDestroy()>

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
        initUser()     ||
        initComputer()
        // add ...
    ) ) return 1;
    return 0;
}

int OnUpdate(time_t ElapsedTime){
    if( (
        updateInfra1()          ||
        updateGame(ElapsedTime) ||
        updateUser()            ||
        updateComputer()        ||
        updateInfra2()
        // add ...
    ) ) return 1;
    return 0;
}

int OnDestroy(){
    deleteGame();
    deleteInfra();
    waitUntilKeyInput();
    // add ...

    return 0;
}

#include "Infra.h"
#include "Game.h"

#include "base.h"

// <OnStart()>
#ifndef __INC_INFRA 
int setInfra() { return 0; }
#endif
#ifndef __INC_GAME
int initGame() { return 0; }
#endif
int initUser() { return 0; }
int initComputer() { return 0; }
// </OnStart()>

// <OnUpdate()>
#ifndef __INC_INFRA
int FastEscape() { return 0; }
int initScreen() { return 0; }
#endif
int updateUser() { return 0; }
int updateComputer() { return 0; }
#ifndef __INC_GAME
int updateGame() { return 0; }
#endif
#ifndef __INC_INFRA
int updateScreen() { return 0; }
#endif
// </OnUpdate>

// <OnDestroy()>
int showResult() { return 0; }
#ifndef __INC_INFRA
int deleteData() { return 0; }
void waitUntilKeyInput() { return 0; }
#endif
// </OnDestroy()>

int main(void){
    if( OnStart() ){
        game_over=True;
    }

    time_t t1, t2;
    t1=t2=clock();

    while( !game_over ){
        t2=clock();
        time_t _ElapsedTime=t2-t1;
        
        t1=t2;

        if( OnUpdate(_ElapsedTime) ){
            game_over=True;
        }
    }
    OnDestroy();

    return 0;
}

int OnStart(){
    if( (
        setInfra()     ||
        initGame()     ||
        initUser()     ||
        initComputer()
        // add ...
    ) ) return 1;
    return 0;
}

int OnUpdate(time_t ElapsedTime){
    if( (
        FastEscape()     ||
        initScreen()     ||
        updateSystem()   ||
        updateUser()     ||
        updateComputer() ||
        updateGame()     || 
        updateScreen()
        // add ...
    ) ) return 1;
    return 0;
}

int OnDestroy(){
    showResult();
    deleteData();
    waitUntilKeyInput();
    // add ...

    return 0;
}

#include "base.h"

Pixel map[CONSOLE_HEIGHT][CONSOLE_WIDTH];
Bool game_over;

int main(void){
    if( !OnStart() ){
        game_over=True;
    }

    time_t t1, t2;
    t1=t2=clock();

    while( !game_over ){
        t2=clock();
        time_t _ElapsedTime=t2-t1;
        
        t1=t2;

        getKBInput();

        if( !OnUpdate(_ElapsedTime) ){
            game_over=True;
        }
    }

    OnDestroy();

    return 0;
}

int OnStart(){
    if( !(
        setInfra()     ||
        initGame()     ||
        initUser()     ||
        initComputer()
        // add ...
    ) ){
        return 1;
    }
    return 0;
}

int OnUpdate(size_t ElapsedTime){
    if( !(
        FastEscape()     ||
        updateUser()     ||
        updateComputer() ||
        updateGame()     || 
        updateConsole()
        // add ...
    ) ){
        return 1;
    }
    return 0;
}

int OnDestroy(){
    showResult();
    deleteData();
    waitUntilKeyInput();
    // add ...
}

int updateComputer() {
    updateMap();
    //À½...
}
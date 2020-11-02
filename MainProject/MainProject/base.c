#include "header.h"

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
        setInfra() ||
        initUser() ||
        initComputer()
        // add ...
    ) ){
        return 1;
    }
    return 0;
}

int OnUpdate(size_t ElapsedTime){
    if( !(
        FastEscape() ||
        updateUser() ||
        updateComputer() ||
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

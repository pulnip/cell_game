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
        setInfra() &
        initUser() &
        initComputer()
    ) ){
        return 1;
    }
    return 0;
}

int OnUpdate(){
    if( !(
        FastEscape() &
        updateUser() &
        updateComputer() &
        updateConsole()
    ) ){
        return 1;
    }
    return 0;
}

int Destroy(){
    showResult();
    deleteData();
    waitUntilQuit();
}

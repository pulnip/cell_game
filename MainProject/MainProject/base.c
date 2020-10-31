#include "header.h"

int main(void){
    OnStart();

    time_t t1, t2;
    t1=t2=clock();
    while( !game_over ){
        t2=clock();
        if( !OnUpdate(t2-t1) ){
            game_over=True;
        }
        t1=t2;
    }
    OnDestroy();

    return 0;
}

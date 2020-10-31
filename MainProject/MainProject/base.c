#include "header.h"

int main(void){
    OnStart();
    while( !OnUpdate() ){

    }
    OnDestroy();

    return 0;
}

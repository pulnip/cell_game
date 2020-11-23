#include <Windows.h>
#include <stdio.h>

typedef unsigned char Bool;

int main(void){
    Bool lastState=0;
    Bool state=0;

    int cnt=0;

    while(cnt<10){
        if(GetKeyState(VK_SPACE)&0x8000) state=1;
        else state=0;

        Bool isChanged=state^lastState;

        if(isChanged&state){
            puts("CHANGED");
            cnt+=1;
        }

        lastState=state;
    }
}
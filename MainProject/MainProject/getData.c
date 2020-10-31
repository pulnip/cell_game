#include "header.h"

extern KeyState keys[0x100];

void getKBInput(){
    for(int i=0; i<0x100; ++i){
        short tmpKey=GetKeyState(i);
        keys[i].bPressed=(tmpKey&0x1000)>>(sizeof(short)-1);
        keys[i].bToggled=tmpKey&0x1;
    }
}

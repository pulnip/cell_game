#include "header.h"

int setConsoleDefault(){
    hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT rectWindowSize={
        0, 0, CONSOLE_WIDTH, CONSOLE_HEIGHT
    };

    COORD coord={1, 1};

    SetConsoleWindowInfo(hStdOut, TRUE, &rectWindowSize);

    SetConsoleScreenBufferSize(hStdOut, coord);

    return 0;
}

void getKBInput(){
    for(int i=0; i<0x100; ++i){
        short tmpKey=GetKeyState(i);
        keys[i].bPressed=(tmpKey&0x1000)>>(sizeof(short)-1);
        keys[i].bToggled=tmpKey&0x1;
    }
}

void drawMap(){
    CHAR_INFO screen[CONSOLE_WIDTH*CONSOLE_HEIGHT];
    
    const size_t screenSize=CONSOLE_WIDTH*CONSOLE_HEIGHT;
}

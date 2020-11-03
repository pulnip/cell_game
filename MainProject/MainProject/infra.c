#include "header.h"

int setInfra(){
    setConsoleDefault();

    initMapToStartScreen();
    drawScreen();
    // add ...

    waitUntilKeyInput();
}

int FastEscape(){
    if( GetKeyState(VK_ESCAPE)&0x8000 ) return 1;
    return 0;
}

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
        KeyState lastState=keys[i];
        
        short tmpKey=GetKeyState(i);
        keys[i].bPressed=(tmpKey&0x1000)>>(sizeof(short)-1);
        keys[i].bToggled=tmpKey&0x1;

        Bool isChanged=
            (lastState.bPressed^keys[i].bPressed) |
            (lastState.bToggled^keys[i].bToggled);
        
        keys[i].bKeyDown = keys[i].bPressed & isChanged;
        keys[i].bKeyUp   = !keys[i].bPressed & isChanged;
    }
}

int waitUntilKeyInput(){
    Bool isAnyKeyPressed=False;
    do{
        getKBInput();
        isAnyKeyPressed=False;

        for(int i=0; i<0xff; ++i){
            isAnyKeyPressed |= keys[i].bPressed;
        }
    } while(!isAnyKeyPressed);
}

void filterPixelToCI(){
    for(int i=0; i<CONSOLE_HEIGHT; ++i){
        for(int j=0; j<CONSOLE_WIDTH; ++i){

            Pixel const unit=map[i][j];
            CHAR_INFO* const pMapPoint=&ciMap[CONSOLE_WIDTH*i+j];

            if(unit.Point){
                pMapPoint->Char.AsciiChar='P';
                pMapPoint->Attributes=FG_BLUE|BG_WHITE;
            }

            if(unit.Food){
                pMapPoint->Char.AsciiChar='+';
                pMapPoint->Attributes=FG_GREEN|BG_BLACK;
            }

            if(unit.Cell){
                pMapPoint->Char.AsciiChar='@';
                if(unit.Cell==UserCell) {
                    pMapPoint->Attributes=FG_WHITE|BG_BLACK;
                } else if(unit.Cell==EnemyCell) {
                    pMapPoint->Attributes=FG_RED|BG_BLACK;
                }
            }
        }
    }
}

void drawScreen(){
    COORD mapSize={CONSOLE_WIDTH, CONSOLE_HEIGHT};
    COORD coord={0, 0};
    SMALL_RECT WriteRegion={ //Left, Top. Right, Bottom
        0, 0,
        CONSOLE_WIDTH-1,
        CONSOLE_HEIGHT-1
    };

    WriteConsoleOutputA(
        hStdOut,
        ciMap, mapSize, coord,
        &WriteRegion
    );
}

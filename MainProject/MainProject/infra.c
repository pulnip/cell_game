#include "Game.h"

#include "Screen.h"
#include "EventBlock.h"

#include "Infra.h"

HANDLE hStdOut;
CONSOLE_SCREEN_BUFFER_INFO csbi;

KeyState keys[0x100];

int setInfra(){
    if (setConsoleDefault() ||
        readScreenFromFile()
    ) return 1;
    drawScreen();

    initTriggers();
    makeTrigger();
    // add ...

    waitUntilKeyInput();

    return 0;
}

int updateSystem(){
    getKBInput();
    checkTriggered();
    drawTriggers();

    return 0;
}

int deleteData(){
    deleteTriggers();

    return 0;
}

int FastEscape(){
    if( GetKeyState(VK_ESCAPE)&0x8000 ) return 1;
    return 0;
}

int setConsoleDefault(){
    hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    if(hStdOut==NULL) return 1;
    
    SMALL_RECT rectWindowSize;
    rectWindowSize.Left=rectWindowSize.Top=0;
    rectWindowSize.Right=CONSOLE_WIDTH-1;
    rectWindowSize.Bottom=CONSOLE_HEIGHT-1;

    COORD coord;
    coord.X=CONSOLE_WIDTH;
    coord.Y=CONSOLE_HEIGHT;

    if( (!(SetConsoleScreenBufferSize(hStdOut, coord))) ||
        (!(SetConsoleWindowInfo(hStdOut, TRUE, &rectWindowSize)))
    ) return 1;

    return 0;
}

void getKBInput(){
    for(int i=0; i<0x100; ++i){
        KeyState lastState=keys[i];
        
        short tmpKey=GetKeyState(i);
        keys[i].bPressed = (tmpKey&0x8000)>>(8*sizeof(short)-1)&0x1;
        keys[i].bToggled = tmpKey&0x1;

        Bool isChanged=(lastState.bPressed)^(keys[i].bPressed);
        
        keys[i].bKeyDown =   keys[i].bPressed & isChanged;
        keys[i].bKeyUp   = (!keys[i].bPressed)&0x1 & isChanged ;
    }
}

void waitUntilKeyInput(){
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
    for(    int i=0; i<CONSOLE_HEIGHT; ++i){
        for(int j=0; j<CONSOLE_WIDTH; ++i){
            Pixel const unit=map[i][j];
            CHAR_INFO* const pMapPoint=&screen[i][j];

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
                } else if(unit.Cell==CPUCell) {
                    pMapPoint->Attributes=FG_RED|BG_BLACK;
                }
            }
        }
    }
}

void makeTrigger(){
    Rect rectq={3, 34, 19, 35};
    Rect rectw={22, 34, 31, 35};

    Trigger* tq=createTrigger(rectq, 'Q');
    Trigger* tw=createTrigger(rectw, 'W');

    appendOnKeyDownEvent(tq, ToggleButtonAnimation);
    appendOnKeyDownEvent(tw, ButtonShowAnimation);
    appendOnKeyUpEvent(tw, ButtonHideAnimation);
}

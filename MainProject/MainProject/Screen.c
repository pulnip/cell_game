#include "Screen.h"

#include <stdio.h>

HANDLE hStdOut;
CONSOLE_SCREEN_BUFFER_INFO csbi;

CHAR_INFO background[CONSOLE_HEIGHT][CONSOLE_WIDTH];
CHAR_INFO screen[CONSOLE_HEIGHT][CONSOLE_WIDTH];

int initScreen(){
    setConsoleDefault();
    readScreenFromFile();
    copyScreenFromBG();

    drawScreen();

    return 0;
}

int updateScreen1(){
    copyScreenFromBG();

    return 0;
}

int updateScreen2(){
    filterPixelToCI();
    drawTriggers();
    drawScreen();

    return 0;
}

int setConsoleDefault(void) {
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

int readScreenFromFile(){

#ifdef _MSC_VER
    FILE* map_in = NULL;
    FILE* log = NULL;
    fopen_s(&map_in, SCREEN_FILE_PATH, "rt");
    fopen_s(&log, ".\\log.txt", "wt");
#else
    FILE* map_in=fopen(SCREEN_FILE_PATH, "rt");
    FILE* log=fopen(".\\log.txt", "wt");
#endif
    if((map_in==NULL)||(log==NULL)){
        puts("Couldn\'t open file.");
        return 1;
    }

    char buffer[CONSOLE_WIDTH];

    for(int i=0; i<CONSOLE_HEIGHT; ++i){
        size_t bytes=fread(buffer, sizeof(char), sizeof(buffer)/sizeof(char), map_in);
        while(fgetc(map_in) != '\n');

        fprintf(log, "[%d Bytes]: %s\n", (int)bytes, buffer);

        for(int j=0; j<CONSOLE_WIDTH; ++j){
            background[i][j].Char.AsciiChar=buffer[j];
            background[i][j].Attributes=BG_BLACK|FG_WHITE;
        }
    }

    fclose(map_in);
    fclose(log);

    return 0;
}

int copyScreenFromBG(void){
    for(    int i=0; i<CONSOLE_HEIGHT; ++i){
        for(int j=0; j<CONSOLE_WIDTH;  ++j){
            screen[i][j]=background[i][j];
        }
    }

    return 0;
}

int filterPixelToCI(){
    for(    int i=0; i<MAP_HEIGHT; ++i){
        for(int j=0; j<MAP_WIDTH ; ++j){
            Pixel const unit=map[i][j];
            CHAR_INFO* const pMapPoint=&screen[MAP_TOP+i][MAP_LEFT+j];

            if(unit.Point){
                pMapPoint->Char.AsciiChar='P';
                pMapPoint->Attributes=FG_BLUE|BG_WHITE;
            }

            if(unit.Food){
                pMapPoint->Char.AsciiChar='+';
                pMapPoint->Attributes=FG_GREEN|BG_BLACK;
            }

            if(unit.isUserCell){
                pMapPoint->Char.AsciiChar='@';
                pMapPoint->Attributes=FG_WHITE|BG_BLACK;
            }
            if(unit.isCPUCell){
                pMapPoint->Char.AsciiChar='@';
                pMapPoint->Attributes=FG_RED|BG_BLACK;
            }
        }
    }

    return 0;
}

int drawTrigger(Trigger* t){
    if(t==NULL) return 1;

    if( !(t->isHidden) ){
        Rect rect=t->pos;

        for(    int i=rect.Top ; i<rect.Bottom; ++i){
            for(int j=rect.Left; j<rect.Right ; ++j){
                screen[i][j].Attributes=FG_BLACK|BG_WHITE;   
            }
        }
    }

    return 0;
}
int drawTriggers(void){
    Node* n=Triggers.head;
    if(n==NULL) return 1;

    while(n!=NULL){
        drawTrigger(n->pObject);

        n=n->next;
    }

    return 0;
}

int drawScreen(void){
    COORD screenSize={CONSOLE_WIDTH, CONSOLE_HEIGHT};
    COORD coord={0, 0};
    SMALL_RECT WriteRegion={ //Left, Top. Right, Bottom
        0, 0,
        CONSOLE_WIDTH-1,
        CONSOLE_HEIGHT-1
    };

    WriteConsoleOutputA(
        hStdOut,
        (CHAR_INFO*)screen, screenSize, coord,
        &WriteRegion
    );

    return 0;
}

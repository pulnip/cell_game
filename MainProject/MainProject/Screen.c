#include "Screen.h"
#include "Infra.h"

#include <windows.h>
CHAR_INFO background[CONSOLE_HEIGHT][CONSOLE_WIDTH];
CHAR_INFO screen[CONSOLE_HEIGHT][CONSOLE_WIDTH];

int readScreenFromFile(){

#ifdef _MSC_VER
    FILE* map_in = NULL;
    FILE* log = NULL;
    fopen_s(&map_in, SCREEN_FILE_PATH, "rt");
    fopen_s(&log, ".\\log.txt", "wt");
#else
    FILE* map_in=fopen(MAP_FILE_PATH, "rt");
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

        fprintf(log, "[%d Bytes]: %s\n", bytes, buffer);

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

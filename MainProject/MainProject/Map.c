#include "Map.h"
#include "Infra.h"

#include <windows.h>
CHAR_INFO screen[CONSOLE_HEIGHT][CONSOLE_WIDTH];

int readScreenFromFile(){
    char buffer[CONSOLE_WIDTH+1];

    FILE* map_in=fopen(MAP_FILE_PATH, "rt");

    for(int i=0; i<CONSOLE_HEIGHT; ++i){
        fgets(buffer, sizeof(buffer), map_in);

        for(int j=0; j<CONSOLE_WIDTH; ++j){
            screen[i][j].Char.AsciiChar=buffer[i];
            screen[i][j].Attributes=BG_BLACK|FG_WHITE;
        }
    }
}

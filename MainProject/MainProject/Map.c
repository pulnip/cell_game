#include "Map.h"
#include "Infra.h"

#include <windows.h>
CHAR_INFO screen[CONSOLE_HEIGHT][CONSOLE_WIDTH];

int readScreenFromFile(){

#ifdef _MSC_VER
    FILE* map_in = NULL;
    FILE* log = NULL;
    fopen_s(&map_in, MAP_FILE_PATH, "rt");
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
            screen[i*CONSOLE_WIDTH+j].Char.AsciiChar=buffer[j];
            screen[i*CONSOLE_WIDTH+j].Attributes=BG_BLACK|FG_WHITE;
        }
    }

    fclose(map_in);
    fclose(log);

    return 0;
}

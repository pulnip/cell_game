#include <stdio.h>
#include <Windows.h>

#define CONSOLE_WIDTH 120
#define CONSOLE_HEIGHT 40

#define MAP_FILE_PATH ".\\map.txt"

enum Color{
    FG_BLACK  =0x00,
    FG_BLUE   =0x01,
    FG_GREEN  =0x02,
    FG_CYAN   =0x03,
    FG_RED    =0x04,
    FG_MAGENTA=0x05,
    FG_YELLOW =0x06,
    FG_WHITE  =0x07,

    FG_INTENSE=0x08,

    BG_BLACK  =0x00,
    BG_BLUE   =0x10,
    BG_GREEN  =0x20,
    BG_CYAN   =0x30,
    BG_RED    =0x40,
    BG_MAGENTA=0x50,
    BG_YELLOW =0x60,
    BG_WHITE  =0x70,

    BG_INTENSE=0x80
};

CHAR_INFO screen[CONSOLE_WIDTH*CONSOLE_HEIGHT];
HANDLE hStdOut;

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

int readScreenFromFile(){

    FILE* map_in=fopen(MAP_FILE_PATH, "rt");
    FILE* log=fopen(".\\log.txt", "wt");

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
}

int main(void){
    setConsoleDefault();

    readScreenFromFile();

    COORD mapSize={CONSOLE_WIDTH, CONSOLE_HEIGHT};
    COORD coord={0, 0};
    SMALL_RECT WriteRegion={ //Left, Top. Right, Bottom
        0, 0,
        CONSOLE_WIDTH-1,
        CONSOLE_HEIGHT-1
    };

    WriteConsoleOutputA(
        hStdOut,
        screen, mapSize, coord,
        &WriteRegion
    );

    fgetc(stdin);
}
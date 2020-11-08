#ifndef __INC_INFRA
#define __INC_INFRA

#ifndef __INC_BASE
#include "base.h"
#endif

#include <Windows.h>

typedef struct _KeyState{
    Bool bKeyDown;
    Bool bKeyUp;

    Bool bPressed;
    Bool bToggled;
} KeyState;

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

extern HANDLE hStdOut;
extern CONSOLE_SCREEN_BUFFER_INFO csbi;
extern CHAR_INFO ciMap[CONSOLE_HEIGHT*CONSOLE_WIDTH];

extern KeyState keys[0x100];

int setInfra();
int FastEscape();

int setConsoleDefault();
void getKBInput();
void filterPixelToCI();
void drawScreen();

#endif // __INC_INFRA

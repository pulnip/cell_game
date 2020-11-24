#ifndef __INC_INFRA
#define __INC_INFRA

#include "SuperHeader.h"

#include <Windows.h>

typedef struct _KeyState{
    Bool bKeyDown;
    Bool bKeyUp;

    Bool bPressed;
    Bool bToggled;
} KeyState;

extern HANDLE hStdOut;
extern CONSOLE_SCREEN_BUFFER_INFO csbi;

extern KeyState keys[0x100];

int setInfra();
int FastEscape();

int setConsoleDefault();
void getKBInput();
void waitUntilKeyInput();

void filterPixelToCI();

void makeTrigger();

#endif // __INC_INFRA

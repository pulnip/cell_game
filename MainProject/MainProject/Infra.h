#ifndef __INC_INFRA
#define __INC_INFRA

#include "SuperHeader.h"

#include "Screen.h"
#include "EventBlock.h"

#include <Windows.h>

typedef struct _KeyState{
    Bool bKeyDown;
    Bool bKeyUp;

    Bool bPressed;
    Bool bToggled;
} KeyState;

extern KeyState keys[0x100];

StatusFunc initInfra;

StatusFunc FastEscape;
StatusFunc updateInfra1;
StatusFunc updateInfra2;

StatusFunc deleteInfra;
Procedure waitUntilKeyInput;

Procedure getKBInput;

StatusFunc checkTriggered;
StatusFunc makeTrigger;

#endif // __INC_INFRA

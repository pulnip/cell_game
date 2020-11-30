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

typedef struct _VerticalScrollWindow{
    Trigger* pUpTrigger;
    Trigger* pDownTrigger;

    List messageList;
    List msgTriggers;
    int msglistPos;
} VerticalScrollWindow;

typedef struct _UserInput{
    int num;
    Bool deletion;
    Bool _seeEnemy,
         _seeFriend,
         _seeFood,
         _moveCloser,
         _moveFurther,
         _getFood,
         _getPoint,
         _doCannibal,
         _divide
    ;
} UserInput;

extern KeyState keys[0x100];
extern UserInput userInput;

StatusFunc initInfra;

StatusFunc FastEscape;
StatusFunc updateInfra1;
StatusFunc updateInfra2;

StatusFunc deleteInfra;
Procedure waitUntilKeyInput;

Procedure getKBInput;

StatusFunc checkTriggered;
StatusFunc makeTrigger;

int initScrollWindow(Trigger* ut, Trigger* dt);
StatusFunc updateScrollWindow;
StatusFunc deleteScrollWindow;

size_t getCStringLen(char* str);
int printMsgToScreen(char* msg, Coord);

// Event
void ScrollUpMsgPos(void*);
void ScrollDownMsgPos(void*);

#endif // __INC_INFRA

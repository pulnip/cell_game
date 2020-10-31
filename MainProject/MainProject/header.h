#include <stdio.h>
#include <Windows.h>

typedef unsigned char Bool;
#ifndef True
#define True 1
#define False 0
#endif

typedef struct _KeyState{
    Bool bPressed;
    Bool bToggled;
} KeyState;

int OnStart();
int OnUpdate();
int OnDestroy();
void getKBInput();

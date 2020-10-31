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

typedef struct _Coord{
    int x;
    int y;
} Coord;

const int defaultHP=10;

typedef struct _Cell{
    void (**DNA)(void);
    Coord pos;
    int hp;
    Coord forward;
} Cell;

typedef struct _Link{
    Cell* pCell;
    Link* next;
} Link;
Link* head;
Link* tail;

int OnStart();
int OnUpdate();
int OnDestroy();
void getKBInput();

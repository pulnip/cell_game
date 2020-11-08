#ifndef __INC_BASE
#define __INC_BASE

#include <stdio.h>
#include <time.h>
#include <Windows.h>

#ifndef True
#define True 1
#define False 0
#endif

typedef unsigned char Bool;
typedef unsigned char SmallSize_t;

typedef struct _Coord{
    int x;
    int y;
} Coord;

typedef struct _Pixel{
    Bool Cell;
    // 0: no cell, 1: User cell, 2: Enemy cell
    SmallSize_t Point;
    SmallSize_t Food;
} Pixel;

typedef void BEHAVIOUR_t(void);
typedef void (*pBEHAVIOUR_t)(void);
typedef void (**DNA_t)(void);

typedef struct _Cell{
    DNA_t DNA;
    Coord pos;
    int hp;
    Coord forward;
} Cell;

enum isCell{
    NoCell   =0,
    UserCell =1,
    EnemyCell=2
};

// <Global Var>
#define PROTO_CELL_NUMBER 20
#define CONSOLE_WIDTH 120
#define CONSOLE_HEIGHT 40

const int defaultHP=10;

extern Pixel map[CONSOLE_HEIGHT][CONSOLE_WIDTH];
extern Bool game_over;
// </Global Var>

#define GetRandom(min, max) ( \
    (rand() % (int)((max)-(min))) + (min) \
)

int OnStart();
int OnUpdate(time_t ElapsedTime);
int OnDestroy();

int setInfra();
int initGame();
int initUser();
int initComputer();

int FastEscape();
int updateUser();
int updateComputer();
int updateGame();
int updateConsole();

int showResult();
int deleteData();
int waitUntilKeyInput();

#endif // __INC_BASE

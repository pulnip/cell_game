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
    // 0: no cell, 1: User cell, 2: CPU cell
    SmallSize_t Point;
    SmallSize_t Food;
} Pixel;

typedef enum _isCell{
    NoCell   =0,
    UserCell =1,
    CPUCell  =2
} isCell;

typedef struct _Cell{
    isCell id;
    DNA_t DNA;
    Coord pos;
    int hp;
    Coord forward;
    // 탐색한 것의 위치 좌표
} Cell;

typedef void (BEHAVIOUR_t)(Cell*);
typedef BEHAVIOUR_t* pBEHAVIOUR_t;
typedef pBEHAVIOUR_t* DNA_t; //DNA is Array of pBEHAVIOUR


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
// GetRandom(-5, 10) = -5 ~ 9 integer


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

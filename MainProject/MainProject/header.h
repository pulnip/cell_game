#include <stdio.h>
#include <time.h>
#include <Windows.h>

typedef unsigned char Bool;
#ifndef True
#define True 1
#define False 0
#endif

typedef struct _KeyState{
    Bool bPressed;
    Bool bPressing;

    Bool bToggled;
} KeyState;

typedef struct _Coord{
    int x;
    int y;
} Coord;

typedef struct _Cell{
    void (**DNA)(void);
    Coord pos;
    int hp;
    Coord forward;
} Cell;

// <Linked List>
typedef struct _Node{
    Node* next;
    Cell* pCell;
} Node;

typedef struct _List{
    Node* head;
    Node* tail;
} List;

int initList(List*);
int appendNode(Cell*, List*);
int destroyNode(Cell*, List*);
size_t getListLen(List*);
void destroyList(List*);
// </Linked List>

typedef unsigned char SmallSize_t;
typedef struct _Pixel{
    Bool Cell;
    // 0: no cell, 1: User cell, 2: Enemy cell
    SmallSize_t Point;
    SmallSize_t Food;
} Pixel;

enum isCell{
    NoCell   =0,
    UserCell =1,
    EnemyCell=2
};

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

// <Global Var>
const int defaultHP=10;

#define PROTO_CELL_NUMBER 20
#define CONSOLE_WIDTH 120
#define CONSOLE_HEIGHT 40
HANDLE hStdOut;
CONSOLE_SCREEN_BUFFER_INFO csbi;
Pixel map[CONSOLE_HEIGHT][CONSOLE_WIDTH];
CHAR_INFO ciMap[CONSOLE_HEIGHT*CONSOLE_WIDTH];

List userCell, comCell;

KeyState keys[0x100];

Bool game_over;
// </Global Var>


int OnStart();
int OnUpdate(time_t ElapsedTime);
int OnDestroy();

int initUser();
int initComputer();

int updateUser();
int updateComputer();
int updateConsole();

int showResult();
int deleteData();
int waitUntilKeyInput();

// <infra.c>
int setInfra();
int FastEscape();
int setConsoleDefault();
void getKBInput();
void filterPixelToCI();
void drawScreen();
// </infra.c>

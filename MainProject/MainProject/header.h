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
// </Linked List>

typedef unsigned char SmallSize_t;
typedef struct _Pixel{
    Bool bCell;
    SmallSize_t bPoint;
    SmallSize_t bFood;
    CHAR_INFO ci;
}Pixel;

// <Global Var>
const int defaultHP=10;

#define PROTO_CELL_NUMBER 20
#define CONSOLE_WIDTH 120
#define CONSOLE_HEIGHT 40
HANDLE hStdOut;
CONSOLE_SCREEN_BUFFER_INFO csbi;
Pixel map[CONSOLE_WIDTH][CONSOLE_HEIGHT];

List userCell, comCell;

KeyState keys[0x100];

Bool game_over;
// </Global Var>


int OnStart();
int OnUpdate(time_t ElapsedTime);
int OnDestroy();

void getKBInput();
void drawMap();

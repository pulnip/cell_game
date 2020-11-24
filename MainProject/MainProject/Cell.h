#ifndef __INC_CELL
#define __INC_CELL

#include "SuperHeader.h"

#include "Game.h"

#ifndef __INC_SCREEN
typedef enum _isCell{
    NoCell   =0,
    UserCell =1,
    CPUCell  =2
} isCell;
#endif

typedef struct _Cell{
    isCell id;
    void (**DNA)(struct _Cell);
    Coord pos;
    int hp;
    Coord forward;
    // 탐색한 것의 위치 좌표
} Cell;

typedef void (BEHAVIOUR_t)(Cell*);
typedef BEHAVIOUR_t* pBEHAVIOUR_t;
typedef pBEHAVIOUR_t* DNA_t; //DNA is Array of pBEHAVIOUR



#define PROTO_CELL_NUMBER 20

#define MAX_SIGHT 5
#define DEFAULT_HP 10

BEHAVIOUR_t seeEnemy;
BEHAVIOUR_t seeFriend;
BEHAVIOUR_t seeFood;
// modify Sight and Distance

BEHAVIOUR_t moveCloser;
BEHAVIOUR_t moveFurther;
// it is about the Sight.

BEHAVIOUR_t getFood;
BEHAVIOUR_t getPoint;
BEHAVIOUR_t doCannibal;

BEHAVIOUR_t divide;

#define BEHAVIOUR_NUMBER 9

#endif // __INC_CELL

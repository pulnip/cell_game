#ifndef __INC_CELL
#define __INC_CELL

#include "SuperHeader.h"
#include "LinkedList.h"

#include "Map.h"

#define DNA_LEN 8

typedef struct _Cell{
    isCell id;
    void (*DNA[DNA_LEN])(struct _Cell);
    int turnDNA;
    Coord lastPos;
    Coord pos;
    Coord forward;
    BasicInfo stat;
    // The location coordinates of the searched
} Cell;

extern List UserCells;
extern List CPUCells;

typedef void (BEHAVIOUR_t)(Cell*);
typedef BEHAVIOUR_t* pBEHAVIOUR_t;
//DNA is Array of pBEHAVIOUR

typedef struct _BasicInfo
{
    int healthPoint; //= 1000;   //체력
    int attackPoint; //= 100;       //공격력
    int defensePoint; //= 20;       //방어력
} BasicInfo;


#define PROTO_CELL_NUMBER 20

#define MAX_SIGHT 5
#define DEFAULT_HP 1000

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

Cell* searchCellByPos(Coord pos, isCell id);

#define BEHAVIOUR_NUMBER 9

#endif // __INC_CELL

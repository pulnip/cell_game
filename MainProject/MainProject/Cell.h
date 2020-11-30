#ifndef __INC_CELL
#define __INC_CELL

#include "SuperHeader.h"
#include "LinkedList.h"

#include "Map.h"

#define DNA_LEN 8

typedef struct _BasicInfo
{
    int healthPoint; //= 1000;   //ü��
    int attackPoint; //= 100;       //���ݷ�
    int defensePoint; //= 20;       //����
} BasicInfo;

typedef struct _Cell{
    isCell id;
    void (*DNA[DNA_LEN])(struct _Cell*);
    int turnDNA;
    Coord lastPos;
    Coord pos;
    Coord forward;
    BasicInfo stat;
    int score;  //only for CPU
    // The location coordinates of the searched
} Cell;

extern List UserCells;
extern List CPUCells;

extern int SkillPoint;

typedef void (BEHAVIOUR_t)(Cell*);
typedef BEHAVIOUR_t* pBEHAVIOUR_t;
//DNA is Array of pBEHAVIOUR

#define PROTO_CELL_NUMBER 20

#define MAX_SIGHT 5
#define DEFAULT_HP 1000
#define DEFAULT_AP 100
#define DEFAULT_DP 20

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
extern pBEHAVIOUR_t BehaviourList[BEHAVIOUR_NUMBER];

#endif // __INC_CELL

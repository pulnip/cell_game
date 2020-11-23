#ifndef __INC_GAME
#define __INC_GAME

#include "SuperHeader.h"

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
    void (**DNA)(struct _Cell*);
    Coord pos;
    int hp;
    Coord forward;
    // 탐색한 것의 위치 좌표
} Cell;

typedef void (BEHAVIOUR_t)(Cell*);
typedef BEHAVIOUR_t* pBEHAVIOUR_t;
typedef pBEHAVIOUR_t* DNA_t; //DNA is Array of pBEHAVIOUR

#define PROTO_CELL_NUMBER 20

#define FoodGenerateProbability 30 // unit: [%]
#define PointGenerateProbability 5 // unit: [%]

#define MaxFoodRegen CONSOLE_HEIGHT*CONSOLE_WIDTH
#define MaxPointRegen CONSOLE_HEIGHT*CONSOLE_WIDTH/10

extern const int defaultHP;

extern Pixel map[CONSOLE_HEIGHT][CONSOLE_WIDTH];
extern Bool game_over;

int initMap(void);
int updateMap(void);
int spreadFood(void);
int getFoodAmount(void);
int spreadPoint(void);
int getPointAmount(void);


#endif // __INC_GAME
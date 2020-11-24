#ifndef __INC_GAME
#define __INC_GAME

#include "SuperHeader.h"

#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct _Pixel{
    Bool Cell;
    // 0: no cell, 1: User cell, 2: CPU cell
    SmallSize_t Point;
    SmallSize_t Food;
} Pixel;

#define FoodGenerateProbability 30 // unit: [%]
#define PointGenerateProbability 5 // unit: [%]

#define MaxFoodRegen CONSOLE_HEIGHT*CONSOLE_WIDTH
#define MaxPointRegen CONSOLE_HEIGHT*CONSOLE_WIDTH/10

extern Pixel map[CONSOLE_HEIGHT][CONSOLE_WIDTH];
extern Bool game_over;

int initMap(void);
int updateMap(void);
int spreadFood(void);
int getFoodAmount(void);
int spreadPoint(void);
int getPointAmount(void);

#endif // __INC_GAME

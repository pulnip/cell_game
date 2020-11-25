#ifndef __INC_MAP
#define __INC_MAP

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

#define MAP_TOP    (CONSOLE_TOP+1) 
#define MAP_BOTTOM (CONSOLE_BOTTOM*3/4)
#define MAP_LEFT   (CONSOLE_LEFT+1)
#define MAP_RIGHT  (CONSOLE_RIGHT-1)

#define MAP_WIDTH  (MAP_RIGHT-MAP_LEFT)
#define MAP_HEIGHT (MAP_BOTTOM-MAP_TOP)

extern Pixel map[MAP_HEIGHT][MAP_WIDTH];

// unit: [%]
#define FoodGenerateProbability 2
#define PointGenerateProbability 1

#define MaxFoodRegen (MAP_HEIGHT*MAP_WIDTH)
#define MaxPointRegen (MAP_HEIGHT*MAP_WIDTH/10)

StatusFunc initMap;
Procedure updateMap;
Procedure spreadFood;
int getFoodAmount(void);
Procedure spreadPoint;
int getPointAmount(void);

#endif // __INC_MAP
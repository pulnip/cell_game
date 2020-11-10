#ifndef __INC_CELL_BEHAVIOURS
#define __INC_CELL_BEHAVIOURS

#ifndef __INC_BASE
#include "base.h"
#endif

#define MAX_SIGHT 5

BEHAVIOUR_t seeEnemy;
BEHAVIOUR_t seeFriend;
BEHAVIOUR_t seeFood;
// modify Sight and Distance

BEHAVIOUR_t moveCloser;
BEHAVIOUR_t moveFurther;
// it is about the Sight.

BEHAVIOUR_t getFoodFromMap;
BEHAVIOUR_t getPointFromMap;
BEHAVIOUR_t doCannibal;

BEHAVIOUR_t divide;

#define BEHAVIOUR_NUMBER 8
pBEHAVIOUR_t const BehaviourList[BEHAVIOUR_NUMBER]={
    seeEnemy, seeFriend, seeFood,
    moveCloser, moveFurther,
    getFoodFromMap, getPointFromMap,
    doCannibal
};

#endif // __INC_CELL_BEHAVIOURS
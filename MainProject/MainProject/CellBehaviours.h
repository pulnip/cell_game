#ifndef __INC_CELL_BEHAVIOURS
#define __INC_CELL_BEHAVIOURS

#ifndef __INC_BASE
#include "base.h"
#endif

typedef void BEHAVIOUR(void);

#define MAX_SIGHT 5

BEHAVIOUR seeEnemy;
BEHAVIOUR seeFriend;
BEHAVIOUR seeFood;
// modify Sight and Distance

BEHAVIOUR moveCloser;
BEHAVIOUR moveFurther;
// it is about the Sight.

BEHAVIOUR getFoodFromMap;
BEHAVIOUR getPointFromMap;
BEHAVIOUR doCannibal;

BEHAVIOUR divide;


#endif // __INC_CELL_BEHAVIOURS
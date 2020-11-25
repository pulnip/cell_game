#ifndef __INC_GAME
#define __INC_GAME

#include "SuperHeader.h"

#include <time.h>

#include "Map.h"
#include "Cell.h"

extern Bool game_over;

StatusFunc initGame;
int updateGame(time_t ElapsedTime);
StatusFunc deleteGame;

#endif // __INC_GAME

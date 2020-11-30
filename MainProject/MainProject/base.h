#ifndef __INC_BASE
#define __INC_BASE

#include "SuperHeader.h"

#include "Infra.h"
#include "Game.h"
#include "CPUCell.h"
// #include "UserCell.h"

StatusFunc OnStart;
int OnUpdate(time_t ElapsedTime);
StatusFunc OnDestroy;

#endif // __INC_BASE

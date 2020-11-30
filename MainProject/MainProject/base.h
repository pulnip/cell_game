#ifndef __INC_BASE
#define __INC_BASE

#include "SuperHeader.h"

#include "Infra.h"
#include "Game.h"
// #include "CpuMain.h"
// #include "UserCell.h"

StatusFunc OnStart;
int OnUpdate(time_t ElapsedTime);
StatusFunc OnDestroy;

// <OnStart()>
#ifndef __INC_INFRA 
int initInfra(void)     _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_GAME
int initGame(void)     _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_USER_CELL
int initUserCell(void) _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_CPU_MAIN
int initCPUCell(void)  _INT_FUNC_NOT_IMPLEMENT
#endif
// </OnStart()>

// <OnUpdate()>
#ifndef __INC_INFRA
int FastEscape(void)     _INT_FUNC_NOT_IMPLEMENT
int updateInfra1(void)   _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_GAME
int updateGame(void)     _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_USER_CELL
int updateUserCell(void) _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_CPU_MAIN
int updateCPUCell(void)  _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_INFRA
int updateInfra2(void)   _INT_FUNC_NOT_IMPLEMENT
#endif
// </OnUpdate>


// <OnDestroy()>
#ifndef __INC_USER_CELL
int deleteUserCell(void)     _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_CPU_MAIN
int deleteCPUCell(void)      _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_GAME
int deleteGame(void)         _INT_FUNC_NOT_IMPLEMENT
#endif
#ifndef __INC_INFRA
int deleteInfra(void)        _INT_FUNC_NOT_IMPLEMENT
void waitUntilKeyInput(void) _INT_FUNC_NOT_IMPLEMENT
#endif
// </OnDestroy()>

#endif // __INC_BASE

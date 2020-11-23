#ifndef __INC_BASE
#define __INC_BASE

#include "SuperHeader.h"

#include <time.h>

int OnStart();
int OnUpdate(time_t ElapsedTime);
int OnDestroy();

// <OnStart()>
int setInfra();
int initGame();
int initUser();
int initComputer();
// </OnStart()>

// <OnUpdate()>
int FastEscape();
int initScreen();
int updateSystem();
int updateUser();
int updateComputer();
int updateGame();
int updateScreen();
// </OnUpdate>

// <OnDestroy()>
int showResult();
int deleteData();
void waitUntilKeyInput();
// </OnDestroy()>


#endif // __INC_BASE

#ifndef __INC_CELL_PROPERTIES
#define __INC_CELL_PROPERTIES

#include "SuperHeader.h"
#include "Game.h"
#include "Cell.h"
#include "CpuMain.h"
#include "Map.h"
#include "base.h"

BasicInfo ChooseStat();
int AgrresiveAbility(int level);
int StabilityAbility(int level);
int DefensiveAbility(int level);
void SelectBestTech(time_t ElapsedTime);



int Attack(int attackpoint, int defensepoint); //공격 포인트는 공격하는 사람의 것 방어 포인트는 방어 하는 사람의 것



#endif // __INC_CELL_PROPERTIES

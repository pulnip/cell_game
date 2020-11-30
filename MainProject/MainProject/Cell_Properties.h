#ifndef __INC_CELL_PROPERTIES
#define __INC_CELL_PROPERTIES

#include "SuperHeader.h"
#include "Game.h"
#include "Cell.h"
#include "CpuMain.h"
#include "Map.h"
#include "base.h"


int AgrresiveAbility(int level);
int StabilityAbility(int level);
int DefensiveAbility(int level);
void SelectBestTech(time_t ElapsedTime);



int Attack(int attack_point, int defense_point); //공격 포인트는 공격하는 사람의 것 방어 포인트는 방어 하는 사람의 것
void BeAttacked(int health_point, int defense_point); //공격 받음


#endif // __INC_CELL_PROPERTIES

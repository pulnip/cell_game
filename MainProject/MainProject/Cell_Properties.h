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



int Attack(int attackpoint, int defensepoint); //���� ����Ʈ�� �����ϴ� ����� �� ��� ����Ʈ�� ��� �ϴ� ����� ��



#endif // __INC_CELL_PROPERTIES

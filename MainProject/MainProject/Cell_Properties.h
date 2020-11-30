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



int Attack(int attack_point, int defense_point); //���� ����Ʈ�� �����ϴ� ����� �� ��� ����Ʈ�� ��� �ϴ� ����� ��
void BeAttacked(int health_point, int defense_point); //���� ����


#endif // __INC_CELL_PROPERTIES

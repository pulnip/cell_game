#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "CellBehaviours.h"
#include "Game.h"
#include "CPU_cell_notice.h"
#include "Cell.h"


void BasicCellInformation();


void AgrresiveAbility(int level, int attack_point);
void StabilityAbility(int level, int health_point);
void DefensiveAbility(int level, int defense_point);



int Attack(int attack_point, int defense_point); //공격 포인트는 공격하는 사람의 것 방어 포인트는 방어 하는 사람의 것
void BeAttacked(int health_point, int defense_point); //공격 받음
void Starve(int health_point, int starve_minus_health_point); //한 턴 지나서 허기로 인해 체력 깎이는 행동





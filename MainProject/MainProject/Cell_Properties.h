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



int Attack(int attack_point, int defense_point); //���� ����Ʈ�� �����ϴ� ����� �� ��� ����Ʈ�� ��� �ϴ� ����� ��
void BeAttacked(int health_point, int defense_point); //���� ����
void Starve(int health_point, int starve_minus_health_point); //�� �� ������ ���� ���� ü�� ���̴� �ൿ





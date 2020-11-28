#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "CellBehaviours.h"
#include "Game.h"
#include "CPU_cell_notice.h"
#include "Cell.h"


void Basic_Cell_Information();
void Recognize_ability(int level, int Recognize_ability);//레벨과 현재 기동력을 입력하세요
//이거 근데 cell.h에서 MAX_SIGHT의 수치를 변형해야 하는 거라 define하지 않고 그냥 변수 선언 하면 안되려나? 아니면 그냥 이 항목 빼버리든가 둘 중 하나로 정합시당


void Agrresive_ability(int level, int attack_point);//레벨과 현재 공격력을 입력하세요
void Stability_ability(int level, int health_point);//레벨과 현재 '최대'체력을 입력하세요
void Defensive_ability(int level, int defense_point);//레벨과 현재 방어력을 입력하세요
void Mobility_ability(int level);//레벨을 입력하세요
void Digestive_ability(int level, int starve_minus_health_point)//레벨과 현재 허기 지수 포인트를 입력하세요


int Attack(int attack_point, int defense_point); //공격 포인트는 공격하는 사람의 것 방어 포인트는 방어 하는 사람의 것
void Be_Attacked(int health_point, int defense_point); //공격 받음
void Starve(int health_point, int starve_minus_health_point); //한 턴 지나서 허기로 인해 체력 깎이는 행동





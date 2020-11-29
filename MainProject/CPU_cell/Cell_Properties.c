#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "CellBehaviours.h"
#include "Game.h"
#include "CPU_cell_notice.h"
#include "Cell.h"
#include "Cell_Properties.h"


struct Coord;
struct Pixel;
struct Cell;

//0.기본세포의 정보
//1.세포의 유전 정보 테크트리
//2.세포 특성의 상호작용



#define Recognize_ability
#define Agrresive_ability
#define Stability_ability
#define Defensive_ability
#define Digestive_ability

//기본 세포의 정보

int recognition_point;//인지 능력
int health_point; //체력
int attack_point; //공격력
int defense_point; //방어력
int starve_minus_health_point; //허기(초당 감소하는 체력)

void Basic_Cell_Information()
{

	int health_point = 1000; 
	int attack_point = 100; 
	int defense_point = 20; 
	
}

BasicInfo choose_stat() //일단 각 테크트리 당 부여할 레벨단계의 입력
{
	Cell asd;
	int level_A;
	int level_S;
	int level_D;

	while (!(total == 5)) {
		int num = GetRandom(1, 5); //범위안에서 랜덤으로 하나 숫자뽑아주는
		if (num == 1) A_level++;
		else if (num == 2) B_level++;
		else if (num == 3) C_level++;
		total++;
	}
	
	asd.stat.healthPoint += Agrresive_ability(level_A);
	asd.stat.attackPoint += Stability_ability(level_S);
	asd.stat.defensePoint += Defensive_ability(level_D);

	return asd.stat
}

//세포 유전 정보 테크트리

/*void Recognize_ability(int level)//레벨을 입력하세요
{
	int level1_Re_ability;
	int level2_Re_ability;
	int level3_Re_ability;

	switch case(level)
	{
	case 1:
		recognition_point += level1_Re_ability;
		break;
	case 2:
		recognition_point += level2_Re_ability;
		break;
	case 3:
		recognition_point += level3_Re_ability;
		break;
	default:
		printf("You just choose between 1 to 5");
		break;

	//인식범위 유전정보
	//cell.h에서의 MAX_SIGHT의 범위를 서서히 1씩 넓혀 나가는 걸로 하면 될 것 같음
	//level1은 6 level2은 7 level3는 8
}
*/
int Agrresive_ability(int level, int attack_point)//레벨과 현재 공격력을 입력하세요
{
	int level1_AG_ability=100;
	int level2_AG_ability=200;
	int level3_AG_ability=300;
	int level4_AG_ability=400;
	int level5_AG_ability=700;

	switch case(level)
	{
	case 1 :
		attack_point += level1_AG_ability;
		break;
	case 2:
		attack_point += level2_AG_ability;
		break;
	case 3:
		attack_point += level3_AG_ability;
		break;
	case 4:
		attack_point += level4_AG_ability;
		break;
	case 5:
		attack_point += level5_AG_ability;
		break;
	}
	default:
	
		break;
	//공격력 유전정보

		return attack_point;
	
}

int Stability_ability(int level, int health_point)//레벨과 현재 '최대'체력을 입력하세요
{
	int level1_ST_ability=200;
	int level2_ST_ability=400;
	int level3_ST_ability=600;
	int level4_ST_ability=800;
	int level5_ST_ability=1500;

	switch case(level)
	{
	case 1:
		health_point += level1_ST_ability;
		break;
	case 2:
		health_point += level2_ST_ability;
		break;
	case 3:
		health_point += level3_ST_ability;
		break;
	case 4:
		health_point += level4_ST_ability;
		break;
	case 5:
		health_point += level5_ST_ability;
		break;
	}
	default:
	
		break;
	
	//체력 유전정보

	return health_point;
}

int Defensive_ability(int level, int defense_point)//레벨과 현재 방어력을 입력하세요
{
	int level1_DE_ability=40;
	int level2_DE_ability=80;
	int level3_DE_ability=120;
	int level4_DE_ability=160;
	int level5_DE_ability=200;

	switch case(level)
	{
	case 1:
		defense_point += level1_DE_ability;
		break;
	case 2:
		defense_point += level2_DE_ability;
		break;
	case 3:
		defense_point += level3_DE_ability;
		break;
	case 4:
		defense_point += level4_DE_ability;
		break;
	case 5:
		defense_point += level5_DE_ability;
		break;
	}
	default:
		
		break;

	//방어력 유전정보

		return defense_point;
}

/*
void Digestive_ability(int level, int starve_minus_health_point)//레벨을 입력하세요
{
	int level1_DI_ability;
	int level2_DI_ability;
	int level3_DI_ability;
	int level4_DI_ability;
	int level5_DI_ability;

	switch case(level)
	{
	case 1:
		starve_minus_health_point += level1_DI_ability;
		break;
	case 2:
		starve_minus_health_point += level2_DI_ability;
		break;
	case 3:
		starve_minus_health_point += level3_DI_ability;
		break;
	case 4:
		starve_minus_health_point += level4_DI_ability;
		break;
	case 5:
		starve_minus_health_point += level5_DI_ability;
		break;
	}
	default:
		printf("You just choose between 1 to 5");
		break;
	//허기 감소 유전정보
}

*/

//세포 특성의 상호작용


//공격
int Attack(int attack_point, int defense_point) //공격 포인트는 공격하는 사람의 것 방어 포인트는 방어 하는 사람의 것
{
	attack_point -= defense_point;
	return attack_point;
}


//공격 받음
int Be_Attacked(int health_point,int defense_point)
{
	health_point = health_point - Attack()+defense_point;
	return health_point;
}


//한 턴 지나서 허기로 인해 체력 깎이는 행동
void Starve(int health_point, int starve_minus_health_point)
{
	health_point = health_point - starve_minus_health_point;
	return health_point;
}



//
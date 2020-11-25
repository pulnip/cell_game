#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "Infra.h"
#include "CellBehaviours.h"
#include "LinkedList.h"
#include "Game.h"
#include "CPU_cell_notice"
#include "Cell.h"
#include "Cell.c"

struct Coord;
struct Pixel;
struct Cell;

//0.기본세포의 정보
//1.세포의 유전 정보 테크트리
//2.세포가 죽는 조건



#define Recognize_ability
#define Agrresive_ability
#define Stability_ability
#define Defensive_ability
#define Mobility_ability
#define Digestive_ability

//기본 세포의 정보

void Basic_Cell_Information()
{
	int health_point = 1000; //체력
	int attack_point = 100; //공격력
	void mobility; //기동성
	int defense_point = 20; //방어력
	int starve_minus_health_point = 10; //허기(초당 감소하는 체력)
}

//세포 유전 정보 테크트리

void Recognize_ability(int level)//레벨을 입력하세요
{
	int level1_Re_ability;
	int level2_Re_ability;
	int level3_Re_ability;

	//인식범위 유전정보
	//cell.h에서의 MAX_SIGHT의 범위를 서서히 1씩 넓혀 나가는 걸로 하면 될 것 같음
	//level1은 6 level2은 7 level3는 8
}

void Agrresive_ability(int level, int attack_point)//레벨과 현재 공격력을 입력하세요
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
		printf("You just choose between 1 to 5");
	//공격력 유전정보
	
}

void Stability_ability(int level, int health_point)//레벨과 현재 '최대'체력을 입력하세요
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
		printf("You just choose between 1 to 5");
	
	//체력 유전정보
}

void Defensive_ability(int level, int defense_point)//레벨과 현재 방어력을 입력하세요
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
		printf("You just choose between 1 to 5");

	//방어력 유전정보
}

void Mobility_ability(int level)//레벨을 입력하세요
{
	int level1_MO_ability;
	int level2_MO_ability;
	int level3_MO_ability;
	int level4_MO_ability;
	int level5_MO_ability;

	//기동력 유전정보
}

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

	//허기 감소 유전정보
}


//세포의 죽음 ==> 체력의 0, 이외의 경우는 시간에 관련한 것이므로 타 파일에서 다룸

//체력이 0이되는 경우

void Cell_Health_Zero()
{

}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "Infra.h"
#include "CellBehaviours.h"
#include "LinkedList.h"
#include "Game.h"
#include "CPU_cell_notice"

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

void Recognize_ability()
{
	int level1_Re_ability;
	int level2_Re_ability;
	int level3_Re_ability;

	//인식범위 유전정보
}

void Agrresive_ability()
{
	int level1_AG_ability;
	int level2_AG_ability;
	int level3_AG_ability;
	int level4_AG_ability;
	int level5_AG_ability;
	//공격력 유정정보
}

void Stability_ability()
{
	int level1_ST_ability;
	int level2_ST_ability;
	int level3_ST_ability;
	int level4_ST_ability;
	int level5_ST_ability;
	
	//체력 유전정보
}

void Defensive_ability()
{
	int level1_DE_ability;
	int level2_DE_ability;
	int level3_DE_ability;
	int level4_DE_ability;
	int level5_DE_ability;

	//방어력 유전정보
}

void Mobility_ability()
{
	int level1_MO_ability;
	int level2_MO_ability;
	int level3_MO_ability;
	int level4_MO_ability;
	int level5_MO_ability;

	//기동력 유전정보
}

void Digestive_ability()
{
	int level1_Di_ability;
	int level2_Di_ability;
	int level3_Di_ability;
	int level4_Di_ability;
	int level5_Di_ability;

	//허기 감소 유전정보
}


//세포의 죽음 ==> 체력의 0, 이외의 경우는 시간에 관련한 것이므로 타 파일에서 다룸

//체력이 0이되는 경우


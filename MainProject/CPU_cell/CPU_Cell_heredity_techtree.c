#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "Infra.h"
#include "CellBehaviours.h"
#include "LinkedList.h"
#include "Game.h"
#include "CPU_cell_notice.h"
#include "Cell.h"
#include "Cell.c"
#include "Cell_properties.c"

struct Coord;
struct Pixel;
struct Cell;


//cell_properties에 있는 유전조건들을 테크트리로 승화시키는 곳
//해야 할 것. 


void Cell_gene_techtree_information() //유저 입장에서 테크트리 선택 시
{
	int num= 0;
	printf("##### 테크트리 #####\n\n");
	printf("1. 인지 능력\n");
	printf("1. 공격 능력\n");
	printf("1. 체력 능력\n");
	printf("1. 방어 능력\n");
	printf("1. 기동 능력\n");
	printf("1. 기동 능력\n");
	scanf("%d",&num;);

	switch(num)
	case 1:
	printf("Recognize_ability	:");
	break;

	case 2:
	printf("Agrresive_ability	:");
	break;

	case 3:
	printf("Stability_ability	:");
	break;

	case 4:
	printf("Defensive_ability	:");
	break;

	case 5:
	printf("Mobility_ability	:");
	break;

	case 6:
	printf("Digestive_ability	:");
	break;
	
	default:
	break;
	

}

int select[6];


void Cell_techtree(int select[6])
{
	//유저는 테크트리 선택
	//cpu는 최적의 테크트리 만들기
	//이

	Recognize_ability(int select[0]);
	Agrresive_ability(int select[1]);
	Stability_ability(int select[2]);
	Defensive_ability(int select[3]);
	Mobility_ability(int select[4]);
	Digestive_ability(int select[5]);

}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "Infra.h"
#include "CellBehaviours.h"
#include "Game.h"
#include "CPU_cell_notice.h"
#include "Cell.h"
#include "Cell_properties.c"

struct Coord;
struct Pixel;
struct Cell;


//cell_properties�� �ִ� �������ǵ��� ��ũƮ���� ��ȭ��Ű�� ��
//�ؾ� �� ��. 


void Cell_gene_techtree_information() //���� ���忡�� ��ũƮ�� ���� ��
{
	int num= 0;
	printf("##### ��ũƮ�� #####\n\n");
	printf("1. ���� �ɷ�\n");
	printf("2. ���� �ɷ�\n");
	printf("3. ü�� �ɷ�\n");
	printf("4. ��� �ɷ�\n");
	printf("5. �⵿ �ɷ�\n");
	printf("6. ��ȭ �ɷ�\n");
	printf("��ũƮ���� �ø��� ���� ������ ��ȣ�� �Է��ϼ��� :");
	scanf("%d",&num);

	switch(num){
	case 1:
	int num_level;
	printf("��ũƮ�� ���� : ");
	scanf("%d",&num_level);

	Recognize_ability(int )
	break;

	case 2:
	int num_level;
	printf("��ũƮ�� ���� : ");
	scanf("%d",&num_level);
	break;

	case 3:
	int num_level;
	printf("��ũƮ�� ���� : ");
	scanf("%d",&num_level);
	break;

	case 4:
	int num_level;
	printf("��ũƮ�� ���� : ");
	scanf("%d",&num_level);	
	break;

	case 5:
	int num_level;
	printf("��ũƮ�� ���� : ");
	scanf("%d",&num_level);
	break;

	case 6:
	int num_level;
	printf("��ũƮ�� ���� : ");
	scanf("%d",&num_level);
	break;
	
	default:
	break;
	}

}

int select[6];


void Cell_techtree(int select[6])
{
	//������ ��ũƮ�� ����
	//cpu�� ������ ��ũƮ�� �����
	//��

	Recognize_ability(int select[0]);
	Agrresive_ability(int select[1]);
	Stability_ability(int select[2]);
	Defensive_ability(int select[3]);
	Mobility_ability(int select[4]);
	Digestive_ability(int select[5]);

}
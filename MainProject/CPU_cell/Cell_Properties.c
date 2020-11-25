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

//0.�⺻������ ����
//1.������ ���� ���� ��ũƮ��
//2.������ �״� ����



#define Recognize_ability
#define Agrresive_ability
#define Stability_ability
#define Defensive_ability
#define Mobility_ability
#define Digestive_ability

//�⺻ ������ ����

void Basic_Cell_Information()
{
	int health_point = 1000; //ü��
	int attack_point = 100; //���ݷ�
	void mobility; //�⵿��
	int defense_point = 20; //����
	int starve_minus_health_point = 10; //���(�ʴ� �����ϴ� ü��)
}

//���� ���� ���� ��ũƮ��

void Recognize_ability(int level)//������ �Է��ϼ���
{
	int level1_Re_ability;
	int level2_Re_ability;
	int level3_Re_ability;

	//�νĹ��� ��������
	//cell.h������ MAX_SIGHT�� ������ ������ 1�� ���� ������ �ɷ� �ϸ� �� �� ����
	//level1�� 6 level2�� 7 level3�� 8
}

void Agrresive_ability(int level, int attack_point)//������ ���� ���ݷ��� �Է��ϼ���
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
	//���ݷ� ��������
	
}

void Stability_ability(int level, int health_point)//������ ���� '�ִ�'ü���� �Է��ϼ���
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
	
	//ü�� ��������
}

void Defensive_ability(int level, int defense_point)//������ ���� ������ �Է��ϼ���
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

	//���� ��������
}

void Mobility_ability(int level)//������ �Է��ϼ���
{
	int level1_MO_ability;
	int level2_MO_ability;
	int level3_MO_ability;
	int level4_MO_ability;
	int level5_MO_ability;

	//�⵿�� ��������
}

void Digestive_ability(int level, int starve_minus_health_point)//������ �Է��ϼ���
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

	//��� ���� ��������
}


//������ ���� ==> ü���� 0, �̿��� ���� �ð��� ������ ���̹Ƿ� Ÿ ���Ͽ��� �ٷ�

//ü���� 0�̵Ǵ� ���

void Cell_Health_Zero()
{

}
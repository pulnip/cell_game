#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "CellBehaviours.h"
#include "Game.h"
#include "CPU_cell_notice.h"
#include "Cell.h"
#include "Cell_Properties.h"
#include "CpuMain.h"


struct Coord;
struct Pixel;
struct Cell;

//0.�⺻������ ����
//1.������ ���� ���� ��ũƮ��
//2.���� Ư���� ��ȣ�ۿ�




#define AgrresiveAbility
#define StabilityAbility
#define DefensiveAbility


//�⺻ ������ ����


int health_point; //ü��
int attack_point; //���ݷ�
int defense_point; //����


void BasicCellInformation()
{

	int health_point = 1000; 
	int attack_point = 100; 
	int defense_point = 20; 
	
}

BasicInfo ChooseStat() 
{
	BasicInfo _temp;
	int level_A=0;
	int level_S=0;
	int level_D=0;
	_temp.healthPoint = DEFAULT_HP;
	_temp.attackPoint = DEFAULT_AP;
	_temp.defensePoint = DEFAULT_DP;
	int total, num = 0;

	while (!(total == 5)) {
		
		num = GetRandom(1, 4); //1~3 �����ȿ��� �������� �ϳ� ���ڻ̾��ִ�
		if (num == 1)
		{
			level_A++;
		}
		else if (num == 2) 
		{ 
			level_S++;
		}
		else if (num == 3)
		{
			level_D++;
		}

		total = level_A + level_S + level_D;
		
	}
	
	SelectBestTech(level_A, level_S, level_D);

	BasicInfo.stat.healthPoint += StabilityAbility(level_S);
	BasicInfo.stat.attackPoint += AgrresiveAbility(level_A);
	BasicInfo.stat.defensePoint += DefensiveAbility(level_D);

	return _temp;
}

void SelectBestTech(int a, int b, int c)
{
	updateCPUCell(time_t ElapsedTime);

	if (time_t ElapsedTime > 100) //�ð��� 100�� �Ѿ�� �� cpu�� ���� ��
	{
		BasicInfo.stat.healthPoint += 100;
		BasicInfo.stat.attackPoint += 10;
		BasicInfo.stat.defensePoint += 1;
	}
	else if (time_t ElapsedTime > 500) //�ð��� 500�� �Ѿ�� �� cpu�� ���� ��
	{
		BasicInfo.stat.healthPoint += 200;
		BasicInfo.stat.attackPoint += 20;
		BasicInfo.stat.defensePoint += 2;
	}
	else if (time_t ElapsedTime > 1000) //�ð��� 1000�� �Ѿ�� �� cpu�� ���� ��
	{
		BasicInfo.stat.healthPoint += 300;
		BasicInfo.stat.attackPoint += 30;
		BasicInfo.stat.defensePoint += 3;
	}

	
}


//���� ���� ���� ��ũƮ��

/*void Recognize_ability(int level)//������ �Է��ϼ���
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

	//�νĹ��� ��������
	//cell.h������ MAX_SIGHT�� ������ ������ 1�� ���� ������ �ɷ� �ϸ� �� �� ����
	//level1�� 6 level2�� 7 level3�� 8
}
*/

int AgrresiveAbility(int level)//������ �Է��ϼ���
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
	//���ݷ� ��������

		return attack_point;
	
}

int StabilityAbility(int level)//������ �Է��ϼ���
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
	
	//ü�� ��������

	return health_point;
}

int DefensiveAbility(int level)//������ �Է��ϼ���
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

	//���� ��������

		return defense_point;
}

/*
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
		break;
	//��� ���� ��������
}

*/

//���� Ư���� ��ȣ�ۿ�


//����
int Attack(int attack_point, int defense_point) //���� ����Ʈ�� �����ϴ� ����� �� ��� ����Ʈ�� ��� �ϴ� ����� ��
{
	attack_point -= defense_point;
	return attack_point;
}


//���� ����
int BeAttacked(int health_point,int defense_point)
{
	health_point = health_point - Attack()+defense_point;
	return health_point;
}


//�� �� ������ ���� ���� ü�� ���̴� �ൿ
void Starve(int health_point, int starve_minus_health_point)
{
	health_point = health_point - starve_minus_health_point;
	return health_point;
}



//
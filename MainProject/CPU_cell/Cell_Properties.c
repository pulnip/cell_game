#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "Infra.h"
#include "CellBehaviours.h"
#include "LinkedList.h"
#include "Game.h"
#include "CPU_cell_notice"

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

void Recognize_ability()
{
	int level1_Re_ability;
	int level2_Re_ability;
	int level3_Re_ability;

	//�νĹ��� ��������
}

void Agrresive_ability()
{
	int level1_AG_ability;
	int level2_AG_ability;
	int level3_AG_ability;
	int level4_AG_ability;
	int level5_AG_ability;
	//���ݷ� ��������
}

void Stability_ability()
{
	int level1_ST_ability;
	int level2_ST_ability;
	int level3_ST_ability;
	int level4_ST_ability;
	int level5_ST_ability;
	
	//ü�� ��������
}

void Defensive_ability()
{
	int level1_DE_ability;
	int level2_DE_ability;
	int level3_DE_ability;
	int level4_DE_ability;
	int level5_DE_ability;

	//���� ��������
}

void Mobility_ability()
{
	int level1_MO_ability;
	int level2_MO_ability;
	int level3_MO_ability;
	int level4_MO_ability;
	int level5_MO_ability;

	//�⵿�� ��������
}

void Digestive_ability()
{
	int level1_Di_ability;
	int level2_Di_ability;
	int level3_Di_ability;
	int level4_Di_ability;
	int level5_Di_ability;

	//��� ���� ��������
}


//������ ���� ==> ü���� 0, �̿��� ���� �ð��� ������ ���̹Ƿ� Ÿ ���Ͽ��� �ٷ�

//ü���� 0�̵Ǵ� ���


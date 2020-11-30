#include "Cell_Properties.h"

int healthPoint = 0;
int attackPoint = 0;
int defensePoint = 0;


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
	

	_temp.healthPoint += StabilityAbility(level_S);
	_temp.attackPoint += AgrresiveAbility(level_A);
	_temp.defensePoint += DefensiveAbility(level_D);

	return _temp;
}

void SelectBestTech(time_t ElapsedTime)
{
	updateCPUCell(ElapsedTime);

	if (time_t ElapsedTime > 100) //�ð��� 100�� �Ѿ�� �� cpu�� ���� ��
	{
		_temp.healthPoint += 100;
		_temp.attackPoint += 10;
		_temp.defensePoint += 1;
	}
	else if (ElapsedTime > 500) //�ð��� 500�� �Ѿ�� �� cpu�� ���� ��
	{
		_temp.healthPoint += 200;
		_temp.attackPoint += 20;
		_temp.defensePoint += 2;
	}
	else if (ElapsedTime > 1000) //�ð��� 1000�� �Ѿ�� �� cpu�� ���� ��
	{
		_temp.healthPoint += 300;
		_temp.attackPoint += 30;
		_temp.defensePoint += 3;
	}

	
}


int AgrresiveAbility(int level)//������ �Է��ϼ���
{
	int attackpoint = BasicInfo.stat.attackPoint;
	int level1_AG_ability=100;
	int level2_AG_ability=200;
	int level3_AG_ability=300;
	int level4_AG_ability=400;
	int level5_AG_ability=700;

	switch (level)
	{
	case 1 :
		attackpoint += level1_AG_ability;
		break;
	case 2:
		attackpoint += level2_AG_ability;
		break;
	case 3:
		attackpoint += level3_AG_ability;
		break;
	case 4:
		attackpoint += level4_AG_ability;
		break;
	case 5:
		attackpoint += level5_AG_ability;
		break;
	default:
		break;

	}
	//���ݷ� ��������

		return attackpoint;
	
}

int StabilityAbility(int level)//������ �Է��ϼ���
{
	int healthpoint = BasicInfo.stat.healthpoint;
	int level1_ST_ability=200;
	int level2_ST_ability=400;
	int level3_ST_ability=600;
	int level4_ST_ability=800;
	int level5_ST_ability=1500;

	switch (level)
	{
	case 1:
		healthpoint += level1_ST_ability;
		break;
	case 2:
		healthpoint += level2_ST_ability;
		break;
	case 3:
		healthpoint += level3_ST_ability;
		break;
	case 4:
		healthpoint += level4_ST_ability;
		break;
	case 5:
		healthpoint += level5_ST_ability;
		break;
	default:

		break;

	}
	
	//ü�� ��������

	return healthpoint;
}

int DefensiveAbility(int level)//������ �Է��ϼ���
{
	int defensepoint = BasicInfo.stat.defensepoint;
	int level1_DE_ability=40;
	int level2_DE_ability=80;
	int level3_DE_ability=120;
	int level4_DE_ability=160;
	int level5_DE_ability=200;

	switch (level)
	{
	case 1:
		defensepoint += level1_DE_ability;
		break;
	case 2:
		defensepoint += level2_DE_ability;
		break;
	case 3:
		defensepoint += level3_DE_ability;
		break;
	case 4:
		defensepoint += level4_DE_ability;
		break;
	case 5:
		defensepoint += level5_DE_ability;
		break;
	default:

		break;

	}

	//���� ��������

		return defensepoint;
}




//����
int Attack(int attackpoint, int defensepoint) //���� ����Ʈ�� �����ϴ� ����� �� ��� ����Ʈ�� ��� �ϴ� ����� ��
{
	attackpoint -= defensepoint;
	return attackpoint;
}




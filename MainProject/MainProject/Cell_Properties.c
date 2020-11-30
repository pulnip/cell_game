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
	int total = 0;
	int num = 0;

	while (!(total == 5)) {

		num = GetRandom(1, 4); //1~3 범위안에서 랜덤으로 하나 숫자뽑아주는
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
	BasicInfo _temp;
	_temp.healthPoint = DEFAULT_HP;
	_temp.attackPoint = DEFAULT_AP;
	_temp.defensePoint = DEFAULT_DP;


	if (ElapsedTime > 100) //시간이 100이 넘어갔을 때 cpu의 스펙 업
	{
		_temp.healthPoint += 100;
		_temp.attackPoint += 10;
		_temp.defensePoint += 1;
	}
	else if (ElapsedTime > 500) //시간이 500이 넘어갔을 때 cpu의 스펙 업
	{
		_temp.healthPoint += 200;
		_temp.attackPoint += 20;
		_temp.defensePoint += 2;
	}
	else if (ElapsedTime > 1000) //시간이 1000이 넘어갔을 때 cpu의 스펙 업
	{
		_temp.healthPoint += 300;
		_temp.attackPoint += 30;
		_temp.defensePoint += 3;
	}

	
}


int AgrresiveAbility(int level)//레벨을 입력하세요
{
	BasicInfo _temp;
	_temp.healthPoint = DEFAULT_HP;
	_temp.attackPoint = DEFAULT_AP;
	_temp.defensePoint = DEFAULT_DP;
	int level1_AG_ability=100;
	int level2_AG_ability=200;
	int level3_AG_ability=300;
	int level4_AG_ability=400;
	int level5_AG_ability=700;

	switch (level)
	{
	case 1 :
		attackPoint += level1_AG_ability;
		break;
	case 2:
		attackPoint += level2_AG_ability;
		break;
	case 3:
		attackPoint += level3_AG_ability;
		break;
	case 4:
		attackPoint += level4_AG_ability;
		break;
	case 5:
		attackPoint += level5_AG_ability;
		break;
	default:
		break;

	}
	//공격력 유전정보

		return attackPoint;
	
}

int StabilityAbility(int level)//레벨을 입력하세요
{
	BasicInfo _temp;
	_temp.healthPoint = DEFAULT_HP;
	_temp.attackPoint = DEFAULT_AP;
	_temp.defensePoint = DEFAULT_DP;
	int level1_ST_ability=200;
	int level2_ST_ability=400;
	int level3_ST_ability=600;
	int level4_ST_ability=800;
	int level5_ST_ability=1500;

	switch (level)
	{
	case 1:
		healthPoint += level1_ST_ability;
		break;
	case 2:
		healthPoint += level2_ST_ability;
		break;
	case 3:
		healthPoint += level3_ST_ability;
		break;
	case 4:
		healthPoint += level4_ST_ability;
		break;
	case 5:
		healthPoint += level5_ST_ability;
		break;
	default:

		break;

	}
	
	//체력 유전정보

	return healthPoint;
}

int DefensiveAbility(int level)//레벨을 입력하세요
{
	BasicInfo _temp;
	_temp.healthPoint = DEFAULT_HP;
	_temp.attackPoint = DEFAULT_AP;
	_temp.defensePoint = DEFAULT_DP;
	int level1_DE_ability=40;
	int level2_DE_ability=80;
	int level3_DE_ability=120;
	int level4_DE_ability=160;
	int level5_DE_ability=200;

	switch (level)
	{
	case 1:
		defensePoint += level1_DE_ability;
		break;
	case 2:
		defensePoint += level2_DE_ability;
		break;
	case 3:
		defensePoint += level3_DE_ability;
		break;
	case 4:
		defensePoint += level4_DE_ability;
		break;
	case 5:
		defensePoint += level5_DE_ability;
		break;
	default:

		break;

	}

	//방어력 유전정보

		return defensePoint;
}




//공격
int Attack(int attackpoint, int defensePoint) //공격 포인트는 공격하는 사람의 것 방어 포인트는 방어 하는 사람의 것
{
	attackpoint -= defensePoint;
	return attackpoint;
}




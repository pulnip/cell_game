#include "CPUCell.h"

int healthPoint = 0;
int attackPoint = 0;
int defensePoint = 0;

int initCPUCell(void) {
	initList(&CPUCells);
	int count = 0;
	for (int i = 0; i < PROTO_CELL_NUMBER; i++) {

		Cell* newCell = createCpuCell();
		if (newCell == NULL) return 1;
	}

	return 0;
}
#include <stdio.h>
int updateCPUCell(time_t ElapsedTime) {
	static time_t timer = 0;
	timer += ElapsedTime;

	if (timer > 500) {
		exeCpuCells();
		timer -= 500;
	}

	return 0;
}

int deleteCPUCell(void) {
	eraseHeapObjectList(&CPUCells);

	return 0;
}

//Cell create 
Cell* createCpuCell(void) {
	Cell* cell = malloc(sizeof(Cell));
	if (cell == NULL) return NULL;

	cell->id = CPUCell;

	setCpuMovingSet(cell);
	cell->turnDNA = 0;

	cell->lastPos.x = cell->pos.x = GetRandom(0, MAP_WIDTH);
	cell->lastPos.y = cell->pos.y = GetRandom(0, MAP_HEIGHT);

	cell->forward.x = cell->pos.x;
	cell->forward.y = cell->pos.y;

	ChooseStat(&(cell->stat));

	cell->score = 0;

	appendNode(cell, &CPUCells);

	return cell;
}

void setCpuMovingSet(Cell* cell) {
	for (int i = 0; i < 8; i++) {
		cell->DNA[i] = BehaviourList[GetRandom(0, BEHAVIOUR_NUMBER)];
	}
}


void exeCpuCells(void) {
	Node* n = CPUCells.head;
	while (n != NULL) {
		Cell* cell = n->pObject;

		cell->DNA[cell->turnDNA](cell);

		map[cell->lastPos.y][cell->lastPos.x].isCPUCell = False;
		map[cell->pos.y][cell->pos.x].isCPUCell = True;
		cell->lastPos.x = cell->pos.x;
		cell->lastPos.y = cell->pos.y;

		cell->turnDNA = ((cell->turnDNA) + 1) % 8; 

		n = n->next;
	}
}

bestDNA* selectBestArray(bestDNA* _bestDNA) {
	Node* n = CPUCells.head;

	_bestDNA[0].score = 0;
	while (n != NULL) {
		Cell* cell = n->pObject;

		if (_bestDNA[0].score <= cell->score) {
			_bestDNA[1].score = _bestDNA[0].score;
			for (int i = 0; i < 8; i++) {
				_bestDNA[1].DNA[i] = _bestDNA[0].DNA[i];
			}
			_bestDNA[0].score = cell->score;
			for (int i = 0; i < 8; i++) {
				_bestDNA[1].DNA[i] = _bestDNA[0].DNA[i];
			}
		}
		else if
			(_bestDNA[1].score <= cell->score) {
			_bestDNA[1].score = cell->score;
			for (int i = 0; i < 8; i++) {
				_bestDNA[1].DNA[i] = _bestDNA[0].DNA[i];
			}
		}
		n = n->next;
	}
	return _bestDNA;
}

void ChooseStat(BasicInfo* _temp)
{
	int level_A = 0;
	int level_S = 0;
	int level_D = 0;
	_temp->healthPoint = DEFAULT_HP;
	_temp->attackPoint = DEFAULT_AP;
	_temp->defensePoint = DEFAULT_DP;
	int total = 0;
	int num = 0;

	while (total != 5) {

		num = GetRandom(1, 4);
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


	_temp->healthPoint += StabilityAbility(level_S);
	_temp->attackPoint += AgrresiveAbility(level_A);
	_temp->defensePoint += DefensiveAbility(level_D);
}

void SelectBestTech(time_t ElapsedTime)
{
	BasicInfo _temp;
	_temp.healthPoint = DEFAULT_HP;
	_temp.attackPoint = DEFAULT_AP;
	_temp.defensePoint = DEFAULT_DP;


	if (ElapsedTime > 100)
	{
		_temp.healthPoint += 100;
		_temp.attackPoint += 10;
		_temp.defensePoint += 1;
	}
	else if (ElapsedTime > 500)
	{
		_temp.healthPoint += 200;
		_temp.attackPoint += 20;
		_temp.defensePoint += 2;
	}
	else if (ElapsedTime > 1000)
	{
		_temp.healthPoint += 300;
		_temp.attackPoint += 30;
		_temp.defensePoint += 3;
	}
}

int AgrresiveAbility(int level)
{
	int attackPoint = DEFAULT_AP;

	int level1_AG_ability = 100;
	int level2_AG_ability = 200;
	int level3_AG_ability = 300;
	int level4_AG_ability = 400;
	int level5_AG_ability = 700;

	switch (level)
	{
	case 1:
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

	return attackPoint;
}

int StabilityAbility(int level)
{
	int healthPoint = DEFAULT_HP;
	int level1_ST_ability = 200;
	int level2_ST_ability = 400;
	int level3_ST_ability = 600;
	int level4_ST_ability = 800;
	int level5_ST_ability = 1500;

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

	return healthPoint;
}

int DefensiveAbility(int level)
{
	int defensePoint = DEFAULT_DP;
	int level1_DE_ability = 40;
	int level2_DE_ability = 80;
	int level3_DE_ability = 120;
	int level4_DE_ability = 160;
	int level5_DE_ability = 200;

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

	return defensePoint;
}

int Attack(int attackpoint, int defensePoint)
{
	return attackpoint-defensePoint;
}

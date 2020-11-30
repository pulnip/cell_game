#include "CpuMain.h"

int initCPUCell(void) {
	initList(&CPUCells);
	int count = 0;
	for (int i = 0; i < PROTO_CELL_NUMBER; i++) {  // usercell.có�� �׳� createCpuCell()���� ������ ����� ���߿� ���� ���鶧 �����ϸ� �����ϳ�
		
		Cell* newCell = createCpuCell();
		if (!(newCell == NULL)) {
			count++;
		}
	}
	if (count != PROTO_CELL_NUMBER) return -1; // fail
	
	return 0; //success
}

int updateCPUCell(time_t ElapsedTime) {
	static time_t timer=0;
	timer+=ElapsedTime;

	exeCpuCells(); // 

	return 0;
}

int deleteCPUCell(void){
	eraseHeapObjectList(&CPUCells);

	return 0;
}

//Cell create 
Cell* createCpuCell(void) {
	Cell* cell = malloc(sizeof(Cell));
	if (cell == NULL) return NULL;
	BasicInfo _tempStat;
	cell->id = CPUCell;

	cell->lastPos.x = cell->pos.x = GetRandom(0, MAP_WIDTH);
	cell->lastPos.y = cell->pos.y = GetRandom(0, MAP_HEIGHT);

	cell->turnDNA = 0;

	_tempStat = ChooseStat();
	cell->stat.healthPoint = _tempStat.healthPoint;
	cell->stat.defensePoint = _tempStat.defensePoint;
	cell->stat.attackPoint = _tempStat.attackPoint;

	cell->forward.x = cell->pos.x;
	cell->forward.y = cell->pos.y;

	cell->score = 0;
	// DNA�� �� �Լ� �ۿ��� ����
	appendNode(cell, &CPUCells);

	setCpuMovingSet(cell);

	return cell;
} //���߿� destroyed �ʿ�




void setCpuMovingSet(Cell* cell) {   //�ൿ�� ����ϴ� ��Ʈ�� ����� �Լ�  
	for (int i = 0; i < 8; i++) { //sensoring movement doing
		cell->DNA[i] = BehaviourList[GetRandom(0, BEHAVIOUR_NUMBER)];
	}
}


void exeCpuCells(void) {
	Node* n = CPUCells.head;
	while (n != NULL) {
		Cell* cell = n->pObject;

		cell->DNA[cell->turnDNA](cell);
		
		//print
		map[cell->pos.x][cell->pos.y].isCPUCell = True;
		cell->lastPos.x = cell->pos.x;
		cell->lastPos.y = cell->pos.y;
		map[cell->lastPos.x][cell->lastPos.y].isCPUCell = False;

		cell->turnDNA = ((cell->turnDNA) + 1) % 8; // 1~8������ ��Ʈ �ȿ����� 
		n = n->next;
	}
}

bestDNA* selectBestArray(bestDNA *_bestDNA) { //������ �� ������ �´����� �𸣰ڴ�. score �ű�� DNA����Ű�� �ŵ� ���� �����̳�
	Node* n = CPUCells.head;
	Cell* cell;
	_bestDNA[0].score = 0;
	while (n != NULL) {
		cell = n->pObject;

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

/*
void *createNewSet(bestDNA baseDNA, bestDNA base2DNA) { //1�� �迭  //2��迭
	void *tempSet[DNA_LEN];
	for (int i = 0; i < 8; i++) {
		(tempSet+i) = BehaviourLIst[baseDNA.DNA[GetRandom(0, 2)][i]];
	}
}
*/





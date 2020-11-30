#include "CpuMain.h"

int initCPUCell(void) {
	initList(&CPUCells);
	int count = 0;
	for (int i = 0; i < PROTO_CELL_NUMBER; i++) {  // usercell.có�� �׳� createCpuCell()���� ������ ����� ���߿� ���� ���鶧 �����ϸ� �����ϳ�
		
		Cell* newCell = createCpuCell(void);
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
	BasicInfo _tempStat;
	cell->id = CPUCell;

	cell->lastPos.x = cell->pos.x = GetRandom(0, MAP_WIDTH);
	cell->lastPos.y = cell->pos.y = GetRandom(0, MAP_HEIGHT);

	cell->turnDNA = 0;

	_tempStat = ChooseStat();
	cell->stat.healthPoint = _tempStat.stat.healthPoint;
	cell->stat.defensePoint = _tempStat.stat.defensePoint;
	cell->stat.attackPoint = _tempStat.stat.attackPoint;

	cell->forward.x = cell->pos.x;
	cell->forward.y = cell->pos.y;

	cell->score = 0;
	// DNA�� �� �Լ� �ۿ��� ����
	appendNode(cell, &CPUcells);

	setCpuMovingSet(cell);

	return cell;
} //���߿� destroyed �ʿ�


void changeIsCellPos(Cell* _cell) {  //exeCpuCells �ȿ� ���Ե�
	_cell->lastPos.x = _cell->pos.x;
	_cell->lastPos.y = -cell->pos.y;
	map[_cell->lastPos.x][_cell->lastPos.y] = False;
}


void setCpuMovingSet(Cell* cell) {   //�ൿ�� ����ϴ� ��Ʈ�� ����� �Լ�  
	for (int i = 0; i < 8; i++) { //sensoring movement doing
		cell->DNA[i] = BehaviourList[GetRandom(0, sizeof(BehaviourList) / 4)];
	}
}


void exeCpuCells(void) {
	Node* n = CPUCells.head;
	while (n != NULL) {
		Cell* cell = n->pObject;
		cell->DNA[cell->turnDNA](cell); //Do �ʿ���°ǰ�
		changeIsCellPos(cell);
		
		map[cell->pos.x][cell->pos.y] = True;
		cell->turnDNA = ((cell->turnDNA) + 1) % 8; // 1~8������ ��Ʈ �ȿ����� 
		n = n->next;
		updateGame(200); //2000/200 == 10 == 0.1��?
	}
}

bestDNA* selectBestArray(bestDNA *_bestDNA) { //������ �� ������ �´����� �𸣰ڴ�. score �ű�� DNA����Ű�� �ŵ� ���� �����̳�
	Node* n = CPUCells.head;
	Cell* cell;
	_bestDNA[0]->score = 0;
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


void *createNewSet(bestDNA baseDNA, bestDNA base2DNA) { //1�� �迭  //2��迭
	void *tempSet[DNA_LEN]();
	for (int i = 0; i < 8; i++) {
		tempSet[i] = Behaviour[parentSet[GetRandom(0, 2)][i]]; ]
	}
	tempSet[8] = 0; //score?
}






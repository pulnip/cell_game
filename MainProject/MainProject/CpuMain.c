#include "CpuMain.h"

int initCPUCell(void) {
	initList(&CPUCells);
	int count = 0;
	for (int i = 0; i < PROTO_CELL_NUMBER; i++) {  // usercell.có�� �׳� createCpuCell()���� ������ ����� ���߿� ���� ���鶧 �����ϸ� �����ϳ�
		Cell _temp;
		BasicInfo _tempStat;
		_temp.id = CPUCell;  //Cell->id , isCell = 1
		_temp.pos.x = GetRandom(0, MAP_WIDTH);  
		_temp.pos.y = GetRandom(0, MAP_HEIGHT);
		_temp.turnDNA = 0;
		_temp.forward.x = _temp.pos.x;
		_temp.forward.y = _temp.pos.y;
		_tempStat = ChooseStat();
		_temp.stat.healthPoint = _tempStat.stat.healthPoint;
		_temp.stat.defensePoint = _tempStat.stat.defensePoint;
		_temp.stat.attackPoint = _tempStat.stat.attackPoint;
		
		Cell* newCell = createCpuCell(_temp);
		if (!(newCell == NULL)) {
			count++;
			setCpuMovingSet(newCell);
		}
	}
	if (count != PROTO_CELL_NUMBER) return -1; // fail
	
	return 0; //success
}

int updateCPUCell(void) {  
	exeCpuCells(); // 

	return 0;
}

int deleteCPUCell(void){
	eraseHeapObjectList(&CPUCells);

	return 0;
}

//Cell create 
Cell* createCpuCell(Cell _temp) {
	Cell* cell = malloc(sizeof(Cell));

	cell->hp = _temp.hp;
	cell->id = _temp.id;
	cell->pos = _temp.pos;
	cell->forward = _temp.forward;;
	// DNA�� �� �Լ� �ۿ��� ����
	appendNode(cell, &CPUcells);

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
	Node* n = Cells.head;
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

void selectBestArray(bestDNA* bestDNA, int _ListLen) { //������ �� ������ �´����� �𸣰ڴ�. score �ű�� DNA����Ű�� �ŵ� ���� �����̳�
	bestDNA* _bestDNA[2];
	_bestDNA[0]->score = bestDNA->score;
	for (int i = 0; i < _ListLen; i++) {
		if (_bestDNA[0]->score == (bestDNA + i)->score) { 
			_bestDNA[1]->score = (bestDNA + i)->score; 
			_bestDNA[1]->DNA = (bestDNA + i)->DNA; //����?
		}
		if (_bestDNA[0]->score < (bestDNA + i)->score) { 
			_bestDNA[0]->score = (bestDNA + i)->score; 
			_bestDNA[0]->DNA = (bestDNA + i)->DNA; 
		}
		else if
			(_bestDNA[1]->score < bestDNA->score) {
			_bestDNA[1]->score = bestDNA->score;
		}
	}
}


void *createNewSet(bestDNA baseDNA, bestDNA base2DNA) { //1�� �迭  //2��迭
	void *tempSet[DNA_LEN]();
	for (int i = 0; i < 8; i++) {
		tempSet[i] = Behaviour[parentSet[GetRandom(0, 2)][i]]; ]
	}
	tempSet[8] = 0; //score?
}






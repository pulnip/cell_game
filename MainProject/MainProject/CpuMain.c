#include "CpuMain.h"

int initComputer(void) {
	initList(&CPUCells);
	int count = 0;
	for (int i = 0; i < PROTO_CELL_NUMBER; i++) {
		Cell _temp;
		BasicInfo _tempStat;
		//tempDNA createMovingSet(cell); //����ü 2�����迭 ���ٹ�� �� ã�ƺ����� cell->set
		//createTech(cell); //�¸��̰� ¥���� �ڵ尡 ���� �𸣰���
		_temp.id = 2;  //Cell->id , isCell = 1
		_temp.pos.x = GetRandom(0, MAP_WIDTH);  
		_temp.pos.y = GetRandom(0, MAP_HEIGHT);
		_temp.turnDNA = 0;
		_temp.forward.x = _temp.pos.x;
		_temp.forward.y = _temp.pos.y;
		_tempStat = chooseStat();
		_temp.stat.healthPoint = _tempStat.stat.healthPoint;
		_temp.stat.defensePoint = _tempStat.stat.defensePoint;
		_temp.stat.attackPoint = _tempStat.stat.attackPoint;
		
		Cell* newCell = createCpuCell(_temp);
		if (!(newCell == NULL)) {
			count++;
			setCpuMovingSet(newCell);
		}
	}
	if (count == PROTO_CELL_NUMBER) { return 1; } // suc
	else { return -1; }//fail
}

int updateComputer(void) {  
	exeCpuCells(); // 
}

//Cell create 
Cell* createCpuCell(Cell _temp) {
	Cell* cell = malloc(sizeof(Cell));

	cell->hp = _temp.hp;
	cell->id = _temp.id;
	cell->pos = _temp.pos;
	cell->forward = _temp.forward;
	//void (**DNA)(struct _Cell);

	appendNode(cell, &CPUcells);

	return cell;
} //���߿� destroyed �ʿ�


void changeIsCellPos(Cell* _cell) {  //exeCpuCells �ȿ� ���Ե�
	_cell->lastPos.x = _cell->pos.x;
	_cell->lastPos.y = -cell->pos.y;
	map[_cell->lastPos.x][_cell->lastPos.y] = False;
}


void setCpuMovingSet(Cell* cell) {   //�ൿ�� ����ϴ� ��Ʈ�� ����� �Լ�  
	for (int i = 0; i < 8; i++) { // ����ü cell�� �����ϴ� ���
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

void Sort(Cell* set) { //�̿ϼ�
	int bestSet[2] = { 0,0 };//���������� �ؾ��Ұ� ������ ��� �־�� ���� 2�����迭�� �ٲ㼭 ��Ʈ������ ������
	int* best = bestSet;  //���������� �ƴҶ��� ����	
	if (best[0] == set.score) { best[1] = set.score; }
	if (best[0] < set.score) { best[0] = set.score; }
	else {
		if (best[1] < set.score) { best[1] = set.score; }
	}
}

void createNewSet(**parentSet) { //2�����迭�� �Դٰ� ���� //������� �����ʿ� �̿ϼ�
	int tempSet[8];
	for (int i = 0; i < 8; i++) {
		tempSet[i] = Behaviour[parentSet[GetRandom(0, 2)][i]]; ]
	}
	tempSet[8] = 0; //score?
}






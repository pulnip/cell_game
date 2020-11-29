#include "CpuMain.h"

int initComputer(void) {
	initList(&CPUCells);
	int count = 0;
	for (int i = 0; i < PROTO_CELL_NUMBER; i++) {
		Cell _temp;
		//tempDNA createMovingSet(cell); //구조체 2차원배열 접근방법 모름 찾아봐야함 cell->set
		//createTech(cell); //태림이가 짜놓은 코드가 뭔지 모르겠음
		_temp.id = 2;  //Cell->id , isCell = 1
		_temp.pos.x = GetRandom(0, MAP_WIDTH);  
		_temp.pos.y = GetRandom(0, MAP_HEIGHT);
		_temp.turnDNA = 0;
		_temp.forward = _temp.pos;
		_temp.stat = getBasicInfo();
		//tech 넣을자리


		Cell newCell = createCpuCell(_temp);
		if (!(newCell) == NULL) {
			count++;
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
} //나중에 destroyed 필요


void changeIsCellPos(Cell* _cell) {  //exeCpuCells 안에 포함됨
	_cell->lastPos.x = _cell->pos.x;
	_cell->lastPos.y = -cell->pos.y;
	map[_cell->lastPos.x][_cell->lastPos.y] = False;
}


void createCpuMovingSet(Cell* cell) {   //행동을 담당하는 세트만 만드는 함수  
	for (int i = 0; i < 8; i++) { // 구조체 cell에 접근하는 방법
		cell->DNA[i] = BehaviourList[GetRandom(0, sizeof(BehaviourList) / 4)];
	}
}


void exeCpuCells(void) { // ?
	Node* n = Cells.head;
	while (n != NULL) {
		Cell* cell = n->pObject;
		cell->DNA[cell->turnDNA](cell); //Do 필요없는건가
		isCellPos(cell);
		map[cell->pos.x][cell->pos.y] = True;
		cell->turnDNA = ((cell->turnDNA) + 1) % 8; // 1~8까지의 세트 안에서만 

			n = n->next;
	}
}

void Sort(Cell* set) { //미완성
	int bestSet[2] = { 0,0 };//전역변수로 해야할것 같은데 어따 넣어야 하지 2차원배열로 바꿔서 세트정보도 넣을까
	int* best = bestSet;  //전역변수가 아닐때를 위해	
	if (best[0] == set.score) { best[1] = set.score; }
	if (best[0] < set.score) { best[0] = set.score; }
	else {
		if (best[1] < set.score) { best[1] = set.score; }
	}
}

void createNewSet(**parentSet) { //2차원배열로 왔다고 가정 //대대적인 수정필요 미완성
	int tempSet[9];
	for (int i = 0; i < 8; i++) {
		tempSet[i] = Behaviour[parentSet[GetRandom(0, 2)][i]]; ]
	}
	tempSet[8] = 0; //score?
}






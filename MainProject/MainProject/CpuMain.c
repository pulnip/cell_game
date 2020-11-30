#include "CpuMain.h"

int initCPUCell(void) {
	initList(&CPUCells);
	int count = 0;
	for (int i = 0; i < PROTO_CELL_NUMBER; i++) {  // usercell.c처럼 그냥 createCpuCell()에서 받을까 고민중 나중에 새로 만들때 생각하면 아찔하네
		
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
	// DNA는 이 함수 밖에서 만듬
	appendNode(cell, &CPUCells);

	setCpuMovingSet(cell);

	return cell;
} //나중에 destroyed 필요




void setCpuMovingSet(Cell* cell) {   //행동을 담당하는 세트만 만드는 함수  
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

		cell->turnDNA = ((cell->turnDNA) + 1) % 8; // 1~8까지의 세트 안에서만 
		n = n->next;
	}
}

bestDNA* selectBestArray(bestDNA *_bestDNA) { //졸려서 이 문법이 맞는지도 모르겠다. score 옮기면 DNA가르키는 거도 같이 움직이나
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
void *createNewSet(bestDNA baseDNA, bestDNA base2DNA) { //1등 배열  //2등배열
	void *tempSet[DNA_LEN];
	for (int i = 0; i < 8; i++) {
		(tempSet+i) = BehaviourLIst[baseDNA.DNA[GetRandom(0, 2)][i]];
	}
}
*/





#include "CpuMain.h"

int initCPUCell(void) {
	initList(&CPUCells);
	int count = 0;
	for (int i = 0; i < PROTO_CELL_NUMBER; i++) {  // usercell.c처럼 그냥 createCpuCell()에서 받을까 고민중 나중에 새로 만들때 생각하면 아찔하네
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
	// DNA는 이 함수 밖에서 만듬
	appendNode(cell, &CPUcells);

	return cell;
} //나중에 destroyed 필요


void changeIsCellPos(Cell* _cell) {  //exeCpuCells 안에 포함됨
	_cell->lastPos.x = _cell->pos.x;
	_cell->lastPos.y = -cell->pos.y;
	map[_cell->lastPos.x][_cell->lastPos.y] = False;
}


void setCpuMovingSet(Cell* cell) {   //행동을 담당하는 세트만 만드는 함수  
	for (int i = 0; i < 8; i++) { //sensoring movement doing
		cell->DNA[i] = BehaviourList[GetRandom(0, sizeof(BehaviourList) / 4)];
	}
}


void exeCpuCells(void) {
	Node* n = Cells.head;
	while (n != NULL) {
		Cell* cell = n->pObject;
		cell->DNA[cell->turnDNA](cell); //Do 필요없는건가
		changeIsCellPos(cell);
		
		map[cell->pos.x][cell->pos.y] = True;
		cell->turnDNA = ((cell->turnDNA) + 1) % 8; // 1~8까지의 세트 안에서만 
		n = n->next;
		updateGame(200); //2000/200 == 10 == 0.1초?
	}
}

void selectBestArray(bestDNA* bestDNA, int _ListLen) { //졸려서 이 문법이 맞는지도 모르겠다. score 옮기면 DNA가르키는 거도 같이 움직이나
	bestDNA* _bestDNA[2];
	_bestDNA[0]->score = bestDNA->score;
	for (int i = 0; i < _ListLen; i++) {
		if (_bestDNA[0]->score == (bestDNA + i)->score) { 
			_bestDNA[1]->score = (bestDNA + i)->score; 
			_bestDNA[1]->DNA = (bestDNA + i)->DNA; //가능?
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


void *createNewSet(bestDNA baseDNA, bestDNA base2DNA) { //1등 배열  //2등배열
	void *tempSet[DNA_LEN]();
	for (int i = 0; i < 8; i++) {
		tempSet[i] = Behaviour[parentSet[GetRandom(0, 2)][i]]; ]
	}
	tempSet[8] = 0; //score?
}






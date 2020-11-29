#include "CpuMain.h"

int initComputer(void) {
	initList(&Cells);
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

		(); // 개선이 필요합니다. cell에 대한 접근방법 필요.

		Cell newCell = createCpuCell(_temp);
		if (!(newCell) == NULL) {
			count++;
		}
	}
	if (count == PROTO_CELL_NUMBER) { return 1; } // suc
	else { return -1; }//fail
}
/*
*typedef struct _Cell{
*    isCell id;  getId
*    void (**DNA)(struct _Cell);
*    Coord pos; getPos
*    int turnDNA; init(0)
*    int hp;
*    BasicInfo stat;
*    Coord forward;
*    // The location coordinates of the searched
*} Cell;
*/

int updateComputer(void) { //cell이 
	exeCpuCells(); // 
}

//Cell create (getId, get posForward
Cell* createCpuCell(Cell _temp) {
	Cell* cell = malloc(sizeof(Cell));

	cell->hp = _temp.hp;
	cell->id = _temp.id;
	cell->pos = _temp.pos;
	cell->forward = _temp.forward;
	//void (**DNA)(struct _Cell);

	appendNode(cell, &cells);

	return cell;
} //나중에 destroyed 필요


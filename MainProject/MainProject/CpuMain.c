#include "CpuMain.h"

int initComputer(void) {
	initList(&Cells);
	int count = 0;
	for (int i = 0; i < PROTO_CELL_NUMBER; i++) {
		Cell _temp;
		//tempDNA createMovingSet(cell); //����ü 2�����迭 ���ٹ�� �� ã�ƺ����� cell->set
		//createTech(cell); //�¸��̰� ¥���� �ڵ尡 ���� �𸣰���
		_temp.id = 2;  //Cell->id , isCell = 1
		_temp.pos = getPos();
		_cell.pos.x = GetRandom(0, MAP_WIDTH);  
		_cell.pos.y = GetRandom(0, MAP_HEIGHT);
		_temp.turnDNA = 0;
		_temp.stat = getBasicInfo();

		(); // ������ �ʿ��մϴ�. cell�� ���� ���ٹ�� �ʿ�.

		Cell newCell = createCell(_temp);
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

int updateComputer(void) { //cell�� 
	exeCells(); // 
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
} //���߿� destroyed �ʿ�


isCell getId(char *_id){ //map.h isCell ����ü����
	if (!(strcmp(_id,"USER")) {
		return 1;
	}
	else if (!(strcmp(_id, "CPU")) {
		return 2;
	}
	else if (!(strcmp(_id, "NOCELL")) {
		return 0;
	}
	else { return -1;} // ��������
}

Coord getPos(void) {
	Cell _cell; 
	_cell.pos.x = GetRandom(0, MAP_WIDTH);  //0�� �³�?
	_cell.pos.y = GetRandom(0, MAP_HEIGHT);
	return _cell.pos;
}

Coord getForward(void) {
	Cell _cell;
	_cell.forward.x = GetRandom(?, ? ); //? forward���� �Ұ���
	_cell.forward.y = GetRandom(?, ? ); // "
	return _cell.forward;
}

void _setForward(Cell* cell, Coord coord){
	cell->forward.x=coord.x;
	cell->forward.y=coord.y;
}
Coord _getForward(Cell* cell){
	return cell->forward
}

BasicInfo getBasicInfo(void) {
	Cell _cell;
	_cell.healthPoint; //= 1000;   //ü��
	int attackPoint; //= 100;       //���ݷ�
	int defensePoint; //= 20;       //����
	int starveMinusHealthPoint; //= 10; //���?

}
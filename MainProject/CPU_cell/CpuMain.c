#include "CpuCell.h"

int initComputer(void) {//cell �������� �𸣰ڳ�
	for (int i = 0; i < PROTO_CELL_NUMBER; i++) {
		Cell _temp//�ϴ� cell�� ����� �Լ� return ��� ���� ������ // ��ũ�� ����Ʈ���� �����ؾ��� set�⺻ 9ĭ
		//tempDNA createMovingSet(cell); //����ü 2�����迭 ���ٹ�� �� ã�ƺ����� cell->set
		//createTech(cell); //�¸��̰� ¥���� �ڵ尡 ���� �𸣰���
		_temp.id = getId("CPU");  //Cell->id , isCell = 1
		_temp.pos = getPos();
		_temp.forward = getForward();
		_temp
		Basic_Cell_Information(); // ������ �ʿ��մϴ�. cell�� ���� ���ٹ�� �ʿ�.

		createCell(_temp);
	}
}
/*
*typedef struct _Cell{
*    isCell id;
*    void (**DNA)(struct _Cell);
*    Coord pos;
*    int hp;
*    Coord forward;
*    // The location coordinates of the searched
*	// Tech�� DNA�� ������ �ʿ����� �ʳ� �ͽ��ϴ�.
*} Cell;
*/

int updateComputer(void) { //cell�� 
	for (int i = 0; i < 8; i++) { //  �ѹ��� 8���̾ƴ϶� �ѹ���.
		while(list.next != NULL)
			doYourMovingSet(&cell);
	}
}

//Cell create (getId, get posForward
Cell* createCell(cell _temp) {
	Cell* cell = malloc(sizeof(Cell));

	cell->hp = _temp.hp;
	cell->id = _temp.id;
	cell->pos = _temp.pos;
	cell->forward = _temp.forward;
	//void (**DNA)(struct _Cell);

	appendNode(cell, &cell);

	return cell;
} //���߿� destroyed �ʿ�


isCell getId(char *_id){ //map.h isCell ����ü����
	if (!strcmp(_id,"USER") {
		return 1;
	}
	else if (!strcmp(_id, "CPU") {
		return 2;
	}
	else if (!strcmp(_id, "NOCELL") {
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
	Coord.forward.x = GetRandom(?, ? ); //? forward���� �Ұ���
	Coord.forward.x = GetRandom(?, ? ); // "
	return _cell.forward;
}
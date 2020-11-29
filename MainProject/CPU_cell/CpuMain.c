#include "CpuCell.h"

int initComputer(void) {//cell �������� �𸣰ڳ�
	for (int i = 0; i < PROTO_CELL_NUMBER; i++) {
		Cell cell = createCell();//�ϴ� cell�� ����� �Լ� return ��� ���� ������ // ��ũ�� ����Ʈ���� �����ؾ��� set�⺻ 9ĭ
		createMovingSet(&cell); //����ü 2�����迭 ���ٹ�� �� ã�ƺ����� cell->set
		createTech(&cell); //�¸��̰� ¥���� �ڵ尡 ���� �𸣰���
		createId(&cell, 1);  //Cell->id , isCell = 1
		createPosforward(&cell);
		Basic_Cell_Information(); // ������ �ʿ��մϴ�. cell�� ���� ���ٹ�� �ʿ�.
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

void createId(Cell *cell, int id) {
	cell->id = 1;
}
void createPosforward(*cell) {
	GetRandom(0, 2)
}
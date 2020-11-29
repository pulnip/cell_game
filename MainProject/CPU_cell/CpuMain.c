#include "CpuCell.h"

int initComputer(void) {//cell 선언방법을 모르겠네
	for (int i = 0; i < PROTO_CELL_NUMBER; i++) {
		Cell cell = createCell();//일단 cell을 만드는 함수 return 방법 생각 안했음 // 링크드 리스트까지 연결해야함 set기본 9칸
		createMovingSet(&cell); //구조체 2차원배열 접근방법 모름 찾아봐야함 cell->set
		createTech(&cell); //태림이가 짜놓은 코드가 뭔지 모르겠음
		createId(&cell, 1);  //Cell->id , isCell = 1
		createPosforward(&cell);
		Basic_Cell_Information(); // 개선이 필요합니다. cell에 대한 접근방법 필요.
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
*	// Tech랑 DNA의 구별이 필요하지 않나 싶습니다.
*} Cell;
*/

int updateComputer(void) { //cell이 
	for (int i = 0; i < 8; i++) { //  한번에 8번이아니라 한번씩.
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
#include "CpuCell.h"

int initComputer(void) {//cell 선언방법을 모르겠네
	for (int i = 0; i < PROTO_CELL_NUMBER; i++) {
		Cell cell = createCell();//일단 cell을 만드는 함수 return 방법 생각 안했음 // 링크드 리스트까지 연결해야함
		createMovingSet(*cell); //구조체 2차원배열 접근방법 모름 찾아봐야함 cell->set
		createTech(*cell); //태림이가 짜놓은 코드가 뭔지 모르겠음
		createId(*cell, 1);  //Cell->id , isCell = 1
		createPosforward(*cell);
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
*} Cell;
*/

int updateComputer(void) { //cell이 
	for (int i = 0; i < 8; i++) { // 
		doYourMovingSet(cell->set);
	}
}

void createId(Cell *cell, int id) {
	cell.id 에 id 넣기.; (구조체에 직접적으로 접근해야함)

}
void createPosforward(*cell) {
}
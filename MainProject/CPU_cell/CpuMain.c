#include "CpuCell.h"

int initComputer(void) {//cell 선언방법을 모르겠네
	for (int i = 0; i < PROTO_CELL_NUMBER; i++) {
		Cell _temp//일단 cell을 만드는 함수 return 방법 생각 안했음 // 링크드 리스트까지 연결해야함 set기본 9칸
		//tempDNA createMovingSet(cell); //구조체 2차원배열 접근방법 모름 찾아봐야함 cell->set
		//createTech(cell); //태림이가 짜놓은 코드가 뭔지 모르겠음
		_temp.id = getId("CPU");  //Cell->id , isCell = 1
		_temp.pos = getPos();
		_temp.forward = getForward();
		_temp
		Basic_Cell_Information(); // 개선이 필요합니다. cell에 대한 접근방법 필요.

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
*	// Tech랑 DNA의 구별이 필요하지 않나 싶습니다.
*} Cell;
*/

int updateComputer(void) { //cell이 
	for (int i = 0; i < 8; i++) { //  한번에 8번이아니라 한번씩.
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
} //나중에 destroyed 필요


isCell getId(char *_id){ //map.h isCell 구조체참조
	if (!strcmp(_id,"USER") {
		return 1;
	}
	else if (!strcmp(_id, "CPU") {
		return 2;
	}
	else if (!strcmp(_id, "NOCELL") {
		return 0;
	}
	else { return -1;} // 생성실패
}

Coord getPos(void) {
	Cell _cell; 
	_cell.pos.x = GetRandom(0, MAP_WIDTH);  //0이 맞나?
	_cell.pos.y = GetRandom(0, MAP_HEIGHT);
	return _cell.pos;
}

Coord getForward(void) {
	Cell _cell;
	Coord.forward.x = GetRandom(?, ? ); //? forward뭘로 할건지
	Coord.forward.x = GetRandom(?, ? ); // "
	return _cell.forward;
}
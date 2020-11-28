#include "CpuCellSet.h"
//CPU 세트를 만드는 곳

//행동 패턴을 만드는 곳

// Cell 구조체에 point 추가?
void createMovingSet(Cell *cell) {   //행동을 담당하는 세트만 만드는 함수  
	for (int i = 0; i < 8; i++) { // 구조체 cell에 접근하는 방법
		cell -> set[i] = BehaviourList[GetRandom(0, sizeof(BehaviourList) / 4)];
	}
	set[8] = 0; // 아니면 set의 마지막을 score로? 20번째줄 참고 
}

void doYourMovingSet(int* set) {   //보내온 세트에 따라 행동
	for (int j = 0; j < 8; j++) {
		DO set[j](); 
	}
}

void Sort(Cell* set) { //set를 받아와서 거기서 '가중치'에 접근 가중치를 새로 Cell구조체에 넣어야 하나
	int bestSet[2] = { 0,0 };//전역변수로 해야할것 같은데 어따 넣어야 하지 2차원배열로 바꿔서 세트정보도 넣을까
	int* best = bestSet;  //전역변수가 아닐때를 위해	
	if (best[0] == set.score) { best[1] = set.score; }
	if (best[0] < set.score) { best[0] = set.score; }
	else {
		if (best[1] < set.score) { best[1] = set.score; }
	}
}

void createNewSet(**parentSet) { //2차원배열로 왔다고 가정
	int tempSet[9];
	for (int i = 0; i < 8; i++) {
		tempSet[i] = Behaviour[parentSet[GetRandom(0, 2)][i]]; ]
	}
	tempSet[8] = 0; //score?
	
					// 세포 창조에 들어갈 줄 ex) createCpuCell(tempSet);
}


}



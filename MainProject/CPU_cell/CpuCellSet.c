#include "CpuCellSet.h"
//CPU 세트를 만드는 곳

//행동 패턴을 만드는 곳

int bestArray[8]; //최적의 세트.

void createMovingSet(int *set) {   //행동을 담당하는 세트만 만드는 함수  
	for (int i = 0; i < 8; i++) {
		set[i] = BehaviourList[GetRandom(0, sizeof(BehaviourList) / 4)];
	}
}

void doYourMovingSet(int* set) {   //보내온 세트에 따라 행동
	for (int j = 0; j < 8; j++) {
		DO set[j](); 
	}
}

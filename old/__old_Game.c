#include "base.h"

int OnStart() {
	for (int i = 0; i < PROTO_CELL_NUMBER; i++) {
		UserAppend(CreateCell()); //유저리스트추가(셀생성())
		ComputerAppend(CreateCell()); // 컴퓨터리스트추가((셀생성))
	}
}

int OnUpdate(time_t ElapsedTime) {
	Cycle(); //한사이클
	CheckFinish(); // 종료조건체크
}

int OnDestroy() {

}

int Cylcle() {
	Basic(); // 가장 기본이 되는 행동 default;
	if (MeetEnemy == 1) { // 적을 네명이서 둘러쌓았다
		Destroy(); //cell파괴(삭제할셀,리스트)
		IncreaseHP(); // 셀의 HP증가(*셀)
	}
	if (SelfDivide() == 1) { //분열하기위한 포지션체크, 분열이가능한가
		Append(CreateCell()); // userAppend or ComputerAppend
	}
}

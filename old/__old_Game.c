#include "base.h"

int OnStart() {
	for (int i = 0; i < PROTO_CELL_NUMBER; i++) {
		UserAppend(CreateCell()); //��������Ʈ�߰�(������())
		ComputerAppend(CreateCell()); // ��ǻ�͸���Ʈ�߰�((������))
	}
}

int OnUpdate(time_t ElapsedTime) {
	Cycle(); //�ѻ���Ŭ
	CheckFinish(); // ��������üũ
}

int OnDestroy() {

}

int Cylcle() {
	Basic(); // ���� �⺻�� �Ǵ� �ൿ default;
	if (MeetEnemy == 1) { // ���� �׸��̼� �ѷ��׾Ҵ�
		Destroy(); //cell�ı�(�����Ҽ�,����Ʈ)
		IncreaseHP(); // ���� HP����(*��)
	}
	if (SelfDivide() == 1) { //�п��ϱ����� ������üũ, �п��̰����Ѱ�
		Append(CreateCell()); // userAppend or ComputerAppend
	}
}

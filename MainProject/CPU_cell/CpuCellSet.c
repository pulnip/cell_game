#include "CpuCellSet.h"
//CPU ��Ʈ�� ����� ��

//�ൿ ������ ����� ��

int bestArray[8]; //������ ��Ʈ.

void createMovingSet(int *set) {   //�ൿ�� ����ϴ� ��Ʈ�� ����� �Լ�  
	for (int i = 0; i < 8; i++) {
		set[i] = BehaviourList[GetRandom(0, sizeof(BehaviourList) / 4)];
	}
}

void doYourMovingSet(int* set) {   //������ ��Ʈ�� ���� �ൿ
	for (int j = 0; j < 8; j++) {
		DO set[j](); 
	}
}

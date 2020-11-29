#include "CpuCellSet.h"
//CPU ��Ʈ�� ����� ��

//�ൿ ������ ����� ��

// Cell ����ü�� point �߰�?
void createMovingSet(Cell *cell) {   //�ൿ�� ����ϴ� ��Ʈ�� ����� �Լ�  
	for (int i = 0; i < 8; i++) { // ����ü cell�� �����ϴ� ���
		cell -> set[i] = BehaviourList[GetRandom(0, sizeof(BehaviourList) / 4)];
	}
	set[8] = 0; // �ƴϸ� set�� �������� score��? 20��°�� ���� 
}

void exeCpuCells(void) {
	Node* n = Cells.head;
	while (n!= NULL) {
		Cell* cell = n->pObject;
		DO cell->DNA[cell->turnDNA](cell); //Do �ʿ���°ǰ�
		//filterPixelToCI()
		cell->turnDNA = ((cell->turnDNA) + 1) % 8 // 1~8������ ��Ʈ �ȿ����� 
		n = n->next;
	}
}

void Sort(Cell* set) { //set�� �޾ƿͼ� �ű⼭ '����ġ'�� ���� ����ġ�� ���� Cell����ü�� �־�� �ϳ�
	int bestSet[2] = { 0,0 };//���������� �ؾ��Ұ� ������ ��� �־�� ���� 2�����迭�� �ٲ㼭 ��Ʈ������ ������
	int* best = bestSet;  //���������� �ƴҶ��� ����	
	if (best[0] == set.score) { best[1] = set.score; }
	if (best[0] < set.score) { best[0] = set.score; }
	else {
		if (best[1] < set.score) { best[1] = set.score; }
	}
}

void createNewSet(**parentSet) { //2�����迭�� �Դٰ� ����
	int tempSet[9];
	for (int i = 0; i < 8; i++) {
		tempSet[i] = Behaviour[parentSet[GetRandom(0, 2)][i]]; ]
	}
	tempSet[8] = 0; //score?
	
					// ���� â���� �� �� ex) createCpuCell(tempSet);
}





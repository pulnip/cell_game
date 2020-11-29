#include "CpuCellSet.h"
#include "Cell_Properties.h" // �¸��� �Լ��� ������ ��������� ����
#include "Cell.h"
#include "Map.h"
#include <string.h>
#include "SuperHeader.h"
typedef void(*DO)();

void createMovingSet(Cell* cell);
void exeCpuCells(void);


extern List Cells;

int initComputer(void);
int updateComputer(void);


Cell* createCpuCell(Cell temp);
//cell base data

void changeIsCellPos(Cell* _cell);
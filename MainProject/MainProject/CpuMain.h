#include "CpuCellSet.h"
#include "Cell_Properties.h" // �¸��� �Լ��� ������ ��������� ����
#include "Cell.h"
#include "Map.h"
#include <string.h>


extern List Cells;

int initComputer(void);
int updateComputer(void);


Cell* createCpuCell(Cell temp);
//cell base data

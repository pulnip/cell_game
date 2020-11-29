#include "CpuCellSet.h"
#include "Cell_Properties.h" // �¸��� �Լ��� ������ ��������� ����
#include "Cell.h"
#include "Map.h"
#include <string.h>


extern List Cells;

int initComputer(void);
int updateComputer(void);


Cell* createCell(Cell temp);
//cell base data
isCell getId(char* _id);
Coord getPos(void);
Coord getForward(void);
BasicInfo getBasicInfo();

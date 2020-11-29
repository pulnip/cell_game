#include "CellProperties.h" // �¸��� �Լ��� ������ ��������� ����
#include "Cell.h"
#include "Map.h"
#include "Game.h"
#include <string.h>
#include "SuperHeader.h"
typedef void(*DO)();

void setCpuMovingSet(Cell* cell);
void exeCpuCells(void);


int initComputer(void);
int updateComputer(void);


Cell* createCpuCell(Cell temp);
//cell base data

void changeIsCellPos(Cell* _cell);
#include "CpuCellSet.h"
#include "Cell_Properties.h" // 태림이 함수를 가져올 헤더파일이 없음
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
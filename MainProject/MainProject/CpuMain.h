#include "CpuCellSet.h"
#include "Cell_Properties.h" // 태림이 함수를 가져올 헤더파일이 없음
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

#ifndef __INC_CPU_MAIN
#define __INC_CPU_MAIN

#include "SuperHeader.h"

#include "Cell_Properties.h"
#include "Cell.h"
#include "Map.h"

#include <time.h>

typedef void(*DO)();

typedef struct _bestDNA {
	void (*DNA[DNA_LEN])(struct _Cell);
	int score;
}bestDNA;

StatusFunc initCPUCell;
int updateCPUCell(time_t ElapsedTime);
StatusFunc deleteCPUCell;

void setCpuMovingSet(Cell* cell);


Cell* createCpuCell();
//cell base data

void exeCpuCells(void);
bestDNA* selectBestArray(bestDNA* _bestDNA);
void* createNewSet(bestDNA baseDNA, bestDNA base2DNA);//alsdhkstjd

#endif // __INC_CPU_MAIN

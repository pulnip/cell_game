#ifndef __INC_CPU_CELL
#define __INC_CPU_CELL

#include "SuperHeader.h"

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

Cell* createCpuCell();
void setCpuMovingSet(Cell* cell);

void exeCpuCells(void);
bestDNA* selectBestArray(bestDNA* _bestDNA);
void* createNewSet(bestDNA baseDNA, bestDNA base2DNA);

void ChooseStat(BasicInfo*);
void SelectBestTech(time_t ElapsedTime);
int AgrresiveAbility(int level);
int StabilityAbility(int level);
int DefensiveAbility(int level);
int Attack(int attackpoint, int defensepoint);

#endif
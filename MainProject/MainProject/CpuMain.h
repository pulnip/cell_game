#include "Cell_Properties.h" // 태림이 함수를 가져올 헤더파일이 없음
#include "Cell.h"
#include "Map.h"
#include "Game.h"
#include <string.h>
#include "SuperHeader.h"
typedef void(*DO)();

typedef struct _bestDNA {
	void (*DNA[DNA_LEN])(struct _Cell);
	int score;
}bestDNA;

int initComputer(void);
int updateComputer(void);


void changeIsCellPos(Cell* _cell);

void setCpuMovingSet(Cell* cell);


Cell* createCpuCell(Cell temp);
//cell base data

void exeCpuCells(void);
void selectBestArray(bestDNA* bestDNA, int _ListLen);
void* createNewSet(bestDNA baseDNA, bestDNA base2DNA);//alsdhkstjd


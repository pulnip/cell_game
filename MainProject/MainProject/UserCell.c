#include "UserCell.h"

List Cells;

#define PROTO_CPU_CELL_NUMBER 2

int initUserCell(void){
    initList(&Cells);

    for(int i=0; i<PROTO_CELL_NUMBER; ++i){
        Cell* cell=createUserCell();
    }

    // ..

    return 0;
}
int updateUserCell(void){
    // ..

    printCells();

    return 0;
}
int deleteUserCell(void){
    eraseHeapObjectList(&Cells);
    // ..

    return 0;
}

Cell* createUserCell(){
    Cell* cell=malloc(sizeof(Cell));
    cell->id=UserCell;

    cell->DNA=NULL;

    cell->lastPos.x=cell->pos.x=GetRandom(0, MAP_WIDTH);
    cell->lastPos.y=cell->pos.y=GetRandom(0, MAP_HEIGHT);

    cell->turnDNA=0;

    cell->hp=DEFAULT_HP;

    cell->forward.x=cell->pos.x;
    cell->forward.x=cell->pos.y;

    // basic info
    // ..

    appendNode(cell, &Cells);

    return cell;
}

void printCells(void){
    Node* n=Cells.head;

    while(n!=NULL){
        Cell* cell=n->pObject;

        map[cell->lastPos.y][cell->lastPos.x].isUserCell=False;
        map[cell->pos.y][cell->pos.x].isUserCell=True;

        n=n->next;
    }
}

#include "UserCell.h"

UserInput userInput;

int initUserCell(void){
    initList(&UserCells);

    for(int i=0; i<PROTO_USER_CELL_NUMBER; ++i){
        Cell* cell = createUserCell();
    }
    UserCellDNA();
    return 0;
}

int updateUserCell(void){
    // ü�� ���̸� ���� (���ݷ� - ���� ��ŭ)
    // ���� ������ �ǰ� ����
    // ���� �ȸ����� �� ����
    printUserCells();
    return 0;
}

int deleteUserCell(void){
    eraseHeapObjectList(&UserCells);
    // ..

    return 0;
}

Cell* createUserCell(){

    Cell* cell=malloc(sizeof(Cell));
    cell->id=UserCell;

    strcpy(cell->DNA, NULL);

    cell->lastPos.x=cell->pos.x=GetRandom(0, MAP_WIDTH);
    cell->lastPos.y=cell->pos.y=GetRandom(0, MAP_HEIGHT);

    cell->turnDNA=0;

    cell->stat.healthPoint = DEFAULT_HP;
    cell->stat.attackPoint = DEFAULT_AP;
    cell->stat.defensePoint = DEFAULT_DP;

    cell->forward.x=cell->pos.x;
    cell->forward.x=cell->pos.y;

    appendNode(cell, &UserCells);

    return cell;
}

void printUserCells(void){
    Node* n=UserCells.head;

    while(n!=NULL){
        Cell* cell=n->pObject;

        map[cell->lastPos.y][cell->lastPos.x].isUserCell=False;
        map[cell->pos.y][cell->pos.x].isUserCell=True;

        n=n->next;
    }
}

/* printf("-----��Ʈ ���------\n");
printf("1. ���� ����\n");
printf("2. �Ʊ��� ����\n");
printf("3. ������ ����\n");
printf("4. ������ �ٰ�����\n");
printf("5. �ָ� ��������\n");
printf("6. ������ �Ա�\n");
printf("7. ����Ʈ�� ���\n");
printf("8. ���� �����ϱ�\n");
printf("9. �п��ϱ�\n"); */

void UserCellDNA(void)
{
    char* const arr[9] = { "seeEnemy", "seeFriend", "seeFood", "moveCloser", "moveFurther", 
        "getFood", "getPoint", "doCannibal", "divide" };
    int* SaveArr[8];
    for (int i = 0; i < 8; i++) 
    {
        int num = UserInput(); // ȭ�鿡�� ������ �Է��� �޾Ҵٰ� �����ϴ� ������ �Լ�
        num = SaveArr[i];
    }
}

void UserCellTechTree(void)
{

}
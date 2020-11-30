#include "UserCell.h"
#include "Cell_Properties.h"

UserInput userInput;
int health_point = 0;
int attack_point = 0;
int defense_point = 0;

int initUserCell(void){
    initList(&UserCells);

    for(int i=0; i<PROTO_USER_CELL_NUMBER; ++i){
        Cell* cell = createUserCell();
    }
    UserCellDNA();
    UserCellTechTree();
    return 0;
}

int updateUserCell(time_t ElapsedTime){
    static time_t timer=0;
    timer+=ElapsedTime;
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
    cell->forward.y=cell->pos.y;

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
	int num_a, num_b, num_c;
	printf("1. ȣ���� \n");
	printf("2. ������ \n");
	printf("3. ���׼� \n");

	printf("���׷��̵� �ϰ� ���� �ɷµ��� ���ڷ� �Է��Ͻÿ� (ex.1 2 3): \n");
	scanf_s("%d %d %d", &num_a, &num_b, &num_c);

	switch (num_a)
	{
	case 1:
		attack_point += 100;
		break;
	case 2:
		health_point += 10;
		break;
	case 3:
		defense_point += 1;
		break;
	default:
		break;
	}

	switch (num_b)
	{
	case 1:
		attack_point += 100;
		break;
	case 2:
		health_point += 10;
		break;
	case 3:
		defense_point += 1;
		break;
	default:
		break;
	}


	switch (num_c)
	{
	case 1:
		attack_point += 100;
		break;
	case 2:
		health_point += 10;
		break;
	case 3:
		defense_point += 1;
		break;
	default:
		break;
	}
}
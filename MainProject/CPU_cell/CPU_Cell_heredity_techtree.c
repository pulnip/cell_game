#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "Infra.h"
#include "CellBehaviours.h"
#include "LinkedList.h"
#include "Game.h"
#include "CPU_cell_notice.h"
#include "Cell.h"
#include "Cell.c"
#include "Cell_properties.c"

struct Coord;
struct Pixel;
struct Cell;


//cell_properties�� �ִ� �������ǵ��� ��ũƮ���� ��ȭ��Ű�� ��
//�ؾ� �� ��. 


void Cell_gene_techtree_information()
{
	printf("##### ��ũƮ�� #####")
}

int select[6];


void Cell_techtree(int select[6])
{
	//������ ��ũƮ�� ����
	//cpu�� ������ ��ũƮ�� �����
	//��

	Recognize_ability(int select[0]);
	Agrresive_ability(int select[1]);
	Stability_ability(int select[2]);
	Defensive_ability(int select[3]);
	Mobility_ability(int select[4]);
	Digestive_ability(int select[5]);

}
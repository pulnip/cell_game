#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "Infra.h"
#include "CellBehaviours.h"
#include "Game.h"
#include "CPU_cell_notice.h"

//������ �� ���� �� ������
//#####�� �׸��� ������ �� �ǵ� �츮 �ʿ� ���� �������� ���ϵ� ������ ���� ������#####
//���� �� ���� �ϳ��� ���� ������Ʈ �� �߰� �ܰ��� �� ������ �ϳ� �� �ް� �ִ� �� ���� ��
//�׷��ϱ�
//�������� �� -- ���� �� -- CPU���� �� �̷� ������ ������




//������ ������

//�켱 �������� �����;� ��

//���������� �����ӿ� ���� ������ �����;� �� --1	(�ʿ� ���� ���Ͽ��� ������ �������°ɷ� �ұ�?)
//�׸��� ���������� �ൿ�� ���� ������ �����;� ���� --2

//�׸��� ���� �� �������� �����ؾ߰��� --3

//������ �������� �����ߴٸ� ������ ���Ѿ߰���.
//		������ hp�� ���ؼ� ������Ʈ �ؾ��ϸ� --> �켱 ���� cpu���� �� �� ������ �����;� �Ѵ�.
//		������ ������ ���ؼ��� ������Ʈ�� �ؾ����� -->���� ������ �������ٸ� �ʿ��� ��������
//		������ �ൿ�� ������ ��Ʈ�� ���� �̿� �°� �����;� ����
//		(������ ��Ʈ�� ���̵��� ����)
//		(���� ��� ���̵�1�� ���� ������ �Ա� ���� �ѷ� �ο����� �Ϻ� �����̴��� ���� �ʴ� �ൿ�� �ϴ� �ݸ鿡)
//		(		   ���̵�10�� �ٵ��� �˰������� �������簡 ��Ե� �ּ��� ���� �δ� �ൿ�� ���̵���)

//�̷��� ��Ʈ�� ���� ���� ������ �ൿ�� �ؾ߰���
//��ǻ�ͼ����� �ൿ �Լ��� ��������
//��ǻ�ͼ����� [�̵�]�ϴ� ���� ����ϴ� �ൿ�Լ�
//��ǻ�ͼ����� ���� �˰����� ���� �ൿ�ϴ� �Լ�(�ڼ��ϰԴ� �𸣰ڴ�)

struct Coord;
struct Pixel;
struct Cell;


void Get_User_Cell_information(int )
{
	//������������ ������ �����´�
	//��� ���� ������ 
	int Distinguish_Pixel;

	if (Pixel.no_cell == True)
	{
		Distinguish_Pixel = 0;
	}
	else if (Pixel.User_cell == True)
	{
		Distinguish_Pixel = 1
	}
	else if (Pixel.CPU_cell == True)
	{
		Distinguish_Pixel = 2
	}
	

	Cell.id

	
}

int main(void)
{

}
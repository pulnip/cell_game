/*
��Ʈ�� �޾Ƽ� DNA�� �����ϴ°� onstart�� �ְ�
��Ʈ�� ���� �ൿ�ؼ� �ʾ�����Ʈ + �����ο�
������ ������ �����˰��� ������ ������ ���� 5�� ���� �ڽļ� 13�� + 2�� ���� �ٽ� ����
*/

//�ڰ�� �Ű������� � ������ �޾ƾ� ���� ���� ��ĭ���� �׾�...��

#include <stdio.h>
#include <time.h>
#include <Windows.h>

void Get_User_Cell_information();	//���� ������ DNA ������ �������� �Լ�

void Create_DNA();	//DNA�� ����� �Լ�
void CPU_Cell_Map_Update();	//CPU������ �� ������Ʈ �Լ�
int Score();	//������ �ο��ϴ� �Լ�


typedef struct Send_Cpucell_result {

}SCPU_result;	//CPU������ ��Ȳ�� ������ ���� �����ϴ� ����ü

void Send_Cpucell_result();	//CPU������ ��Ȳ�� ������ �Լ�




typedef struct Get_Set_Information {

}GSet_Inform;	//��Ʈ�� ������ �������� ���� �����ϴ� ����ü

void Get_Set_Information();	//��Ʈ�� ������ �������� �Լ�


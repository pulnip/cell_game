#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "CellBehaviours.h"
#include "Game.h"
#include "CPU_cell_notice.h"
#include "Cell.h"


void Basic_Cell_Information();
void Recognize_ability(int level, int Recognize_ability);//������ ���� �⵿���� �Է��ϼ���
//�̰� �ٵ� cell.h���� MAX_SIGHT�� ��ġ�� �����ؾ� �ϴ� �Ŷ� define���� �ʰ� �׳� ���� ���� �ϸ� �ȵǷ���? �ƴϸ� �׳� �� �׸� �������簡 �� �� �ϳ��� ���սô�


void Agrresive_ability(int level, int attack_point);//������ ���� ���ݷ��� �Է��ϼ���
void Stability_ability(int level, int health_point);//������ ���� '�ִ�'ü���� �Է��ϼ���
void Defensive_ability(int level, int defense_point);//������ ���� ������ �Է��ϼ���
void Mobility_ability(int level);//������ �Է��ϼ���
void Digestive_ability(int level, int starve_minus_health_point)//������ ���� ��� ���� ����Ʈ�� �Է��ϼ���


int Attack(int attack_point, int defense_point); //���� ����Ʈ�� �����ϴ� ����� �� ��� ����Ʈ�� ��� �ϴ� ����� ��
void Be_Attacked(int health_point, int defense_point); //���� ����
void Starve(int health_point, int starve_minus_health_point); //�� �� ������ ���� ���� ü�� ���̴� �ൿ





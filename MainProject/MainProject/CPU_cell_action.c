#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "Infra.h"
#include "CellBehaviours.h"
#include "Game.h"
#include "CPU_cell_notice.h"

//질문은 맨 위에 써 놓을께
//#####아 그리고 생각이 난 건데 우리 맵에 대한 공통적인 파일도 만들어야 하지 않을까#####
//공통 맵 파일 하나에 각자 업데이트 할 중간 단계의 맵 파일을 하나 씩 달고 있는 게 좋을 듯
//그러니까
//유저세포 맵 -- 통합 맵 -- CPU세포 맵 이런 식으로 말이지




//순서를 정하자

//우선 정보들을 가져와야 해

//유저세포의 움직임에 대한 정보를 가져와야 해 --1	(맵에 관한 파일에서 정보를 가져오는걸로 할까?)
//그리고 유저세포의 행동에 대한 정보를 가져와야 하지 --2

//그리고 가져 온 정보들을 정리해야겠지 --3

//가져온 정보들을 정리했다면 적용을 시켜야겠지.
//		세포의 hp에 대해서 업데이트 해야하며 --> 우선 유저 cpu세포 둘 다 정보를 가져와야 한다.
//		세포의 유무에 대해서도 업데이트를 해야하지 -->만약 세포가 없어졌다면 맵에서 지워야지
//		세포가 행동할 패턴의 세트를 이제 이에 맞게 가져와야 겠지
//		(가져온 세트는 난이도에 따라서)
//		(예를 들면 난이도1은 유저 세포가 먹기 좋게 둘러 싸여지기 일보 직전이더라도 먹지 않는 행동을 하는 반면에)
//		(		   난이도10은 바둑의 알고리즘을 가져오든가 어떻게든 최선의 수를 두는 행동을 보이도록)

//이렇게 세트에 따라서 이제 실제로 행동을 해야겠지
//컴퓨터세포의 행동 함수를 만들어야지
//컴퓨터세포가 [이동]하는 것을 담당하는 행동함수
//컴퓨터세포가 유전 알고리즘에 관해 행동하는 함수(자세하게는 모르겠다)

struct Coord;
struct Pixel;
struct Cell;


void Get_User_Cell_information(int )
{
	//유저세포에서 정보를 가져온다
	//상대 유저 세포의 
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
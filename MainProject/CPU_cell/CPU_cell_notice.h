/*
세트를 받아서 DNA를 생성하는건 onstart에 있고
세트에 따라 행동해서 맵업데이트 + 점수부여
게임이 끝나면 유전알고리즘에 보내서 점수에 따라 5개 유지 자식셀 13개 + 2개 랜덤 다시 생성
*/

//자고로 매개변수는 어떤 식으로 받아야 할지 몰라서 빈칸으로 뒀어...ㅠ

#include <stdio.h>
#include <time.h>
#include <Windows.h>

void Get_User_Cell_information();	//유저 세포의 DNA 정보를 가져오는 함수

void Create_DNA();	//DNA를 만드는 함수
void CPU_Cell_Map_Update();	//CPU세포의 맵 업데이트 함수
int Score();	//점수를 부여하는 함수


typedef struct Send_Cpucell_result {

}SCPU_result;	//CPU세포의 상황을 보내기 위해 정리하는 구조체

void Send_Cpucell_result();	//CPU세포의 상황을 보내는 함수




typedef struct Get_Set_Information {

}GSet_Inform;	//세트의 정보를 가져오기 위해 정리하는 구조체

void Get_Set_Information();	//세트의 정보를 가져오는 함수


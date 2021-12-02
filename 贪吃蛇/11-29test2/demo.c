#define _CRT_SECURE_NO_WARNINGS 1
#include "snake.h"



int main()
{
	//�������
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);


	srand((unsigned int)time(NULL));  //���������

	InitSnake();  //��ʼ����
	InitFood();   //��ʼ��ʳ��
	InitWall();
	InitUI();     //����
	PlayGame();  

	//��ӡ����
	ShowScore();
	return 0;
}
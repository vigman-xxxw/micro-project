#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("****************************\n");
	printf("*********  1.play  *********\n");
	printf("*********  0.exit  *********\n");
	printf("****************************\n");
}

void game()
{
	//��ʼ������
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');

	

	//��ӡ����
	//DisplayBoard(mine,ROW,COL);
	DisplayBoard(show, ROW, COL);


	//������
	SetMine(mine,ROW,COL);


	//DisplayBoard(mine, ROW, COL);

	//�Ų���
	FindMine(mine,show, ROW, COL);


}

int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("ɨ����Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("��������,����������\n");
		}
	} while (input);


	return 0;
}
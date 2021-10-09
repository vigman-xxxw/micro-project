#include "game.h"


void menu()
{
	printf("***********************\n");
	printf("******** 1.play *******\n");
	printf("******** 0.exit *******\n");
	printf("***********************\n");
}

char ret = 0;  //������Ϸ״̬


void game()
{
	char board[ROW][COL];
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);

		DisplayBoard(board, ROW, COL);
		//�ж��Ƿ������Ϸ
		ret = IsWin(board, ROW, COL);
		
		if (ret != 'C')
		{
			break;
		}

		//��������
		ComputerMove(board, ROW, COL);

		DisplayBoard(board, ROW, COL);

		//�ж��Ƿ������Ϸ
		ret = IsWin(board, ROW, COL);

		if (ret != 'C')                               //  BUG :  1.ƽ�ֲ��˳�   2.������������ҵ����Ӹ���
		{
			break;
		}


	}
	if (ret == '*')
	{
		printf("���Ӯ��\n");
		

	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
		
	}
	else
	{
		printf("ƽ��\n");
	}
	DisplayBoard(board, ROW, COL);

}



int main()
{
	int c = 0;

	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>\n");
		scanf("%d",&c);
		switch (c)
		{
		case 1:
			printf("��������Ϸ\n");
			game();
			break;

		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����,����ѡ��\n");
			break;
		}
	} while (c);

	return 0;
}
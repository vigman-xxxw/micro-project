#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#include <stdio.h>


void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
			//printf("%c \n", board[i][j]);
		}
	}
}


//      3*3     ��������
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//
//	for (i = 0; i < row; i++)
//	{
//		printf(" %c ح %c ح %c \n", board[i][0], board[i][1], board[i][2]);
//		if (i < row -1)
//		{
//			printf("---ح---ح---\n");
//		}
//	}
//}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int m = 0;
	for (m = 0; m < row; m=m+1)     //��ӡ��
	{
		int n = 0;
		for (n = 0;n<col;n++)    //��ӡ��
		{
			printf(" %c ",board[m][n]);
			if (n < col - 1)
			{
				printf("ح");

			}
		}
		printf("\n");
		if (m < row - 1)
		{
			int m = 0;
			for (m = 0; m < col; m++)
			{
				//printf("%d", col);

				printf("---");
				if (m < col - 1)
					printf("ح");
			}
			printf("\n");
		 }

		
	}
}



void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("�����:>\n");
		printf("����������:>");
		scanf("%d %d", &x, &y);

		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{

			//����
			//�Ƿ����걻ռ��
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���걻ռ��\n");
			}

		}
		else
		{
			printf("����Ƿ�, ����������\n");
		}

	}
	

}



void ComputerMove(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		printf("������;>\n");
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
		
	}

}

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;  //����û��
			}

		}
	}
	return 1; //��������
}


char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//�ж�����
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}


	}
	//�ж�����
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}

	//�ж϶Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}


	//�ж�ƽ��
	//����������˷���1  ��������0
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}
	//����
	return 'C';


}	

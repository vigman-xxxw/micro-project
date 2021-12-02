#include "snake.h"


//�ߵĳ�ʼ��
void InitSnake()
{
	snake.size = 2;
	snake.body[0].x = WIDE / 2;     //��ͷ��ʼ��
	snake.body[0].y = HIGH / 2;

	snake.body[1].x = WIDE / 2 - 1; //�ߵ�һ�������ʼ��
	snake.body[1].y = HIGH / 2;
}


//ʳ��ĳ�ʼ��
void InitFood()
{
	food.x = rand() % WIDE; 
	food.y = rand() % HIGH;
}


//��ʼ��UI 
void InitUI()
{
	//��ȡ���λ�õı���
	COORD coord = { 0 };

	//����
	
	for (int i = 0; i < snake.size; i++)
	{
		coord.X = snake.body[i].x;
		coord.Y = snake.body[i].y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		if(i == 0)
			putchar('@');
		else
		{
			putchar('*');
		}
		
	}
	//ȥ����β
	coord.X = lastx;
	coord.Y = lasty;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(' ');

	//��ʳ��
	coord.X = food.x;
	coord.Y = food.y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('#');




}

void PlayGame()
{
	char key = 'd';
	//�ж����Ƿ�ײǽ
	while (snake.body[0].x >=0 && snake.body[0].x <WIDE
		&& snake.body[0].y >=0 && snake.body[0].y <HIGH)
	{

		InitUI();

		//�����û�����wasd
		if (_kbhit()) //��������ֵΪ��˵��������  �����������û�����
		{
			key = _getch();
		}
		switch (key)
		{
		case 'w':
			kx = 0;
			ky = -1;
			break;
		case 'a':
			kx = -1;
			ky = 0;
			break;
		case 's':
			kx = 0;
			ky = 1;
			break;
		case 'd':
			kx = 1;
			ky = 0;
			break;
		default:
			break;
		}


		//��ͷײ���� 
		
		for (int i = 1; i < snake.size; i++)
		{
			//��ͷ�Ƿ��������
			if (snake.body[0].x == snake.body[i].x
				&& snake.body[0].y == snake.body[i].y)
				return;
		}
		//��ͷײʳ��
		if (snake.body[0].x == food.x
			&& snake.body[0].y == food.y)
		{
			//ʳ����ʧ
			InitFood();

			//��������
			snake.size++;
			//�ӷ�
			score += 10;
			//����
			sleepsed -= 20;
		}

		//�洢��β������
		lastx = snake.body[snake.size - 1].x;
		lasty = snake.body[snake.size - 1].y;
		
		//���ƶ� ǰһ���������һ�����帳ֵ
		for (int i = snake.size - 1; i > 0; i--)
		{
			snake.body[i].x = snake.body[i - 1].x;
			snake.body[i].y = snake.body[i - 1].y;

		}
		snake.body[0].x += kx;   //�޸���ͷ����
		snake.body[0].y += ky;

		//����
		Sleep(sleepsed);
		//����
		//system("cls");

	}
}

void InitWall()
{
	for (int i = 0; i <= HIGH; i++)
	{
		for (int j = 0; j <= WIDE; j++)
		{
			if (j == WIDE)
			{
				printf("|");
			}
			else if (i == HIGH)
			{
				printf("_");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}


void ShowScore()
{
	//�����Ĭ��λ���ƶ�����������Ϸ��λ��
	COORD coord;
	coord.X = 0;
	coord.Y = HIGH + 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	printf("GAME OVER!!!\n");
	printf("�ɼ�Ϊ %d\n\n\n\n\n",score);
}

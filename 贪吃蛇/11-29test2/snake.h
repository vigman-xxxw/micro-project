#pragma once
//ͷ�ļ�����
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

//�궨��
#define WIDE 60
#define HIGH 20

static int score = 0;

static int kx = 0;    //�û�����wasd �õ�������
static int ky = 0;

static int lastx = 0;  //��β������
static int lasty = 0;

static int sleepsed = 400;


//һ������Ķ���
struct BODY
{
	int x;
	int y;
}body;

//�����߶���
struct SNAKE
{
	struct BODY body[HIGH * WIDE];
	int size;
}snake;

//����ʳ�����
struct FOOD
{
	int x;
	int y;
}food;


//����������
void InitSnake();

void InitFood();

void InitUI();

void PlayGame();

void InitWall();

void ShowScore();

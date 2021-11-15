#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
//ͷ�ļ�
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//����
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30

#define DEFAULT_SZ 3
#define INC_SZ 2

#define MAX 1000

//���͵Ķ���
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;  //��struct PeoInfo  ��дΪ PeoInfo 

typedef struct Contact
{
	//����ͨѶ¼       ��̬�汾
	PeoInfo* data;  //���붯̬�ռ�
	int sz;
	int capacity;//�������
}Contact;

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);


//������ϵ��
void AddContact(Contact* pc);


//��ӡͨѶ¼��Ϣ
void PrintContact(const Contact* pc);


//ɾ��ͨѶ¼����Ϣ
void DelContact(Contact* pc);

//����ͨѶ¼
void SearchContact(Contact* pc);


//FindByName����
int FindByName(Contact* pc, char name[]);


//�޸�ͨѶ¼
void ModifyContact(Contact* pc);


//����ͨѶ¼
void DestoryContact(Contact *pc);

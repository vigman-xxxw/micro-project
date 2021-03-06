#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
//头文件
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//定义
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30

#define DEFAULT_SZ 3
#define INC_SZ 2

#define MAX 1000

//类型的定义
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;  //把struct PeoInfo  简写为 PeoInfo 

typedef struct Contact
{
	//创建通讯录       动态版本
	PeoInfo* data;  //申请动态空间
	int sz;
	int capacity;//最大容量
}Contact;

//初始化通讯录
void InitContact(Contact* pc);


//增加联系人
void AddContact(Contact* pc);


//打印通讯录信息
void PrintContact(const Contact* pc);


//删除通讯录的信息
void DelContact(Contact* pc);

//查找通讯录
void SearchContact(Contact* pc);


//FindByName定义
int FindByName(Contact* pc, char name[]);


//修改通讯录
void ModifyContact(Contact* pc);


//销毁通讯录
void DestoryContact(Contact *pc);

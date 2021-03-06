#include "contact.h"



void menu()
{
	printf("********************************\n");
	printf("*******  1.add    2.del    *****\n");
	printf("*******  3.search 4.modify *****\n");
	printf("*******  5.sort   6.print  *****\n");
	printf("*******  0.exit            *****\n");
	printf("********************************\n");
}


enum option
{            //枚举类型成员最好大写
	EXIT,
	add,
	del,
	search,
	modify,
	sort,
	print

};

int main()
{
	int input = 0;
	//创建通讯录
	Contact con;
	//初始化通讯录
	//给data申请一块连续的空间在堆上
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			AddContact(&con);
			break;
		case del:
			DelContact(&con);
			break;
		case search:
			SearchContact(&con);
			break;
		case modify:
			ModifyContact(&con);
			break;
		case sort:
			//自己完善
			break;
		case print:
			PrintContact(&con);   //即使不修改数据 传地址也比较好
			break;
		case EXIT:
			//保存数据
			SaveContact(&con);

			//销毁内存中的数据
			DestoryContact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("输入有误,请重新输入;>");
			break;
		}


	} while (input);


	return 0;
}
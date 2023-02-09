#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include"contact.h"
void menu()
{
	printf("*******************************\n");
	printf("*******1.add     2.del   ******\n");
	printf("*******3.search  4.modify******\n");
	printf("*******5.show    6.sort  ******\n");
	printf("*******0.exit            ******\n");
	printf("*******************************\n");
}
int main()
{
	int input=0;
	//创建同学录
	struct Contact con;//con就是通讯录，里边包含：date指针，capacity和size
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请选择\n");
		scanf("%d",&input);
		switch(input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			break;
		case EXIT:
			//销毁通讯录，释放动态开辟的内存
			DestroryContact(&con);
			printf("退出同学录\n");
			break;
		default:
			printf("选择错误\n");
			break;

		}

	}while(input);
	return 0;

}
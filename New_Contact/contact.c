#define _CRT_SECURE_NO_WARNINGS 1 
#include"contact.h"
//#include<memory.h>


void InitContact(struct Contact* ps)
{
	//memset(ps->data,0,sizeof(ps->data));
	//ps->size=0;
	ps->data=(struct PeoInfe*)malloc(DEFAULT_SZ*sizeof(struct PeoInfe));
	if(ps->data==NULL)
	{
		return;
	}
	ps->size=0;
	ps->capacity=DEFAULT_SZ;//默认开始容量
}
void CheckCapacity(struct Contact* ps)
{
	if(ps->size==ps->capacity)
	{
		//增容
		struct PeoInfe* ptr=(struct PeoInfe*)realloc(ps->data,(ps->capacity+2)*sizeof(struct PeoInfe));
		if(ptr !=NULL)
		{
			ps->data=ptr;
			ps->capacity+=2;
			printf("增容成功\n");
		}
		else
		{
			printf("增容失败\n");
		}
	}
}
void AddContact(struct Contact* ps)
{
	//检测当前通讯录的容量，如果满了增容，如果不满什么都不执行
	CheckCapacity(ps);
	//增加数量
	printf("请输入名字:>");
	scanf("%s",ps->data[ps->size].name);
	printf("请输入年龄:>");
	scanf("%d",&(ps->data[ps->size].age));
	printf("请输入性别:>");
	scanf("%s",ps->data[ps->size].sex);
	printf("请输入电话:>");
	scanf("%s",ps->data[ps->size].tele);
	printf("请输入地址:>");
	scanf("%s",ps->data[ps->size].addr);
	ps->size++;
	printf("添加成功\n");


}

void ShowContact(const struct Contact* ps)
{
	if(ps->size==0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i=0;
	    printf("%-5s\t%-4s\t%-5s\t%-13s\t%-20s\n","名字","年龄","性别","电话","地址");
		for(i=0;i<ps->size;i++)
		{
			printf("%-5s\t%-4d\t%-5s\t%-13s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);

		}
	}
	
}


static int FindByname(struct Contact* ps,char name[MAX_NAME])
{
	int i=0;
	for(i=0;i<ps->size;i++)
	{
		if(0==strcmp(ps->data[i].name,name))
		{
			return i;
		}
	}
	return -1;
	
}//static修饰的函数只能在contact.c中使用，不用暴露在外面

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	int i=0;
	int pos=0;
	printf("请输入名字\n");
	scanf("%s",name);
	pos=FindByname(ps,name);//找到了返回名字所在元素的下标，找不到返回-1

	if(pos==-1)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		//删除数据
		int j=0;
		for(j=pos;j<ps->size-1;j++)
		{
			ps->data[j]=ps->data[j+1];
		}
		ps->size--;
		printf("删除成功\n");
	}
	
}

void SearchContact(struct Contact* ps)
{
	char name[MAX_NAME];
	int pos=0;
	printf("请输入要查找人的名字\n");
	scanf("%s",name);
	pos=FindByname(ps,name);//找到了返回名字所在元素的下标，找不到返回-1

	if(pos==-1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("%-5s\t%-4s\t%-5s\t%-13s\t%-20s\n","名字","年龄","性别","电话","地址");
			printf("%-5s\t%-4d\t%-5s\t%-13s\t%-20s\n",
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tele,
				ps->data[pos].addr);
		
	}

}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	int pos=0;
	printf("请输入要修改人的名字\n");
	scanf("%s",name);
	pos=FindByname(ps,name);
	if(pos==-1)
		printf("要修改的人信息不存在\n");
	else
	{
		printf("请输入名字:>");
		scanf("%s",ps->data[pos].name);
		printf("请输入年龄:>");
		scanf("%d",&(ps->data[pos].age));
		printf("请输入性别:>");
		scanf("%s",ps->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s",ps->data[pos].tele);
		printf("请输入地址:>");
		scanf("%s",ps->data[pos].addr);
		
		printf("修改成功\n");
		
	}
}

void DestroryContact(struct Contact* ps)
{
	free(ps->data);
	ps->data=NULL;
}
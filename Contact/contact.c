#define _CRT_SECURE_NO_WARNINGS 1 
#include"contact.h"
#include<memory.h>
#include<stdio.h>
#include<string.h>
void InitContact(struct Contact* ps)
{
	memset(ps->data,0,sizeof(ps->data));
	ps->size=0;
}

void AddContact(struct Contact* ps)
{
	if(ps->size==MAX)
	{
		printf("ͨѶ¼����\n");
	}
	//��������
	else
	{
		printf("����������:>");
		scanf("%s",ps->data[ps->size].name);
		printf("����������:>");
		scanf("%d",&(ps->data[ps->size].age));
		printf("�������Ա�:>");
		scanf("%s",ps->data[ps->size].sex);
		printf("������绰:>");
		scanf("%s",ps->data[ps->size].tele);
		printf("�������ַ:>");
		scanf("%s",ps->data[ps->size].addr);
		ps->size++;
		printf("��ӳɹ�\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	if(ps->size==0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i=0;
	    printf("%-5s\t%-4s\t%-5s\t%-13s\t%-20s\n","����","����","�Ա�","�绰","��ַ");
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
	
}//static���εĺ���ֻ����contact.c��ʹ�ã����ñ�¶������

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	int i=0;
	int pos=0;
	printf("����������\n");
	scanf("%s",name);
	pos=FindByname(ps,name);//�ҵ��˷�����������Ԫ�ص��±꣬�Ҳ�������-1

	if(pos==-1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		//ɾ������
		int j=0;
		for(j=pos;j<ps->size-1;j++)
		{
			ps->data[j]=ps->data[j+1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
	
}

void SearchContact(struct Contact* ps)
{
	char name[MAX_NAME];
	int pos=0;
	printf("������Ҫ�����˵�����\n");
	scanf("%s",name);
	pos=FindByname(ps,name);//�ҵ��˷�����������Ԫ�ص��±꣬�Ҳ�������-1

	if(pos==-1)
	{
		printf("Ҫ���ҵ��˲�����\n");
	}
	else
	{
		printf("%-5s\t%-4s\t%-5s\t%-13s\t%-20s\n","����","����","�Ա�","�绰","��ַ");
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
	printf("������Ҫ�޸��˵�����\n");
	scanf("%s",name);
	pos=FindByname(ps,name);
	if(pos==-1)
		printf("Ҫ�޸ĵ�����Ϣ������\n");
	else
	{
		printf("����������:>");
		scanf("%s",ps->data[pos].name);
		printf("����������:>");
		scanf("%d",&(ps->data[pos].age));
		printf("�������Ա�:>");
		scanf("%s",ps->data[pos].sex);
		printf("������绰:>");
		scanf("%s",ps->data[pos].tele);
		printf("�������ַ:>");
		scanf("%s",ps->data[pos].addr);
		
		printf("�޸ĳɹ�\n");
		
	}
}
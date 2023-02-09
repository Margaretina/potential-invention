//#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum opt
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT

};

struct PeoInfe
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];

};

//ͨѶ¼����
struct Contact
{
	struct PeoInfe *data;//���һ����Ϣ
	int size;//��¼��ǰ����Ԫ�ظ���
	int capacity;//��¼��ǰͨѶ¼�������
};

//��������
//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps);
//����һ����Ϣ��ͨѶ¼
void AddContact(struct Contact* ps);
//��ӡͨѶ¼�е���Ϣ
void ShowContact(const struct Contact* ps);
//ɾ��ָ������ϵ��
void DelContact(struct Contact* ps);
//����ָ�����ֵ���
void SearchContact(struct Contact* ps);
//�޸�ָ����ϵ��
void ModifyContact(struct Contact* ps);
//�ͷŶ�̬���ٵ��ڴ�
void DestroryContact(struct Contact* ps);
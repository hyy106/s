#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Student
{
	int stuid;
	int stuage;
	char stuname[100];

	struct Student* next;
};

struct Student* headP = NULL;
struct Student* tailP = NULL;
int flag;


void printStudent(struct Student* curP)
{
	printf("ѧ��:%d  ����:%d  ����:%s\n", curP->stuid, curP->stuage, curP->stuname);
}


void printLinkedList(struct Student* headP)
{
	while (headP != NULL)
	{
		printStudent(headP);
		headP = headP->next;
	}
}


void addStudent()
{
	struct Student* nodeP = (struct Student*)malloc(sizeof(struct Student));
	printf("������ѧ�ţ�");
	scanf("%d", &nodeP->stuid);
	printf("���������䣺");
	scanf("%d", &nodeP->stuage);
	printf("���������֣�");
	scanf("%s", nodeP->stuname);
	nodeP->next = NULL;
	if (headP == NULL)
	{
		headP = nodeP;
		tailP = nodeP;
	}
	else
	{
		tailP->next = nodeP;
		tailP = nodeP;

	}
	printf("��ӳɹ�");

}


void findStudent()
{
	printf("��������Ҫ��ѯ��ѧ��ѧ��");
	int id;
	scanf("%d", &id);
	struct Student* curP = headP;
	while (curP != NULL)
	{
		if (curP->stuid == id)
		{
			printStudent(curP);
			flag = 1;
			break;
		}
		else
		{
			curP = curP->next;
		}
	}
	if (flag == 0)
	{
		printf("û�����ѧ��\n");
	}
}


void printfAllStudent()
{
	if (headP == NULL)
	{
		printf("û��ѧ��Ŷ\n");
	}
	else
	{
		printLinkedList(headP);
	}
}


void deleteStudent()
{
	printf("������Ҫɾ��ѧ����ѧ�ţ�");
	int id;
	scanf("%d", &id);
	struct Student* curP = headP;
	if (curP->stuid = id)
	{
		headP = headP->next;
		free(curP);
		curP = NULL;
	}

	struct Student* preP = curP;
	curP = curP->next;
	while (curP != NULL)
	{
		if (curP->stuid = id)
		{
			struct Student* next = curP->next;
			preP->next = next;
			free(curP);
			curP = NULL;
			printf("�Ѿ�ɾ��\n");
			break;
		}
		else
		{
			preP = curP;
			curP = curP->next;
		}
	}
	printf("��ѧ�������ڣ��޷�ɾ��\n");
}


int main()
{
	printf("��ӭʹ�ü���ѧ������ϵͳ\n");
	printf("��1���ѧ��\n");
	printf("��2��ѯѧ��\n");
	printf("��3��ӡ����ѧ��\n");
	printf("��4ɾ��ѧ��\n");
	printf("��5�˳�����\n");

	while (1)
	{
		char c;
		scanf("%c", &c);
		switch (c)
		{
		case'1':
			addStudent();
			break;
		case'2':
			findStudent();
			break;
		case'3':
			printfAllStudent();
		case'4':
			deleteStudent();
			break;
		case'5':
			exit(0);
		default:
			break;
		}
	}
}

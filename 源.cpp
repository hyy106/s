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
	printf("学号:%d  年龄:%d  姓名:%s\n", curP->stuid, curP->stuage, curP->stuname);
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
	printf("请输入学号：");
	scanf("%d", &nodeP->stuid);
	printf("请输入年龄：");
	scanf("%d", &nodeP->stuage);
	printf("请输入名字：");
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
	printf("添加成功");

}


void findStudent()
{
	printf("请输入想要查询的学生学号");
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
		printf("没有这个学生\n");
	}
}


void printfAllStudent()
{
	if (headP == NULL)
	{
		printf("没有学生哦\n");
	}
	else
	{
		printLinkedList(headP);
	}
}


void deleteStudent()
{
	printf("请输入要删除学生的学号：");
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
			printf("已经删除\n");
			break;
		}
		else
		{
			preP = curP;
			curP = curP->next;
		}
	}
	printf("该学生不存在，无法删除\n");
}


int main()
{
	printf("欢迎使用简易学生管理系统\n");
	printf("按1添加学生\n");
	printf("按2查询学生\n");
	printf("按3打印所有学生\n");
	printf("按4删除学生\n");
	printf("按5退出程序\n");

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EMPTY 0

typedef struct node {
	char name[20];
	int age;
	struct node* link;
}Stack;

Stack* GetNode()
{
	Stack* tmp;
	tmp = (Stack*)malloc(sizeof(Stack));
	tmp->link = EMPTY;
	return tmp;
}

void Push(Stack** top,Stack data)
{
	Stack* tmp;
	tmp = *top;
	*top = GetNode();
	strcpy((*top)->name, data.name);
	(*top)->age = data.age;
	(*top)->link = tmp;
}

void Pop(Stack** top)
{
	Stack* tmp;

	if (*top == EMPTY)
	{
		printf("Stack is Empty!!\n");
		return;
	}
		printf("����\n");
		tmp = *top;
		*top = (*top)->link;
		free(tmp);
}

void Print(Stack** top)
{
	Stack* tmp;
	int count = 1;
	tmp = *top;
	printf("��ȣ\t�̸�\t����\n");
	while (tmp != EMPTY) // tmp �� �־ �۵��� 0 �ܴ̿� ���̱� ����
	{
		printf("(%d)\t%s\t%3d\n",count, tmp->name, tmp->age);
		tmp = tmp->link;
		count++;
	}
}
int main()
{
	Stack* top = EMPTY;
	int sel = 0;
	Stack data;

	while (sel != 4) {
		printf("1. �Է�\n");
		printf("2. ����\n");
		printf("3. ���\n");
		printf("4. ����\n");
		printf("��ȣ �Է� >> ");
		scanf_s("%d", &sel);

		switch (sel) {
		case 1:
			//�̸� �Է�
			printf("�̸� �Է� : ");
			scanf("%s", data.name);
			//���� �Է�
			printf("���� �Է� : ");
			scanf_s("%d", &data.age);
			//Push �Լ� ȣ��
			Push(&top,data);
			system("pause");
			break;
		case 2:
			//Pop �Լ� ȣ��
			Pop(&top);
			system("pause");
			break;
		case 3:
			//Print �Լ� ȣ��
			Print(&top);
			system("pause");
			break;
		case 4:
			//Pop �Լ� ȣ��
			while(top) Pop(&top);
			break;
		default:
			printf("1 ~ 4 �� �ϳ��� �Է����ּ���.\n");
			system("pause");
		}
		system("cls");
	}
	
	return 0;
}
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
		printf("삭제\n");
		tmp = *top;
		*top = (*top)->link;
		free(tmp);
}

void Print(Stack** top)
{
	Stack* tmp;
	int count = 1;
	tmp = *top;
	printf("번호\t이름\t나이\n");
	while (tmp != EMPTY) // tmp 를 넣어도 작동됨 0 이외는 참이기 때문
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
		printf("1. 입력\n");
		printf("2. 삭제\n");
		printf("3. 출력\n");
		printf("4. 종료\n");
		printf("번호 입력 >> ");
		scanf_s("%d", &sel);

		switch (sel) {
		case 1:
			//이름 입력
			printf("이름 입력 : ");
			scanf("%s", data.name);
			//나이 입력
			printf("나이 입력 : ");
			scanf_s("%d", &data.age);
			//Push 함수 호출
			Push(&top,data);
			system("pause");
			break;
		case 2:
			//Pop 함수 호출
			Pop(&top);
			system("pause");
			break;
		case 3:
			//Print 함수 호출
			Print(&top);
			system("pause");
			break;
		case 4:
			//Pop 함수 호출
			while(top) Pop(&top);
			break;
		default:
			printf("1 ~ 4 중 하나를 입력해주세요.\n");
			system("pause");
		}
		system("cls");
	}
	
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define EMPTY 0

typedef struct node {
	int data;
	struct node* link;
}Stack;

Stack* GetNode()
{
	Stack* tmp;
	tmp = (Stack*)malloc(sizeof(Stack));
	tmp->link = EMPTY;
	return tmp;
}

void Push(Stack** top, int data)
{
	Stack* tmp;
	tmp = *top;
	*top = GetNode();
	(*top)->data = data;
	(*top)->link = tmp;
}


void Pop(Stack** top)
{
	Stack* tmp;

	// 해제할 공간의 데이터 출력
	if (*top == EMPTY)
	{
		printf("Stack is Empty!!\n");
		return;
	} // else 대신 return으로 종료 시켜버릴 수 있다.
		tmp = *top;
		printf("data = %d\n", (*top)->data);
		// top의 값 변경
		*top = (*top)->link;
		// 공간 해제
		free(tmp);
}

int main()
{
	Stack* top = EMPTY;

	Push(&top, 10);
	Push(&top, 20);
	Push(&top, 30);

	Pop(&top);
	Pop(&top);
	Pop(&top);
	Pop(&top);
	Pop(&top);



	return 0;
}
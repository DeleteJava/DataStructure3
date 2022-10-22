#include <stdio.h>
#include <stdlib.h>
#define EMPTY 0

typedef struct node {
	int data;
	struct node* link;
}LinkedList;

LinkedList* GetNode()
{
	LinkedList* tmp;
	tmp = (LinkedList*)malloc(sizeof(LinkedList));
	tmp->link = EMPTY;
	return tmp;
}

void Insert(LinkedList** head, int data)
{
	LinkedList* tmp;
	if (*head == 0)
	{
		*head = GetNode();
		(*head)->data = data;
	}
	else
	{
		Insert(&(*head)->link, data);
	}

}

void Output(LinkedList** head)
{
	if (*head)
	{
		printf("%d\n", (*head)->data);
		Output(&(*head)->link);
	}
}

void Search(LinkedList** head, int data)
{
	if ((*head) == EMPTY)
	{
		printf("%d not exist!!\n", data);
		return;
	}
	else if ((*head)->data == data)
	{
		printf("%d Search!!\n", data);
	}
	else Search(&(*head)->link, data);
}

void Delete(LinkedList** head,int data)
{
	LinkedList* tmp;
	if (*head == EMPTY)
	{
		printf("%d is not in data!!\n", data);
	}
	else if ((*head)->data == data)
	{
		tmp = *head;
		*head = (*head)->link;
		free(tmp);
	}
	else
	{
		Delete(&(*head)->link, data);
	}
}

void Add(LinkedList** head, int data, int data2)
{
	LinkedList* newnode = EMPTY;
	if (*head == EMPTY)
	{
		printf("%d not exist!!\n", data);
	}
	else if ((*head)->data == data)
	{
		Insert(&newnode,data2);
		newnode->link = (*head)->link;
		(*head)->link = newnode;
	}
	else
	{
		Add(&(*head)->link, data, data2);
	}
}

void Sort(LinkedList** head)
{
	LinkedList* tmp;
	int tmp_int;	
	if (*head)
	{
		tmp = (*head)->link;
		while (tmp)
		{
			if ((*head)->data < tmp->data)
			{
				tmp_int = (*head)->data;
				(*head)->data = tmp->data;
				tmp->data = tmp_int;
			}
			tmp = tmp->link;
		}
		Sort(&(*head)->link);
	}
}


int main(void)
{
	// head 선언
	LinkedList* head = EMPTY;
	Insert(&head,10);
	Insert(&head, 20);
	Insert(&head, 30);
	//Output(&head);
	//int data;
	//printf("찾을 데이터 값 입력 : ");
	//scanf_s("%d", &data);
	//Search(&head,data);
	//Delete(&head,40);
	//Add(&head, 20, 25);
	//Add(&head, 30, 35);
	//Add(&head, 40, 45);
	Sort(&head);
	Output(&head);

	return 0;
}
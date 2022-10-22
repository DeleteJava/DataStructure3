#include <stdio.h>
#include <stdlib.h>
#define EMPTY 0


typedef struct Node {
	struct Node* Llink;
	int data;
	struct Node* Rlink;
}DLinkedList;

DLinkedList* GetNode()
{
	DLinkedList* tmp;
	tmp = (DLinkedList*)malloc(sizeof(DLinkedList));
	tmp->Rlink = EMPTY;
	tmp->Llink = EMPTY;
}

void Insert(DLinkedList** head,int data)
{
	if (*head == EMPTY)
	{
		*head = GetNode();
		(*head)->data = data;
	}
	else
	{
		Insert(&(*head)->Rlink,data);
		(*head)->Rlink->Llink = head;
	}

}

void Output(DLinkedList** head)
{
	if (*head)
	{
		printf("%d\n", (*head)->data);
		Output(&(*head)->Rlink);
	}
	else 
		return;
}

void Add(DLinkedList** head,int data1, int data2)
{
	DLinkedList* newNode = EMPTY;
	if (*head == EMPTY)
		printf("%d no exitst!!\n", data1);
	else if((*head)->data == data1)
	{
		Insert(&newNode,data2);
		newNode->Llink = *head;
		newNode->Rlink = (*head)->Rlink->Rlink;
		(*head)->Rlink->Llink = newNode;
		(*head)->Rlink = newNode;
	}
	else
	{
		Add(&(*head)->Rlink, data1, data2);
	}
}

void Delete(DLinkedList** head,int data)
{	
	DLinkedList* tmp;
	if ((*head)->data == data)
	{
		tmp = *head;
		*head = (*head)->Rlink;
		(*head)->Llink = (*head)->Llink->Llink;
		free(tmp);
	}
	else
		Delete(&(*head)->Rlink,data);
}

int main(void)
{
	// head ¼±¾ğ
	DLinkedList* head = EMPTY;
	Insert(&head,10);
	Insert(&head, 20);
	Insert(&head, 30);
	//Add(&head,20,25);
	Output(&head);
	Delete(&head,20);







	return 0;
}
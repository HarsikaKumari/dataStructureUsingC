// WAP to Implement Queue Operations using Linked List //
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void Enqueue(int Element)
	{
		struct Node* New_Node = (struct Node*)malloc(sizeof(struct Node));
		New_Node->data = Element;
		New_Node->next = NULL;
		
		if(front == NULL && rear == NULL)
			{
				front = rear = New_Node;
				return;
			}
		rear->next = New_Node;
		rear = New_Node;
	}

int Dequeue()
{
	if(front==NULL)
		{
			printf("Queue is Empty");
			return -1;
		}
	struct Node* temp = front;
	int Element = temp->data;
		if(front == rear)
			{
				front = rear = NULL;
			}
		else
			{
				front = front->next;
			}
		free(temp);
		return Element;
}

int main()
{
	Enqueue(10);
	Enqueue(20);
	Enqueue(30);
	Enqueue(40);
	printf("%d \n",Dequeue());
	printf("%d \n",Dequeue());
	printf("%d \n",Dequeue());
//	printf("%d \n",Dequeue());
	return 0;
}

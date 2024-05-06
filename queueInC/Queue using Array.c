// WAP to implement Queue operations using array.
#include<stdio.h>
#define Size 100
int Queue[Size];
int front = -1;
int rear = -1;

void Enqueue(int Element)
    {
        if(rear==Size-1)
            {
                printf("Queue is Full !!");
            }
        if(front==-1)
            {
                front = 0;
            }
        rear ++;
        Queue[rear] = Element;
    }

void Dequeue()
    {
        if(front == -1 || front > rear)
            {
                printf("Queue is Empty");
                return -1;
            }
        int Element = Queue[front];
        front++;
        return Element;
    }

void Display()
	{
		for(int i;i<=rear;i++)
		{
			printf("%d",Queue[i]);
		}
	}
	
	
int main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Dequeue();
    Display();
}

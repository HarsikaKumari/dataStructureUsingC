#include<stdio.h>

void push();

void pop();

void peek();

int stack[50],i,j,ch=0,n,top=-1;

void main()
{
	printf("Enter the  number of elements in the stack : ");
	scanf("%d,&n");
//	stack[n];
	printf("stack \n");
	
	while (ch!=4)
	{
		printf("choose one from the below options...\n");
		printf("\n1.push\n2.pop\n3.peek\n4.Exit");
		printf("\n enter your option:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				push();
				break;
			}
			case 2:
			{
				pop();
				break;
			}
			case 3:
			{
				peek();
				break;
			}
			case 4:
			{
				printf("Exit");
				break;
			}
			default:
			{
				printf("Invalid option");
			}
		};
	}
}




void push()
{
	int value;
	if (top == n)
	printf("\n Overflow \n");
	else
	{
		printf("Enter the value:");
		scanf("%d",&value);
		top = top  +1;
		stack[top] = value;
	}
}



void pop()
{
	if(top == -1)
	printf("Underflow \n");
	else
	top = top-1;
}


void peek()
{
	
	for(i=top;i>=0;i--)
	{
		printf("%d\n",stack[i]);
	}
	if(top == -1)
	{
		printf("%d\n",stack[i]);
	}
	if(top == -1)
	{
		printf("Stack is empty \n");
	}
	
}

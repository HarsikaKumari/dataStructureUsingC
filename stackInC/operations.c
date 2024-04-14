#include <stdio.h>
void push();
void pop();
void peek();
int stack[50], i, j, ch = 0, n, top = -1;
void main()
{
    printf("Enter the number of elements in the stack ");
    scanf("%d", &n);
    printf("Stack \n");
    while (ch != 4)
    {
        printf("Choose one from the below options...\n");
        printf("\n 1.Push\n 2.Pop\n 3.Peek\n 4.Exit");
        printf("\n Enter your option: ");
        scanf("%d", &ch);
        switch (ch)
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
        printf("Enter the value: ");
        scanf("%d", &value);
        top = top + 1;
        stack[top] = value;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("Underflow \n");
    }
    else
    {
        top = top - 1;
    }
}
void peek()
{
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
    if (top == -1)
    {
        printf("Stack is empty \n");
    }
}

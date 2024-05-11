#include <stdio.h>
void push(value);
// void peek();
int stack[50], i, n, top = -1, value;
void main()
{
    n = 1;
   push(20);
   for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}
// insertion
void push(value)
{
    if (top == n)
        printf("Overflow \n");
    else
    {
        printf("Enter the value:");
        scanf("%d", &value);
        top = top + 1;
        stack[top] = value;
    }
}

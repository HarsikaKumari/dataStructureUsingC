#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void peek();
void clearStack(); // New function to clear the stack

#define MAX_SIZE 50
int stack[MAX_SIZE], top = -1;

int main() {
    int ch;
    int n;
    
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);
    if (n > MAX_SIZE || n <= 0) {
        printf("Invalid number of elements. Using maximum allowed size.\n");
        n = MAX_SIZE;
    }

    printf("Stack Operations\n");

    while (1) {
        printf("\nChoose one from the below options...\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Clear Stack\n5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                push(n);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                clearStack();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}

void push(int n) {
    int value;
    if (top == n - 1) {
        printf("Overflow\n");
        clearStack(); // Attempt to clear the stack if it overflows
    } else {
        printf("Enter the value: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("Value pushed: %d\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Underflow\n");
    } else {
        printf("Popped value: %d\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

void clearStack() {
    top = -1; // Reset the top index to indicate an empty stack
    printf("Stack cleared.\n");
}
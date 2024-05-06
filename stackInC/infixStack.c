#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if the character is an operator
int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return 1;
    }
    return 0;
}

// Function to perform the operation
int performOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// Function to evaluate the infix expression
int evaluateInfix(char* exp) {
    int i, k;
    int len = strlen(exp);
    int stack[len];
    int top = -1;

    for (i = 0; i < len; i++) {
        if (isdigit(exp[i])) {
            int num = 0;
            while (i < len && isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            stack[++top] = num;
        } else if (exp[i] == '(') {
            // Handle parentheses
        } else if (isOperator(exp[i])) {
            int val1 = stack[top--];
            int val2 = stack[top--];
            stack[++top] = performOperation(val2, val1, exp[i]);
        }
    }

    return stack[top];
}

int main() {
    char exp[] = "3+2*2";
    printf("Value of %s is %d\n", exp, evaluateInfix(exp));
    return 0;
}

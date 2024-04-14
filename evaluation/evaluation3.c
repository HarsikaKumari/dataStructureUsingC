#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *head;

 int main () {
    struct node *head = NULL;
    head = push (head, 22);
    head = push (head, 42);
    head = pop (head, 42);
    printf("%d\n", head);
    return 0;
 }

int push (struct node *head, int data) {
    struct node *temp = malloc (sizeof (struct node));
    temp = temp -> next;
    temp -> next = NULL;
    temp -> data = data;
    temp -> prev = NULL;
    temp -> next = head;
    head = temp;
    free(temp); 
    return head;
}

int pop (struct node *head, int data) {
    struct node *temp = malloc (sizeof (struct node));
    if (head = NULL)
    {
        printf("List empty.\n");
        return;
    }
    else {
        temp -> prev = NULL;
        temp -> data = NULL;
        temp -> next = head;
    }
    return head;

}

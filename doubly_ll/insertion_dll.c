// Doubly linked list insertion at first,end,at specific position and create a empty node.

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} head;
struct Node *addToEmpty(struct Node *head, int data)
{
    struct Node *temp = malloc(sizeof(struct Node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}
struct Node *addAtBeg(struct Node *head, int data)
{
    struct Node *temp = malloc(sizeof(struct Node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    temp->next = head;
    temp->prev = temp;
    head = temp;
    return head;
}
struct Node *addAtEnd(struct Node *head, int data)
{
    struct Node *temp, *tp;
    temp = malloc(sizeof(struct Node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    tp = head;
    while (tp->next != NULL)
        tp = tp->next;
    tp->next = temp;
    temp->prev = tp;
    return head;
}
struct Node *addAfterPos(struct Node *head, int data, int position)
{
    struct Node *newP = NULL;
    struct Node *temp = head;
    struct Node *temp2 = NULL;
    newP = addToEmpty(newP, data);
    while (position != 1)
    {
        temp = temp->next;
        position--;
    }
    if (temp->next == NULL)
    {
        temp->next = newP;
        newP->prev = temp;
    }
    else
    {
        temp2 = temp->next;
        temp->next = newP;
        temp2->prev = newP;
        newP->next = temp2;
        newP->prev = temp;
    }
    return head;
}
int main()
{
    struct Node *head = NULL;
    struct Node *ptr;
    int position = 3;
    head = addToEmpty(head, 20);

    /**
     *
     * This implementation is buggy
     *
     */
    head = addToEmpty(head, 21);

    head = addAtBeg(head, 45);
    head = addAtEnd(head, 150);
    head = addAfterPos(head, 8, position);
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}

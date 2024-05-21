#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
} head;
struct node *addToEmpty(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}
struct node *addAtEnd(struct node *head, int data)
{
    struct node *temp, *tp;
    temp = malloc(sizeof(struct node));
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
struct node *delFirst(struct node *head)
{
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}
struct node *delLast(struct node *head)
{
    struct node *temp = head;
    struct node *temp2;
    while (temp->next != NULL)
        temp = temp->next;
    temp2 = temp->prev;
    temp2->next = NULL;
    free(temp);
    return head;
}
struct node *delInner(struct node *head, int position)
{
    struct node *temp = head;
    struct node *temp2 = NULL;
    if (position == 1)
    {
        head = delFirst(head);
        return head;
    }
    while (position > 1)
    {
        temp = temp->next;
        position--;
    }
    if (temp->next == NULL)
        head = delLast(head);

    else
    {
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
        temp = NULL;
    }
    return head;
}
void print(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct node *head = NULL;
    head = addToEmpty(head, 50);
    head = addAtEnd(head, 15);
    head = addAtEnd(head, 89);
    printf("before deletion:\n");
    print(head);
    head = delInner(head, 2);
    printf("After deletion :\n");
    print(head);
    return 0;
}

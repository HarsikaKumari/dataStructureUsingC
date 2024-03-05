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

// struct node* addAtBeg(struct node* head, int data) {
//     struct node* temp = malloc(sizeof(struct node));
//     temp->prev = NULL;
//     temp->data = data;
//     temp->next = NULL;
//     temp->next = head;
//     temp->prev = temp;
//     head = temp;
//     return head;
// }

struct node *addAtBeg(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = head;

    if (head != NULL)
    {
        head->prev = temp;
    }

    head = temp;
    return head;
}

struct node *addAtEnd(struct node *head, int data)
{
    struct node *newNode, *ptr;
    newNode = malloc(sizeof(struct node));
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;
    ptr = head;

    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = newNode;
    newNode->prev = ptr;
    return head;
}
// struct node* addAfterPos (struct node* head, int data, int position)
// {
//     struct node* newP=NULL;
//     struct node* newNode=head;
//     struct node* temp2=NULL;
//     newP = addToEmpty(newP,data);
//     while(position!=1)
//     {
//         temp=temp ->next;
//         position --;
//     }
//     if(temp -> next==NULL)
//     {
//         temp ->next=newP;
//         temp ->prev=temp;

//     }
//     else
//     {
//         temp2=temp ->next;
//         temp ->next = newP;
//         temp2 ->prev=newP;
//         newP ->next=temp;
//         newP ->prev=temp;
//     }
//     return head;
// }
struct node *addAfterPos(struct node *head, int data, int position)
{
    struct node *newP = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;

    // Create a new node and initialize it
    newP = addToEmpty(newP, data);

    // If the list is empty or position is 1, add at the beginning
    if (head == NULL || position == 1)
    {
        head = addAtBeg(head, data);
        return head;
    }

    // Traverse to the specified position
    while (position != 1 && temp != NULL)
    {
        temp = temp->next;
        position--;
    }

    // Check if the specified position is valid
    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return head;
    }

    // Insert the new node at the specified position
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
    struct node *head = NULL;
    struct node *ptr;

    int position = 2;
    head = addToEmpty(head, 80);
    head = addAtBeg(head, 90);
    head = addAtEnd(head, 150);
    // head = addAfterPos(head, 49, position);
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct node 
{
    struct node* prev;
    int data;
    struct node* next;
} 
head;
struct node* addToEmpty (struct node* head,int data)
{
    struct node * temp = malloc (sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    head=temp;
    return head;
}
struct node* addAtBeg (struct node* head, int data)
{
    struct node * temp=malloc(sizeof(struct node));
    temp ->prev = NULL;
        temp -> data = data;
temp -> next = NULL;
temp -> next = head;
temp -> prev =temp;
head = temp;
return head;
}
struct node* addAtEnd(struct node* head, int data)
{
    struct node* temp, *tp;
    temp=malloc(sizeof(struct node));
temp ->prev=NULL;
temp ->data=data;
temp ->next=NULL;
tp=head;
while(tp ->next != NULL)
tp=tp ->next;
tp -> next =temp;
temp -> prev = tp;
return head;
}
struct node* addAfterPos (struct node* head, int data, int position)
{
    struct node* newP=NULL;
    struct node* temp=head;
    struct node* temp2=NULL;
    newP=addToEmpty(newP,data);
    while(position!=1)
    {
        temp=temp ->next;
        position --;
    }
    if(temp -> next==NULL)
    {
        temp ->next==newP;
        temp ->prev=temp;

    }
    else
    {
        temp2=temp ->next;
        temp ->next = newP;
        temp2 ->prev=newP;
        newP ->next=temp;
        newP ->prev=temp;
    }
    return head;
}
int main()
{
    struct node* head=NULL;
    struct node*ptr;
    int position=2;
    head=addToEmpty(head,50);
    head=addAtBeg(head , 30);
    head=addAtEnd(head,15);
    head=addAfterPos(head,89,position);
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d \n",ptr ->data);

    }
    return 0;
}
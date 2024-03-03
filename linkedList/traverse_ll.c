#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head;
void createlist (int n){
    struct node *newNode, *temp;
    int data, i;
    head = (struct node *) malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Unable to allocate memory: ");
        exit (0);
    }
    printf("Enter the data of node 1: ");
    scanf("%d", &data);
    head -> data = data;
    head -> next = NULL;
    temp = head;
    for (i = 2; i <= n; i++)
    {
        newNode = (struct node * ) malloc (sizeof (struct node));
        if (newNode == NULL) {
            printf("unable to allocate memory. ");
            break;
        }
        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode -> next = NULL;
        temp -> next = newNode;
        temp = temp -> next;
    }
}

void traverselist() {
    struct node *temp;
    
    // Check if the list is empty
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    // Traverse the list and print data
    while (temp != NULL) {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
}

int main () {
    int n;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createlist(n);
    printf("\n Data in the list \n");
    traverselist();
    return 0;
}

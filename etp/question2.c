#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void displayList(struct Node *head, int data) {
    struct Node *temp = head;
        printf("%d ", temp->data);
        temp->next = NULL;
    printf("Linked List elements: ", temp);
    printf("\n");
}

int main() {
    struct Node *head = NULL; 
    // Displaying the linked list
    displayList(head, 20);

    return 0;
}

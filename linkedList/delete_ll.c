#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new Node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to delete a node with a given key without using free
void deleteNode(struct Node** head, int key) {
    // Initialize two pointers
    struct Node *current = *head, *prev = NULL;

    // Check if the key is present in the head node
    if (current != NULL && current->data == key) {
        *head = current->next; // Move head to the next node
        return; // Do not free the memory
    }

    // Search for the key to be deleted, keeping track of the previous node
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    // If the key is not present in the linked list
    if (current == NULL) {
        printf("Key not found in the linked list.\n");
        return;
    }

    // Unlink the node from the linked list
    prev->next = current->next;

    // Do not free the memory of the deleted node

}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to test the deleteNode function
int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    // Print the original linked list
    printf("Original Linked List: ");
    printList(head);

    // Delete node with key 3 without using free
    deleteNode(&head, 3);

    // Print the linked list after deletion
    printf("Linked List after deleting node with key 3: ");
    printList(head);

    return 0;
}

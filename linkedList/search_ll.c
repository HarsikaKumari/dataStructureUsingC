// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node *next;
// };

// int main() {
//     struct Node *head = NULL;
//     struct Node *temp, *newNode;

//     // Creating a linked list with some elements
//     for (int i = 1; i <= 5; i++) {
//         newNode = (struct Node *)malloc(sizeof(struct Node));
//         if (newNode == NULL) {
//             printf("Memory allocation failed.\n");
//             return 1;
//         }

//         newNode->data = i * 10;
//         newNode->next = NULL;

//         if (head == NULL) {
//             head = newNode;
//             temp = head;
//         } else {
//             temp->next = newNode;
//             temp = temp->next;
//         }
//     }

//     // Displaying the linked list
//     printf("Linked List elements: ");
//     temp = head;
//     while (temp != NULL) {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");

//     // Searching for an element in the linked list
//     int searchElement;
//     printf("Enter the element to search: ");
//     scanf("%d", &searchElement);

//     // Performing the search
//     temp = head;
//     while (temp != NULL) {
//         if (temp->data == searchElement) {
//             printf("Element found in the linked list.\n");
//             return 0;
//         }
//         temp = temp->next;
//     }

//     // If the loop completes without finding the element
//     printf("Element not found in the linked list.\n");

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *temp, *newNode;
    int position = 1;  // To keep track of the current position

    // Creating a linked list with some elements
    for (int i = 1; i <= 5; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        newNode->data = i * 10;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    // Displaying the linked list
    printf("Linked List elements: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Searching for an element in the linked list
    int searchElement;
    printf("Enter the element to search: ");
    scanf("%d", &searchElement);

    // Performing the search
    temp = head;
    while (temp != NULL) {
        if (temp->data == searchElement) {
            printf("Element %d found at position %d in the linked list.\n", searchElement, position);
            return 0;
        }
        temp = temp->next;
        position++;
    }

    // If the loop completes without finding the element
    printf("Element not found in the linked list.\n");

    return 0;
}


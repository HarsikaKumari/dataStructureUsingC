#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data)
   {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
struct Node* search(struct Node* root, int value) 
  {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}
struct Node* delete(struct Node* root, int value)
   {
    if (root == NULL) 
    {
        return root;
    }
    if (value < root->data) 
    {
        root->left = delete(root->left, value);
    } else if (value > root->data) 
    {
        root->right = delete(root->right, value);
    } else 
       {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}
void inorderTraversal(struct Node* root) 
{
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}
int main() 
{
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    printf("Inorder traversal of the BST: \n");
    inorderTraversal(root);
    struct Node* searchResult = search(root, 60);
    if (searchResult != NULL) {
        printf(" \nElement found: %d \n", searchResult->data);
    } 
  else
    {
        printf("Element not found.");
    }
    root = delete(root, 20);
    root = delete(root, 30);
    root = delete(root, 50);
    printf("Inorder traversal after deletion of 20, 30, and 50:\n ");
    inorderTraversal(root);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
 
void storeInorder(struct node* node, int inorder[], int* index_ptr)
{

    if (node == NULL)
        return;
 
    storeInorder(node->left, inorder, index_ptr);
 
    inorder[*index_ptr] = node->data;
    (*index_ptr)++;
 
    storeInorder(node->right, inorder, index_ptr);
}
 
int countNodes(struct node* root)
{
    if (root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
 
int compare(const void* a, const void* b)
{
    return ((int)a - (int)b);
}
 
void arrayToBST(int* arr, struct node* root, int* index_ptr)
{
    if (root == NULL)
        return;
 
    arrayToBST(arr, root->left, index_ptr);
 

    root->data = arr[*index_ptr];
    (*index_ptr)++;
 

    arrayToBST(arr, root->right, index_ptr);
}
 
void binaryTreeToBST(struct node* root)
{
    if (root == NULL)
        return;
 
    int n = countNodes(root);
 
    int* arr = (int *)malloc(n*sizeof(int));
    int i = 0;
    storeInorder(root, arr, &i);
 
    qsort(arr, n, sizeof(arr[0]), compare);
 

    i = 0;
    arrayToBST(arr, root, &i);
 
    free(arr);
}
 
struct node* newNode(int data)
{
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
 
    printInorder(node->left);
 
    printf("%d ", node->data);
 
    printInorder(node->right);
}
 
int main()
{
    struct node* root = NULL;
 
    root = newNode(5);
    root->left = newNode(10);
    root->right = newNode(150);
    root->left->left = newNode(200);
    root->right->right = newNode(50);
 
    binaryTreeToBST(root);
 
    printf("Inorder Traversal after BST: \n");
    printInorder(root);
 
    return 0;
}
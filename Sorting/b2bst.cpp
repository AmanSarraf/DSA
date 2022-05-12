#include<iostream>
using namespace std;
struct node
{ 
    int data;
    node* left;
     node* right;

 
};

void Inorder(node* node,int inorder[],int *ptr)
{
    if(node==NULL)
    {
        return;
    }
     Inorder(node->left, inorder, ptr);

     inorder[*ptr] = node->data;
     (*ptr)++;

     Inorder(node->right, inorder, ptr);

}

int countNodes(node* root)
{
    if (root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}



void arrayToBST(int* arr, node* root, int* index_ptr)
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
 
   
    int* arr = new int[n];
    int i = 0;
    Inorder(root, arr, &i);
 
   
    qsort(arr, n, sizeof(arr[0]), compare);   //for quick sort
 
   
    i = 0;
    arrayToBST(arr, root, &i);
 
   
    delete[] arr;
}

struct node* newNode(int data)
{
    struct node* temp = new struct node;
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
 
  
    cout <<" "<< node->data;
 
   
    printInorder(node->right);
}


int main()
{
    struct node* root = NULL;

    cout<<"This is Question no.1 \n Enter 5 numbers"<<endl;
    int arr[5];
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
 
    
    root = newNode(arr[0]);
    root->left = newNode(arr[1]);
    root->right = newNode(arr[2]);
    root->left->left = newNode(arr[3]);
    root->right->right = newNode(arr[4]);
 

    binaryTreeToBST(root);
 
    cout <<" Inorder Traversal of BST---------------------" << endl ;
    printInorder(root);
 
    return 0;
}
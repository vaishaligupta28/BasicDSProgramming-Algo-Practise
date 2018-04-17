#include<stdlib.h>
#include<stdio.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}

void inorderTraverseRecursive(struct node* root)
{
    if(root->left != NULL)
        inorderTraverseRecursive(root->left);
    printf("%d ", root->data);
    if(root->right != NULL)
        inorderTraverseRecursive(root->right);
}

void preorderTraverseRecursive(struct node* root)
{
    printf("%d ", root->data);
    if(root->left != NULL)
        preorderTraverseRecursive(root->left);
    if(root->right !=  NULL)
        preorderTraverseRecursive(root->right);
}

void postorderTraverseRecursive(struct node* root)
{
    if(root->left != NULL)
        postorderTraverseRecursive(root->left);
    if(root->right != NULL)
        postorderTraverseRecursive(root->right);
    printf("%d ", root->data);
}


void main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printf("INORDER TRAVERSAL: ");
    inorderTraverseRecursive(root);
    printf("\nPREORDER TRAVERSAL: ");
    preorderTraverseRecursive(root);
    printf("\nPOSTORDER TRAVERSAL: ");
    postorderTraverseRecursive(root);
}

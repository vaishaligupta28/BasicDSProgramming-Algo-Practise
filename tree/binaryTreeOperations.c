//Basic operation on binary tree, insertion, deletion...which is po
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct * newNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
}

void insert(struct node* root, int data)
{
    struct node* newNode = newNode(data);
    if(root == NULL)
        root = newNode;
    else if(root->left == NULL)
}

void main()
{

}

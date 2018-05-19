#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* newTreeNode(int data)
{
    struct TreeNode* newNode = (struct TreeNode* )malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct TreeNode* do_mirror(struct TreeNode* root)
{
    if(!root)
        return;
    else
    {
        struct TreeNode* temp;
        do_mirror(root->left);
        do_mirror(root->right);

        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}


void inorder(struct TreeNode* root)
{
    if(!root)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void main()
{
    struct TreeNode* root = newTreeNode(1);
    root->left = newTreeNode(2);
    root->right = newTreeNode(3);
    root->left->left = newTreeNode(4);
    root->left->right = newTreeNode(5);
    printf("INORDER TRAVERSAL: ");
    inorder(root);
    do_mirror(root);
    printf("\nAfter taking mirror, INORDER TRAVERSAL: ");
    inorder(root);
}

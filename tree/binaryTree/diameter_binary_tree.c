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

int max(int a, int b)
{
    return a > b ? a : b;
}


int height(struct TreeNode* root)
{
    if(!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}


int diameter_between_nodes(struct TreeNode* root)
{
    if(!root)
        return 0;
    else
    {
        int lh = height(root->left);
        int rh = height(root->right);

        int ldiam = diameter_between_nodes(root->left);
        int rdiam = diameter_between_nodes(root->right);

        return max(lh + rh + 1 , max(ldiam , rdiam));
    }
}


void inorder(struct TreeNode* root)
{
    if(root->left != NULL)
        inorder(root->left);
    printf("%d ", root->data);
    if(root->right != NULL)
        inorder(root->right);
}


void main()
{
    struct TreeNode* root = newTreeNode(1);
    root->left = newTreeNode(2);
    root->right = newTreeNode(3);
    root->left->left = newTreeNode(4);
    root->left->right = newTreeNode(5);
    root->left->right->left = newTreeNode(6);
    root->left->right->left->right = newTreeNode(7);
    root->left->left->left = newTreeNode(8);
    printf("INORDER TRAVERSAL: ");
    inorder(root);
    printf("\nDiamater of tree is : %d", diameter_between_nodes(root));
}


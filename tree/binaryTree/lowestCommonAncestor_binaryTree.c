//Method 2:

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

struct TreeNode* lca(struct TreeNode* root, int n1, int n2)
{
    if(!root)
        return NULL;
    if(root->data == n1 || root->data == n2)
        return root;
    struct TreeNode* left = lca(root->left, n1, n2);
    struct TreeNode* right = lca(root->right, n1, n2);
    if(left != NULL && right != NULL)
        return root;
    else if(left == NULL && right == NULL)
        return NULL;
    else
        return left!= NULL ? left: right;
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
    printf("INORDER TRAVERSAL: ");
    inorder(root);
    printf("\nLowest Common Ancestor b/w %d and %d : %d", 4, 5, lca(root, 4, 5)->data);
}

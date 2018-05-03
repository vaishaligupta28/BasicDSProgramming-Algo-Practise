#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* parent;
};

struct TreeNode* newTreeNode(int data)
{
    struct TreeNode* newTreeNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newTreeNode->data = data;
    newTreeNode->left = NULL;
    newTreeNode->right = NULL;
    newTreeNode->parent = NULL;
    return newTreeNode;
}

//method 1: O(n^2)
struct TreeNode* constructFromPreorderUtil(int list[], int *rootIndex, int low, int high, int size)
{
    if(*rootIndex >= size || low > high)
        return NULL;
    struct TreeNode* root = newTreeNode(list[*rootIndex]);//create the root for that tree
    *rootIndex = *rootIndex + 1;

    if(low == high)//means only one element is remaining
        return root;

    //search for the element that is greater than the element at rootIndex
    int i;
    for(i=low; i<=high; i++)
        if(list[i] > root->data)//limiting condition where we will get the first largest element than root
            break;
    root->left = constructFromPreorderUtil(list, rootIndex, *rootIndex, i-1, size);//construct the left subtree
    root->right = constructFromPreorderUtil(list, rootIndex, i, high, size);//construct right subtree
    return root;
}

struct TreeNode* constructFromPreorder(int list[], int size)
{
    int rootIndex = 0;
    constructFromPreorderUtil(list, &rootIndex, 0, size-1,size);
}

void inorder(struct TreeNode* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d  ", root->data);
    inorder(root->right);
}

void main()
{
    int preorderList[] = {10,5,1,7,40,50};
    struct TreeNode* root = constructFromPreorder(preorderList, 6);
    inorder(root);
}

/**
Method 3, using order statistics tree, in which left child count is stored in the node itself
*/

#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
    int data;
    int leftChildCount;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newTreeNode(int data)
{
    struct TreeNode* newNode = (struct TreeNode* )malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->leftChildCount = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/**
similar to the insertion in BST iteratively but just while traversing keep increasing the count
*/
struct TreeNode* insert_in_order_statistics_tree(struct TreeNode* root, int data)
{
    struct TreeNode* pTraverse = root;
    struct TreeNode* pCurr = root;
    struct TreeNode* newNode = newTreeNode(data);
    while(pTraverse)
    {
        pCurr = pTraverse;
        if(data < pTraverse->data)
        {
            pCurr->leftChildCount++;//if data is lesser than curr data, means it will attach to curr left subtree so
            //will have to increase curr leftchildcount by 1
            pTraverse = pTraverse->left;
        }
        else
        {
            //if greater than curr->data, then will lie in curr right subtree so no need to increment left count
            pTraverse = pTraverse->right;
        }
    }

    //pCurr knows where the new node has to be attached
    if(!root)
        root = newNode;
    else if(data < pCurr->data)
        pCurr->left = newNode;
    else
        pCurr->right = newNode;
    return root;
}

int getKthSmallestElement(struct TreeNode* root, int k)
{
    struct TreeNode* pTraverse = root;
    while(pTraverse)
    {
        if(k == pTraverse->leftChildCount+1)
            return pTraverse->data;
        else if(k < pTraverse->leftChildCount+1)
            pTraverse = pTraverse->left;
        else
        {
            k = k - (pTraverse->leftChildCount+1);
            pTraverse = pTraverse->right;
        }
    }
    return -1;
}

void main()
{
    int i;
    struct TreeNode* root = NULL;
    int inputTree[] = {40,20,55,10,50,30,70,53,8};
    int size = sizeof(inputTree)/sizeof(inputTree[0]);
    for(i=0;i<size;i++)
    {
        root = insert_in_order_statistics_tree(root, inputTree[i]);
    }
    printf("%d", getKthSmallestElement(root, 4));
}

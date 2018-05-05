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
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder_morris(struct TreeNode* root)
{
    struct TreeNode* current = root;
    struct TreeNode* pre_current;
    if(!root)
        return;

    while(current)
    {
        if(current->left == NULL)
        {
            printf("%d ", current->data);
            current = current->right;
        }
        else
        {
            //find the inorder successor of the current
            pre_current = current->left;
            while(pre_current->right != NULL && pre_current->right != current)
                pre_current = pre_current->right;

            /* Make current as right child of its inorder predecessor */
            if(pre_current->right == NULL)//whenever pre_current->right becomes null, it has to be made to point to current
            {
                pre_current->right = current;
                current = current->left;
            }

            //revert the changes here
            else//whenever pre_current->right == current,  pre_current->right has to be made null
            {
                pre_current->right = NULL;
                printf("%d ", current->data);
                current = current->right;
            }
        }
    }
}

void main()
{
    struct TreeNode* root = newTreeNode(44);
    root->left = newTreeNode(22);
    root->left->right = newTreeNode(33);
    root->right = newTreeNode(66);
    root->left->left = newTreeNode(10);
    root->left->left->right = newTreeNode(20);
    root->right->left = newTreeNode(55);
    root->right->right = newTreeNode(70);
    root->right->left->left = newTreeNode(50);
    root->left->left->left = newTreeNode(8);
    root->right->left->left->right = newTreeNode(53);
    printf("Morrris Inorder traversal:\n");
    inorder_morris(root);
}

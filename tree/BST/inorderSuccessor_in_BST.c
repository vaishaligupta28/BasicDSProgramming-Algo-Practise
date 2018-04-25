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
    struct TreeNode* newTreeNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newTreeNode->data = data;
    newTreeNode->left = NULL;
    newTreeNode->right = NULL;
    return newTreeNode;
}

//inorder will print BST in sorted order
void inorder(struct TreeNode* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct TreeNode* getAddressOfMinimumNode(struct TreeNode* root)
{
    if(!root)
        return root;
    while(root->left != NULL)
        root = root->left;
    return root;
}

struct TreeNode* search(struct TreeNode* root, int data)
{
    if(root == NULL || data == root->data)
        return root;
    else if(data < root->data)
        return search(root->left, data);
    return search(root->right, data);
}

//method 2......
struct TreeNode* inorderSuccessor_1(struct TreeNode* root, int data)
{
    struct TreeNode* node = search(root, data);//root is used for searching
    struct TreeNode* successor;
    if(!node)
        return node;
    if(node->right != NULL)//node has no right subtree
    {
        return getAddressOfMinimumNode(node->right);//if right not null, address of min value in right subtree is successor
    }
    else
    {
        while(root != node)//go till the node whose successor is to be found
        {

            if(node->data < root->data)
            {
                successor = root;//this might be the successor if there was no other ancestor
                printf("\nSuccesssor: %d", successor->data);
                root = root->left;//root has to go to its left to check for more ancestors
            }
            else
                root = root->right;//else just traverse because if the node lies in right subtree then its already bigger
        }
        return successor;
    }
}


void main()
{
    struct TreeNode* root = newTreeNode(44);
    root->left = newTreeNode(22);
    root->right = newTreeNode(66);
    root->left->left = newTreeNode(10);
    root->right->left = newTreeNode(55);
    root->right->right = newTreeNode(70);
    root->right->left->left = newTreeNode(50);
    root->left->left->left = newTreeNode(8);
    root->right->left->left->right = newTreeNode(53);
    printf("Tree is : ");
    inorder(root);
    printf("\nInorder successor of %d is %d", 66, inorderSuccessor_1(root, 66)->data);
}


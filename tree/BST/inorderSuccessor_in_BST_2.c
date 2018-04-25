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

struct TreeNode* inorderSuccessor(struct TreeNode* root, int data)
{
    struct TreeNode* node = search(root, data);
    if(!node)
        return node;
    if(node->right != NULL)
    {
        return getAddressOfMinimumNode(node->right);
    }
    else
    {
        struct TreeNode* p = node->parent;
        while(p != root)
        {
            printf("\n%d", p->data);
            if(p != NULL && p->data < node->data)//if parent < node, then it should keep finding another parent
            {
                p = p->parent;
            }
            else
                return p;//return if you find an ancestor whose data is bigger than the nodes data
        }
    }
}


void main()
{
    struct TreeNode* root = newTreeNode(44);
    root->left = newTreeNode(22);
    root->left->parent  = root;
    root->right = newTreeNode(66);
    root->right->parent = root;
    root->left->left = newTreeNode(10);
    root->left->left->parent = root->left;
    root->right->left = newTreeNode(55);
    root->right->left->parent = root->right;
    root->right->right = newTreeNode(70);
    root->right->right->parent = root->right;
    root->right->left->left = newTreeNode(50);
    root->right->left->left->parent = root->right->left;
    root->left->left->left = newTreeNode(8);
    root->left->left->left->parent = root->left->left;
    root->right->left->left->right = newTreeNode(53);
    root->right->left->left->right->parent = root->right->left->left;
    printf("Tree is : ");
    inorder(root);
    printf("\nInorder successor of %d is %d", 8, inorderSuccessor(root, 8)->data);
}

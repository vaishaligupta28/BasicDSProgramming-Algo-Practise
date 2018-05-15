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

int min(int a, int b)
{
    return a < b? a: b;
}

int max(int a, int b)
{
    return a > b? a: b;
}

struct TreeNode* lca(struct TreeNode* root, int n1, int n2)
{
    if(root)
    {
        if(root->data >= min(n1, n2) && root->data <= max(n1, n2))
            return root;
        else if(max(n1, n2) < root->data){
            return lca(root->left , n1, n2);
        }
        else if(min(n1, n2) > root->data)//if min of n1 and n2 lies in right subtree then the other will also lie in right subtree
            return lca(root->right , n1, n2);
    }
    return root;
}

struct TreeNode* insert(struct TreeNode* root, int data)
{
    /* If the tree is empty, return a new node */
    if (root == NULL) return newTreeNode(data);

    /* Otherwise, recur down the tree */
    if (data < root->data)
        root->left  = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    /* return the (unchanged) node pointer */
    return root;
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

void main()
{
    int i;
    struct TreeNode* root = NULL;
    //int inputTree[] = {40,20,80,10,30,90,55,8,45,70,60,75,65};
    int inputTree[] = {40,20,30,90,55,8,45,70,60,75,65,15,10};
    int size = sizeof(inputTree)/sizeof(inputTree[0]);
    for(i=0;i<size;i++)
    {
        root = insert(root, inputTree[i]);
    }
    inorder(root);
    printf("\nLowest common ancestor of %d and %d:  %d", 90, 45, lca(root, 90 ,45)->data);
}


//Method 1: going to that level and getting the summing all the nodes at that level
//Time complexity: O(n^2);


//Method 2: enqueue all child nodes and while the stack becomes empty, pop the elements one by one,
//keep inc the counter and this is width at that level
//match with prev widths
//if greater, then change the val of max width otherwise
//follow level order traversals using queue
//Time complexity: O(n)



#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct Tre
    eNode* right;
};


struct TreeNode* newTreeNode(int data)
{
    struct TreeNode* newNode = (struct TreeNode* )malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(struct TreeNode* root)
{
    int l, r;
    if(!root)
        return 0;
    else if(root->left == NULL && root->right== NULL)
        return 0;
    else
    {
        if(root->left != NULL){
            l = height(root->left);
        }
        if(root->right != NULL){
            r = height(root->right);
        }
        return 1 + (l > r? l : r);
    }
}

int getWidthOfGivenLevel(struct TreeNode* root, int level)
{
    static int k = 0;
    if(root == NULL)
        return 0;
    else if(level == 0)
        return ++k;//so to print data at level 2, you want to pass through 2 levels
    else if(level > 0){
        getWidthOfGivenLevel(root->left, level-1);
        getWidthOfGivenLevel(root->right, level-1);
    }
}

int max(int a , int b)
{
    return a > b? a : b;
}

//same as level order traversals
int width_tree(struct TreeNode* root)
{
    int i;
    static int width = 0;
    int h = height(root);
    for(i=0;i<=h;i++)
    {
        width = max(width, getWidthOfGivenLevel(root, i));
    }
    return width;
}


void main()
{
    struct TreeNode* root = newTreeNode(1);
    root->left = newTreeNode(2);
    root->right = newTreeNode(3);
    root->left->left = newTreeNode(4);
    root->left->right = newTreeNode(5);
    printf("Width of the tree:  %d", width_tree(root));
}

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


//Time complexity: O(n^2)
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

//time complexity : O(n)...calculating height along with diameter
int diameter_between_nodes_2(struct TreeNode* root, int *height)
{
    if(!root)
    {
        *height = 0;
        return 0;
    }
    else
    {
        int lh, rh;
        int ldiam = diameter_between_nodes_2(root->left, &lh);
        int rdiam = diameter_between_nodes_2(root->right, &rh);

        *height = 1 + max(lh, rh);//this height is setting the value of lh of immediate parent
        return max(lh + rh + 1 , max(ldiam, rdiam));//set the ldiam or rdiam of parent
    }
}

//Time complexity = O(n).... just cal diameter along with calculating height
int height_with_diameter(struct TreeNode* root, int* diamter)//this function is not returning diameter
{
    if(!root)
        return 0;
    else
    {
        int l_height = height_with_diameter(root->left, diamter);
        int r_height = height_with_diameter(root->right, diamter);

        *diamter = max(*diamter, 1 + l_height + r_height);//if my total of left and right + 1 is greater than already calculated diameter then dont calculate again
        printf("root: %d, diameter: %d\n",root->data, *diamter);
        return 1 + max(l_height, r_height);
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
    int h = 0;
    height_with_diameter(root, &h);
    printf("\nDiamater of tree is : %d", h);
}


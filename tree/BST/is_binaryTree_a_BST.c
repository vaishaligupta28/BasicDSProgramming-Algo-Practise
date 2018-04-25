#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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

//a good method to set a range for a value and check for it
int isBSTCheck(struct TreeNode* root, int min, int max)
{
    //empty tree is a BST, if root becomes null
    if(root == NULL)
        return 1;
    //if node is not in its range(check the range of a node)
    if(root->data < min || root->data > max)
        return 0;
        //if both subtrees pass BSTCheck, then BST
    return isBSTCheck(root->left, min, root->data) && isBSTCheck(root->right, root->data, max);
}


//traverse,
int isBSTCheck_2(struct TreeNode* root)
{
    static struct TreeNode *prev = NULL;

    // traverse the tree in inorder fashion and keep track of prev node
    if (root && printf("isBSTCheck_2(%d)\n", root->data))
    {
        if (!isBSTCheck_2(root->left) && printf("%d left subtree is not bst\n", root->data))//go to the leftmost node, if it is not bst
          return 0;

        // Allows only distinct valued nodes
        if (prev != NULL && root->data <= prev->data && printf("root= %d\n", root->data) && printf("root->data is less than prev data\n"))
          return 0;

        prev = root;
        printf("prev = %d\n", prev->data);

        return isBSTCheck_2(root->right);
    }
    printf("root is null\n");
    return 1;
}


void isBST(struct TreeNode* root)
{
    if(isBSTCheck_2(root))
        printf("Is a BST");
    else
        printf("Is not a BST");
}


void main()
{
    struct TreeNode* root = newTreeNode(22);
    root->left = newTreeNode(10);
    root->right = newTreeNode(44);
    root->left->left = newTreeNode(14);
    root->left->right = newTreeNode(4);
    root->right->left = newTreeNode(1);
    root->right->right = newTreeNode(55);
    isBST(root);
}

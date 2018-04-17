#include<stdlib.h>
#include<stdio.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}

/**

Algorithm 1:  Count nodes
---------------------------------------
*/
void countNodes1(struct node* root, int* ptrCount)
{
    if(root == NULL)
        return;
    if(root->left != NULL)
    {
        /**
        whenever visiting a node that is not null, increment the count
        */
        (*ptrCount)++;
        countNodes1(root->left, ptrCount);
    }
    if(root->right != NULL)
    {
        (*ptrCount)++;
        countNodes1(root->right, ptrCount);
    }
}


/**

Algorithm 2: Count nodes
---------------------------
            1 ---->root
           / \
  LSB-->  2   3  <--RSB
        /  \  /  \
       4   5  6   7

       count(tree) = 1+ count(left subtree) + count(right subtree)
*/
int countNodes2(struct node* root)
{
    if(root)
        return (1 + countNodes2(root->left) + countNodes2(root->right));
    else
        return 0;//very important.......if returning to expression, you need to return a value
}

void main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    int count = 1;
    countNodes1(root, &count);
    printf("\nTotal nodes: %d", count);
    printf("\nTotal nodes: %d", countNodes2(root));
}


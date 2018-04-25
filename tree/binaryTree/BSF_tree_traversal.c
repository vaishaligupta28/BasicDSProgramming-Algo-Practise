//BFS - breadth first searching
//Also called Level order traversal
#include<stdio.h>
#include<stdlib.h>
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
    return newNode;
}

int height(struct node* root)
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

void printGivenLevel(struct node* root, int level)
{
    if(root == NULL)
        return;
    else if(level == 0)
        printf("%d ", root->data);//so to print data at level 2, you want to pass through 2 levels
    else if(level > 0){
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void levelOrderTraverse(struct node* root)
{
    int i;
    int h = height(root);
    for(i=0;i<=h;i++)
    {
        printGivenLevel(root, i);
    }
}

void main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printf("Level order traversal using algorithm 1:  ");
    levelOrderTraverse(root);
}


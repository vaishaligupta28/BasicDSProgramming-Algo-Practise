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

void print_nodes_at_kth_Level(struct node* root, int level)
{
    if(root == NULL)
        return;
    else if(level == 0)
        printf("%d ", root->data);//so to print data at level 2, you want to pass through 2 levels
    else if(level > 0){
        print_nodes_at_kth_Level(root->left, level-1);
        print_nodes_at_kth_Level(root->right, level-1);
    }
}


void main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    printf("Level order traversal using algorithm 1:  ");
    print_nodes_at_kth_Level(root, 2);
}




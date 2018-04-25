//BFS - breadth first searching
//Also called Level order traversal
#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct QueueNode
{
    struct TreeNode* treeNode;
    struct QueueNode * next;
};

struct QueueNode* front = NULL;
struct QueueNode* rear = NULL;
void display();

struct QueueNode* newQueueNode(struct TreeNode* newTreeNode)
{
    struct QueueNode* newQueueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newQueueNode->treeNode = newTreeNode;
    newQueueNode->next = NULL;
    return newQueueNode;
}

struct TreeNode* newTreeNode(int data)
{
    struct TreeNode* newTreeNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newTreeNode->data = data;
    newTreeNode->left = NULL;
    newTreeNode->right = NULL;
    return newTreeNode;
}

//enqueue a tree node
void enqueue(struct TreeNode* treeNode)
{
    struct QueueNode* queueNode = newQueueNode(treeNode);
    if(rear == NULL)
    {
        front = rear = queueNode;
    }
    else
    {
        rear->next = queueNode;
        rear = queueNode;
    }
}

//dequeue a tree node
struct TreeNode* dequeue()
{
    struct QueueNode * temp = front;
    struct TreeNode* treeNode;

    //if nothing is there
    if(front == NULL)
        return NULL;
    else
    {
        front = front->next;
        treeNode = temp->treeNode;
        free(temp);

        //if after incrementing front, front becomes NULL, rear has to be NULL as well
        if(front == NULL)
            rear = NULL;
        return treeNode;
    }
}


//level order using queue
void levelOrderTraverseUsingQueue(struct TreeNode* root)
{
    struct TreeNode* temp = root;
    while(temp)
    {
        printf("%d ", temp->data);
        enqueue(temp->left);
        enqueue(temp->right);
        temp = dequeue();
    }
}

void main()
{
    struct TreeNode* root = newTreeNode(1);
    root->left = newTreeNode(2);
    root->right = newTreeNode(3);
    root->left->left = newTreeNode(4);
    root->left->right = newTreeNode(5);
    printf("Level order traversal using Queue:  ");
    levelOrderTraverseUsingQueue(root);
//    enqueue(root);
//    enqueue(root->left);
//    enqueue(root->right);
//    printf("\nDeququed elem: %d", dequeue()->data);
//    printf("\nDeququed elem: %d", dequeue()->data);
//    printf("\nDeququed elem: %d", dequeue()->data);
}


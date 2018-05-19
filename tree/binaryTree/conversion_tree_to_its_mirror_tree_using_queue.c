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
    struct TreeNode* newNode = (struct TreeNode* )malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
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

void swap(struct TreeNode** ptr1 , struct TreeNode** ptr2)
{
    struct TreeNode* temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}


struct TreeNode* do_mirror_using_queue(struct TreeNode* root)
{
    if(!root)
        return;
    else
    {
        struct TreeNode* temp= root;
        while(temp)
        {
            swap(&temp->left, &temp->right);//instead of printing, just swap their left and right childs

            if(temp->left)
            enqueue(temp->left);

            if(temp->right)
            enqueue(temp->right);

            temp = dequeue();
        }
    }
}

void inorder(struct TreeNode* root)
{
    if(!root)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void main()
{
    struct TreeNode* root = newTreeNode(1);
    root->left = newTreeNode(2);
    root->right = newTreeNode(3);
    root->left->left = newTreeNode(4);
    root->left->right = newTreeNode(5);
    printf("INORDER TRAVERSAL: ");
    inorder(root);
    do_mirror_using_queue(root);
    printf("\nAfter taking mirror, INORDER TRAVERSAL: ");
    inorder(root);
}




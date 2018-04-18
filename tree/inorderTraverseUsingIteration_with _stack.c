#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct StackNode
{
    struct TreeNode* treeNode;
    struct StackNode* next;
};

struct StackNode* top = NULL;

struct StackNode* newStackNode(struct TreeNode* treeNode)
{
    struct StackNode* newStackNode = (struct StackNode* )malloc(sizeof(struct StackNode));
    newStackNode->treeNode = treeNode;
    newStackNode->next = NULL;
    return newStackNode;
};

struct TreeNode* newTreeNode(int data)
{
    struct TreeNode* newTreeNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newTreeNode->data = data;
    newTreeNode->left = NULL;
    newTreeNode->right = NULL;
    return newTreeNode;
}

void display()
{
    struct StackNode * temp = top;
    if(top == NULL)
        printf("Stack is empty");
    else
    {
        printf("\nStack has: \n");
        while(temp != NULL)
        {
            printf("%d  ", temp->treeNode->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int isEmpty()
{
    return (top == NULL);
}

void push(struct TreeNode* treeNode)
{
    struct StackNode* stackNode = newStackNode(treeNode);
    stackNode->next = top;
    top = stackNode;
   // display();
}


struct TreeNode* pop()
{
    struct TreeNode* treeNode;
    struct StackNode* temp = top;
    if(!top)
        return NULL;
    else
    {
        treeNode = top->treeNode;
        top = top->next;
        free(temp);
        return treeNode;
    }
}


void inorderTraversal_iteration_UsingStack(struct TreeNode* root)
{
    struct TreeNode* current = root;
    int done = 0;
    while(done == 0)
    {
        if(current != NULL)
        {
            push(current);//push the current parent
            current = current->left;//then assign the current to current'left subtree
        }
        else
        {
            if(!isEmpty())
            {
                current = pop();//pop the element and assign to current so that we can now explore its both subtrees as well
                printf("%d  ", current->data);
                current = current->right;
            }
            else
                done = 1;
        }
    }
}


void main()
{
    struct TreeNode* root = newTreeNode(1);
    root->left = newTreeNode(2);
    root->right = newTreeNode(3);
    root->left->left = newTreeNode(4);
    root->left->right = newTreeNode(5);
    inorderTraversal_iteration_UsingStack(root);
}


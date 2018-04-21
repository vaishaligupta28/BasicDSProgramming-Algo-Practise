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

struct Stack
{
    struct StackNode* top;
};


struct StackNode* newStackNode(struct TreeNode* treeNode)
{
    struct StackNode* newStackNode = (struct StackNode* )malloc(sizeof(struct StackNode));
    newStackNode->treeNode = treeNode;
    newStackNode->next = NULL;
    return newStackNode;
}

struct Stack* createStack()
{
    struct Stack* stack = (struct Stack* )malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

struct TreeNode* newTreeNode(int data)
{
    struct TreeNode* newTreeNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newTreeNode->data = data;
    newTreeNode->left = NULL;
    newTreeNode->right = NULL;
    return newTreeNode;
}


void display(struct Stack* stack)
{
    struct StackNode * temp = stack->top;
    if(stack->top == NULL)
        printf("Stack is empty");
    else
    {
        while(temp != NULL)
        {
            printf("%d ", temp->treeNode->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int isEmpty(struct Stack* stack)
{
    return (stack->top == NULL);
}

void push(struct Stack* stack, struct TreeNode* treeNode)
{
    struct StackNode* stackNode = newStackNode(treeNode);
    stackNode->next = stack->top;
    stack->top = stackNode;
    // display(stack);
}


struct TreeNode* pop(struct Stack* stack)
{
    struct TreeNode* treeNode;
    struct StackNode* temp = stack->top;
    if(isEmpty(stack))
        return NULL;
    else
    {
        treeNode = stack->top->treeNode;
        stack->top = stack->top->next;
        free(temp);
        return treeNode;
    }
}


void inorderTraversal_iteration_UsingStack(struct TreeNode* root)
{
    printf("Inorder: ");
    struct TreeNode* current = root;
    struct Stack* stack = createStack();
    while(1)
    {
        if(current != NULL)
        {
            push(stack, current);//push the current parent
            current = current->left;//then assign the current to current'left subtree
        }
        else
        {
            if(!isEmpty(stack))
            {
                current = pop(stack);//pop the element and assign to current so that we can now explore its both subtrees as well
                printf("%d ", current->data);
                current = current->right;
            }
            else
                return;
        }
    }
}


void preOrderTraversal_iteration_UsingStack(struct TreeNode * root)
{
    printf("\nPreorder: ");
    struct TreeNode* current = root;
    struct Stack* stack = createStack();
    push(stack, current);
    while(!isEmpty(stack))
    {
        current = pop(stack);
        printf("%d ", current->data);
        if(current->right)
            push(stack, current->right);//adding right subtree before so that it is popped after left subtree
        if(current->left)
            push(stack, current->left);
    }
}


//algorithm is very easy with 2 stacks, like reverse of preorder traversal
void postorderTraversal_iteration_Using_2_Stack(struct TreeNode* root)
{
    printf("\nPostorder using two stack: ");
    struct TreeNode* current = root;
    struct Stack* stack1 = createStack();
    struct Stack* stack2 = createStack();
    push(stack1, current);
    while(!isEmpty(stack1))
    {
        current = pop(stack1);//
        push(stack2, current);
        if(current->left)
            push(stack1, current->left);
        if(current->right)
            push(stack1, current->right);//
    }
    display(stack2);
}

void postorderTraversal_iteration_Using_1_Stack(struct TreeNode* root)
{
    printf("Postorder using only one stack: ");
    struct TreeNode* current = root;
    struct Stack* stack = createStack();
    struct TreeNode* temp;
    while(current || !isEmpty(stack))
    {
        if(current != NULL)
        {
            push(stack, current);
            current = current->left;
        }
        else///top's left is null, this current is top's null
        {
            temp = stack->top->treeNode->right;
            if(!temp)///top right is null
            {
                ///top's right and left both are null
                temp = pop(stack);
                printf("%d ", temp->data);
                while(!isEmpty(stack) && temp == stack->top->treeNode->right)
                {
                    temp = pop(stack);
                    printf("%d ", temp->data);
                }
            }
            else///if top's right not null
                current = temp;///ask it to explore right side of that top
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
    preOrderTraversal_iteration_UsingStack(root);
    postorderTraversal_iteration_Using_2_Stack(root);
    postorderTraversal_iteration_Using_1_Stack(root);
}


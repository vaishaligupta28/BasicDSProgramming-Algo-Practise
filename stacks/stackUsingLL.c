//LL implementation of stacks
//insertion and deletion from same ends

#include<stdio.h>
#include<stdlib.h>
struct StackNode
{
    int data;
    struct StackNode * next;
};

struct StackNode * top = NULL;

int isEmpty()
{
    return top == NULL;
}

void display()
{
    struct StackNode * temp = top;
    if(isEmpty())
        printf("Stack is empty");
    else
    {
        printf("Stack has: \n");
        while(temp != NULL)
        {
            printf("%d \n", temp->data);
            temp = temp->next;
        }
        printf("\n\n");
    }
}

//insert from beg
void push(int item)
{
    struct StackNode *new_node = (struct StackNode *)malloc(sizeof(struct StackNode));//pointer to a node
    new_node->data = item;
    new_node->next = top;
    top = new_node;
    display();
}

//delete from beg
int pop()
{
    struct StackNode * temp = top;
    int elem;
    if(isEmpty())
    {
        printf("Underflow");
    }
    else
    {
        temp = top;
        top = top->next;
        elem = temp->data;
        free(temp);
        return elem;
    }
}

void main()
{
    push(24);
    push(25);
    push(26);
    printf("Element popped : %d\n\n", pop());
    printf("Element popped : %d\n\n", pop());
    printf("Element popped : %d\n\n", pop());
}






#include<stdio.h>  //several macros and standard i/o values like NULL, scanf
#include<stdlib.h> //for library functions like malloc, calloc
//#include<conio.h> //#-preprocessor  include - directory containing all these stdio.h files --- only for console i/o
typedef struct node //typedef - representing as a new type
{
    int data;
    struct node* next;
} SingleLLNode;

struct StackNode
{
    int data;
    struct StackNode * next;
};

struct StackNode * top = NULL;
SingleLLNode *start = NULL;


void insertAtBeg(int);
void displayLL();

int isEmpty();
void display();
void push(int item);
int pop();
void reverse();

void main()
{
    insertAtBeg(0);
    insertAtBeg(1);
    insertAtBeg(2);
    insertAtBeg(3);
    insertAtBeg(4);
    displayLL();
    reverse();
    displayLL();
}

//LL
void insertAtBeg(int data)
{
    SingleLLNode *new_node = (SingleLLNode *)malloc(sizeof(SingleLLNode));//pointer to a node
    new_node->data = data;
    new_node->next = start;
    start = new_node;
}

void displayLL()
{
    SingleLLNode *temp = start;
    if(temp == NULL)
    {
        printf("Empty linked list");
    }
    else
    {
    printf("List:  ");
    while(temp->next != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
    }
}

//stack
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

void push(int item)
{
    struct StackNode *new_node = (struct StackNode *)malloc(sizeof(struct StackNode));//pointer to a node
    new_node->data = item;
    new_node->next = top;
    top = new_node;
}

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

void reverse()
{
    int item;
    SingleLLNode * temp = start;
    while(temp != NULL)
    {
        //pushing the addresses of the nodes including the last elem
        /***
        *adding the addresses is not possible in stack not possible in explicit stack
        */
        push((int)temp);
        temp = temp->next;
    }
    //popping the top elem and adding in LL, with start = top
    temp = (SingleLLNode *)pop();
    start = temp;
    while(!isEmpty())
    {
        temp->next = (SingleLLNode *)pop();
        temp=temp->next;
    }
}

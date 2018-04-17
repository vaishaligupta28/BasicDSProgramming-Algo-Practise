#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
struct StackNode
{
    char data;
    struct StackNode * next;
};

struct StackNode * top = NULL;

char isEmpty()
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
            printf("%c \n", temp->data);
            temp = temp->next;
        }
        printf("\n\n");
    }
}

//insert from beg
void push(char item)
{
    struct StackNode *new_node = (struct StackNode *)malloc(sizeof(struct StackNode));//pointer to a node
    new_node->data = item;
    new_node->next = top;
    top = new_node;
}

//delete from beg
char pop()
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

int isOperand(char ch)
{
    return isalpha(ch);
}

int PrecVal(char ch)
{
    switch(ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}

void infixToPostfix(char * exp)
{
    char posExp[20];
    int i, k=-1;
    printf("%d\n", strlen(exp));
    for(i=0; i<strlen(exp); i++)
    {
        if(isOperand(exp[i]))
        {
            printf("isOperand -push in stack\n");
            posExp[++k] = exp[i];
        }
        else if(exp[i] == '(')
        {
            printf("is open bracket- push in stack\n");
            push(exp[i]);
        }
        else if(exp[i] == ')')
        {
            printf(")\n");
            //pop till you get the corresponding opening bracket
            while(!isEmpty() && top->data != '(')
                posExp[++k] = pop();
            //if opening bracket was never present, then expression will be wrong
            if(!isEmpty() && top->data != '(')
                return;
            else
                posExp[++k] = pop();
        }
        //if operator: pop from stack and add in the expression
        else
        {
            printf("isOperator\n");
            while(!isEmpty() && PrecVal(top->data) > PrecVal(exp[i]))
            {
                printf("precedence of top operator is greater then current operator\n");
                posExp[++k] = pop();
            }
            push(exp[i]);
        }
    }
    while(!isEmpty())
    {
        posExp[++k] = pop();
    }
    posExp[++k]="\0";
    printf("%s", posExp);
}

void main()
{
    char * exp = "a+(b*c-(d/e-f)*g)*h";
    infixToPostfix(exp);
}

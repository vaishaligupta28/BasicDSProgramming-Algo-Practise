/*
Infix - 2+3
1)takes precedence and associativity rules for calculations

Prefix(Polish notation) and Postfix(reverse polish notation) - +23, 23+
2)Both do not require any precedence and associativity rules
3)Postfix is easiest to parse and least costly in terms of time and money


When evaluating prefix/postfix expression or converting prefix to infix exp, use stack method

in prefix = scan from right to left
in postfix = scan from left to right
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
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

int isOperand(char ch)
{
    int asciiVal = ch;
    //return (asciiVal >= 97 && asciiVal <= 122) || (asciiVal >= 65 && asciiVal <= 90) || (asciiVal >=48 && asciiVal <= 57)
    return isdigit(asciiVal);
}

int evaluate(int a, int b, char operand)
{
    switch(operand)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    default:
        return -1;
    }
}

int evalPostfix(char * exp)
{
    int res, i;
    for(i=0; i<strlen(exp); i++)
    {
        if(isOperand(exp[i]))
            push((exp[i] - '0'));//important very important stuff 48 - 47 = 1
        else
        {
            int right = pop();
            int left = pop();
            res = evaluate(left, right, exp[i]);
            push(res);
        }
    }
    //pop remaining elem
    while(!isEmpty())
    {
        res = pop();
    }
    return res;
}

int evalPrefix(char * exp)
{
    int res, i;
    for(i=strlen(exp)-1; i>=0 ; i--)
    {
        if(isOperand(exp[i]))
            push((exp[i] - '0'));//important very important stuff 48 - 47 = 1
        else
        {
            int left = pop();
            int right = pop();
            res = evaluate(left, right, exp[i]);
            push(res);
        }
    }
    //pop remaining elem
    while(!isEmpty())
    {
        res = pop();
    }
    return res;
}


void main()
{
    char * exp1 = "+9*26";
    char * exp2 = "231*+9-";
    printf("%d\n", evalPrefix(exp1));
    printf("%d\n", evalPostfix(exp2));
}


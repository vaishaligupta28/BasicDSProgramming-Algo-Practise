#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct StackNode
{
    char data;
    struct StackNode * next;
};

struct StackNode * top = NULL;

int isEmpty()
{
    return top == NULL;
}

//insert from beg
void push(char ch)
{
    struct StackNode *new_node = (struct StackNode *)malloc(sizeof(struct StackNode));//pointer to a node
    new_node->data = ch;
    new_node->next = top;
    top = new_node;
}

//delete from beg
char pop()
{
    struct StackNode * temp = top;
    char elem;
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

isMatchingPair(char ch1, char ch2)
{
    if((ch1 == '(' && ch2 == ')') || (ch1 == '{' && ch2 == '}') || (ch1 == '[' && ch2 == ']'))
        return 1;
    return 0;
}

isValidExpression(char * str)
{
    int i;
    int len = strlen(str);
    for(i=0; i<len; i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
            push(str[i]);
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            /*If we see an ending parenthesis without a pair ex.  = '()}' or '}}'
              if current character is not a pair parenthesis of top character then there is a mismatch. ex. =  '{(})' */
            if(isEmpty() || !isMatchingPair(top->data, str[i]))
            {
                return 0;
            }
            else
            {
                pop();
            }
        }
    }
    return top == NULL;
}

void main()
{
    char * str = "{([])}";
    if(isValidExpression(str))
        printf("Balanced parenthesis");
    else
        printf("Not-balanced parenthesis");
}


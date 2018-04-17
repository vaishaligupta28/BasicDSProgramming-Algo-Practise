#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int top;
    unsigned capacity;
    int *arr;
};

struct Stack* create_stack(unsigned capacity)
{
    struct Stack* stack1 = (struct Stack*)malloc(sizeof(struct Stack));
    stack1->top = -1;
    stack1->capacity = capacity;
    stack1->arr = (int *)malloc(stack1->capacity * sizeof(int));
}

int isEmpty(struct Stack * stack)
{
    return top(stack) == -1;
}

int isFull(struct Stack * stack)
{
    return top(stack) == stack->capacity - 1;
}

int top(struct Stack * stack)
{
    return stack->top;
}

void push(struct Stack* stack, int item)
{
    if(!isFull(stack)){
        stack->arr[++stack->top] = item;
        //printf("Element pushed at address:  %d\n", stack.arr[stack->top]);
    }
    else{
        printf("Overflow\n");
    }
}

int pop(struct Stack * stack)
{
    if(!isEmpty(stack))
        return stack->arr[stack->top--];
    else
        printf("Underflow\n");
}

void main()
{
    struct Stack * stack1 = create_stack(50);
    push(stack1, 10);
    push(stack1, 20);
    push(stack1, 30);
    push(stack1, 40);
    printf("Element popped: %d\n", pop(stack1));
    printf("Element popped: %d\n", pop(stack1));
    printf("Element popped: %d\n", pop(stack1));
    printf("Element popped: %d\n", pop(stack1));
    printf("Element popped: %d\n", pop(stack1));
    printf("Element popped: %d\n", pop(stack1));
}



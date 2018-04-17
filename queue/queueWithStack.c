//LL implementation of stacks
//insertion and deletion from same ends
#include<stdio.h>
#include<stdlib.h>
struct StackNode
{
    int data;
    struct StackNode * next;
};

struct Queue
{
    struct StackNode * top1;
    struct StackNode * top2;
};


//i want to check the value of *top -->value of top
int isEmpty(struct StackNode ** topref)
{
    //*topref == top
    return *topref == NULL;
}

//insert from beg
void push(int item, struct StackNode **topref, char *str)
{
    struct StackNode *new_node = (struct StackNode *)malloc(sizeof(struct StackNode));//pointer to a node
    new_node->data = item;
    new_node->next = (*topref);
    (*topref) = new_node;
    printf("pushed in %s\n", str);
}

//delete from beg
int pop(struct StackNode ** topref)
{
    printf("\npop\n");
    struct StackNode * temp;
    int elem;
    if(isEmpty(topref))
    {
        printf("Underflow");
    }
    else
    {
        temp = (*topref);
        elem = temp->data;
        (*topref) = (*topref)->next;
        free(temp);
        return elem;
    }
}


void enqueue(int item, struct Queue * q)
{
    push(item, &q->top1, "Stack s1");
}


/* Function to dequeue an item from queue */
int dequeue(struct Queue *q)
{
    int x;

    /* If both stacks are empty then error */
    if(q->top1 == NULL && q->top2 == NULL)
    {
        printf("Q is empty");
        getchar();
        exit(0);
    }

    /* Move elements from satck1 to stack 2 only if
    stack2 is empty */
    if(isEmpty(&q->top2))
    {
        printf("\nstack 2 is empty\n");
        while(!isEmpty(&q->top1))
        {
            printf("\nemptying stack 1\n");
            x = pop(&q->top1);
            push(x, &q->top2, "Stack s2");

        }
    }
    x = pop(&q->top2);
    return x;
}

void main()
{
    struct Queue * queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->top1 = NULL;
    queue->top2 = NULL;
    enqueue(10, queue);
    enqueue(20, queue);
    enqueue(30, queue);
    enqueue(40, queue);
    enqueue(50, queue);
    enqueue(60, queue);
    printf("The dequeued element : %d\n", dequeue(queue));
    //display(&queue->top1, "Stack s1");
    printf("The dequeued element : %d\n", dequeue(queue));
    //display(&queue->top2, "Stack s2");
}







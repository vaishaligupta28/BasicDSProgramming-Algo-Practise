#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5
struct DQ
{
    unsigned capacity;
    int *arr;
    int front, rear;
};

struct DQ * createDQ()
{
    struct DQ *q = (struct DQ *)malloc(sizeof(struct DQ));
    q->capacity = CAPACITY;
    q->arr = (int *)malloc(sizeof(int) * q->capacity);
    q->front = q->rear = -1;
}

int isFull(struct DQ *q)
{
    //when rear gets incremented and becomes MAX - 1, or front gets backward incremented and becomes rear + 1
    return (q->front == 0 && q->rear == q->capacity - 1)||(q->front == q->rear+1);
}

int isEmpty(struct DQ *q)
{
    return q->front == -1;
}

void display(struct DQ *q)
{
    int i;
    if(isEmpty(q))
        printf("Empty");
    else
    {
        printf("-----\n");
        for(i=0;i<q->capacity;i++)
            printf("%d  ", q->arr[i]);
    }
}

void insertFront(struct DQ *q, int data)
{
    if(isFull(q))
    {
        printf("Overflow");
        return;
    }
    else if(q->front == -1)
        q->front = q->rear = 0;
    //since front is decrementing, so when it becomes 0, make it point to end
    else if(q->front == 0)
        q->front = q->capacity - 1;
    else
        q->front = q->front - 1;
    q->arr[q->front] = data;
    display(q);
}

void insertRear(struct DQ *q, int data)
{
    if(isFull(q))
    {
        printf("Overflow");
        return;
    }
    else if(q->rear == -1)
        q->rear = q->front = 0;
    else
        //for restrict rear to not go beyond array capacity, since rear is getting incremented
        q->rear = (q->rear +  1)%(q->capacity);
    q->arr[q->rear] = data;
    display(q);
}

int deleteFront(struct DQ *q)
{
    int data;
    struct DQNode *temp;
    if(isEmpty(q))
        printf("Underflow");
    else if(q->front == q->rear)
    {
        data = q->arr[q->front];
        q->front = q->rear = -1;
    }
    else
    {
        data = q->arr[q->front];
        q->front = (q->front + 1)%(q->capacity);
    }
    return data;
}

int deleteRear(struct DQ *q)
{
    int data;
    struct DQNode *temp;
    if(isEmpty(q))
        printf("Underflow");
    else if(q->front == q->rear)
    {
        data = q->arr[q->rear];
        q->rear = q->front = -1;
    }
    else if(q->rear == 0)
    {
        data = q->arr[q->rear];
        q->rear = q->capacity - 1;
    }
    else
    {
        data = q->arr[q->rear];
        q->rear = q->rear - 1;
    }
    return data;
}


void main()
{
    struct DQ *queue = createDQ();
    insertFront(queue, 17);
    insertRear(queue, 13);
    insertFront(queue, 16);
    insertRear(queue, 14);
    insertFront(queue, 15);
    printf("\n%d", deleteFront(queue));
    printf("\n%d", deleteRear(queue));
    display(queue);
}

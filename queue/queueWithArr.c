#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5
struct Queue
{
    int front, rear,size;
    unsigned capacity;
    int * arr;
};

struct Queue * createQueue()
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->size = 0;
    queue->capacity = CAPACITY;
    //add memory for arr
    queue->arr = (int *)malloc(queue->capacity * sizeof(int));
}

int isFull(struct Queue* queue)
{
    //queue->rear == MAX - 1
    return queue->size == queue->capacity;
}

int isEmpty(struct Queue* queue)
{
    //queue->front == -1
    return queue->size == 0;
}

void enqueue(struct Queue * queue, int item)
{
    if(isFull(queue))
        printf("Overflow");
    else
    {
        //first time both front and rear to be incremented
        if(queue->front == -1)
        {
            queue->front = 0;
        }
        queue->rear = (queue->rear+1)%queue->capacity;
        queue->arr[queue->rear] = item;
        queue->size = queue->size + 1;
        printf("Enqueued\n");
    }
}

int dequeue(struct Queue * queue)
{
    if(isEmpty(queue))
        printf("Underflow");
    else
    {
        int item = queue->arr[queue->front];
        queue->front = (queue->front + 1)%queue->capacity;
        queue->size = queue->size + 1;
        return item;
    }
}

void display(struct Queue * queue)
{
    int i;
    printf("\nQueue contains: ");
    for(i=queue->front; i<=queue->rear; i++)
    {
        printf("%d  ", queue->arr[i]);
    }
    printf("\n");
}

void main()
{
    struct Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);
    display(queue);
    printf("\nInteger dequeued : %d",  dequeue(queue));
    printf("\nInteger dequeued : %d\n", dequeue(queue));
    display(queue);
}

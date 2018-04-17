//Queue Implementation
//Insertion and Deletion at opposite ends
#include<stdio.h>
#include<stdlib.h>
struct QueueNode
{
    int data;
    struct QueueNode * next;
};

struct QueueNode * front = NULL;
struct QueueNode * rear = NULL;

void enqueue(int item)
{
    struct QueueNode * newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newNode->data = item;
    newNode->next = NULL;
    if(rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    display();
}

int dequeue()
{
    struct QueueNode * temp = front;
    int item;

    //if nothing is there
    if(front == NULL)
        printf("Underflow");
    else
    {
        front = front->next;
        item = temp->data;
        free(temp);

        //if after incrementing front, front becomes NULL, rear has to be NULL as well
        if(front == NULL)
            rear = NULL;
        return item;
    }
}

void display()
{
    struct QueueNode * temp = front;
    printf("\nQueue contains: "  );
    while(temp != rear)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}

void main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    printf("\n\nItem dequeued: %d\n", dequeue());
    display();
}

//Deque implementation using Doubly LL
//All operations in O(1) complexity

//insertFirst()
//insertLast()
//deleteFirst()
//deleteLast()
#include<stdio.h>
#include<stdlib.h>
struct DQNode
{
    int data;
    struct DQNode *next;
    struct DQNode *prev;
};

struct DeQue
{
    struct DQNode *front, *rear;
};

struct DQNode* getNewNode(int data)
{
    struct DQNode *newNode = (struct DQNode *)malloc(sizeof(struct DQNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct DeQue* createDQ()
{
    struct DeQue *deQue = (struct DeQue* )malloc(sizeof(struct DeQue));
    deQue->front = NULL;
    deQue->rear = NULL;
    return deQue;
}


void display(struct DeQue *q)
{
    struct DQNode *temp;
    if(q->front == NULL || q->rear == NULL)
        printf("Queue is empty");
    else
    {
        printf("DEQUE contains:  ");
        temp = q->rear;
        while(temp != q->front)
        {
            printf("%d <=> ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}

void insertFront(struct DeQue *q, int data)
{
    struct DQNode* newNode = getNewNode(data);
    if(q->front == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->front->next = newNode;
        newNode->prev = q->front;
        q->front = newNode;
    }
    display(q);
}

void insertRear(struct DeQue *q, int data)
{
    struct DQNode* newNode = getNewNode(data);
    if(q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->prev = newNode;
        newNode->next = q->rear;
        q->rear = newNode;
    }
    display(q);
}

int deleteFront(struct DeQue *q)
{
    int item;
    struct DQNode *temp;
    if(q->front == NULL)
        printf("Empty DQ");
    else
    {
        temp = q->front;
        q->front = q->front->prev;
        item = temp->data;
        free(temp);
        if(q->front == NULL)
            q->rear = NULL;
        return item;
    }
}

//O(1) complexity
int deleteRear(struct DeQue *q)
{
    int item;
    struct DQNode *temp;
    if(q->rear == NULL)
        printf("Empty DQ");
    else
    {
        temp = q->rear;
        q->rear = q->rear->next;
        item = temp->data;
        free(temp);
        if(q->rear == NULL)
            q->front == NULL;
        return item;
    }
}

void main()
{
    struct DeQue *dq = createDQ();
    insertFront(dq, 1);
    insertFront(dq, 2);
    insertRear(dq, 10);
    insertRear(dq, 11);
    printf("The element deleted from front: %d\n", deleteFront(dq));
    display(dq);
    printf("The element deleted from rear: %d\n", deleteRear(dq));
    display(dq);
}

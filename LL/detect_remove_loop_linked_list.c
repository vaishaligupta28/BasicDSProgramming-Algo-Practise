#include<stdio.h>
#include<stdlib.h>
struct node //typedef - representing as a new type
{
    int data;
    struct node* next;
};

struct node* start = NULL;

struct node* new_node(int data)
{
    struct node* new_node = (struct node* )malloc(sizeof(struct node));
    new_node->data = data;
}

//using simple traversal one by one
void removeLoop(struct node* meetingPtr)
{
    struct node* ptr2;
    struct node* ptr1 = start;
    while(1)
    {
        ptr2 = meetingPtr;
        while(ptr2->next != meetingPtr && ptr2->next != ptr1)//loop me ni aya av tk ptr1, bahar hi h
        {
            ptr2 = ptr2->next;
        }
        if(ptr2->next == ptr1)
            break;
        ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
}

//using floyd conclusions
void removeLoop_using_floyd(struct node* meetingPtr)
{
    struct node* ptr1 = meetingPtr;
    struct node* ptr2 = meetingPtr;
    int count = 1;

    while(ptr2->next != meetingPtr)
    {
        ptr2 = ptr2->next;
        count++;
    }
    //now you have length of the loop

    //now use nth node from linked list problem
    ptr1 = start;
    ptr2 = start;

    ///creating a distance between two pointers by length of loop
    int i;
    for(i=0; i<count; i++)
        ptr2 = ptr2->next;

    ///now diff between ptr1 and ptr2 is count

    while(ptr2 != ptr1)
    {
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }

    //now both these nodes have met, this is the start of the loop

    //try removing the link
    while(ptr2->next != ptr1)
        ptr2 = ptr2->next;

    ptr2->next = NULL;
}

//Method 1: using removeLoop() to remove the loop
int detectAndRemoveLoop()
{
    struct node* tortoisePtr = start;
    struct node* harePtr = start;
    while(tortoisePtr && harePtr && harePtr->next)
    {
        tortoisePtr = tortoisePtr->next;
        harePtr = harePtr->next->next;
        if(tortoisePtr == harePtr)
        {
            removeLoop(tortoisePtr);
            return 1;
        }
    }
    return 0;
}

//Method 2: using removeLoop_using_floyd() to remove loop
int detectAndRemoveLoop_using_floyd()
{
    struct node* tortoisePtr = start;
    struct node* harePtr = start;
    while(tortoisePtr && harePtr && harePtr->next)
    {
        tortoisePtr = tortoisePtr->next;
        harePtr = harePtr->next->next;
        if(tortoisePtr == harePtr)
        {
            removeLoop_using_floyd(tortoisePtr);
            return 1;
        }
    }
    return 0;
}

//Method 3: using direct optimized technique in one go using floyd conclusions
int detectAndRemoveLoop_floyd_optimized()
{
    if(start == NULL || start->next == NULL)
        return -1;

    struct node* tortoisePtr = start;
    struct node* harePtr = start;
    while(tortoisePtr && harePtr && harePtr->next)
    {
        tortoisePtr = tortoisePtr->next;
        harePtr = harePtr->next->next;
        if(tortoisePtr == harePtr)
        {
            //remove loop
            printf("meeting point: %d\n", tortoisePtr->data);
            break;
        }
    }

    if(tortoisePtr == harePtr)
    {
        if(tortoisePtr == start)//when loop begins from start of the linked list iteslf and ends at start as well
        {//ex . 50->20->15->50
            while(harePtr->next != start)
                harePtr = harePtr->next;
        }
        else
        {
            tortoisePtr = start;
            while(tortoisePtr->next != harePtr->next)
            {
                harePtr = harePtr->next;
                tortoisePtr = tortoisePtr->next;
            }
        }
        harePtr->next = NULL;
    }
}

void displayLL()
{
    struct node *temp = start;
    if(temp == NULL)
    {
        printf("Empty linked list");
    }
    else
    {
        while(temp->next != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}

void main()
{
    start = new_node(50);
    start->next = new_node(20);
    start->next->next = new_node(15);
    start->next->next->next = new_node(4);
    //start->next->next->next->next = new_node(10);

    /* Create a loop for testing */
    //start->next->next->next->next->next = start->next->next;
    start->next->next->next->next = start;

    //detectAndRemoveLoop();
    //detectAndRemoveLoop_using_floyd();
    detectAndRemoveLoop_floyd_optimized();
    printf("Linked list after removal of loop: ");
    displayLL();

}

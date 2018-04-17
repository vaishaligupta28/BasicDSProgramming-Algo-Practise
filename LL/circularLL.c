#include<stdio.h>  //several macros and standard i/o values like NULL, scanf
#include<stdlib.h> //for library functions like malloc, calloc
//#include<conio.h> //#-preprocessor  include - directory containing all these stdio.h files --- only for console i/o
typedef struct node //typedef - representing as a new type
{
    int data;
    struct node* next;
} CircularLLNode;

CircularLLNode *start = NULL;

void insertAtBeg(int);
void insertAtEnd(int);
void insertAtLoc(int, int);
void deleteAtBeg();
void deleteAtEnd();
void deleteAtLoc(int);
int countNodes();
void displayLL();

int main()
{
    int c, data, loc;
    char ch, toContinue = 'y';
    do
    {
        printf("\n\n*********MAIN MENU*************\n\n");
        printf("\n1)Display linked list");
        printf("\n2)Insertion at beginning ");
        printf("\n3)Insertion at end ");
        printf("\n4)Insertion at particular location ");
        printf("\n5)Deletion at beginning.");
        printf("\n6)Deletion at end.");
        printf("\n7)Deletion at particular location.");
        printf("\n8)Total number of nodes.");
        printf("\n\n*****************Enter your option****************\n");
        scanf("%d", &c);
        if(c <= 4)
        {
            printf("Enter data: ");
            scanf("%d", &data);
        }
        switch(c)
        {
        case 1:
            displayLL();
            break;
        case 2:
            insertAtBeg(data);
            break;
        case 3:
            insertAtEnd(data);
            break;
        case 4:
            printf("\nEnter a location: ");
            scanf("%d", &loc);
            insertAtLoc(data, loc);
            break;
        case 5:
            deleteAtBeg();
            break;
        case 6:
            deleteAtEnd();
            break;
        case 7:
            printf("Enter a location: ");
            scanf("%d", &loc);
            deleteAtLoc(loc);
            break;
        case 8:
            printf("Total nodes:  %d", countNodes());
            break;
        default:
            printf("Incorrect option\n");
            printf("Do you want to continue(y/n)?:  ");
            char toContinue = scanf("%c", &ch);
            break;
        }
    }
    while(c<=8 || toContinue == 'y');
}

void insertAtBeg(int data)
{
    CircularLLNode *temp = start;
    CircularLLNode *new_node = (CircularLLNode *)malloc(sizeof(CircularLLNode));  //malloc returns (void*)
    //If you won't cast the return of malloc(), there is no problem in C because it allows void pointers to be implicitly converted to any other object pointer type.But C++ wont.
    new_node->data = data;
    if(start == NULL)
    {
        start = new_node;
        new_node->next = start;
    }
    else
    {
        while(temp->next != start)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = start;
        start = new_node;
    }
    displayLL();
}

void insertAtEnd(int data)
{
    CircularLLNode *new_node = (CircularLLNode *)malloc(sizeof(CircularLLNode));
    new_node->data = data;
    CircularLLNode *temp = start;
    if(start != NULL)
    {
        while(temp->next != start)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    new_node->next = start;
    displayLL();
}

void insertAtLoc(int data, int loc)
{
    int c = 1;
    CircularLLNode *new_node = (CircularLLNode *)malloc(sizeof(CircularLLNode));
    new_node->data = data;
    CircularLLNode *temp = start;
    if(loc <= 1)
        insertAtBeg(data);
    else if(loc > countNodes())
        insertAtEnd(data);
    else
    {
        while(temp->next != start && c++ != (loc-1))
        {
            temp= temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        displayLL();
    }
}

void deleteAtBeg()
{
    CircularLLNode* ptr, *pptr;
    pptr = start;
    ptr = start;
    while(ptr->next != start)
    {
        ptr=ptr->next;
    }
    ptr->next = start->next;
    start = ptr->next;
    free(pptr);
    displayLL();
}

void deleteAtEnd()
{
    CircularLLNode* ptr, *pptr;
    pptr = start;
    ptr = start;
    while(ptr->next != start)
    {
        pptr = ptr;
        ptr = ptr->next;
    }
    pptr->next = ptr->next;
    free(ptr);
    displayLL();
}

void deleteAtLoc(int loc)
{
    int c = 1;
    CircularLLNode *pptr, *ptr;
    ptr = start;
    pptr = start;
    if(loc <= 1)
        deleteAtBeg();
    else if(loc >= countNodes())
        deleteAtEnd();
    else
    {
        while(ptr->next != start && c++ != loc)
        {
            pptr = ptr;
            ptr =ptr->next;
        }
        pptr->next = ptr->next;
        free(ptr);
        displayLL();
    }
}
void displayLL()
{
    CircularLLNode *temp = start;
    while(temp->next != start)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("%d <-> %d", temp->data, temp->next->data);
}

int countNodes()
{
    int c=1;
    CircularLLNode * temp = start;
    while(temp->next != start)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

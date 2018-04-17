#include<stdio.h>  //several macros and standard i/o values like NULL, scanf
#include<stdlib.h> //for library functions like malloc, calloc
//#include<conio.h> //#-preprocessor  include - directory containing all these stdio.h files --- only for console i/o
typedef struct node //typedef - representing as a new type
{
    int data;
    struct node* next;
    struct node* prev;
} DoublyLLNode;

DoublyLLNode *start = NULL;

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
    DoublyLLNode *new_node = (DoublyLLNode *)malloc(sizeof(DoublyLLNode));  //sizeof(struct node) and not sizeof(struct node *)
    new_node->data = data;
    new_node->next = start;
    new_node->prev = NULL;
    if(start != NULL)
        start->prev = new_node;
    start = new_node;
    displayLL();
}

void insertAtEnd(int data)
{
    DoublyLLNode *new_node = (DoublyLLNode *)malloc(sizeof(DoublyLLNode));
    new_node->data = data;
    DoublyLLNode *temp = start;
    if(start == NULL)
    {
        start = new_node;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    new_node->prev = temp;
    new_node->next = NULL;
    displayLL();
}

void insertAtLoc(int data, int loc)
{
    int c = 1;
    DoublyLLNode *new_node = (DoublyLLNode *)malloc(sizeof(DoublyLLNode));
    new_node->data = data;
    DoublyLLNode *temp = start;
    if(loc <= 1)
        insertAtBeg(data);
    else if(loc > countNodes())
        insertAtEnd(data);
    else
    {
        while(temp->next != NULL && c++ != (loc-1))
        {
            temp= temp->next;
        }
        new_node->next = temp->next;
        temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
        displayLL();
    }
}

void deleteAtBeg()
{
    DoublyLLNode* ptr = start;
    start = ptr->next;
    free(ptr);
    start->prev = NULL;
    displayLL();
}

void deleteAtEnd()
{
    DoublyLLNode *ptr = start;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    displayLL();
}

void deleteAtLoc(int loc)
{
    int c = 1;
    DoublyLLNode *pptr , *ptr;
    ptr = start;
    pptr = start;
    if(loc <= 1)
        deleteAtBeg();
    else if(loc >= countNodes())
        deleteAtEnd();
    else
    {
        while(ptr->next != NULL && c++ != loc)
        {
            pptr = ptr;
            ptr =ptr->next;
        }
        pptr->next = ptr->next;
        ptr->next->prev = pptr;
        free(ptr);
        displayLL();
    }
}
void displayLL()
{
    DoublyLLNode *temp = start;
    while(temp->next != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}

int countNodes()
{
    int c=1;
    DoublyLLNode * temp = start;
    while(temp->next != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

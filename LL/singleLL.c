#include<stdio.h>  //several macros and standard i/o values like NULL, scanf
#include<stdlib.h> //for library functions like malloc, calloc
//#include<conio.h> //#-preprocessor  include - directory containing all these stdio.h files --- only for console i/o
typedef struct node //typedef - representing as a new type
{
    int data;
    struct node* next;
} SingleLLNode;

SingleLLNode *start = NULL;
void insertAtBeg(int);
void insertAtEnd(int);
void insertAtLoc(int, int);
void deleteAtBeg();
void deleteAtEnd();
void deleteAtLoc(int);
int countNodes();
void displayLL();
void reverseUsingIteration();
void recursiveTraverse(SingleLLNode *temp);
void reverseUsingRecursion(SingleLLNode *temp);

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
        printf("\n9)Reverse LL using iterative method");
        printf("\n10)Reverse LL using recursive method");
        printf("\n11)Traversal using Recursion - backward");
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
        case 9:
            printf("The reverse LL is:\n");
            reverseUsingIteration();
            break;
        case 10:
            printf("The reverse LL is:\n");
            reverseUsingRecursion(start);
            displayLL();
            break;
        case 11:
            printf("Traverse LL using Recursion backward: ");
            recursiveTraverse(start);
            break;
        default:
            printf("Incorrect option\n");
            printf("Do you want to continue(y/n)?:  ");
            char toContinue = scanf("%c", &ch);
            break;
        }
    }
    while(c<=10 || toContinue == 'y');
}

void insertAtBeg(int data)
{
    SingleLLNode *new_node = (SingleLLNode *)malloc(sizeof(SingleLLNode));//pointer to a node
    new_node->data = data;
    new_node->next = start;
    start = new_node;
    displayLL();
}

void insertAtEnd(int data)
{
    SingleLLNode *new_node = (SingleLLNode *)malloc(sizeof(SingleLLNode));
    new_node->data = data;
    SingleLLNode *temp = start;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = NULL;
    displayLL();
}

void insertAtLoc(int data, int loc)
{
    int c = 1;
    SingleLLNode *new_node = (SingleLLNode *)malloc(sizeof(SingleLLNode));
    new_node->data = data;
    SingleLLNode *temp = start;
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
        temp->next = new_node;
        displayLL();
    }
}

void deleteAtBeg()
{
    SingleLLNode* ptr = start;
    start = ptr->next;
    free(ptr);
    displayLL();
}

void deleteAtEnd()
{
    SingleLLNode *ptr, *pptr;
    ptr = start;
    pptr = start;
    while(ptr->next != NULL)
    {
        pptr = ptr;
        ptr = ptr->next;
    }
    pptr->next = NULL;
    free(ptr);
    displayLL();
}

void deleteAtLoc(int loc)
{
    int c = 1;
    SingleLLNode *ptr, *pptr;
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
        free(ptr);
        displayLL();
    }
}
void displayLL()
{
    SingleLLNode *temp = start;
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

int countNodes()
{
    int c=1;
    SingleLLNode * temp = start;
    while(temp->next != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

//will have to use three variables, one to store current, 2nd to store next, 3rd store prev;
void reverseUsingIteration()
{
    SingleLLNode *current = start;
    SingleLLNode *prev = NULL;
    SingleLLNode *next;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    start = prev;
    displayLL();
}


void reverseUsingRecursion(SingleLLNode *temp)
{
    if(temp->next == NULL)
    {
        start = temp;
        return;
    }
    reverseUsingRecursion(temp->next);
    temp->next->next = temp;
    temp->next = NULL;
}

void recursiveTraverse(SingleLLNode *temp)
{
    if(temp == NULL)
    {
        return;
    }
    recursiveTraverse(temp->next);
    printf("%d->", temp->data);
}

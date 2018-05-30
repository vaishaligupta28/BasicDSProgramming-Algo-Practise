#include<stdio.h>  //several macros and standard i/o values like NULL, scanf
#include<stdlib.h> //for library functions like malloc, calloc
//#include<conio.h> //#-preprocessor  include - directory containing all these stdio.h files --- only for console i/o
typedef struct node //typedef - representing as a new type
{
    int data;
    struct node* next;
} SingleLLNode;

SingleLLNode *start = NULL;

void insertAtEnd(int data)
{
    SingleLLNode *new_node = (SingleLLNode *)malloc(sizeof(SingleLLNode));
    new_node->data = data;
    SingleLLNode *temp = start;
    if(start == NULL)
    {
        start = new_node;
        new_node->next = NULL;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = NULL;
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
            printf("%d -> ", temp->data);
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

//Method 1:
int get_nthNode_1(int n)
{
    int len = countNodes();
    SingleLLNode* temp = start;
    int c = 1;
    if(n > len)
        return -1;
    while(temp->next != NULL && c++ != (len - n + 1))
        temp = temp->next;
    return temp->data;
}

//Method 2:
int get_nthNode_2(int n)
{
    SingleLLNode* ptr1 = start, *ptr2 = start;
    int c = 1;
    while(ptr2->next != NULL && c++ != n)//after this loop, ptr2 will create a diff from ptr1 with n nodes
        ptr2 = ptr2->next;
    //so when ptr2 will reach end , ptr1 will reach n node from end
    while(ptr2->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1->data;
}


void main()
{
    int arr[] = {2, 3, 8, 7, 22, 10, 9, 5, 1, 11};
    int i;
    for(i=0; i<10; i++)
        insertAtEnd(arr[i]);
    displayLL();
    int nthNode = 6;
    printf("\n%dth node from the end is: %d", nthNode, get_nthNode_1(nthNode));//method 1
    printf("\n%dth node from the end is: %d", nthNode, get_nthNode_2(nthNode));//method 2
}

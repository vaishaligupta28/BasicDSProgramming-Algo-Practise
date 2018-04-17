#include<stdlib.h>
#include<stdio.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}

int height(struct node* root, int *ptrHeight)
{
    int l, r;
    if(!root)
        return 0;
    else if(root->left == NULL && root->right== NULL)
        return 0;
    else
    {
        if(root->left != NULL){
            l = height(root->left, ptrHeight);
            printf("At %d--:  %d\n",root->left->data, l);
        }
        if(root->right != NULL){
            r = height(root->right, ptrHeight);
            printf("At %d++:  %d\n",root->right->data, r);
        }
        *ptrHeight = 1 + (l > r? l : r); /**here link could have been broken*/
        return *ptrHeight;
    }
}
void main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    int h = 0;
    height(root, &h);
    printf("Height: %d", h);
}

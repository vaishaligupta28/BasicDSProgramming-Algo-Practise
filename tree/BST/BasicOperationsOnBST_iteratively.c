#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newTreeNode(int data)
{
    struct TreeNode* newNode = (struct TreeNode* )malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//insertion in BST using iteration
struct TreeNode* insertion(struct TreeNode* root, int data)
{
    struct TreeNode* pCurr = root;
    struct TreeNode* pTrav = root;
    struct TreeNode* newNode = newTreeNode(data);
    while(pTrav)
    {
        pCurr = pTrav;
        if(data < pTrav->data)
            pTrav = pTrav->left;
        else
            pTrav = pTrav->right;
    }

    if(!root)
        root = newNode;
    else if(data < pCurr->data)
        pCurr->left = newNode;
    else
        pCurr->right = newNode;
    return root;
}

struct TreeNode* getAddressOfMinimumNode(struct TreeNode* root)
{
    if(!root)
        return root;
    while(root->left != NULL)
        root = root->left;
    return root;
}

//deletion in BST using iteration
struct TreeNode* deletion(struct TreeNode* root, int data)
{
    struct TreeNode* node = newTreeNode(data);
    struct TreeNode* pTrav = root;
    struct TreeNode* pCurr = root;
    struct TreeNode* temp;
    int flag = 1; /*---> flag indicates if the no more nodes have to be deleted*/
    while(flag)
    {
        while(pTrav->data != data)
        {
            pCurr = pTrav;//it will store the immediate parent
            if(data < pTrav->data)
                pTrav = pTrav->left;
            else if(data > pTrav->data)
                pTrav = pTrav->right;
        }

        //no node found
        if(pTrav == NULL)
            return;

        if(pTrav->left == NULL && pTrav->right == NULL)
        {
            printf("....");
            temp = pTrav;
            if(pCurr->left->data == pTrav->data)
                pCurr->left = NULL;
            else if(pCurr->right->data == pTrav->data)
                pCurr->right = NULL;
            free(temp);
            flag = 0;
        }
        else if(pTrav->right == NULL)
        {
            temp = pTrav;
            if(pCurr->left->data == pTrav->data)
                pCurr->left = pTrav->left;
            else if(pCurr->right->data == pTrav->data)
                pCurr->right = pTrav->left;
            free(temp);
            flag = 0;
        }
        else if(pTrav->left == NULL)
        {
            temp = pTrav;
            if(pCurr->left->data == pTrav->data)
                pCurr->left = pTrav->right;
            else if(pCurr->right->data == pTrav->data)
                pCurr->right = pTrav->right;
            free(temp);
            flag = 0;
        }
        else
        {
            pCurr = pTrav;
            temp = getAddressOfMinimumNode(pTrav->right);
            pTrav->data = temp->data;
            pTrav = pTrav->right;
            data = temp->data;
        }
    }
    return root;
}

void inorder(struct TreeNode* root)
{
    if(!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void main()
{
    int i;
    struct TreeNode* root = NULL;
    //int inputTree[] = {40,20,80,10,30,90,55,8,45,70,60,75,65};
    int inputTree[] = {40,20,30,90,55,8,45,70,60,75,65,15,10};
    int size = sizeof(inputTree)/sizeof(inputTree[0]);
    for(i=0;i<size;i++)
    {
        root = insertion(root, inputTree[i]);
    }
    inorder(root);
//    root = deletion(root, 10);
//    printf("\n\nAfter deletion %d\n", 10);
//    inorder(root);
//    root = deletion(root, 55);
//    printf("\n\nAfter deletion %d\n", 55);
//    inorder(root);
//    root = deletion(root, 60);
//    printf("\n\nAfter deletion %d\n", 60);
//    inorder(root);
//    root = deletion(root, 65);
//    printf("\n\nAfter deletion %d\n", 65);
//    inorder(root);
//    root = deletion(root, 75);
//    printf("\n\nAfter deletion %d\n", 75);
//    inorder(root);

//root = deletion(root, 65);
    root = deletion(root, 90);
    printf("\n");
    inorder(root);
    root = deletion(root, 8);
    printf("\n");
    inorder(root);
    root = deletion(root, 55);
    printf("\n");
    inorder(root);
    root = deletion(root, 20);
    printf("\n");
    inorder(root);
}


#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
    struct TreeNode* left;
    int hasLeftChild;//if left pointer points to its child, then it is 1 and if points to inorder predecessor, then 0
    int data;
    int hasRightChild;//if right pointer points to its child, then it is 1, and if points to inorder successor, then 1
    struct TreeNode* right;
};

struct TreeNode* newTreeNode(int data)
{
    struct TreeNode* newNode = (struct TreeNode* )malloc(sizeof(struct TreeNode));
    newNode->left = NULL;
    newNode->hasLeftChild = 0;
    newNode->data = data;
    newNode->hasRightChild = 0;
    newNode->right = NULL;
}

struct TreeNode* insertion(struct TreeNode* root, int data)
{
    struct TreeNode* pCurr = root;
    struct TreeNode* pTrav = root;
    struct TreeNode* newNode = newTreeNode(data);
    printf("%d\n", data);
    while(pTrav)
    {
        pCurr = pTrav;
        if(data < pTrav->data && (pTrav->hasLeftChild == 1 || pTrav->left == NULL))
        {
            pTrav = pTrav->left;
        }
        else if(data > pTrav->data && (pTrav->hasRightChild == 1 || pTrav->right == NULL))
        {
            pTrav = pTrav->right;
        }
        else
            break;
    }
    if(!root){
        newNode->hasLeftChild = -1;
        newNode->hasRightChild = -1;
        root = newNode;
    }
    else if(data < pCurr->data)
    {
        printf("pCurr: %d\n", pCurr->data);
        if(pCurr->hasLeftChild == -1)//leftmost
        {
            pCurr->left = newNode;
            pCurr->hasLeftChild = 1;
            newNode->hasLeftChild = -1;
            newNode->right = pCurr;
        }
        else
        {
            printf("\npCurr->hasLeftChild == -1");
            newNode->left = pCurr->left;
            pCurr->left = newNode;
            pCurr->hasLeftChild = 1;
            newNode->right = pCurr;
        }
    }
    else
    {
        printf("pCurr: %d\n", pCurr->data);
        if(pCurr->hasRightChild == -1)//rightmost
        {
            pCurr->right = newNode;
            pCurr->hasRightChild = 1;
            newNode->hasRightChild = -1;
            newNode->left = pCurr;
        }
        else
        {
            printf("\npCurr->hasRightChild != -1");
            newNode->right = pCurr->right;
            pCurr->right = newNode;
            pCurr->hasRightChild = 1;
            newNode->left = pCurr;
        }
    }
    printf("\nEnd\n\n");
    return root;
}

struct TreeNode* deletion(struct TreeNode* root)
{

}

void inorder(struct TreeNode *node)
{
    struct TreeNode *prev = NULL;

    // Ignore empty trees
    if (node == NULL)
        return;

    // First, go to the leftmost leaf of the tree
    while (node->left != NULL)
        node = node->left;

    while (node != NULL) {//till you get the next null... i.e the righmost null
        // Nodes are visited along going upward in the tree
        printf("%d ", node->data);

        prev = node;
        node = node->right;

        if (prev->hasRightChild) {
            // We're descending into tree

            if (node != NULL && node->hasLeftChild == 1) {//if node has left pointer as parent, then dont traverse left subtree
                // Again, go to the leftmost leaf in this subtree
                while (node->left != NULL){
                    node = node->left;
                    if(node->hasLeftChild == 0)
                        break;
                }
            }
        }
        // else, we're climbing up in the tree
    }
}

void main()
{
    int i;
    struct TreeNode* root = NULL;
    int inputTree[] = {40,20,30,90,55,8,45,70,60,75,65};
    //,
    int size = sizeof(inputTree)/sizeof(inputTree[0]);
    for(i=0;i<size;i++)
    {
        root = insertion(root, inputTree[i]);
    }
    printf("\n");
    inorder(root);
}

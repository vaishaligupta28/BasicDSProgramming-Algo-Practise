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

/**
Insertion in threaded binary search tree
*/
struct TreeNode* insertion(struct TreeNode* root, int data)
{
    struct TreeNode* pCurr = root;
    struct TreeNode* pTrav = root;
    struct TreeNode* newNode = newTreeNode(data);
    //printf("%d\n", data);
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
        //printf("pCurr: %d\n", pCurr->data);
        if(pCurr->hasLeftChild == -1)//leftmost case 1
        {
            pCurr->left = newNode;
            pCurr->hasLeftChild = 1;
            newNode->hasLeftChild = -1;
            newNode->right = pCurr;
        }
        else//case 2
        {
            //printf("\npCurr->hasLeftChild != -1");
            newNode->left = pCurr->left;
            pCurr->left = newNode;
            pCurr->hasLeftChild = 1;
            newNode->right = pCurr;
        }
    }
    else
    {
        //printf("pCurr: %d\n", pCurr->data);
        if(pCurr->hasRightChild == -1)//rightmost... case 3
        {
            pCurr->right = newNode;
            pCurr->hasRightChild = 1;
            newNode->hasRightChild = -1;
            newNode->left = pCurr;
        }
        else//case 4
        {
            //printf("\npCurr->hasRightChild != -1");
            newNode->right = pCurr->right;
            pCurr->right = newNode;
            pCurr->hasRightChild = 1;
            newNode->left = pCurr;
        }
    }
    //printf("\nEnd\n\n");
    return root;
}

struct TreeNode* getAddressOfMinimumNode(struct TreeNode* root)
{
    if(!root)
        return root;
    while (root->left != NULL && root->hasLeftChild != 0){
        root = root->left;
    }
    return root;
}


/**
Deletion in a threaded binary search tree
*/
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

        //if only single node i.e root
        if(pTrav->hasLeftChild == -1 && pTrav->hasRightChild == -1)
        {
            temp = root;
            free(temp);
            root = NULL;
            flag = 0;
        }
        //leaf nodes can have combinations (-1,0) or (0,0) or (0,-1) or (-1,-1)
        //or we can write {pTrav->hasLeftChild != 1 && pTrav->hasRightChild != 1}
        else if((pTrav->hasLeftChild == -1 || pTrav->hasLeftChild == 0) && (pTrav->hasRightChild == -1 || pTrav->hasRightChild == 0))
        {
            temp = pTrav;
            if(pCurr->left->data == data)
                {
                    if(pTrav->hasLeftChild == -1)
                    {
                        pCurr->left = NULL;
                        pCurr->hasLeftChild = -1;
                    }
                    else
                    {
                        pCurr->left = pTrav->left;
                        pCurr->hasLeftChild = 0;
                    }
                }
             else if(pCurr->right->data == data)
                {
                    if(pTrav->hasRightChild == -1)
                    {
                        pCurr->right = NULL;
                        pCurr->hasRightChild = -1;
                    }
                    else
                    {
                        pCurr->right = pTrav->right;
                        pCurr->hasRightChild = 0;
                    }
                }
            free(temp);
            flag = 0;
        }

        //if node with only left child,node with no right child
        else if(pTrav->hasLeftChild == 1 && pTrav->hasRightChild != 1)
        {
            temp = pTrav;
            if(pCurr->left->data == pTrav->data)
                {
                    if(pTrav->left->hasRightChild != 1)//if the left of node to be deleted has no right child, then make it point to current
                    {
                        pTrav->left->right = pTrav->right;
                    }
                    pCurr->left = pTrav->left;
                }
            else if(pCurr->right->data == pTrav->data)
                {
                    if(pTrav->hasRightChild == 0)//if the left of node to be deleted has right child to parent, then make it point to current
                    {
                        if(pTrav->left->hasRightChild == 0)
                            pTrav->left->right = pTrav->right;
                    }
                    else if(pTrav->hasRightChild == -1)
                    {
                        if(pTrav->left->hasRightChild == 0)
                        {
                            pTrav->left->hasRightChild = -1;
                        }
                        else if(pTrav->left->hasRightChild == 1)
                        {
                           struct TreeNode* temp = pTrav->left;
                           while(temp->right != pTrav){
                              temp = temp->right;
                           }
                           temp->hasRightChild = -1;
                           temp->right = NULL;
                        }
                    }
                    pCurr->right = pTrav->left;
                }
            free(temp);
            flag = 0;
        }

        //if node with only right child,node with no left child
        else if(pTrav->hasRightChild == 1 && pTrav->hasLeftChild != 1)
        {
            temp = pTrav;
            if(pCurr->left->data == pTrav->data)
                {
                    if(pTrav->hasLeftChild == 0)//if the left of node to be deleted has right child to parent, then make it point to current
                    {
                        if(pTrav->right->hasLeftChild == 0)
                            pTrav->right->left = pTrav->left;
                    }
                    else if(pTrav->hasLeftChild == -1)
                    {
                        if(pTrav->right->hasLeftChild == 0)
                        {
                            pTrav->right->hasLeftChild = -1;
                        }
                        else if(pTrav->right->hasLeftChild == 1)
                        {
                           struct TreeNode* temp = pTrav->right;
                           while(temp->left != pTrav){
                              temp = temp->left;
                           }
                           temp->hasLeftChild = -1;
                           temp->left = NULL;
                        }
                    }
                    pCurr->left = pTrav->right;
                }
            else if(pCurr->right->data == pTrav->data)
                {
                    if(pTrav->right->hasLeftChild != 1)//if the left of node to be deleted has no right child, then make it point to current
                    {
                        pTrav->right->left = pTrav->left;
                    }
                    pCurr->right = pTrav->right;
                }
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

/**
Method 1: Traversal in threaded binary search tree
*/
void threaded_traversal_iteration(struct TreeNode *node)
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

/**
Method 2: Traversal in threaded binary search tree using direct inorder successor
*/
struct TreeNode* inorderSuccessor(struct TreeNode* ptr)
{
    if(ptr->hasRightChild == 0)//if has node right child
        return ptr->right;//inorder successor is just parent where it already points

    //if it has right child, then get leftmost of the right subtree
    ptr = ptr->right;
    while(ptr->hasLeftChild)
        ptr = ptr->left;
    return ptr;
}
void threaded_traversal_iteration_method2(struct TreeNode *root)
{
    if(!root)
        return;

    struct TreeNode* ptr = root;
    while(ptr->hasLeftChild != -1){//go to leftmost until reach a leftchild with -1
        ptr = ptr->left;
    }

    while(ptr->hasRightChild != -1){//keep priniting the inorder successor of evry node till you reach rightmost element
        printf("%d ", ptr->data);
        ptr = inorderSuccessor(ptr);
    }
    printf("%d ", ptr->data);
}


void main()
{
    int i;
    struct TreeNode* root = NULL;
    int inputTree[] = {40,20,30,90,55,8,45,70,60,75,65,15,10};
    //,
    int size = sizeof(inputTree)/sizeof(inputTree[0]);
    for(i=0;i<size;i++)
    {
        root = insertion(root, inputTree[i]);
    }
    printf("\n");
    threaded_traversal_iteration_method2(root);

    //root = deletion(root, 65);
    root = deletion(root, 90);
    printf("\n");
    threaded_traversal_iteration(root);
    root = deletion(root, 8);
    printf("\n");
    threaded_traversal_iteration(root);
    root = deletion(root, 55);
    printf("\n");
    threaded_traversal_iteration(root);
    root = deletion(root, 20);
    printf("\n");
    threaded_traversal_iteration(root);
    //root = insertion(root, 85);
    //printf("\n");
    //threaded_traversal_iteration(root);
}

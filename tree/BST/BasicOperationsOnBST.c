/*Operation on binary tree.

1.Insertion
2.Searching
3.Min/Max element
4.Height of a tree
*/
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
    struct TreeNode* newTreeNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newTreeNode->data = data;
    newTreeNode->left = newTreeNode->right = NULL;
    return newTreeNode;
}

struct TreeNode* insert(struct TreeNode* root, int data)
{
    /* If the tree is empty, return a new node */
    if (root == NULL) return newTreeNode(data);

    /* Otherwise, recur down the tree */
    if (data < root->data)
        root->left  = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    /* return the (unchanged) node pointer */
    return root;
}

struct TreeNode* search(struct TreeNode* root, int data)
{
    if(!root || data == root->data)//if tree is empty, return root i.e null and if data found return root
        return root;
    else if(data < root->data)
        return search(root->left, data);
    return search(root->right, data);
}

//inorder will print BST in sorted order
void inorder(struct TreeNode* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


int min(struct TreeNode* root)
{
    if(!root)
        return -1;
    while(root->left != NULL)
        root = root->left;
    return root->data;
}

int max(struct TreeNode* root)
{
    if(!root)
        return -1;
    while(root->right != NULL)
        root = root->right;
    return root->data;
}

struct TreeNode* getAddressOfMinimumNode(struct TreeNode* root)
{
    if(!root)
        return root;
    while(root->left != NULL)
        root = root->left;
    return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int data)
{
    if(root == NULL)
        return root;
    else if(data < root->data)
        root->left = deleteNode(root->left, data);//return the new root after deletion, make current->left = returned root
    else if(data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        struct TreeNode* temp;
        if(root->left == NULL && root->right == NULL)
        {
            temp = root;
            root = NULL;
            free(temp);
        }
        else if(root->left == NULL)
        {
            temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL)
        {
            temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            temp = getAddressOfMinimumNode(root->right);
            root->data = temp->data;//copy the minimum node to root
            root->right = deleteNode(root->right, temp->data);//delete the min/duplicate node from root's right subtree
        }
    }
    return root;
}


void main()
{
    struct TreeNode* root = NULL;
    printf("Insertion:\n");
    root = insert(root, 18);
    root = insert(root, 55);
    root = insert(root, 33);
    root = insert(root, 23);
    root = insert(root, 2);
    printf("Before deletion:  ");
    inorder(root);
    //printf("\n\nSearching %d:", 45);
    //if(search(root, 45))
    //    printf("\nfound");
    //else
    //    printf("\nnot found");
    //printf("\n\nMin element: %d",min(root));
    //printf("\n\nMax element: %d",max(root));
    deleteNode(root, 23);
    printf("\nAfter deletion:  ");
    inorder(root);
}

// C++ program to count no of leaf nodes in a binary tree

// http://www.geeksforgeeks.org/write-a-c-program-to-get-count-of-leaf-nodes-in-a-binary-tree/

/* Base cases are:

        if root is null, return 0
        if root is a leaf node, return 1
        else return (count of leaf nodes in left subtree) + (count of leaf nodes in right subtree)

*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

/* function to count leaf nodes in a binary tree */
int countLeafNodes(struct node* root)
{
    if(root == NULL)
        return 0;

    if(root->left==NULL && root->right==NULL)  // a leaf node
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);    // recur on left and right subtrees and sum the result
}

struct node *newNode(int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
};

int main()
{
    struct node* root = newNode(1);

    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);

    printf("The count of leaf nodes is %d\n", countLeafNodes(root));

    return 0;
}



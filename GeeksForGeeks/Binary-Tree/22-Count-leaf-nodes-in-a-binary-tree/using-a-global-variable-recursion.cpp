// C++ program to count no of leaf nodes in a binary tree

// http://www.geeksforgeeks.org/write-a-c-program-to-get-count-of-leaf-nodes-in-a-binary-tree/

/*
    Ideas: here we use a global variable to keep the count of leaf nodes and traverse the tree in a dfs manner
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

int leafnodeCount=0;

/* function to count leaf nodes in a binary tree */
void countLeafNodes(struct node* root)
{
    if(root == NULL)
        return;

    if(root->left==NULL && root->right==NULL)  // a leaf node
        leafnodeCount++;

    countLeafNodes(root->left);
    countLeafNodes(root->right);
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

    countLeafNodes(root);

    printf("The count of leaf nodes is %d\n", leafnodeCount);

    return 0;
}



// C++ program to calculate the height of a binary tree

/* Idea used here is that we traverse the tree in dfs recursive mannner.

for every node, we calculate:

the height of the left subtree and the height of right subtree and return the

max(height of left subtree,height of right subtree) + 1 for that node

*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

/* Function to calculate height of a binary tree */
int height(struct node* root)
{
    if(root == NULL) return 0;

    int leftSubTreeHeight = height(root->left);
    int rightSubTreeHeight = height(root->right);

    if(leftSubTreeHeight > rightSubTreeHeight)
        return leftSubTreeHeight + 1;
    else
        return rightSubTreeHeight + 1;
}

/* Function to create a new node */
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

    root->left->right->left=newNode(6);

    printf("Height of given binary tree is %d\n", height(root));

    return 0;
}

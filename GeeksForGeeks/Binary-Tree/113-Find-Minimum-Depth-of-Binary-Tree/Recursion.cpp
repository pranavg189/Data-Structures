// C++ program to find minimum depth of tree - Recursive solution

#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

int minDepth(struct node* root)
{
    if(root==NULL) return 0;

    if(root->left==NULL && root->right==NULL)
        return 1;

    if(root->left==NULL)
        return minDepth(root->right) + 1;

    if(root->right==NULL)
        return minDepth(root->left) + 1;

    return 1 + min(minDepth(root->left),minDepth(root->right));
}

struct node *newNode(int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data=val;

    newnode->left=NULL;
    newnode->right==NULL;

    return newnode;
};

int main()
{
    struct node* root=newNode(1);

    root->left=newNode(2);
    root->left->left=newNode(4);
    root->left->left=newNode(5);

    root->right=newNode(3);

    int depth = minDepth(root);

    printf("Minimum depth is %d\n", depth);
    return 0;
}

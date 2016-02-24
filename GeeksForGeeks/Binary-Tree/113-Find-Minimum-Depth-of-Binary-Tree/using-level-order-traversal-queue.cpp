// C++ Program to find the minimum depth of tree

// The idea used here is that we do a level order traversal of tree using a queue
// return the level of the first leaf node found

#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct qItem {
  struct node* qnode;
  int depth;
};

int minDepth(struct node* root)   // minimum depth using level order traversal by queue
{
    if(root == NULL) return 0;

    queue<qItem> q;

    qItem itemNode = {root, 1};
    q.push(itemNode);

    while(q.empty() == false)
    {
        itemNode = q.front();
        q.pop();

        struct node* frontnode = itemNode.qnode;
        int depth = itemNode.depth;

        if(frontnode->left == NULL and frontnode->right == NULL) // if leaf node encountered return minimum depth
            return depth;

        if(frontnode->left != NULL)
        {
            itemNode.qnode=frontnode->left;
            itemNode.depth=depth+1;
            q.push(itemNode);
        }

        if(frontnode->right != NULL)
        {
            itemNode.qnode=frontnode->right;
            itemNode.depth=depth+1;
            q.push(itemNode);
        }
    }

    return 0;
}

struct node *newNode(int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = val;

    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
};

int main()
{

    struct node* root = newNode(1);

    root->left=newNode(2);
    root->left->left=newNode(4);
    root->left->right=newNode(5);

    root->right=newNode(3);

    int depth = minDepth(root);

    printf("Minimum depth = %d\n", depth);

    return 0;
}

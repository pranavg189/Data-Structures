// C++ program to print level order traversal line by line
// we use a iterative queue based solution here to print the nodes

#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

/* function to print level order traversal line by line */
void printLevelLineByLine(struct node* root)
{
    queue<struct node*> q;

    q.push(root);

    while(1)
    {
        int nodeCount=q.size();             // get number of nodes in current level;

        if(nodeCount==0)                    // break if queue becomes empty
            break;

        while(nodeCount>0)                  // loop till the nodeCount is zero
        {
            struct node* temp = q.front();
            printf("%d ",temp->data);
            q.pop();

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);

            nodeCount--;

        }

        printf("\n");                       // print newline after each level
    }
}

/* function to create a new node from a given value */
struct node *newNode(int val)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data=val;

    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
};

int main()
{
    struct node* root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->right = newNode(7);

    printLevelLineByLine(root);
    return 0;
}

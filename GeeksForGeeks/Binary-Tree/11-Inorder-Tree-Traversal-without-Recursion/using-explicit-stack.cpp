// C++ program to print inorder traversal of binary tree using stack

// http://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/

#include <bits/stdc++.h>
using namespace std;


struct node{
    int data;
    struct node* left;
    struct node* right;
};

/* Function to print inorder traversal using stack */
void printInorder(struct node *root)
{
    bool done=false;

    struct node* current = root;

    stack<struct node*> s;

    while(!done)
    {
        if(current != NULL)
        {
            s.push(current);
            current = current->left;
        }
        else
        {
            if(!s.empty())
            {
                current = s.top();
                s.pop();
                printf("%d ", current->data);

                current=current->right;
            }
            else
                done=true;       // exit if stack becomes empty and also current=NULL
        }
    }
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

    /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */


    struct node* root = newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);

    printInorder(root);


    return 0;
}

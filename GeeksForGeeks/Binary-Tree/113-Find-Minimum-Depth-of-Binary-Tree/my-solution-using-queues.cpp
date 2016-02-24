#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

int minDepth(struct node* root)
{
    queue<struct node*> q;

    struct node* temp=root;

    q.push(temp);

    int countOfNodes=0;
    int l=1;
    int level=0;
    while(!q.empty())
    {

        level++;
        for(int i=0;i<l;i++)
        {

                struct node* temp1=q.front();

                if(!temp1->left && !temp1->right) // if leaf node found in level order traversal, then return it's level
                    return level;

                if(temp1->left)
                {
                    countOfNodes++;
                    q.push(temp1->left);
                }

                if(temp1->right)
                {
                    countOfNodes++;
                    q.push(temp1->right);
                }


                q.pop();

        }


        l=countOfNodes;
        countOfNodes=0;
    }

    return 0;
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
    struct node *root=newNode(1);

    root->left=newNode(2);
    root->left->left=newNode(4);
    root->left->right=newNode(5);

    root->right=newNode(3);
    root->right->left=newNode(7);

    int depth=minDepth(root);

    printf("Minimum depth is %d\n",depth);

    return 0;
}

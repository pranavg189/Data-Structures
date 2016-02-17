#include <stdio.h>
#include <stdlib.h>

struct Node{
	int val;

 	struct Node* left;	// left pointer
 	struct	Node* right; // right pointer
};

/* Function to create a new node with a given value */
struct Node* newNode(int val)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));

	node->val=val;
	
	node->left=NULL;
	node->right=NULL;

	return (node);
}

int main()
{
	/*create root*/
	struct Node* root;  // root of our new tree

	root=newNode(1);
	/* following is the tree after above statement 
	  
	    1
      /   \
     NULL  NULL
	
	*/

	root->left=newNode(2);
	root->right=newNode(3);
	/* 2 and 3 become left and right child respectively
	
	       1
         /   \
        2      3
     /    \    /  \
    NULL NULL NULL NULL
	
	*/

	root->left->left=newNode(4);
	/* 4 becomes the left child of 2 

           1
       /       \
      2          3
    /   \       /  \
   4    NULL  NULL  NULL
  /  \
NULL NULL

	*/

	return 0;
}
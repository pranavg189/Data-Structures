/* Problem Statement: Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

/* Here the given solution is based on BFS - we iterate on
all the nodes at a current level and fill the next pointers
for the next level */

class Solution {
public:
    void connect(TreeLinkNode *root) {
        
        if(!root) return;
        
        if(!root->left && !root->right) return;
        
        TreeLinkNode* rightSibling;
        TreeLinkNode* p1=root;
        
        while(p1)           /* iterate on all the nodes at a current level and fill the next pointers for the next level                  */
        {  
            if(p1->next)
            {
                rightSibling = p1->next->left;
            }
            else
                rightSibling=NULL;
                
            p1->left->next=p1->right;
            p1->right->next=rightSibling;
            p1=p1->next;
        }
        
        connect(root->left);
            
        }
    
};
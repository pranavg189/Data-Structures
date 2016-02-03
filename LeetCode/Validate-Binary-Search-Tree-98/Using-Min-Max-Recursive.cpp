/* In this solution, we pass the min and max value in each recursion state and check
if every root node value is between the valid range or not. This is a clean recursive
solution for this */

// Runtime: 16ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
       return isBST(root, LONG_MIN, LONG_MAX); /* We cant use NULL in C++ as it is defined as constant '0' */
                                               /* So we use LONG_MIN and LONG_MAX as the numberic limits */
    }
    
    bool isBST(TreeNode* root, long min,long max)
    {
       if(root==NULL) return true;
       
       if(root->val<=min) return false;
       if(root->val>=max) return false;
       
       return isBST(root->left,min,root->val) && isBST(root->right,root->val,max);
    }
};
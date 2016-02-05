/* Problem : Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers. */

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
    int sumNumbers(TreeNode* root) {
        int pathsum=0;
        string pathnum;
        sumPath(root,pathsum,pathnum);
        return pathsum;
    }
    
    void sumPath(TreeNode* root,int &pathsum,string pathnum) /* we need to pass "pathsum" by reference as we need sum of all cases in the recursion */
    {
        if(root==NULL) return;
        else if(root->left || root->right) pathnum.append(to_string(root->val));
        else if(!root->left && !root->right)
        {
            pathnum.append(to_string(root->val));
            pathsum = pathsum + stoi(pathnum);
        }
        
        sumPath(root->left, pathsum, pathnum);
        sumPath(root->right, pathsum, pathnum);
    }
};
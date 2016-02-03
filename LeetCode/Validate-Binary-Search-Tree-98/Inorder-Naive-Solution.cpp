/* The important point to realize in this problem is that
if we store the inorder traversal of the binary search tree 
it should be sorted in ascending order */

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
        vector<int> path;
        
        if(!root) return true;
        if(!root->left && !root->right) return true;
        
        inorder(root,path);
        printf("%d", path.size());
        for(int i=0;i<path.size()-1;i++)
        {
            if(path[i+1]<=path[i])
                return false;
        }
        
        return true;
    }
    
    void inorder(TreeNode* root, vector<int>& path)
    {
        if(root)
        {
            inorder(root->left,path);
            path.push_back(root->val);
            inorder(root->right,path);
        }
    }
};
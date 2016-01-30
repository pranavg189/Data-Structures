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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> pathsum;
        vector<vector<int>> pathsumvec;
        int sumofnodes=0;
        pathSumHelper(pathsumvec, pathsum, root, sumofnodes, sum);
        return pathsumvec;
    }
    
    void pathSumHelper(vector<vector<int>> &pathsumvec, vector<int> pathsum, TreeNode* root, int sum, int reqSum)
    {
        /* Here just need to pass "pathsumvec" variable by reference as we need to progressively store each pathsum into it.*/
        /* On the other hand, there is no need to pass "pathsum" and "sum" variables by reference as we dont need to progressively
        store the value of their variables. In short, we need to maintain their original values in each states of recursion */
        
        if(root==NULL) return;
        
        pathsum.push_back(root->val);
        sum = sum + root->val;
        
        if(root->left==NULL && root->right==NULL)       /* reached a leaf node */
        {
            
            if(sum == reqSum)
            {
                pathsumvec.push_back(pathsum);
            }
        }
        
        pathSumHelper(pathsumvec,pathsum,root->left,sum,reqSum); /* recur for left tree */
        pathSumHelper(pathsumvec,pathsum,root->right,sum,reqSum); /* recur for right tree */
        
        
    }
};
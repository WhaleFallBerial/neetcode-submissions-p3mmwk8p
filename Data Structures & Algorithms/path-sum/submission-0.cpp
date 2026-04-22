/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int res=0;
        return dfs(root, targetSum, res);
    }

    bool dfs(TreeNode* root, int targetSum, int res)
    {
        if(!root) return false;
        res+=root->val;
        if((!root->left)&&(!root->right))
        {
            if(targetSum==res)
                return true;
            else
                return false;
        }
        return dfs(root->left, targetSum, res)||dfs(root->right, targetSum, res);

    }
};
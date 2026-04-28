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
    void dfs(TreeNode* root, int pathval, int& res)
    {
        pathval=pathval*10+root->val;
        if(!root->left&& !root->right)
        {
            res+=pathval;
            return;
        }else if(!root->left&& root->right)
        {
            dfs(root->right, pathval, res);
            
        }else if(root->left&& !root->right)
        {
            dfs(root->left, pathval, res);
        }else{
            dfs(root->right, pathval, res);
            dfs(root->left, pathval, res);
        }
        return ;
    }
public:
    int sumNumbers(TreeNode* root) {
        int res=0;
        dfs(root, 0, res);
        return res;
    }
};
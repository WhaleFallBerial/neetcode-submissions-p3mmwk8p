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
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }

    int dfs(TreeNode* root, int max_value)
    {
        if(!root) return 0;

        int res=0;
        if(root->val>=max_value)
        {
            res=1;
            max_value=root->val;
        }else{
            res=0;
        }
        res+=dfs(root->left,max_value);
        res+=dfs(root->right,max_value);
        return res;
    }
};

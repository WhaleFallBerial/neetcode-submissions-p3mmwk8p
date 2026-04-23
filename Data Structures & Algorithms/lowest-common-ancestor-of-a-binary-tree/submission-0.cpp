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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res=nullptr;
        dfs(root, p, q,res);
        return res;
    }
    pair<bool, bool> dfs(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode*& res)
    {
        if(!root) return{false,false};
        bool pe=false, qe=false;
        pair<bool, bool> left=dfs(root->left, p, q, res);
        pair<bool, bool> right=dfs(root->right, p, q, res);
        if(left.first||right.first||root==p)
            pe=true;
        if(left.second||right.second||root==q)
            qe=true;
        if(qe&&pe&&!res)
        {
            res=root;
        }
        return{pe,qe};
    }
};
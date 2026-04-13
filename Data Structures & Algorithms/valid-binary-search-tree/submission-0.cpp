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
    bool isValidBST(TreeNode* root) {
        return is_valid(root,INT_MIN, INT_MAX);
    }

    bool is_valid(TreeNode* root, int left, int right)
    {
        if(!root) return true;

        if(!((root->val>left)&&(root->val<right))) return false;

        return is_valid(root->left,left,root->val)&&
        is_valid(root->right,root->val,right);

    }
};

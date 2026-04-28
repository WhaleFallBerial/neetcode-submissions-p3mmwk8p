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
    TreeNode* dfs(int l, int r, vector<int>& postorder, 
    unordered_map<int, int>& inordermap, int& postindex)
    {
        if(l>r) return nullptr;
        TreeNode* root= new TreeNode(postorder[postindex]);
        int idx=inordermap[root->val];
        postindex--;
        root->right=dfs(idx+1, r, postorder, inordermap, postindex);
        root->left=dfs(l, idx-1, postorder, inordermap, postindex);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inordermap;
        int postindex=postorder.size()-1;
        for(int i=0;i<inorder.size();i++)
        {
            inordermap[inorder[i]]=i;
        }
        return dfs(0, inorder.size()-1, postorder, inordermap, postindex);
    }
};
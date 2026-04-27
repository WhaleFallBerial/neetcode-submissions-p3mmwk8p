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
    void dfs(TreeNode* root, unordered_map<int, vector<int>>& tmp,int level)
    {
        if(!root) return;
        tmp[level].push_back(root->val);
        dfs(root->left, tmp, level+1);
        dfs(root->right, tmp, level+1);

        return;
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        unordered_map<int,vector<int>> tmp;
        int level=0;
        dfs(root, tmp, level);
        int n=tmp.size(); 
        vector<vector<int>> res(n);
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                for(auto c:tmp[i])
                {
                    res[i].push_back(c);
                }
            }else{
                for(int j=tmp[i].size()-1;j>=0;j--)
                {
                    res[i].push_back(tmp[i][j]);
                }
            }
        }
        return res;

    }
};
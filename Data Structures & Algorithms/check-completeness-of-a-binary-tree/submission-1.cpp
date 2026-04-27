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
    void dfs(TreeNode* root, unordered_map<int, vector<int>>& tmp, int level)
    {
        if(tmp.find(level)==tmp.end()&&!root)
        {
            tmp[level].push_back(0);
            return;
        }else if(!root){
            tmp[level].push_back(0);
            return;
        }else{
            tmp[level].push_back(root->val);
        }
        
        dfs(root->left, tmp,level+1);
        dfs(root->right, tmp,level+1);
        return;
    }
public:
    bool isCompleteTree(TreeNode* root) {
        unordered_map<int, vector<int>> tmp;
        dfs(root, tmp,0);
        int n=tmp.size();
        for(int i=0;i<n-2;i++)
        {
            for(auto t:tmp[i])
            {
                if(t==0)
                {
                    return false;
                }
            }
        }
        bool nozero=true;
        for(auto t:tmp[n-2])
        {
            if(!nozero&&t!=0)
            {
                return false;
            }else if(nozero&&t==0)
            {
                nozero=false;
            }
        }
        return true;

    }
};
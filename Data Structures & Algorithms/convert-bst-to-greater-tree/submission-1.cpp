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
    void dfs(TreeNode* root, vector<int>&arr)
    {
        if(!root) return;
        dfs(root->right,arr);
        arr.push_back(root->val);
        dfs(root->left, arr);
        return;
    }
    void dfs2(TreeNode* root, vector<int>arr, vector<int>sum, TreeNode*& res)
    {
        if(!root) return;


        for(int i=arr.size()-1;i>=0;i--)
        {
            if(root->val<=arr[i])
            {
               root->val=root->val+sum[i];
               break;
            }
        }

        dfs2(root->right,arr, sum, res);
        dfs2(root->left, arr, sum, res);
        return;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        vector<int> arr;
        vector<int> sum;
        dfs(root, arr);        
        int s=accumulate(arr.begin(),arr.end(),0);
        int tmp=0;
        sum.push_back(tmp);
        for(auto a:arr)
        {
            tmp=tmp+a;
            sum.push_back(tmp);
        }
        TreeNode* res=root;
        dfs2(root, arr, sum, res);
        return root;


    }
};
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
class BSTIterator {
    vector<TreeNode*> dp;
    TreeNode* cur;
    void inorder(TreeNode* root, vector<TreeNode*>& arr)
    {
        if(!root) return;
        inorder(root->left, arr);
        arr.push_back(root);
        inorder(root->right, arr);
        return;
    }
public:
    BSTIterator(TreeNode* root) {
        
        inorder(root, dp);
        cur=dp[0];
    }
    
    int next() {
        int res=0;
        if(cur==dp[dp.size()-1])
        {
            res=cur->val;
            cur=nullptr;
        }else{
        for(int i=0;i<dp.size()-1;i++)
        {
            if(cur==dp[i])
            {
                res=cur->val;
                cur=dp[i+1];
                break;
            }
        }
        }
        return res;
    }
    
    bool hasNext() {
        if(cur==nullptr)
            return false;
        else
            return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
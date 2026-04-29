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
    void inorder(TreeNode* root, vector<TreeNode*>& arr)
    {
        if(!root) return;
        inorder(root->left, arr);
        arr.push_back(root);
        inorder(root->right, arr);
        return;
    }
public:
    void recoverTree(TreeNode* root) {
     vector<TreeNode*> arr;
     inorder(root, arr);

     TreeNode* n1=nullptr;
     TreeNode* n2=nullptr;
    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i]->val>arr[i+1]->val)
        {
            n2=arr[i+1];
            if(!n1)
                n1=arr[i];
            else
                break;
        }
    }
    swap(n1->val, n2->val);
    }
};
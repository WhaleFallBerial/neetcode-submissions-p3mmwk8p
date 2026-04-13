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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsS(root,res);
        return join(res,",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> val=split(data, ",");
        int i=0;
        return dfsD(val,i);
    }

private:
    void dfsS(const TreeNode* root, vector<string>& res)
    {
        if(!root) {
            res.push_back("n");
            return;
        }
        res.push_back(to_string(root->val));
        dfsS(root->left,res);
        dfsS(root->right,res);
    }

    TreeNode* dfsD(vector<string>& val, int& i)
    {   
        if(val[i]=="n")
        {
            i++;
            return nullptr;
        }
        TreeNode* res=new TreeNode(stoi(val[i]));
        i++;
        res->left=dfsD(val,i);
        res->right=dfsD(val,i);
        return res;

    }
    vector<string> split(const string& s, const string& delim)
    {
        vector<string>res;
        stringstream ss(s);
        string item;
        while(getline(ss,item,delim[0]))
        {
            res.push_back(item);
        }
        return res;
    }

    string join(const vector<string>& s, const string& delim)
    {
        stringstream ss;
        for(auto &i:s)
        {
            if(&i!=&s[0]) ss<<delim;
            ss<<i;
        }
        return ss.str();
    }

};

class Solution {
    vector<vector<int>> res;
    void dfs(int n, int k, int idx, int i,  vector<int> tmp)
    {
        if(i==k) {
         res.push_back(tmp);
         return;
        }
        if(idx>n) return;
        dfs(n,k,idx+1,i,tmp);
        tmp.push_back(idx);
        dfs(n,k,idx+1,i+1,tmp);
        
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        dfs(n,k,1,0,tmp);
        return res;
    }
};
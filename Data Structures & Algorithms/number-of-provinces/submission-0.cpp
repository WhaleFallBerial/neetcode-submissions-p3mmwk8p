class Solution {
    void dfs(vector<vector<int>>& isConnected, vector<bool>& v, int idx, int n)
    {
        v[idx]=true;
        for(int i=0;i<n;i++)
        {
            if(!v[i]&&isConnected[idx][i])
            {
                dfs(isConnected, v, i, n);
            }
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> v(n, false);
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(!v[i])
            {
                res++;
                dfs(isConnected, v, i, n);
            }
        }
        return res;
    }
};
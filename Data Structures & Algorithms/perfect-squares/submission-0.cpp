class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return dfs(n, n, 0, dp);
    }

    int dfs(int n, int total, int i, vector<int>& dp)
    {
        if(i>n) return 0;
        if(total==0) return 0;
        if(dp[total]!=-1) return dp[total];
        int res=INT_MAX;
        for(int x=1;x*x<=total;x++)
        {
            res=min(res,dfs(n, total-x*x, i+1, dp)+1);
        }
        dp[total]=res;
        return res;

    }
};
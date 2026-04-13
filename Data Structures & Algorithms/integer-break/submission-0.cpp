class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return dfs(n, n, dp);

    }
    int dfs(int n, int orginal, vector<int>& dp)
    {
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int res=(n==orginal)?0: n;
        for(int i=1;i<n;i++)
        {
            res=max(res,dfs(i, orginal, dp)*dfs(n-i, orginal, dp));
            
        }
        dp[n]=res;
        return res;
    }
};
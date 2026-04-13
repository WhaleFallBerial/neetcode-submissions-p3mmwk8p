class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<int> suffix_sum(n,0);
        suffix_sum[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix_sum[i]=suffix_sum[i+1]+piles[i];
        }

        return dfs(0, 1, piles, dp, suffix_sum, n);
    }

    int dfs(const int i, const int m, const vector<int>& piles, 
    vector<vector<int>>& dp, const vector<int>& suffix_sum, const int n)
    {
        if(i>=n) return 0;

        if(dp[i][m-1]!=-1) return dp[i][m-1];

        int res=0;
        for(int x=1;x<=2*m;x++)
        {
            if(i+x>n) break;
            res=max(res, suffix_sum[i]-dfs(i+x,max(m,x),piles,dp,suffix_sum, n));
        }
        return dp[i][m-1]=res;
    }
};
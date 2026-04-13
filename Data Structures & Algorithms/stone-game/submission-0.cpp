class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<int> cur_sum(n,piles[0]);
        for(int i=1;i<n;i++)
        {
            cur_sum[i]=cur_sum[i-1]+piles[i];
        }
        int alice=dfs(n,0,n-1,piles,dp, cur_sum);
        int total=accumulate(piles.begin(),piles.end(),0);
        
        return alice>total-alice;
    }

    int dfs(const int n, const int l, const int r, 
    const vector<int>& piles, vector<vector<int>>& dp, const vector<int>& cur_sum)
    {
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        
        int cur_num;
        if(l>0)
            cur_num=cur_sum[r]-cur_sum[l-1];
        else
            cur_num=cur_sum[r];

        int res=0;
        res=max(cur_num-dfs(n,l+1,r,piles,dp,cur_sum),cur_num-dfs(n,l,r-1,piles,dp,cur_sum));
        dp[l][r]=res;
        return res;
    }
};
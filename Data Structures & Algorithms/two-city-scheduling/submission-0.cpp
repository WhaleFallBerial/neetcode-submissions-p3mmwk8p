class Solution {
    int dfs(vector<vector<int>>& costs,int idx, int aidx, int bidx, vector<vector<int>>& dp)
    {
        if(idx>=costs.size())
        {
            return 0;
        }
        if(dp[aidx][bidx]!=-1)
        {
            return dp[aidx][bidx];
        }
        int res=INT_MAX;
        if(aidx>0)
        {
            res=dfs(costs, idx+1, aidx-1, bidx, dp)+costs[idx][0];
        }
        if(bidx>0)
        {
            res=min(res, dfs(costs, idx+1, aidx, bidx-1, dp)+costs[idx][1]);
        }
        dp[aidx][bidx]=res;
        return res;

    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size()/2;
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        return dfs(costs, 0, n, n, dp);
    }
};
class Solution {
    int dfs(vector<int>& cache, int idx, vector<vector<int>>& dp)
    {
        if(idx>=dp.size())
        {
            return 0;
        }
        if(cache[idx]!=-1)
        {
            return cache[idx];
        }
        int res= dfs(cache, idx+1, dp);
        int j=idx+1;
        while(j<dp.size()&&dp[idx][1]>dp[j][0])
        {
            j++;
        }
        cache[idx]=max(res, dp[idx][2]+dfs(cache, j, dp));
        return cache[idx];
        
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>> dp(n);
        for(int i=0;i<n;i++)
        {
            dp[i]={startTime[i], endTime[i], profit[i]};
        }
        sort(dp.begin(), dp.end());
        vector<int> cache(n, -1);
        return dfs(cache, 0, dp);
    }
};
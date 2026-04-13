class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
         int total=accumulate(stones.begin(),stones.end(),0);
         int half=(total+1)/2;
        vector<vector<int>> dp(n,vector<int>(total,-1));
       
        
        return dfs(0,total,half,n,0,stones,dp);
    }

    int dfs(const int cur, const int total, 
    const int target, const int n, const int i, 
    const vector<int>& stones, vector<vector<int>>& dp)
    {
        if(i>=n || cur>=target)
        {
            return abs(cur-(total-cur));
        }
        if(dp[i][cur]!=-1) return dp[i][cur];

        int res=min(dfs(cur+stones[i],total,target,n,i+1,stones,dp),dfs(cur,total,target,n,i+1,stones,dp));
        dp[i][cur]=res;
        return res;
    }
};
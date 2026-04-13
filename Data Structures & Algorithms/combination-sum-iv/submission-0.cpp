class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(target+1, -1);
        return dfs(nums, target, dp);

    }
    int dfs(vector<int>& nums, int target, vector<int>& dp)
    {
        if(dp[target]!=-1) return dp[target];
        if(target==0) return 1;
        int res=0;
        for(auto n:nums)
        {
            if(target<n) break;
            res+=dfs(nums, target-n, dp);
        }
        dp[target]=res;
        return res;
    }
};